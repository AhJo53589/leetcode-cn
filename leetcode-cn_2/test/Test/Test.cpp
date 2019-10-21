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

#include "..\Common\Define_IdName.h"
#include "..\Common\ParameterType.h"
#include "..\Common\Common.h"
//#include "..\Common\GraphNode.Hi"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.Hi"
using namespace std;

#define SOLUTION_CPP	SOLUTION_CPP_ID_1
#define TESTS_TXT		TESTS_TXT_ID_1
#define TEST_FUNC		solution

#include SOLUTION_CPP

//////////////////////////////////////////////////////////////////////////



int main()
{
	PerformanceTimer timer;
	ifstream f(TESTS_TXT);
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
