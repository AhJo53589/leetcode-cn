﻿// 5.longest-palindromic-substring.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


void findPalindrome(string s, int &low, int &high)
{
	while (s[low] == s[high])
	{
		low--;
		high++;
		if (low < 0 || high > s.size() - 1) break;
	}
	low++;
	high--;
}

string longestPalindrome(string s)
{
	if (s.size() == 1) return s;

	string ans;
	ans.push_back(s[0]);
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i - 1])
		{
			int low = i - 1;
			int high = i;
			findPalindrome(s, low, high);
			if (high - low + 1 > ans.size())
			{
				ans = s.substr(low, high - low + 1);
			}
		}
		if ((i + 1 < s.size()) && s[i - 1] == s[i + 1])
		{
			int low = i - 1;
			int high = i + 1;
			findPalindrome(s, low, high);
			if (high - low + 1 > ans.size())
			{
				ans = s.substr(low, high - low + 1);
			}
		}
	}
	return ans;
}

int main()
{
	vector<string> str;
	str.push_back("babad");
	str.push_back("babab");
	str.push_back("cbbd");
	str.push_back("ac");

	for (auto s : str)
	{
		cout << endl << "/////////////////////////////////" << endl;
		cout << s << endl;
		cout << longestPalindrome(s) << endl;
	}
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
	vector<vector<vector<int>>> TESTS;
	vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ {1,5,9},{10,11,13},{12,13,15} });
	K.push_back(8);
	ANSWERS.push_back(13);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = kthSmallest(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
		//kthSmallest(TESTS[i], K[i]);
		//cout << checkAnswer<vector<vector<int>>>(TESTS[i], ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}
