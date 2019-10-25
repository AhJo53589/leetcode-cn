// 447.number-of-boomerangs.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int dis(vector<int>&p1, vector<int>&p2)
{
	return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
}
int numberOfBoomerangs(vector<vector<int>>& points) {
	int count = 0;
	int n = points.size();
	//int data[n][n] = { 0 };
	vector<vector<int>> data(n, vector<int>());
	for (int i = 0; i < n; i++) data[i].resize(n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			data[i][j] = dis(points[i], points[j]);
			data[j][i] = data[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		sort(data[i].begin(), data[i].end());
		for (int j = 0; j < n - 1; j++)
		{
			if (data[i][j] == data[i][j + 1]) cnt++;
			else
			{
				count += cnt * (cnt - 1);
				cnt = 1;
			}
		}
		count += cnt * (cnt - 1);
	}
	return count;
}

//////////////////////////////////////////////////////////////////////////
//int numberOfBoomerangs(vector<vector<int>>& points)
//{
//	int res = 0;
//	if (points.empty()) return res;
//	for (int i = 0; i < points.size(); i++)
//	{
//		unordered_map<double, int> _map;
//		for (int j = 0; j < points.size(); j++)
//		{
//			if (i == j) continue;
//			double dis = pow(((double)points[i][0] - (double)points[j][0]), 2) + pow(((double)points[i][1] - (double)points[j][1]), 2);
//			//if (_map.count(dis))	// 可以用排列组合公式
//			//{
//			//	res += _map[dis] * 2;
//			//}
//			_map[dis]++;
//		}
//		for (auto p : _map) res += p.second * (p.second - 1);	//计算排列组合公式 n * (n - 1)
//	}
//	return res;
//}


int main()
{
	vector<vector<vector<int>>> TESTS;
	//vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ { 0, 0 }, { 1, 0 }, { 2, 0 } });
	ANSWERS.push_back(2);

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = numberOfBoomerangs(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}