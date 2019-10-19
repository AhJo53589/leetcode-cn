// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

#include "..\Common\ParameterType.h"
#include "..\Common\Common.h"
//#include "..\Common\GraphNode.Hi"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.Hi"
using namespace std;

//////////////////////////////////////////////////////////////////////////

int jump(vector<int> nums) 
{
	if (nums.size() < 2) return 0;
	int ans = 0;
	int l = 0;
	int r = 1;
	while (r < nums.size())
	{
		int temp = 0;
		for (int i = l; i < r && i < nums.size(); i++)
		{
			temp = max(temp, i + nums[i]);
		}
		l = r;
		r = temp + 1;
		ans++;
	}
	return ans;
}

#define TEST_FUNC jump
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
