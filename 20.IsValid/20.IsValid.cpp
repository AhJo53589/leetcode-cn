// 20.IsValid.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>

using namespace std;

bool isValid(string str)
{
	stack<char> s;
	for (int i = 0; i < str.size(); i++)
	{
		if (s.empty())
		{
			s.push(str[i]);
			continue;
		}

		if (s.top() != '(' && s.top() != '[' && s.top() != '{') return false;

		if ((s.top() == '(' && str[i] == ')')
			|| (s.top() == '[' && str[i] == ']')
			|| (s.top() == '{' && str[i] == '}'))
		{
			s.pop();
		}
		else
		{
			s.push(str[i]);
		}
	}
	return s.empty();
}

int main()
{
	//string s = "()[]{}";
	//string s = "([)]";
	//string s = "{[]}";
	string s = "(]";
	//string s = "";
	cout << isValid(s);
}
