// 56.merge-intervals.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//vector<vector<int>> merge(vector<vector<int>>& intervals) {
//	auto f = [](const vector<int> &vec1, const vector<int> &vec2)
//	{
//		return vec1[0] < vec2[0];
//	};
//
//	sort(intervals.begin(), intervals.end(), f);
//
//	int i = 0;
//	for (int j = 0; j < intervals.size(); ++i)
//	{
//		if (i != j)
//		{
//			intervals[i] = intervals[j];
//		}
//
//		++j;
//		for (; j < intervals.size(); ++j)
//		{
//			if (intervals[i][1] >= intervals[j][0])
//			{
//				intervals[i][1] = max(intervals[i][1], intervals[j][1]);
//			}
//			else
//			{
//				break;
//			}
//		}
//
//	}
//
//	intervals.resize(i);
//	return intervals;
//}


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	auto vector_earse = [](vector<vector<int>> &a, int n)
	{
		for (int i = n; i < a.size() - 1; i++) a[i] = a[i + 1];
		if (a.size() > 0 && a.size() > n) a.pop_back();
	};

	vector<vector<int>> ans;
	for (int i = 0; i < intervals.size(); i++)
	{
		auto n = intervals[i];
		ans.push_back(n);
		if (ans.size() == 1) continue;
		int repeat = ans.size() - 1;
		for (int j = ans.size() - 2; j >= 0; j--)
		{
			auto &m = ans[j];
			if (n[0] <= m[1] && n[1] >= m[0])
			{
				m[0] = min(n[0], m[0]);
				m[1] = max(n[1], m[1]);
				vector_earse(ans, repeat);
				repeat = j;
				n = m;
			}
		}
	}

	return ans;
}

int main()
{
	vector<vector<vector<int>>> N;
	vector<vector<vector<int>>> A;

	N.push_back({ { 1,3 }, { 2,6 }, { 8,10 }, { 15,18 } });
	A.push_back({ { 1,6 }, { 8,10 }, { 15,18 } });

	N.push_back({ { 1,4 }, { 4,5 } });
	A.push_back({ { 1,5 } });

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "/////////////////////////////////" << endl;
		printVectorVectorInt(N[i]);
		vector<vector<int>> ans = merge(N[i]);
		cout << "merge = " << endl;
		printVectorVectorInt(A[i]);
		cout << "my answer = " << endl;
		printVectorVectorInt(ans);
	}
}