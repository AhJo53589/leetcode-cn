// 2.deep-dark-fraction.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//long long gcd(long long x, long long y)
//{
//	return y ? gcd(y, x%y) : x;
//}
//vector<int> fraction(vector<int>& cont) {
//	long long x, y, n = cont.size(), i;
//	x = cont[n - 1];
//	y = 1;
//	for (i = n - 2; ~i; i--)
//	{
//		swap(x, y);
//		x += cont[i] * y;
//	}
//	i = gcd(x, y);
//	x /= i;
//	y /= i;
//	vector<int> ans;
//	ans.push_back(x);
//	ans.push_back(y);
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

void fraction(vector<int>& cont, size_t last, vector<int>& val)
{
	if (last == cont.size() - 1)
	{
		last--;
		val[0] = cont[last + 1];
		val[1] = cont[last] * cont[last + 1] + 1;
		cout << "val[0] = " << val[0] << ", val[1] = " << val[1] << endl;
	}
	else if (last != 0)
	{
		last--;
		int temp = val[1];
		val[1] = cont[last] * val[1] + val[0];
		val[0] = temp;
		cout << "val[0] = " << val[0] << ", val[1] = " << val[1] << endl;
	}
	int g = gcd(val[0], val[1]);
	val[0] /= g;
	val[1] /= g;
	cout << "val[0] = " << val[0] << ", val[1] = " << val[1] << endl;
	if (last == 0)
	{
		swap(val[0], val[1]);
		return;
	}
	fraction(cont, last, val);
}

vector<int> fraction(vector<int>& cont)
{
	if (cont.size() == 1) return { cont[0], 1 };
	vector<int> val(2, 0);
	fraction(cont, cont.size() - 1, val);
	return val;
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
	vector<vector<int>> ANSWERS;

	TESTS.push_back({ 3,2,0,2 });
	ANSWERS.push_back({ 13,4 });

	TESTS.push_back({ 0,0,3 });
	ANSWERS.push_back({ 3,1 });

	TESTS.push_back({ 3 });
	ANSWERS.push_back({ 3,1 });

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = fraction(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}