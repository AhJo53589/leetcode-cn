// 5090.toss-strange-coins.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//double probabilityOfHeads(vector<double>& prob, int target)
//{
//	int len = prob.size();
//	vector<double> res(target + 1, 0);
//	// 初试，掷出 0 的概率为 1
//	res[0] = 1.0;
//	for (int i = 1; i <= len; i++)
//		// 倒着更新，省一维空间
//		for (int j = min(i, target); j >= 0; j--)
//			// 当前掷出 j 个    当前掷出的为反面 * 上次掷出了 j 个    当前掷出的为正面 * 上次掷出了 j - 1 个
//			res[j] = res[j] * (1 - prob[i - 1]) + (j > 0 ? res[j - 1] * prob[i - 1] : 0);
//
//	return res[target];
//}

//////////////////////////////////////////////////////////////////////////
double probabilityOfHeads(vector<double>& prob, int target)
{
	int N = prob.size();
	vector<vector<double>> dp(N, vector<double>(target + 2));
	dp[0][0] = 1 - prob[0];
	dp[0][1] = prob[0];
	for (int i = 1; i < N; i++) 
	{
		dp[i][0] = dp[i - 1][0] * (1 - prob[i]);
		for (int j = 1; j <= target; j++) 
		{
			dp[i][j] = dp[i - 1][j] * (1 - prob[i]) + dp[i - 1][j - 1] * prob[i];
		}
	}

	return dp[N - 1][target];
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
	vector<vector<double>> TESTS;
	vector<int> K;
	vector<double> ANSWERS;

	TESTS.push_back({ 0.4 });
	K.push_back(1);
	ANSWERS.push_back(0.40000);

	TESTS.push_back({ 0.5,0.5,0.5,0.5,0.5 });
	K.push_back(0);
	ANSWERS.push_back(0.03125);

	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		auto ans = probabilityOfHeads(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		f_time_end();
	}
}