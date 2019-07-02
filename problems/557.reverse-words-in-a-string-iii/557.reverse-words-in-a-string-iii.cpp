// 557.reverse-words-in-a-string-iii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>

using namespace std;

string reverseWords(string s)
{
	string str;
	string sub;
	int iBegin = 0;
	int iEnd = 0;

	s += " ";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ') continue;
		for (int j = i - 1; j >= iBegin; j--)
		{
			sub += s[j];
		}
		str += sub;
		if (i != s.size() - 1)
		{
			iBegin = i + 1;
			str += " ";
			sub.clear();
		}
	}
	return str;
}

int main()
{
	string str = "the sky is blue";
	cout << str << endl;
	cout << reverseWords(str) << endl;
}
