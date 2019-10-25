// 38.CountAndSay.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include<string> 
using namespace std;

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221

// 1 被读作  "one 1"  ("一个一"), 即 11。
// 11 被读作 "two 1s" ("两个一"）, 即 21。
// 21 被读作 "one 2", "one 1" （"一个二", "一个一"), 即 1211。


string countAndSay(int n)
{
	if (n <= 0 || n > 30) return "";

	if (n == 1) return "1";

	string str = countAndSay(n - 1);
	string strCount;
	size_t i = 0;
	while (i < str.size())
	{
		size_t j = 1;
		while (str[i] == str[i + j])
		{
			j++;
		}
		strCount += to_string(j);
		strCount += str[i];
		i += j;
	}
	return strCount;
}

int main()
{
	for (int i = 1; i < 31; i++)
	{
		cout << countAndSay(i).c_str() << endl;
	}
}
