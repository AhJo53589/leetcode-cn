// 189.rotate-array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <functional>

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
void rotate(vector<int>& nums, int k)
{
	k = k % nums.size();

	int iLen = nums.size();
	while (k > 0 && iLen > 1 && iLen != k)
	{
		for (int i = iLen - 1; i > k - 1; i--)
		{
			swap(nums[i], nums[i - k]);
		}

		int tmp = k;
		k = k - iLen % k;
		iLen = tmp;
	}
}

//////////////////////////////////////////////////////////////////////////
//void rotate(vector<int>& nums, int k)
//{
//	k = k >= nums.size() ? k - nums.size() : k;
//	if (k)
//	{
//		reverse(nums.begin(), nums.end() - k);
//		reverse(nums.end() - k, nums.end());
//		reverse(nums.begin(), nums.end());
//	}
//}

//////////////////////////////////////////////////////////////////////////
//void rotate(vector<int>& nums, int k)
//{
//	k = nums.size() - k % nums.size();
//	auto it_k = nums.begin() + k;
//	std::rotate(nums.begin(), it_k, nums.end());
//}

//////////////////////////////////////////////////////////////////////////
//void rotate(vector<int>& nums, int k)
//{
//	k = nums.size() - k % nums.size();
//	list<int> lst(nums.begin(), nums.end());
//	auto it_k = lst.begin();
//	while (k--) it_k++;
//	lst.splice(lst.begin(), lst, it_k, lst.end());
//	copy(lst.begin(), lst.end(), nums.begin());
//}

//////////////////////////////////////////////////////////////////////////
//void rotate(vector<int>& nums, int k)
//{
//	k = nums.size() - k % nums.size();
//	vector<int> vct;
//	for (auto i = k; i < nums.size(); i++)
//	{
//		vct.push_back(nums[i]);
//	}
//	for (auto i = 0; i < k; i++)
//	{
//		vct.push_back(nums[i]);
//	}
//	swap(nums, vct);
//}


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
	vector<vector<int>> TESTS;
	vector<int> K;
	vector<vector<int>> ANSWERS;

	TESTS.push_back({ 1,2,3,4,5,6,7 });
	K.push_back(3);
	ANSWERS.push_back({ 5,6,7,1,2,3,4 });

	TESTS.push_back({ 1,2,3,4,5,6,7,8 });
	K.push_back(3);
	ANSWERS.push_back({ 6,7,8,1,2,3,4,5 });

	TESTS.push_back({ 1,2,3,4,5,6,7,8,9 });
	K.push_back(3);
	ANSWERS.push_back({ 7,8,9,1,2,3,4,5,6 });

	TESTS.push_back({ -1,-100,3,99 });
	K.push_back(2);
	ANSWERS.push_back({ 3,99,-1,-100 });


	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		rotate(TESTS[i], K[i]);
		cout << checkAnswer<vector<int>>(TESTS[i], ANSWERS[i]) << endl;

		f_time_end();
	}
}