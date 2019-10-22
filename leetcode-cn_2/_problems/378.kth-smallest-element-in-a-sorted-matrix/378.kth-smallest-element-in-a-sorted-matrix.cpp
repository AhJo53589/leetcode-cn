// 378.kth-smallest-element-in-a-sorted-matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//int lowerbound(vector<int>& row, int val)
//{
//	int low = 0;
//	int high = row.size();
//	while (low < high)
//	{
//		int mid = low + (high - low) / 2;
//		if (row[mid] <= val)
//		{
//			low = mid + 1;
//		}
//		else
//		{
//			high = mid;
//		}
//	}
//	return low;
//}
//
//int kthSmallest(vector<vector<int>>& matrix, int k)
//{
//	size_t m = matrix.size();
//	if (m == 0) return 0;
//
//	int low = matrix[0][0];
//	int high = matrix.back().back();
//
//	while (low < high)
//	{
//		int mid = low + (high - low) / 2;
//		cout << "low = " << low << ", high = " << high << endl;
//		cout << "mid = " << mid << endl;
//
//		int count = 0;
//		for (auto &row : matrix)
//		{
//			count += lowerbound(row, mid);
//			printVectorT(row);
//			cout << "count = " << count << endl;
//			if (count > k) break;
//		}
//		cout << endl;
//		if (count < k)
//		{
//			low = mid + 1;
//		}
//		else
//		{
//			high = mid;
//		}
//	}
//	return low;
//}


//////////////////////////////////////////////////////////////////////////
int lowerbound(vector<int>& row, int val)
{
	int low = 0;
	int high = row.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (row[mid] <= val)
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	return low;
}

int kthSmallest(vector<vector<int>>& matrix, int k)
{
	size_t m = matrix.size();
	if (m == 0) return 0;

	int low = matrix[0][0];
	int high = matrix.back().back();

	while (low < high)
	{
		int mid = low + (high - low) / 2;
		int count = 0;
		for (auto &row : matrix)
		{
			count += lowerbound(row, mid);
			if (count > k) break;
		}
		if (count < k)
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	return low;
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
	vector<vector<vector<int>>> TESTS;
	vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ {1,5,9},{10,11,13},{12,13,15} });
	K.push_back(8);
	ANSWERS.push_back(13);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		printVectorVectorT(TESTS[i]);
		auto ans = kthSmallest(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
		//kthSmallest(TESTS[i], K[i]);
		//cout << checkAnswer<vector<vector<int>>>(TESTS[i], ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}
