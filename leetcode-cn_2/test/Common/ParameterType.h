#pragma once

#include "Common.h"

//////////////////////////////////////////////////////////////////////////
//template <typename T>
//class GetType
//{
//public:
//	typedef T type;
//	typedef T& type_ref;
//	typedef T* type_pointer;
//};
//
//template<typename T>
//class GetType<T&>
//{
//public:
//	typedef typename remove_reference<T>::type type;
//	typedef typename remove_reference<T>::type_ref type_ref;
//	typedef typename remove_reference<T>::type_pointer type_pointer;
//};
//
//template<typename T>
//class GetType<T*>
//{
//public:
//	typedef typename remove_reference<T>::type type;
//	typedef typename remove_reference<T>::type_ref type_ref;
//	typedef typename remove_reference<T>::type_pointer type_pointer;
//};

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
	bool get<bool>()
	{
		if (curr == file.size()) return {};
		return stringToBool(popString());
	}

	template<>
	int get<int>()
	{
		if (curr == file.size()) return {};
		return stringToInt(popString());
	}

	template<>
	std::string get<std::string>()
	{
		if (curr == file.size()) return {};
		return popString();
	}

	template<>
	std::vector<int> get<std::vector<int>>()
	{
		if (curr == file.size()) return {};
		return stringToVectorInt(popString());
	}

	template<>
	std::vector<std::vector<int>> get<std::vector<std::vector<int>>>()
	{
		if (curr == file.size()) return {};
		return stringToVectorVectorInt(popString());
	}

	template<>
	std::vector<std::string> get<std::vector<std::string>>()
	{
		if (curr == file.size()) return {};
		return StringToVectorString(popString());
	}

	bool empty() { return curr == file.size(); }

private:
	bool stringToBool(std::string s)
	{
		if (s == "true" || s == "True" || s == "TRUE") return true;
		return false;
	}

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

	std::vector<std::vector<int>> stringToVectorVectorInt(std::string str)
	{
		std::vector<std::vector<int>> matrix;
		if (str.size() < 3) return matrix;
		str = str.substr(1, str.size() - 2);

		std::string strSub;
		char last = ' ';
		for (auto c : str)
		{
			if (last == ']')
			{
				last = ' ';
				continue;
			}
			strSub += c;
			last = c;
			if (c == ']')
			{
				matrix.push_back(stringToVectorInt(strSub));
				strSub.clear();
			}
		}
		return matrix;
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
		//typedef GetType<Head>::type HeadType;
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


