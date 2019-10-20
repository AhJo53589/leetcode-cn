// 5230.check-if-it-is-a-straight-line.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <functional>

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

#include "../Common/ParameterType.h"
#include "../Common/Common.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
bool isLine(vector<int>& a, vector<int>& b, vector<int>& c)
{
	long long t1 = ((long long)a[0] - b[0]) * ((long long)a[1] - c[1]);
	long long t2 = ((long long)a[0] - c[0]) * ((long long)a[1] - b[1]);
	return t1 == t2;
}

bool checkStraightLine(vector<vector<int>>& coordinates) 
{
	vector<vector<int>>& c = coordinates;
	if (c.size() < 3) return true;
	for (size_t i = 0; i < c.size() - 2; i++)
	{
		if (!isLine(c[i], c[i + 1], c[i + 2]))
			return false;
	}
	return true;
}

bool test(vector<vector<int>> coordinates)
{
	return checkStraightLine(coordinates);
}

#define TEST_FUNC test
int main()
{
	PerformanceTimer timer;
	ifstream f("tests.txt");
	TestCases test_cases(f);

	using func_t = function_type<function<decltype(TEST_FUNC)>>;
	while (!test_cases.empty())
	{
		timer.start();

		func_t::return_type ans = func_t::call(TEST_FUNC, test_cases);
		func_t::return_type answer = test_cases.get<func_t::return_type>();
		cout << checkAnswer<decltype(ans)>(ans, answer) << endl;

		timer.stop();
	}
}
