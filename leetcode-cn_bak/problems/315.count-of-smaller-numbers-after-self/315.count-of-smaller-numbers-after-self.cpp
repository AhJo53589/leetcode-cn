// 315.count-of-smaller-numbers-after-self.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
vector<int> countSmaller(vector<int>& nums)
{
	if (nums.empty()) return {};
	if (nums.size() == 1) return { 0 };

	vector<int> counts(nums.size(), 0);
	vector<int> sort_nums;

	sort_nums.push_back(nums[nums.size() - 1]);
	size_t i = nums.size() - 2;
	do
	{
		auto it = lower_bound(sort_nums.begin(), sort_nums.end(), nums[i]);
		counts[i] = it - sort_nums.begin();
		sort_nums.insert(it, nums[i]);
	} while (i-- != 0);

	return counts;
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
	//vector<int> K;
	vector<vector<int>> ANSWERS;

	TESTS.push_back({ 5,2,6,1 });
	ANSWERS.push_back({ 2,1,1,0 });

	TESTS.push_back({ 2,0,1 });
	ANSWERS.push_back({ 2,0,0 });

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = countSmaller(TESTS[i]);
		//cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}