// 739.DailyTemperatures.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

vector<int> dailyTemperatures(vector<int>& T)
{
	vector<int> days(T.size());
	stack<int> s;
	for (int i = 0; i < T.size(); i++)
	{
		while (!s.empty() && T[s.top()] < T[i])
		{
			days[s.top()] = i - s.top();
			s.pop();
		}
		s.push(i);
	}
	return days;
}

void printfVectorInt(vector<int> &nums)
{
	for (int i : nums)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
	printfVectorInt(temperatures);
	vector<int> rst = dailyTemperatures(temperatures);
	printfVectorInt(rst);
}
