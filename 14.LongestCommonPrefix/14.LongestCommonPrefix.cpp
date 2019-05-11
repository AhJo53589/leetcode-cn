// 14.LongestCommonPrefix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include<string> 
using namespace std;


string longestCommonPrefix(vector<string>& strs)
{
	if (strs.size() == 0) return "";
	if (strs.size() == 1) return strs[0];
	int i = 0;
	while (true)
	{
		for (int j = 1; j < strs.size(); j++)
		{
			if ((i == strs[0].size()) || (i == strs[j].size()) || (strs[0][i] != strs[j][i]))
			{
				if (i == 0) return "";
				return strs[0].substr(0, i);
			}
		}
		++i;
	}
	return "";
}

int main()
{
	vector<string> strs;
	//strs.push_back("flower");
	//strs.push_back("flow");
	//strs.push_back("flight");
	//strs.push_back("dog");
	//strs.push_back("racecar");
	//strs.push_back("car");
	strs.push_back("23");
	cout << longestCommonPrefix(strs).c_str() << endl;
}
