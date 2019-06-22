// 887.SuperEggDrop.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int calcMaximumCoverage(int iTime, int K)
{
	// 有K个蛋，行动iTime次，计算能判断多少层

	if (iTime == 1) return 2;		// 如果只有1次行动了，无论有几个蛋，都只能判断出2层
	if (K == 1) return iTime + 1;	// 如果只有1个蛋了，蛋不能碎，只能一层一层判断，可以判断出iTime + 1层

	// 行动一次，扔个蛋，计算蛋碎了的情况下能判断多少层 + 蛋没碎的情况能判断多少层
	return calcMaximumCoverage(iTime - 1, K - 1) + calcMaximumCoverage(iTime - 1, K);
}

int superEggDrop(int K, int N)	// 8ms
{
	int iTime = 0;
	int iMaxCoverage = 0;
	do
	{
		++iTime;
		iMaxCoverage = calcMaximumCoverage(iTime, K);
	} while (iMaxCoverage < N + 1);
	return iTime;
}

//int superEggDrop(int K, int N)	// 8ms  改了一下也没有提升太多效率，还是上边整洁。。。
//{
//	int iTime = 0;
//	int iMaxCoverage = 0;
//	if (K > 1)
//	{
//		++iTime;
//		iMaxCoverage = calcMaximumCoverage(iTime, K);
//		while (iMaxCoverage < N + 1)
//		{
//			++iTime;
//			iMaxCoverage += calcMaximumCoverage(iTime - 1, K - 1);
//		};
//		return iTime;
//	}
//	else
//	{
//		do 
//		{
//			++iTime;
//			iMaxCoverage = calcMaximumCoverage(iTime, K);
//		} while (iMaxCoverage < N + 1);
//	}
//	return iTime;
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
	std::cout << "k = " << 1 << " n = " << 3 << " count = " << superEggDrop(1, 3) << std::endl;

	for (int k = 2; k < 3; k++)
	{
		for (int n = 1; n < 20; n++)
		{
			std::cout << "k = " << k << " n = " << n << " count = " << superEggDrop(k, n) << std::endl;
		}
	}
}

