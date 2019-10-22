// 412.FizzBuzz.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <random>

using namespace std;


vector<string> fizzBuzz(int n)
{
	vector<string> str;
	for (int i = 1; i <= n; i++)
	{
		if (i % 15 == 0)
		{
			str.push_back("FizzBuzz");
		}
		else if (i % 5 == 0)
		{
			str.push_back("Buzz");
		}
		else if (i % 3 == 0)
		{
			str.push_back("Fizz");
		}
		else
		{
			str.push_back(to_string(i));
		}
	}
	return str;
}

int main()
{
	vector<string> str = fizzBuzz(100);
	for (string s : str)
	{
		cout << s << endl;
	}
}
