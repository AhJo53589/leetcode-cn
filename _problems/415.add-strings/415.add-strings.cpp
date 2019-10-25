// 415.add-strings.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


string addStrings(string num1, string num2)
{
	while (num1.size() < num2.size()) num1.insert(num1.begin(), '0');
	while (num2.size() < num1.size()) num2.insert(num2.begin(), '0');

	string sum;
	int iCarry = 0;
	for (int i = num1.size() - 1; i >= 0; i--)
	{
		int val = (int)(num1[i] - '0') + (int)(num2[i] - '0') + iCarry;
		iCarry = val / 10;
		val %= 10;
		char c = (char)(val)+'0';
		sum.push_back(c);
	}
	if (iCarry != 0) sum.push_back((char)(iCarry) + '0');

	reverse(sum.begin(), sum.end());

	return sum;
}

int main()
{
	string num1 = "1111";
	string num2 = "9999";
	string sum = addStrings(num1, num2);
	cout << num1 << " + " << num2 << " = " << sum;
}