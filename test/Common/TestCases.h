#pragma once

#include "StringConvert.h"

//////////////////////////////////////////////////////////////////////////
// �����������ַ���ת��Ϊ��Ӧ���Ͳ���
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
		return convert<T>(popString());
	}

	template<>
	std::vector<int> get<std::vector<int>>()
	{
		if (curr == file.size()) return {};
		return StringToVectorInt(popString());
	}

	template<>
	std::vector<std::vector<int>> get<std::vector<std::vector<int>>>()
	{
		if (curr == file.size()) return {};
		return StringToVectorVectorInt(popString());
	}

	template<>
	std::vector<std::string> get<std::vector<std::string>>()
	{
		if (curr == file.size()) return {};
		return StringToVectorString(popString());
	}

	bool empty() { return curr == file.size(); }

private:
	std::vector<std::string> file;
	std::size_t curr;
};
