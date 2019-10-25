// 5232.replace-the-substring-for-balanced-string.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int balancedString(string s) 
{
	int ans = s.size();
	int n = s.size() / 4;
	unordered_map<char, int> um_count;
	unordered_map<char, int> um_replace;
	auto f_check = [&um_count, &um_replace, n]()
	{
		return (um_count['Q'] - um_replace['Q'] <= n
			&& um_count['W'] - um_replace['W'] <= n
			&& um_count['E'] - um_replace['E'] <= n
			&& um_count['R'] - um_replace['R'] <= n);
	};

	for (auto c : s)
	{
		um_count[c]++;
	}

	int i = 0, j = 0;
	while (i < s.size())
	{
		while (j < s.size() && !f_check())
		{
			um_replace[s[j++]]++;
		}
		if (f_check())
		{
			ans = min(ans, j - i);
		}
		um_replace[s[i++]]--;
	}
	return ans;
}

#define TEST_FUNC balancedString
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
