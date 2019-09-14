// 218.the-skyline-problem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//	vector<pair<int, int>> h;
//	vector<vector<int>> res;
//	multiset<int> m;
//	int pre = 0, cur = 0;
//	for (auto &a : buildings) {
//		h.push_back({ a[0], -a[2] });
//		h.push_back({ a[1], a[2] });
//	}
//	sort(h.begin(), h.end());
//	m.insert(0);
//	for (auto &a : h) {
//		if (a.second < 0) m.insert(-a.second);
//		else m.erase(m.find(a.second));
//		cur = *m.rbegin();
//		if (cur != pre) {
//			res.push_back({ a.first, cur });
//			pre = cur;
//		}
//	}
//
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
//vector<vector<int>> ans;
//map<int, int> heights = { {INT_MIN, 0} };//左结点记录至下一个结点区间值。
//
//void update(int i, int j, int h) {
//
//	//安插等效关键结点。即将一个区间插入一个点，变成两个值相等子区间，以方便更新结点数据。
//	heights[i] = (--heights.upper_bound(i))->second;
//	heights[j] = (--heights.upper_bound(j))->second;
//
//	auto pI = heights.find(i), pJ = heights.find(j), pBefor = pI;
//	--pBefor;
//	//更新结点数据,同时处理去重
//	for (auto p = pI; p != pJ;) {
//		int newVal = max(p->second, h);
//		if (newVal == pBefor->second) {
//			p = heights.erase(p);
//		}
//		else {
//			p->second = newVal;
//			++p, ++pBefor;
//		}
//	}
//	if (pJ->second == pBefor->second) heights.erase(pJ);
//}
//
//vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//	for (auto building : buildings) {
//		update(building[0], building[1], building[2]);
//	}
//	for (auto p = ++heights.begin(); p != heights.end(); ++p) {
//		ans.push_back({ p->first, p->second });
//	}
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
{
	const size_t Li = 0;
	const size_t Ri = 1;
	const size_t Hi = 2;
	const size_t x = 0;
	const size_t y = 1;

	vector<vector<int>> ans;
	vector<vector<int>> vec;

	auto f_lower_bound = [&](const vector<int> &b)
	{
		int start = 0;
		int last = vec.size();
		while (start < last)
		{
			int mid = start + (last - start) / 2;
			if (vec[mid][Hi] < b[Hi])
			{
				start = mid + 1;
			}
			else
			{
				last = mid;
			}
		}
		return last;
	};

	auto f_insert = [&](const vector<int> &b)
	{
		if (vec.empty() || b[Hi] > vec.back()[Hi])
		{
			vec.push_back(b);
			return;
		}

		auto it = vec.begin() + f_lower_bound(b);

		if (b[Ri] <= (*it)[Ri]) return;
		if (b[Hi] == (*it)[Hi])
		{
			(*it) = b;
		}
		else
		{
			vec.insert(it, b);
		}
	};

	auto f_pop_back = [&]()
	{
		int _x = vec.back()[Ri];
		while (!vec.empty() && vec.back()[Ri] <= _x)
		{
			vec.pop_back();
		}
		int _y = vec.empty() ? 0 : vec.back()[Hi];
		ans.push_back({ _x, _y });
	};

	for (auto &b : buildings)
	{
		while (!vec.empty() && b[Li] > vec.back()[Ri])
		{
			f_pop_back();
		}

		if (vec.empty())
		{
			ans.push_back({ b[Li], b[Hi] });
		}
		else if (b[Hi] > vec.back()[Hi])
		{
			if (b[Li] == ans.back()[x])
			{
				ans.back()[y] = b[Hi];
			}
			else
			{
				ans.push_back({ b[Li], b[Hi] });
			}
		}

		f_insert(b);
	}

	while (!vec.empty())
	{
		f_pop_back();
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
	vector<vector<vector<int>>> TESTS;
	//vector<int> K;
	vector<vector<vector<int>>> ANSWERS;

	TESTS.push_back({ {2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8} });
	ANSWERS.push_back({ {2,10}, {3,15}, {7,12}, {12,0}, {15,10}, {20,8}, {24,0} });

	TESTS.push_back({ {0,2,3},{2,5,3} });
	ANSWERS.push_back({ {0,3}, {5,0} });

	TESTS.push_back({ {2,9,10},{9,12,15} });
	ANSWERS.push_back({ {2,10}, {9,15}, {12,0} });

	TESTS.push_back({ {2,4,7},{2,4,5},{2,4,6} });
	ANSWERS.push_back({ {2,7}, {4,0} });

	TESTS.push_back(StringToVectorVectorInt("[[2,4,70],[3,8,30],[6,100,41],[7,15,70],[10,30,102],[15,25,76],[60,80,91],[70,90,72],[85,120,59]]"));
	ANSWERS.push_back(StringToVectorVectorInt("[[2,70],[4,30],[6,41],[7,70],[10,102],[30,41],[60,91],[80,72],[90,59],[120,0]]"));

	TESTS.push_back(StringToVectorVectorInt("[[6765,184288,53874],[13769,607194,451649],[43325,568099,982005],[47356,933141,123943],[59810,561434,119381],[75382,594625,738524],[111895,617442,587304],[143767,869128,471633],[195676,285251,107127],[218793,772827,229219],[316837,802148,899966],[329669,790525,416754],[364886,882642,535852],[368825,651379,6209],[382318,992082,300642],[397203,478094,436894],[436174,442141,612149],[502967,704582,918199],[503084,561197,625737],[533311,958802,705998],[565945,674881,149834],[615397,704261,746064],[624917,909316,831007],[788731,924868,633726],[791965,912123,438310]]"));
	ANSWERS.push_back(StringToVectorVectorInt("[[6765,53874],[13769,451649],[43325,982005],[568099,918199],[704582,899966],[802148,831007],[909316,705998],[958802,300642],[992082,0]]"));


	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = getSkyline(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}