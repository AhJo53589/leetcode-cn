// 42.trapping-rain-water.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int trap(vector<int>& height)
{
	if (height.empty()) return 0;

	int ans = 0;
	int left = -1;
	int cut = 0;
	for (int i = 0; i < height.size(); i++)
	{
		if (left == -1)
		{
			left = (height[i] != 0) ? i : left;
			continue;
		}

		if (height[i] < height[left])
		{
			cut += height[i];
		}
		else
		{
			ans += (i - left - 1) * min(height[left], height[i]) - cut;
			left = i;
			cut = 0;
		}
	}
	if (left == -1) return ans;

	cut = 0;
	int right = height.size();
	for (int i = height.size() - 1; i >= left; i--)
	{
		if (right == height.size())
		{
			right = (height[i] != 0) ? i : right;
			continue;
		}

		if (height[i] < height[right])
		{
			cut += height[i];
		}
		else
		{
			ans += (right - i - 1) * min(height[right], height[i]) - cut;
			right = i;
			cut = 0;
		}
	}
	return ans;
}
//////////////////////////////////////////////////////////////////////////
//int trap(vector<int>& height, int &first, int last)
//{
//	int ans = 0;
//	int cut = 0;
//
//	for (int i = 0; i < last; i++)
//	{
//		if (first == -1)
//		{
//			first = (height[i] != 0) ? i : first;
//			continue;
//		}
//
//		if (height[i] < height[first])
//		{
//			cut += height[i];
//		}
//		else
//		{
//			ans += (i - first - 1) * min(height[first], height[i]) - cut;
//			first = i;
//			cut = 0;
//		}
//	}
//
//	return ans;
//}
//
//int trap(vector<int>& height)
//{
//	if (height.empty()) return 0;
//
//	int ans = 0;
//	int first = -1;
//	int last = height.size();
//	ans = trap(height, first, last);
//	if (first == -1) return ans;
//
//	reverse(height.begin(), height.end());
//	last = height.size() - first;
//	first = -1;
//	ans += trap(height, first, last);
//
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

	TESTS.push_back({ 0,1,0,2,1,0,1,3,2,1,2,1 });
	ANSWERS.push_back(6);

	TESTS.push_back({ 0 });
	ANSWERS.push_back(0);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = trap(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}
