// 5231.remove-sub-folders-from-the-filesystem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
void check(unordered_set<string> &us, string &s)
{
	string t = "/";
	size_t i = 1;
	while (i < s.size())
	{
		i = s.find('/', i);
		i = (i == s.npos) ? s.size() : i;
		if (us.count(s.substr(0, i)) != 0) return;
		i++;
	}
	us.insert(s);
}

vector<string> removeSubfolders(vector<string>& folder)
{
	sort(folder.begin(), folder.end(), [](string &a, string&b)
	{
		return a.size() < b.size();
	});
	unordered_set<string> us;
	for (auto &s : folder)
	{
		check(us, s);
	}

	vector<string> ans(us.begin(), us.end());
	return ans;
}

vector<string> test(vector<string> folder)
{
	return removeSubfolders(folder);
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
