// 334.increasing-triplet-subsequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
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
//bool increasingTriplet(vector<int>& nums) 
//{
//	int a = INT_MAX;
//	int b = INT_MAX;
//
//	for (auto e : nums) 
//	{
//		if (e <= a) a = e;
//		else if (e <= b) b = e;
//		else return true;
//	}
//	return false;
//}

//////////////////////////////////////////////////////////////////////////
bool increasingTriplet(vector<int>& nums)
{
	if (nums.size() < 3) return false;
	int l = 0;
	int l2 = 0;
	int m = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (m == l)
		{
			if (nums[l] < nums[i]) m = i;
			else
			{
				l = i;
				l2 = i;
				m = i;
			}
		}
		else
		{
			if (nums[m] < nums[i]) return true;
			if (nums[i] < nums[l2]) l2 = i;
			else if (nums[l2] < nums[i] && nums[i] < nums[m])
			{
				l = l2;
				m = i;
			}
		}
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
// 调试版
bool increasingTriplet_test(vector<int>& nums)
{
	int l = 0;
	int l2 = 0;
	int m = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (m == l)
		{
			if (nums[l] < nums[i])
			{
				m = i;
				cout << "i = " << i << " | ";
				cout << "m = " << nums[i] << endl;
			}
			else
			{
				l = i;
				l2 = i;
				m = i;
				cout << "i = " << i << " | ";
				cout << "l = " << nums[i] << ", ";
				cout << "l2 = " << nums[i] << ", ";
				cout << "m = " << nums[i] << endl;
			}
		}
		else
		{
			if (nums[m] < nums[i])
			{
				cout << "i = " << i << " | ";
				cout << "Find = " << nums[l] << "," << nums[m] << "," << nums[i] << endl;
				return true;
			}
			if (nums[i] < nums[l2])
			{
				l2 = i;
				cout << "i = " << i << " | ";
				cout << "l2 = " << nums[i] << endl;
			}
			else if (nums[l2] < nums[i] && nums[i] < nums[m])
			{
				l = l2;
				m = i;
				cout << "i = " << i << " | (l = l2) ";
				cout << "l = " << nums[l2] << ", ";
				cout << "m = " << nums[i] << endl;
			}
		}
	}
	return false;
}


int main()
{
	vector<vector<int>> TESTS;
	//vector<int> K;
	vector<bool> ANSWERS;

	TESTS.push_back(StringToVectorInt("[1,2,3,4,5]"));
	ANSWERS.push_back(true);

	TESTS.push_back(StringToVectorInt("[5,4,3,2,1]"));
	ANSWERS.push_back(false);

	TESTS.push_back(StringToVectorInt("[9,7,8,5,6,3,4,1,2]"));
	ANSWERS.push_back(false);

	TESTS.push_back(StringToVectorInt("[9,7,8,5,6,1,4,2,3]"));
	ANSWERS.push_back(true);

	TESTS.push_back(StringToVectorInt("[3,9,8,5,2,1,2,3,4]"));
	ANSWERS.push_back(true);

	TESTS.push_back(StringToVectorInt("[5,1,5,5,2,5,4]"));
	ANSWERS.push_back(true);

	TESTS.push_back(StringToVectorInt("[1,1,-2,6]"));
	ANSWERS.push_back(false);

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		//auto ans = setZeroes(TESTS[i]);
		printVectorT(TESTS[i]);
		bool ans = increasingTriplet(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}
