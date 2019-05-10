// 8.MyAtoi.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

//去掉所有空格
void trim(string &s)
{
	if (!s.empty())
	{
		s.erase(0, s.find_first_not_of(" "));
		//s.erase(s.find_last_not_of(" ") + 1);
	}

	//int index = 0;
	//if (!s.empty())
	//{
	//	while ((index = s.find(' ', index)) != string::npos)
	//	{
	//		s.erase(index, 1);
	//	}
	//}
}
bool getCleanString(string &s)
{
	string t;
	bool bBeginFlag = true;
	bool bEndFlag = true;
	bool bNegative = false;

	trim(s);
	auto i = s.begin();
	while (i != s.end())
	{
		if (!bEndFlag)
		{
			i = s.erase(i);
			continue;
		}

		if (bBeginFlag)
		{
			if (*i == '-' || *i == '+')
			{
				bNegative = (*i == '-');
				i = s.erase(i);
				bBeginFlag = false;
				continue;
			}
			else if (*i >= '0' && *i <= '9')
			{
				bBeginFlag = false;
				++i;
			}
			else
			{
				bEndFlag = false;
				continue;
			}
		}

		if (*i < '0' || *i > '9')
		{
			bEndFlag = false;
		}
		else
		{
			++i;
		}
	}
	return bNegative;
}

int myAtoi(string str)
{
	bool bNegative = getCleanString(str);
	double num = 0;
	auto i = str.begin();
	while (i != str.end())
	{
		long iTemp = *i - '0';
		num *= 10;
		num += iTemp;
		++i;
		if (!bNegative && num > INT_MAX)
		{
			num = INT_MAX;
			break;
		}
		if (bNegative && -num < INT_MIN)
		{
			num = INT_MAX + 1;
			break;
		}
	}
	return bNegative ? -num : num;
}

//int myAtoi(string str) 
//{
//	int i = 0;
//	int res = 0;
//	int rev = 1;
//	int num = 0;
//	while (i < str.length() && str.at(i) == ' ')    // 吃掉空格
//		i++;
//	if (i < str.length() && str.at(i) == '-')       // 判断正负数
//	{
//		rev = -1;
//		i++;
//	}
//	else if (i < str.length() && str.at(i) == '+')
//		i++;
//	while (i < str.length() && isdigit(str.at(i)))
//	{
//		num = str.at(i++) - '0';
//		res = (long)res * 10 + num;                   // num是个位
//		if (res % 10 != num)                    // 判断是否溢出的方式
//			return rev > 0 ? INT_MAX : INT_MIN;
//	}
//
//	return rev * res;
//}

int main()
{
	string s = "   -42";
	//string s = "4193 with words";
	//string s = "words and 987";
	//string s = "-91283472332";
	//string s = "   +0 123";
	cout << myAtoi(s) << endl;
}
