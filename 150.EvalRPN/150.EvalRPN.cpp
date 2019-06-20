// 150.EvalRPN.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

int evalRPN(vector<string>& tokens)
{
	if (tokens.empty()) return 0;
	stack<int> s;
	for (auto str : tokens)
	{
		if (str == "+" || str == "-" || str == "*" || str == "/")
		{
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			if (str == "+") s.push(b + a);
			if (str == "-") s.push(b - a);
			if (str == "*") s.push(b * a);
			if (str == "/") s.push(b / a);
		}
		else
		{
			s.push(stoi(str));
		}
	}
	return s.top();
}

void printfVectorString(vector<string> &strs)
{
	for (auto i : strs)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	//vector<string> tokens = { "2", "1", "+", "3", "*" };
	vector<string> tokens = { "4", "13", "5", "/", "+" };
	//vector<string> tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	printfVectorString(tokens);
	cout << evalRPN(tokens);
}
