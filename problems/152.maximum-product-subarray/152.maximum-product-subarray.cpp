// 152.maximum-product-subarray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int maxProduct(vector<int>& nums)
{
	int ans = INT_MIN;
	int maxTmp = 1;
	int minTmp = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] < 0)
		{
			swap(maxTmp, minTmp);
		}
		maxTmp = max(nums[i], maxTmp * nums[i]);
		minTmp = min(nums[i], minTmp * nums[i]);
		ans = max(ans, maxTmp);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
//int ans(vector<int>& nums) {
//	int res = nums[0], n = nums.size();
//	vector<int> f(n, 0), g(n, 0);
//	f[0] = nums[0];
//	g[0] = nums[0];
//	for (int i = 1; i < n; ++i)
//	{
//		f[i] = max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
//		g[i] = min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
//		res = max(res, f[i]);
//	}
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
//int ans(vector<int>& nums)
//{
//	if (nums.empty()) return 0;
//
//	int ans = INT_MIN;
//	int product_all = 1;
//	int product_left = 1;
//	int product_right = 0;
//	size_t start = 0;
//	bool bLeft = true;
//
//	auto f = [&](size_t i)
//	{
//		if (start == i && i == nums.size()) return;
//		if (start == i) product_all *= nums[i];
//		else if (start != i - 1)
//		{
//			product_all = (product_all < 0) ? max(product_all / product_left, product_all / product_right) : product_all;
//		}
//		ans = max(ans, product_all);
//
//		product_all = 1;
//		product_left = 1;
//		product_right = 0;
//		start = i + 1;
//		bLeft = true;
//	};
//
//	for (size_t i = 0; i < nums.size(); i++)
//	{
//		if (nums[i] == 0)
//		{
//			f(i);
//			ans = max(ans, 0);
//			continue;
//		}
//		if (nums[i] < 0)
//		{
//			product_left = bLeft ? product_left * nums[i] : product_left;
//			bLeft = false;
//			product_right = 1;
//		}
//
//		product_all *= nums[i];
//		product_left = bLeft ? product_left * nums[i] : product_left;
//		product_right *= nums[i];
//	}
//	f(nums.size());
//	return ans;
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
	vector<vector<int>> TESTS;
	//vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ 2,3,-2,4 });
	ANSWERS.push_back(6);

	TESTS.push_back({ -2,0,-1 });
	ANSWERS.push_back(0);

	TESTS.push_back({ -2 });
	ANSWERS.push_back(-2);

	TESTS.push_back({ 0 });
	ANSWERS.push_back(0);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = maxProduct(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}