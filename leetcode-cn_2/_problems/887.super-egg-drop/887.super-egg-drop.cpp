// 887.super-egg-drop.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

int calcMaximumCoverage(int iTime, int K)
{
	// 有K个蛋，行动ans次，计算能判断多少层

	if (iTime == 1) return 2;		// 如果只有1次行动了，无论有几个蛋，都只能判断出2层
	if (K == 1) return iTime + 1;	// 如果只有1个蛋了，蛋不能碎，只能一层一层判断，可以判断出ans + 1层

	// 行动一次，扔个蛋，计算蛋碎了的情况下能判断多少层 + 蛋没碎的情况能判断多少层
	return calcMaximumCoverage(iTime - 1, K - 1) + calcMaximumCoverage(iTime - 1, K);
}

int superEggDrop(int K, int N)	// 8ms
{
	int ans = 1;
	while (calcMaximumCoverage(ans, K) < N + 1)
	{
		++ans;
	}
	return ans;
}


//int superEggDrop(int K, int N)	// 8ms  改了一下也没有提升太多效率，还是上边整洁。。。
//{
//	int ans = 0;
//	int iMaxCoverage = 0;
//	if (K > 1)
//	{
//		++ans;
//		iMaxCoverage = calcMaximumCoverage(ans, K);
//		while (iMaxCoverage < N + 1)
//		{
//			++ans;
//			iMaxCoverage += calcMaximumCoverage(ans - 1, K - 1);
//		};
//		return ans;
//	}
//	else
//	{
//		do 
//		{
//			++ans;
//			iMaxCoverage = calcMaximumCoverage(ans, K);
//		} while (iMaxCoverage < N + 1);
//	}
//	return ans;
//}

//int superEggDrop(int K, int N)	// 4ms
//{
//	int dp[K + 1];
//	fill(dp, dp + K + 1, 0);
//	int m = 0;
//	while (dp[K] < N) {
//		for (int i = K; i >= 1; i--)
//			dp[i] = dp[i] + dp[i - 1] + 1;
//		m++;
//	}
//	return m;
//}

//typedef vector<vector<int>> MI;
//typedef vector<int> VI;
//int superEggDrop(int K, int N)	// 8ms
//{
//	if (K == 0 || N == 0) {
//		return 0;
//	}
//
//	if (N == 1) {
//		return 1;
//	}
//
//	if (K == 1) {
//		return N;
//	}
//	MI mi;
//	VI vi;
//	for (int j = 0; j < K + 1; ++j) {
//		vi.push_back(0);
//	}
//	mi.push_back(vi);
//	for (int x = 1; x < N + 1; ++x) {
//		VI vi;
//		vi.push_back(0);
//		vi.push_back(x);
//
//		int n = 0;
//		for (int k = 2; k < K + 1; ++k) {
//			VI& tmp = mi[x - 1];
//			n = tmp[k - 1] + tmp[k] + 1;
//			vi.push_back(n);
//		}
//
//		if (n >= N) {
//			return x;
//		}
//
//		mi.push_back(vi);
//	}
//
//	return N;
//}


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
	vector<int> TESTS;
	vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back(1);
	K.push_back(2);
	ANSWERS.push_back(2);

	TESTS.push_back(2);
	K.push_back(6);
	ANSWERS.push_back(3);

	TESTS.push_back(3);
	K.push_back(14);
	ANSWERS.push_back(4);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = superEggDrop(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
		//kthSmallest(TESTS[i], K[i]);
		//cout << checkAnswer<vector<vector<int>>>(TESTS[i], ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}
