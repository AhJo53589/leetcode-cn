// 5206.remove-all-adjacent-duplicates-in-string-ii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
using namespace std;

//////////////////////////////////////////////////////////////////////////
//string removeDuplicates(string s, int k)
//{
//	string ans;
//	int cnt = 1;
//	for (size_t i = 1; i < s.size(); i++)
//	{
//		if (s[i] == s[i - 1])
//		{
//			cnt = (cnt + 1) % k;
//		}
//
//		if (s[i] != s[i - 1] || i == s.size() - 1)
//		{
//			while (cnt > 0)
//			{
//				cnt--;
//				ans.push_back(s[i - 1]);
//			}
//			cnt = 1;
//			if (s[i] != s[i - 1] && i == s.size() - 1)
//			{
//				ans.push_back(s[i]);
//			}
//		}
//	}
//
//	return (ans.size() == s.size()) ? ans : removeDuplicates(ans, k);
//}

//////////////////////////////////////////////////////////////////////////
//string removeDuplicates(string s, int k)
//{
//	vector<string> sub;
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		if (sub.empty() || s[i] != sub.back()[0])
//		{
//			sub.push_back({ s[i] });
//		}
//		else
//		{
//			sub.back() += s[i];
//			if (sub.back().size() == k)
//			{
//				sub.pop_back();
//			}
//		}
//	}
//	string ans;
//	for (auto &&s : sub)
//	{
//		ans.append(s);
//	}
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
string removeDuplicates(string s, int k)
{
	string sub;
	vector<int> cnt;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (sub.empty() || s[i] != sub.back())
		{
			sub.push_back(s[i]);
			cnt.push_back(1);
			continue;
		}
		if (++cnt.back() == k)
		{
			sub.pop_back();
			cnt.pop_back();
		}
	}
	string ans;
	for (size_t i = 0; i < sub.size(); i++)
	{
		while (cnt[i]-- > 0)
		{
			ans += sub[i];
		}
	}
	return ans;
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
	vector<string> TESTS;
	vector<int> K;
	vector<string> ANSWERS;

	TESTS.push_back("abcd");
	K.push_back(2);
	ANSWERS.push_back("abcd");

	TESTS.push_back("deeedbbcccbdaa");
	K.push_back(3);
	ANSWERS.push_back("aa");

	TESTS.push_back("pbbcggttciiippooaais");
	K.push_back(2);
	ANSWERS.push_back("ps");

	TESTS.push_back("iiiixxxxxiiccccczzffffflllllllllfffffllyyyyyuuuuuz");
	K.push_back(5);
	ANSWERS.push_back("izzlz");

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = removeDuplicates(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}