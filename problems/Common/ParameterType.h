#pragma once

//////////////////////////////////////////////////////////////////////////
class TestCases
{
public:
	TestCases(std::ifstream& is) : curr(0)
	{
		std::string text;
		while (getline(is, text))
		{
			file.push_back(text);
		}
	}
	std::string popString()
	{
		if (curr == file.size()) return {};
		return file[curr++];
	}


	template<class T>
	T get();

	template<>
	int get<int>()
	{
		if (curr == file.size()) return {};
		return stringToInt(popString());
	}

	template<>
	std::vector<int> get<std::vector<int>>()
	{
		if (curr == file.size()) return {};
		return stringToVectorInt(popString());
	}

	bool empty() { return curr == file.size(); }

private:
	int stringToInt(std::string s)
	{
		return std::stoi(s);
	}

	std::vector<int> stringToVectorInt(std::string input)
	{
		std::vector<int> output;
		input = input.substr(1, input.length() - 2);
		std::stringstream ss;
		ss.str(input);
		std::string item;
		char delim = ',';
		while (getline(ss, item, delim))
		{
			output.push_back(stoi(item));
		}
		return output;
	}


private:
	std::vector<std::string> file;
	std::size_t curr;
};

//////////////////////////////////////////////////////////////////////////
// 获取函数的返回值和参数列表
// 将参数列表展开
// 将参数填入测试数据
// 调用函数
template<class R, class ...Params>
class type_warp;

template<class R, class Head, class... Tail>
class type_warp<R, Head, Tail...> : public type_warp<R, Tail...>
{
public:
	using Base = type_warp<R, Tail...>;
	template<class F, class... Args>
	static R call(F&& f, TestCases& caster, Args&&... args)
	{
		Head head = caster.get<Head>();
		return Base::call(f, caster, std::forward<Args>(args)..., std::forward<Head>(head));
	}
};

template<class R>
class type_warp<R>
{
public:
	template<class F, class... Args>
	static R call(F&& f, TestCases& caster, Args&&... args)
	{
		return f(std::forward<Args>(args)...);
	}
};

template<typename T>
struct function_type;
template<typename R, typename ...Args>
struct function_type<std::function<R(Args...)>> : public type_warp<R, Args...>
{
	using return_type = R;
};


