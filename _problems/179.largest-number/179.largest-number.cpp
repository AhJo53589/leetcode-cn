// 179.largest-number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>

#include <algorithm>
#include <array>
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
#include <sstream>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.Hi"
//#include "..\Common\TreeNode.Hi"
//#include "..\Common\ListNode.Hi"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//string largestNumber(vector<int>& nums)
//{
//	auto f_sort = [](const string &a, const string &b)
//	{
//		string r_a = a + b;
//		string r_b = b + a;
//		int i = 0;
//		do
//		{
//			if (r_a[i] == r_b[i]) continue;
//			return (r_a[i] - '0' < r_b[i] - '0');
//		} while (++i < r_a.size());
//		return (r_a[0] - '0' < r_b[0] - '0');
//	};
//
//	vector<string> str;
//	for (auto &n : nums)
//	{
//		str.push_back(to_string(n));
//	}
//	sort(str.rbegin(), str.rend(), f_sort);
//
//	string ans;
//	bool bZeroFlag = true;
//	for (auto &s : str)
//	{
//		if (bZeroFlag)
//		{
//			if (s == "0") continue;
//			bZeroFlag = false;
//		}
//		ans.append(s);
//	}
//	return ans.empty() ? "0" : ans;
//}

//////////////////////////////////////////////////////////////////////////
string largestNumber(vector<int>& nums)
{
	auto f_sort = [](const int &a, const int &b)
	{
		long long n_a = 10;
		while (a / n_a) n_a *= 10;
		long long n_b = 10;
		while (b / n_b) n_b *= 10;
		long long r_a = (long long)a * n_b + (long long)b;
		long long r_b = (long long)b * n_a + (long long)a;
		return r_a < r_b;
	};

	sort(nums.rbegin(), nums.rend(), f_sort);

	string ans;
	bool bZeroFlag = true;
	for (auto &n : nums)
	{
		if (bZeroFlag)
		{
			if (n == 0) continue;
			bZeroFlag = false;
		}
		ans.append(to_string(n));
	}
	return ans.empty() ? "0" : ans;
}

int main()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);

	auto f_time_cout = [&]()
	{
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << endl;
	};

	//////////////////////////////////////////////////////////////////////////
	vector<vector<int>> TESTS;
	//vector<int> K;
	vector<string> ANSWERS;

	TESTS.push_back({ 10,2 });
	ANSWERS.push_back("210");

	TESTS.push_back({ 3,30,34,5,9 });
	ANSWERS.push_back("9534330");

	TESTS.push_back({ 121,12 });
	ANSWERS.push_back("12121");

	TESTS.push_back({ 0,0 });
	ANSWERS.push_back("0");

	TESTS.push_back({ 999999998,999999997,999999999 });
	ANSWERS.push_back("999999999999999998999999997");

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = largestNumber(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}
