// 324.wiggle-sort-ii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//void wiggleSort(vector<int>& nums) {
//	if (2 > nums.size()) {
//		return;
//	}
//
//	int nums_size = nums.size();
//	auto midptr = nums.begin() + nums_size / 2;
//	nth_element(nums.begin(), midptr, nums.end());
//	int mid = *midptr;
//#define A(i) nums[(1+2*(i)) % (nums_size|1)]
//	int i = 0, j = 0, k = nums_size - 1;
//	while (j <= k) {
//		if (A(j) > mid)
//			swap(A(i++), A(j++));
//		else if (A(j) < mid)
//			swap(A(j), A(k--));
//		else
//			j++;
//	}
//}

//////////////////////////////////////////////////////////////////////////
void wiggleSort(vector<int>& nums) {
	/**/
	vector<int> tmp(nums.begin(), nums.end());
	int len = nums.size();
	int k = (len + 1) >> 1;
	int j = len;
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < len; ++i) {
		nums[i] = i & 1 ? tmp[--j] : tmp[--k];
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
	//vector<int> K;
	vector<vector<int>> ANSWERS;

	TESTS.push_back({ 1, 5, 1, 1, 6, 4 });
	ANSWERS.push_back({ 1, 4, 1, 5, 1, 6 });

	TESTS.push_back({ 1, 3, 2, 2, 3, 1 });
	ANSWERS.push_back({ 2, 3, 1, 3, 1, 2 });

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		//auto ans = wiggleSort(TESTS[i]);
		//cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
		wiggleSort(TESTS[i]);
		cout << checkAnswer<vector<int>>(TESTS[i], ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}
