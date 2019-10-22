// 67.add-binary.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

string addBinary(string a, string b)
{
	string *pA = (a.size() < b.size()) ? &a : &b;
	string *pB = (a.size() >= b.size()) ? &a : &b;
	string c;

	int iCarry = 0;
	int iDiff = pB->size() - pA->size();
	for (int i = pA->size() - 1; i >= 0; i--)
	{
		int a = (*pA)[i] == '1';
		int b = (*pB)[i + iDiff] == '1';
		char sum = (a + b + iCarry == 0 || a + b + iCarry == 2) ? '0' : '1';
		c.insert(c.begin(), sum);
		iCarry = (a + b + iCarry > 1) ? 1 : 0;
	}
	for (int i = iDiff - 1; i >= 0; i--)
	{
		if (iCarry == 0)
		{
			c.insert(c.begin(), (*pB)[i]);
		}
		else
		{
			char sum = ((*pB)[i] == '0') ? '1' : '0';
			c.insert(c.begin(), sum);
			iCarry = (sum == '0') ? 1 : 0;
		}
	}
	if (iCarry == 1) c.insert(c.begin(), '1');

	return c;
}

//string addBinary(string a, string b)
//{
//	/* 1.补0 */
//	while (a.size() < b.size())
//		a.insert(a.begin(), '0');
//	while (b.size() < a.size())
//		b.insert(b.begin(), '0');
//
//	/* 2.相加 */
//	string res;
//	int add = 0;
//	for (int i = a.size() - 1; i >= 0; i--)
//	{
//		int val = (int)(a[i] - '0') + (int)(b[i] - '0') + add;
//		add = val / 2;
//		val %= 2;
//		char c = (char)(val)+'0';
//		res.push_back(c);
//	}
//	if (add != 0) res.push_back((char)(add)+'0');
//
//	reverse(res.begin(), res.end());
//
//	return res;
//}

int main()
{
	//string a = "11";
	//string b = "1";
	//string a = "1010";
	//string b = "1011";
	string a = "100";
	string b = "110010";

	cout << a << " + " << b << " = ";
	cout << addBinary(a, b) << endl;

}
