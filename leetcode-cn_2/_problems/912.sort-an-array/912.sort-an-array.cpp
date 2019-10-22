// 912.sort-an-array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
size_t partition(vector<int>& nums, size_t left, size_t right)
{
	size_t mid = left;
	for (auto i = left; i < right; i++)
	{
		if (nums[i] < nums[right - 1])
		{
			swap(nums[i], nums[mid++]);
		}
	}
	swap(nums[mid], nums[right - 1]);
	return mid;
}

void quickSort(vector<int>& nums, size_t left, size_t right)
{
	if (left >= right) return;
	size_t mid = partition(nums, left, right);
	quickSort(nums, left, mid);
	quickSort(nums, mid + 1, right);
}

vector<int> sortArray(vector<int>& nums)
{
	quickSort(nums, 0, nums.size());
	return nums;
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
	vector<vector<int>> TESTS;
	vector<vector<int>> ANSWERS;

	TESTS.push_back({ 5,2,3,1 });
	ANSWERS.push_back({ 1,2,3,5 });

	TESTS.push_back({ 5,1,1,2,0,0 });
	ANSWERS.push_back({ 0,0,1,1,2,5 });

	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		sortArray(TESTS[i]);
		cout << checkAnswer<vector<int>>(TESTS[i], ANSWERS[i]) << endl;

		f_time_end();
	}
}