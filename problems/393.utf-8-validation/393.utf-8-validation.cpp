// 393.utf-8-validation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
bool validUtf8(vector<int>& data, size_t start)
{
	if (start == data.size()) return true;
	bitset<8> n = data[start];
	if (n[7] == 0) return validUtf8(data, start + 1);

	size_t len = 0;
	int i = 8;
	while (--i >= 0)
	{
		if (n[i] == 0) break;
		if (n[i] == 1)
		{
			len++;
		}
	}
	if (len < 2 || len > 4) return false;

	for (size_t j = 1; j < len; j++)
	{
		if (start + j >= data.size()) return false;
		n = data[start + j];
		if (n[7] != 1 || n[6] != 0) return false;
	}
	return validUtf8(data, start + len);
}

bool validUtf8(vector<int>& data)
{
	return validUtf8(data, 0);
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
	vector<bool> ANSWERS;

	TESTS.push_back({ 197, 130, 1 });
	ANSWERS.push_back(true);

	TESTS.push_back({ 235, 140, 4 });
	ANSWERS.push_back(false);

	TESTS.push_back({ 145 });
	ANSWERS.push_back(false);

	TESTS.push_back({ 248,130,130,130 });
	ANSWERS.push_back(false);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = validUtf8(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}
