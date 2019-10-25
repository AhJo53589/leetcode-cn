﻿// 5.coin-bonus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
using namespace std;

//////////////////////////////////////////////////////////////////////////
//typedef long long ll;
//const int P = 1000000007;
//int h[50005], ne[50005], l[50005], r[50005], d[50005], N;
//ll t[131072], m[131072];
//void dfs(int x)
//{
//	d[l[x] = ++N] = x;
//	for (int i = h[x]; i; i = ne[i])dfs(i);
//	r[x] = N;
//}
//void fix(int R, int l, int r, int l1, int r1, int d)
//{
//	if (l1 <= l && r <= r1)
//	{
//		t[R] = (t[R] + (ll)(r - l + 1)*d) % P;
//		m[R] += d;
//		if (m[R] >= P)m[R] -= P;
//		return;
//	}
//	int mid = l + r >> 1;
//	if (l1 <= mid)fix(R << 1, l, mid, l1, r1, d);
//	if (r1 > mid)fix(R << 1 | 1, mid + 1, r, l1, r1, d);
//	t[R] = (t[R << 1] + t[R << 1 | 1] + (ll)(r - l + 1)*m[R]) % P;
//}
//int ask(int R, int l, int r, int l1, int r1, int d)
//{
//	if (l1 <= l && r <= r1)return (t[R] + (ll)d*(r - l + 1)) % P;
//	d += m[R];
//	if (d >= P)d -= P;
//	int mid = l + r >> 1, s = 0;
//	if (l1 <= mid)s = ask(R << 1, l, mid, l1, r1, d);
//	if (r1 > mid)s = (s + ask(R << 1 | 1, mid + 1, r, l1, r1, d)) % P;
//	return s;
//}
//vector<int> ans;
//vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
//	ans.clear();
//	for (auto l : leadership)
//	{
//		ne[l[1]] = h[l[0]];
//		h[l[0]] = l[1];
//	}
//	dfs(1);
//	for (auto o : operations)if (o[0] == 1)fix(1, 1, n, l[o[1]], l[o[1]], o[2]);
//	else if (o[0] == 2)fix(1, 1, n, l[o[1]], r[o[1]], o[2]);
//	else ans.push_back(ask(1, 1, n, l[o[1]], r[o[1]], 0));
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
struct Person
{
	Person() : coins(0) {}
	vector<Person *> childs;
	int coins;
};

void addCoins(Person *p, int coins)
{
	if (p == nullptr) return;
	p->coins += coins;

	for (auto pChild : p->childs)
	{
		addCoins(pChild, coins);
	}
}

void getCoins(Person *p, int &val)
{
	if (p == nullptr) return;
	val += p->coins;

	for (auto pChild : p->childs)
	{
		getCoins(pChild, val);
	}
}

vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations)
{
	const int mod = 1000000007;

	unordered_map<int, Person *> _map;
	for (int i = 1; i <= n; i++)
	{
		_map[i] = new Person();
	}
	for (auto &l : leadership)
	{
		_map[l[0]]->childs.push_back(_map[l[1]]);
	}

	vector<int> ans;
	for (auto &op : operations)
	{
		if (op[0] == 1)
		{
			_map[op[1]]->coins += op[2];
		}
		else if (op[0] == 2)
		{
			addCoins(_map[op[1]], op[2]);
		}
		else if (op[0] == 3)
		{
			int val = 0;
			getCoins(_map[op[1]], val);
			val %= mod;
			ans.push_back(val);
		}
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
	vector<vector<vector<int>>> L;
	vector<vector<vector<int>>> O;
	vector<vector<int>> ANSWERS;

	TESTS.push_back(6);
	L.push_back({ {1, 2},{1, 6},{2, 3},{2, 5},{1, 4} });
	O.push_back({ {1, 1, 500},{2, 2, 50},{3, 1},{2, 6, 15},{3, 1} });
	ANSWERS.push_back({ 650, 665 });


	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = bonus(TESTS[i], L[i], O[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}