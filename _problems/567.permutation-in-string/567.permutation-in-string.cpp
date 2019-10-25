// 567.permutation-in-string.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
bool checkInclusion(string s1, string s2)
{
	int cc_s1[26] = { 0 };
	for (auto &c : s1)
	{
		cc_s1[c - 'a']++;
	}

	int cc_s2[26] = { 0 };
	size_t left = 0;
	for (size_t i = 0; i < s2.size(); i++)
	{
		int t = s2[i] - 'a';
		cc_s2[t]++;
		if (cc_s2[t] == cc_s1[t])
		{
			bool bFlag = true;
			for (size_t j = 0; j < 26; j++)
			{
				if (cc_s2[j] != cc_s1[j])
				{
					bFlag = false;
					break;
				}
			}
			if (bFlag) return true;
		}
		else if (cc_s2[t] > cc_s1[t])
		{
			for (size_t j = left; j <= i; j++)
			{
				int t2 = s2[j] - 'a';
				cc_s2[t2]--;
				left++;
				if (s2[j] == s2[i]) break;
			}
		}
	}
	return false;
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


	vector<string> TESTS;
	vector<string> K;
	vector<bool> ANSWERS;

	TESTS.push_back("ab");
	K.push_back("eidbaooo");
	ANSWERS.push_back(true);

	TESTS.push_back("ab");
	K.push_back("eidboaoo");
	ANSWERS.push_back(false);

	TESTS.push_back("adc");
	K.push_back("dcda");
	ANSWERS.push_back(true);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = checkInclusion(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}