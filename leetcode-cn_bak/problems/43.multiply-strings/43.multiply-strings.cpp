// 43.multiply-strings.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//string addStrings(string num1, string num2)
//{
//	while (num1.size() < num2.size()) num1.insert(num1.begin(), '0');
//	while (num2.size() < num1.size()) num2.insert(num2.begin(), '0');
//
//	string sum;
//	int iCarry = 0;
//	for (int i = num1.size() - 1; i >= 0; i--)
//	{
//		int val = (int)(num1[i] - '0') + (int)(num2[i] - '0') + iCarry;
//		iCarry = val / 10;
//		val %= 10;
//		char c = (char)(val) + '0';
//		sum.push_back(c);
//	}
//	if (iCarry != 0) sum.push_back((char)(iCarry) + '0');
//
//	reverse(sum.begin(), sum.end());
//
//	return sum;
//}
//
//string multiply(string num1, string num2)
//{
//	if (num1 == "0" || num2 == "0") return "0";
//
//	string sum;
//	int len1 = num1.size();
//	int len2 = num2.size();
//	for (int i = 0; i < len1; i++)
//	{
//		for (int j = 0; j < len2; j++)
//		{
//			int val = (int)(num1[i] - '0') * (int)(num2[j] - '0');
//			int zero = (len1 - i - 1) + (len2 - j - 1);
//			string t = to_string(val);
//			while (zero-- > 0) t += "0";
//			sum = addStrings(sum, t);
//		}
//	}
//	return sum;
//}

string multiply(string num1, string num2)
{
	string ret(num1.size() + num2.size(), '0');
	for (int i = num1.size() - 1; i >= 0; i--)
	{
		int val1 = num1[i] - '0';
		for (int j = num2.size() - 1; j >= 0; j--)
		{
			int val2 = num2[j] - '0';
			int sum = (ret[i + j + 1] - '0') + val1 * val2;
			ret[i + j + 1] = (char)(sum % 10 + '0');
			ret[i + j] += sum / 10;
		}
	}

	for (int i = 0; i < ret.size(); i++)
	{
		if (ret[i] != '0' || i == ret.size() - 1) return ret.substr(i, ret.size() - i);
	}
	return "0";
}


int main()
{
	vector<string> N;
	vector<string> N2;
	vector<string> A;

	N.push_back("2");
	N2.push_back("3");
	A.push_back("6");

	N.push_back("123");
	N2.push_back("456");
	A.push_back("56088");

	N.push_back("123456789");
	N2.push_back("987654321");
	A.push_back("121932631112635269");

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "/////////////////////////////////" << endl;
		cout << N[i] << " * " << N2[i] << " = ";
		string ans = multiply(N[i], N2[i]);
		cout << ans << endl;
		cout << "Answer = " << A[i] << endl;
	}
}