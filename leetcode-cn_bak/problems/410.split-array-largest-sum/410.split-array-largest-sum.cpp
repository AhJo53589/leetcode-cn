// 410.split-array-largest-sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
// 动态规划 228ms
//int splitArray(vector<int>& nums, int m) {
//	int n = nums.size();
//	vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX));
//	vector<double> sub(n + 1, 0);
//	for (int i = 0; i < n; i++) {
//		sub[i + 1] = sub[i] + (double)nums[i];
//	}
//	f[0][0] = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			for (int k = 0; k < i; k++) {
//				f[i][j] = min(f[i][j], max(f[k][j - 1], (int)(sub[i] - sub[k])));
//			}
//		}
//	}
//	return f[n][m];
//}

//////////////////////////////////////////////////////////////////////////
// 二分查找 4ms
//bool canSplit(vector<int>& nums, int m, int split_sum) 
//{
//	long long sum = 0;
//	int cnt = 1;
//	for (auto &n : nums) 
//	{
//		sum += n;
//		if (sum <= split_sum) continue;
//
//		sum = n;
//		++cnt;
//		if (cnt > m) return false;
//	}
//	return true;
//}
//
//int splitArray(vector<int>& nums, int m) 
//{
//	long long l = 0;
//	long long r = 0;
//	for (auto &n : nums) 
//	{
//		r += n;
//		l = max(l, (long long)n);
//	}
//
//	while (l < r)
//	{
//		int mid = l + (r - l) / 2;
//		if (canSplit(nums, m, mid)) r = mid;
//		else l = mid + 1;
//	}
//	return r;
//}

//////////////////////////////////////////////////////////////////////////
// 4ms
int splitArray(vector<int>& nums, int m, int split_sum)
{
	long long sum = 0;
	long long nextsum = 0;
	int cnt = 1;
	for (int &n : nums) 
	{
		sum += n;
		if (sum <= split_sum) continue;

		nextsum = (nextsum == 0) ? sum : min(nextsum, sum);
		sum = n;
		++cnt;
		if (cnt > m) return splitArray(nums, m, nextsum);
	}
	return split_sum;
}

int splitArray(vector<int>& nums, int m)
{
	int num_max = 0;
	long long sum = 0;
	for (auto &n : nums)
	{
		num_max = max(num_max, n);
		sum += n;
	}
	return splitArray(nums, m, max((int)(sum / m), num_max));
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

	vector<vector<int>> TESTS;
	vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ 7,2,5,10,8 });
	K.push_back(2);
	ANSWERS.push_back(18);

	TESTS.push_back({ 1,1,1,1,1 });
	K.push_back(2);
	ANSWERS.push_back(3);

	TESTS.push_back({ 1,1,1,1,1,1,1 });
	K.push_back(3);
	ANSWERS.push_back(3);

	TESTS.push_back({ 1,2147483647 });
	K.push_back(2);
	ANSWERS.push_back(2147483647);

	TESTS.push_back({ 2,3,1,1,1,1,1 });
	K.push_back(5);
	ANSWERS.push_back(3);

	TESTS.push_back({ 10,5,13,4,8,4,5,11,14,9,16,10,20,8 });
	K.push_back(8);
	ANSWERS.push_back(25);

	TESTS.push_back({ 5334,6299,4199,9663,8945,3566,9509,3124,6026,6250,7475,5420,9201,9501,38,5897,4411,6638,9845,161,9563,8854,3731,5564,5331,4294,3275,1972,1521,2377,3701,6462,6778,187,9778,758,550,7510,6225,8691,3666,4622,9722,8011,7247,575,5431,4777,4032,8682,5888,8047,3562,9462,6501,7855,505,4675,6973,493,1374,3227,1244,7364,2298,3244,8627,5102,6375,8653,1820,3857,7195,7830,4461,7821,5037,2918,4279,2791,1500,9858,6915,5156,970,1471,5296,1688,578,7266,4182,1430,4985,5730,7941,3880,607,8776,1348,2974,1094,6733,5177,4975,5421,8190,8255,9112,8651,2797,335,8677,3754,893,1818,8479,5875,1695,8295,7993,7037,8546,7906,4102,7279,1407,2462,4425,2148,2925,3903,5447,5893,3534,3663,8307,8679,8474,1202,3474,2961,1149,7451,4279,7875,5692,6186,8109,7763,7798,2250,2969,7974,9781,7741,4914,5446,1861,8914,2544,5683,8952,6745,4870,1848,7887,6448,7873,128,3281,794,1965,7036,8094,1211,9450,6981,4244,2418,8610,8681,2402,2904,7712,3252,5029,3004,5526,6965,8866,2764,600,631,9075,2631,3411,2737,2328,652,494,6556,9391,4517,8934,8892,4561,9331,1386,4636,9627,5435,9272,110,413,9706,5470,5008,1706,7045,9648,7505,6968,7509,3120,7869,6776,6434,7994,5441,288,492,1617,3274,7019,5575,6664,6056,7069,1996,9581,3103,9266,2554,7471,4251,4320,4749,649,2617,3018,4332,415,2243,1924,69,5902,3602,2925,6542,345,4657,9034,8977,6799,8397,1187,3678,4921,6518,851,6941,6920,259,4503,2637,7438,3893,5042,8552,6661,5043,9555,9095,4123,142,1446,8047,6234,1199,8848,5656,1910,3430,2843,8043,9156,7838,2332,9634,2410,2958,3431,4270,1420,4227,7712,6648,1607,1575,3741,1493,7770,3018,5398,6215,8601,6244,7551,2587,2254,3607,1147,5184,9173,8680,8610,1597,1763,7914,3441,7006,1318,7044,7267,8206,9684,4814,9748,4497,2239 });
	K.push_back(9);
	ANSWERS.push_back(194890);


	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = splitArray(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}