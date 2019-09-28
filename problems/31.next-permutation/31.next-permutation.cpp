// 31.next-permutation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


//////////////////////////////////////////////////////////////////////////
//void nextPermutation(vector<int>& nums)
//{
//	vector<int> ans = nums;
//	if (next_permutation(nums.begin(), nums.end()))
//	{
//		for (int i = 0; i < nums.size(); i++)
//		{
//			if (ans[i] > nums[i])
//			{
//				sort(ans.begin(), ans.end());
//			}
//		}
//	}
//}

//////////////////////////////////////////////////////////////////////////
//void nextPermutation(vector<int>& nums) {
//	if (nums.size() > 1) {
//		int i;
//		for (i = nums.size() - 1; i > 0 && nums[i - 1] >= nums[i]; i--);
//
//		reverse(nums.begin() + i, nums.end());
//		if (i-- != 0) {
//			auto it = upper_bound(nums.begin() + i, nums.end(), nums[i]);
//			swap(nums[i], *it);
//		}
//	}
//}

//////////////////////////////////////////////////////////////////////////
void nextPermutation(vector<int>& nums)
{
	if (nums.empty()) return;

	vector<int> vec;
	bool bEndFlag = true;
	for (size_t i = nums.size() - 1; i > 0;)
	{
		i--;
		vec.push_back(nums[i + 1]);
		if (nums[i] < nums[i + 1])
		{
			bEndFlag = false;
			sort(vec.begin(), vec.end());
			auto it = upper_bound(vec.begin(), vec.end(), nums[i]);
			swap(nums[i], *it);
			for (size_t j = 0; j < vec.size(); j++)
			{
				nums[j + i + 1] = vec[j];
			}
			break;
		}
	}

	if (bEndFlag)
	{
		sort(nums.begin(), nums.end());
	}
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
	vector<vector<int>> ANSWERS;

	TESTS.push_back({ 3,2,1 });
	ANSWERS.push_back({ 1,2,3 });

	TESTS.push_back({ 1,2,3 });
	ANSWERS.push_back({ 1,3,2 });

	TESTS.push_back({ 1,1,5 });
	ANSWERS.push_back({ 1,5,1 });

	TESTS.push_back({ 1,5,1 });
	ANSWERS.push_back({ 5,1,1 });

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		nextPermutation(TESTS[i]);
		cout << checkAnswer<vector<int>>(TESTS[i], ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}