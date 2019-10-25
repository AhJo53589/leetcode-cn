// 6.zigzag-conversion.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <functional>

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
string convert(string s, int numRows)
{
	if (numRows == 1) return s;
	string ans;
	size_t iStep = numRows * 2 - 2;
	for (size_t i = 0; i < numRows; i++)
	{
		size_t iOffset = (i == 0) ? 0 : (numRows - i - 1) * 2;
		size_t t = i;
		while (t < s.size())
		{
			ans.push_back(s[t]);
			if (iOffset != 0 && t + iOffset < s.size())
			{
				ans.push_back(s[t + iOffset]);
			}
			t += iStep;
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

	auto f_time_begin = [&time, &nFreq, &nBeginTime, &nEndTime]()
	{
		cout << endl << "/////////////////////////////" << endl;
		QueryPerformanceCounter(&nBeginTime);
	};

	auto f_time_end = [&time, &nFreq, &nBeginTime, &nEndTime]()
	{
		QueryPerformanceCounter(&nEndTime);
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << endl;
	};

	//////////////////////////////////////////////////////////////////////////
	vector<string> TESTS;
	vector<int> K;
	vector<string> ANSWERS;

	TESTS.push_back("LEETCODEISHIRING");
	K.push_back(3);
	ANSWERS.push_back("LCIRETOESIIGEDHN");

	TESTS.push_back("LEETCODEISHIRING");
	K.push_back(4);
	ANSWERS.push_back("LDREOEIIECIHNTSG");


	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		auto ans = convert(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		f_time_end();
	}
}