#pragma once

#include "StringConvert.h"

//////////////////////////////////////////////////////////////////////////
// 将测试用例字符串转换为对应类型参数
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

	TestCases(std::vector<std::string> &&vs) : curr(0), file(std::move(vs)) {}


	std::string popString()
	{
		if (curr == file.size()) return {};
		return file[curr++];
	}

	template<class T>
	T get()
	{
		if (curr == file.size()) return {};
		return convert<T, std::string>(popString());
	}

	bool empty() { return curr == file.size(); }

private:
	std::vector<std::string> file;
	std::size_t curr;
};
