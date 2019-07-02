// 151.reverse-words-in-a-string.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	stack<string> st;
	string sub;
	s += " ";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			sub += s[i];
		}
		else
		{
			if (!sub.empty())
			{
				st.push(sub);
				sub.clear();
			}
		}
	}
	string str;
	while (!st.empty())
	{
		str += st.top();
		st.pop();
		str += " ";
	}
	if (!str.empty())
	{
		str = str.substr(0, str.size() - 1);
	}
	return str;
}

int main()
{
	string str = "the sky is blue";
	cout << str << endl;
	cout << reverseWords(str) << endl;
}