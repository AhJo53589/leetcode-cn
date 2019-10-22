// 60.permutation-sequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//void getPermutation(vector<int> &nums)
//{
//	if (nums.empty()) return;
//
//	vector<int> vec;
//	for (size_t i = nums.size() - 1; i > 0;)
//	{
//		i--;
//		vec.push_back(nums[i + 1]);
//		if (nums[i] < nums[i + 1])
//		{
//			sort(vec.begin(), vec.end());
//			auto it = lower_bound(vec.begin(), vec.end(), nums[i]);
//			swap(nums[i], *it);
//			for (size_t j = 0; j < vec.size(); j++)
//			{
//				nums[j + i + 1] = vec[j];
//			}
//			break;
//		}
//	}
//}
//
//string getPermutation(int n, int k)
//{
//	vector<int> nums;
//	for (int i = 0; i < n; i++)
//	{
//		nums.push_back(i + 1);
//	}
//	while (--k > 0)
//	{
//		getPermutation(nums);
//	}
//	string ans;
//	for (auto &n : nums)
//	{
//		ans += to_string(n);
//	}
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
int factorial(unordered_map<int, int> &fac, int k)
{
	if (k < 2) return 1;
	if (fac.count(k)) return fac[k];
	int f = k * factorial(fac, k - 1);
	fac[k] = f;
	return f;
}

void getPermutation(vector<int> &nums, int len, unordered_map<int, int> &fac, int k)
{
	if (k == 0 || len == 0) return;

	int f = factorial(fac, len - 1);
	if (k < f)
	{
		getPermutation(nums, len - 1, fac, k);
	}
	else
	{
		int i = nums.size() - len;
		int j = k / f;
		k -= j * f;

		for (j = min(i + j, (int)nums.size() - 1); j > i; j--)
		{
			swap(nums[j], nums[j - 1]);
		}
		getPermutation(nums, len - 1, fac, k);
	}
}

string getPermutation(int n, int k)
{
	vector<int> nums;
	for (int i = 0; i < n; i++)
	{
		nums.push_back(i + 1);
	}

	unordered_map<int, int> fac;
	getPermutation(nums, nums.size(), fac, k - 1);

	string ans;
	for (auto &n : nums)
	{
		ans += to_string(n);
	}
	return ans;
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
	vector<int> TESTS;
	vector<int> K;
	vector<string> ANSWERS;

	//for (int i = 1; i < 9; i++)
	//{
	//	TESTS.push_back(3);
	//	K.push_back(i);
	//	ANSWERS.push_back(to_string(i));
	//}

	//for (int i = 1; i < 25; i++)
	//{
	//	TESTS.push_back(4);
	//	K.push_back(i);
	//	ANSWERS.push_back(to_string(i));
	//}

	TESTS.push_back(3);
	K.push_back(3);
	ANSWERS.push_back("213");

	TESTS.push_back(4);
	K.push_back(9);
	ANSWERS.push_back("2314");

	TESTS.push_back(8);
	K.push_back(15198);
	ANSWERS.push_back("41273865");

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = getPermutation(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}
