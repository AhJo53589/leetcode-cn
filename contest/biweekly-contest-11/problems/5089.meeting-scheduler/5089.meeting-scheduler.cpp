// 5089.meeting-scheduler.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <functional>

#include <algorithm>
#include <numeric>
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
vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) 
{
	sort(slots1.begin(), slots1.end());
	sort(slots2.begin(), slots2.end());

	size_t i = 0, j = 0;
	while (i < slots1.size() && j < slots2.size())
	{
		int start = max(slots1[i][0], slots2[j][0]);
		int end = min(slots1[i][1], slots2[j][1]);
		if (end - start >= duration)
		{
			return { start, start + duration };
		}
		if (slots1[i][1] < slots2[j][1])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	return {};
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
	vector<vector<vector<int>>> TESTS;
	vector<vector<vector<int>>> K;
	vector<int> D;
	vector<vector<int>> ANSWERS;

	TESTS.push_back(StringToVectorVectorInt("[[10,50],[60,120],[140,210]]"));
	K.push_back(StringToVectorVectorInt("[[0,15],[60,70]]"));
	D.push_back(8);
	ANSWERS.push_back(StringToVectorInt("[60,68]"));

	TESTS.push_back(StringToVectorVectorInt("[[10,50],[60,120],[140,210]]"));
	K.push_back(StringToVectorVectorInt("[[0,15],[60,70]]"));
	D.push_back(12);
	ANSWERS.push_back(StringToVectorInt("[]"));

	TESTS.push_back(StringToVectorVectorInt("[[216397070, 363167701],[98730764,158208909],[441003187,466254040], [558239978, 678368334], [683942980, 717766451]]"));
	K.push_back(StringToVectorVectorInt("[[50490609, 222653186], [512711631, 670791418], [730229023, 802410205], [812553104, 891266775], [230032010, 399152578]]"));
	D.push_back(456085);
	ANSWERS.push_back(StringToVectorInt("[98730764,99186849]"));

	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		auto ans = minAvailableDuration(TESTS[i], K[i], D[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		f_time_end();
	}
}