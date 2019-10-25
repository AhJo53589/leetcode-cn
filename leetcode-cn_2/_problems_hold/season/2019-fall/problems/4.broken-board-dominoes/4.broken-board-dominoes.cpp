// 4.broken-board-dominoes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//int domino(int n, int m, vector<vector<int>>& broken) {
//	int a[10], f[10][256], ans = 0, o[256], i, j, k;
//	memset(a, 0, sizeof(a));
//	for (auto b : broken)a[b[0]] |= 1 << b[1];
//	memset(f, 128, sizeof(f));
//	f[0][(1 << m) - 1] = 0;
//	for (i = 1; i < 1 << m; i++)o[i] = o[i >> 1] + (i & 1);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < 1 << m; j++)f[i + 1][0] = max(f[i + 1][0], f[i][j]);
//		if (i)for (j = 0; j < 1 << m; j++)for (k = 0; k < 1 << m; k++)if (!(j&k) && !(a[i - 1] & k) && !(a[i] & k))f[i + 1][k] = max(f[i + 1][k], f[i][j] + o[k]);
//		for (j = 0; j + 1 < m; j++)if (!(a[i] >> j & 1) && !(a[i] >> j + 1 & 1))for (k = 0; k < 1 << m; k++)if (!(k >> j & 1) && !(k >> j + 1 & 1))f[i + 1][k | 1 << j | 1 << j + 1] = max(f[i + 1][k | 1 << j | 1 << j + 1], f[i + 1][k] + 1);
//	}
//	for (i = 0; i < 1 << m; i++)ans = max(ans, f[n][i]);
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
int domino(int n, int m, vector<vector<int>>& broken) 
{
	return 0;
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
	vector<int> N;
	vector<int> M;
	vector<int> ANSWERS;

	TESTS.push_back({ {1,0}, {1,1} });
	N.push_back(2);
	M.push_back(3);
	ANSWERS.push_back(2);

	TESTS.push_back({ });
	N.push_back(3);
	M.push_back(3);
	ANSWERS.push_back(4);


	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = domino(N[i], M[i], TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}