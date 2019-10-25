// 166.fraction-to-recurring-decimal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//string fractionToDecimal(int numerator, int denominator)
//{
//	if (denominator == 0) return "0";
//	string res;
//	if ((numerator < 0 && denominator>0) || (numerator > 0 && denominator < 0))
//	{
//		res += '-';
//	}
//
//	long long int numl = numerator;
//	long long int denl = denominator;
//	numl = abs(numl);
//	denl = abs(denl);
//	if (numl < denl)
//	{
//		if (numl != 0) res += "0.";
//		else res += "0";
//	}
//	else
//	{
//		res += to_string(numl / denl);
//		numl = numl % denl;
//		if (numl != 0) res += ".";
//	}
//	unordered_map<int, int>ump;
//	string tp;
//	int flag = 0;
//	int index = 0;
//	while (numl)
//	{
//		auto it = ump.find(numl);
//		if (it == ump.end())
//		{
//			ump[numl] = index++;
//			numl *= 10;
//			tp += to_string(numl / denl);
//			numl = numl % denl;
//		}
//		else
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if (flag)
//	{
//		auto it = ump.find(numl);
//		string ss1 = tp.substr(0, it->second);
//		res += ss1;
//		string ss2 = tp.substr(it->second);
//		res += "(" + ss2 + ")";
//	}
//	else
//	{
//		res += tp;
//	}
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
string fractionToDecimal(int numerator, int denominator) {
	string result;
	if (denominator == 0)
		return result;
	long long num = static_cast<long long>(numerator);
	long long denom = static_cast<long long>(denominator);
	//处理符号
	if ((num < 0 && denom > 0) || (num > 0 && denom < 0))
		result += "-";
	num = abs(num);
	denom = abs(denom);
	//处理整数部分
	result += to_string(num / denom);
	num %= denom;
	//处理小数部分
	if (num)
		result += ".";
	//利用hash表记录出现过的除数从而定位循环
	unordered_map<long long, int> map;
	int index = 0;//当前index - map[num]可以定位循环的长度
	while (num && map.find(num) == map.end()) {
		map[num] = index++;
		num *= 10;
		result += to_string(num / denom);
		num %= denom;
	}
	//如果是出现了循环小数
	if (map.find(num) != map.end()) {
		result += "()";
		int cur = result.size() - 2;
		while (index-- > map[num]) {
			swap(result[cur], result[cur - 1]);
			--cur;
		}
	}
	return result;
}


int main()
{
	vector<vector<int>> TESTS;
	//vector<int> K;
	vector<string> ANSWERS;

	TESTS.push_back({ 1,2 });
	ANSWERS.push_back("0.5");

	TESTS.push_back({ 2,1 });
	ANSWERS.push_back("2");

	TESTS.push_back({ 2,3 });
	ANSWERS.push_back("0.(6)");

	TESTS.push_back({ 0,1 });
	ANSWERS.push_back("0");

	//TESTS.push_back({ -2147483648​,-1 });
	//ANSWERS.push_back("0.5");


	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = fractionToDecimal(TESTS[i][0], TESTS[i][1]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}