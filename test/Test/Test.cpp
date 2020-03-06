// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <ctime>  
#include <functional>

#include <algorithm>
#include <numeric>
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
#include "..\Common\Common.h"
#include "..\Common\TestCases.h"
#include "..\Common\ParameterType.h"
#include "..\Common\PerformanceTimer.h"

using namespace std;


//////////////////////////////////////////////////////////////////////////
// 选择题目代码
#define USE_DEFAULT_INCLUDE

#ifdef USE_DEFAULT_INCLUDE

// 1. 选择使用 #题库中的题，根据编号加载，使用 Define_IdName.h 中定义的宏#
// example: 
// SOLUTION_CPP_FOLDER_NAME_ID_1 ==> SOLUTION_CPP_FOLDER_NAME_ID_2
#define SOLUTION_ID						SOLUTION_CPP_FOLDER_NAME_ID_139

#define ADD_QUOTES(A)					#A
#define SOLUTION_CPP_PATH(_name)		ADD_QUOTES(../../problems/##_name/SOLUTION.cpp)
#define SOLUTION_CPP_ID_TO_PATH(_name)	SOLUTION_CPP_PATH(_name)
#define SOLUTION_CPP_FULL_PATH			SOLUTION_CPP_ID_TO_PATH(SOLUTION_ID)
#include SOLUTION_CPP_FULL_PATH

#else

// 2. 或者选择使用 #指定路径的题目代码#
#define SOLUTION_CPP_FULL_PATH			"../../problems_test/399/SOLUTION.cpp"
#include SOLUTION_CPP_FULL_PATH

#endif



//////////////////////////////////////////////////////////////////////////
int main()
{
	PerformanceTimer timer;
#ifdef USE_GET_TEST_CASES_IN_CPP
	TestCases test_cases(_get_test_cases_string());
#else
	string strSolution = "SOLUTION.cpp";
	string strTest = "tests.txt";
	string file = SOLUTION_CPP_FULL_PATH;
	file.replace(file.find(strSolution), strSolution.size(), strTest);
	ifstream f(file);
	TestCases test_cases(f);
#endif

	while (!test_cases.empty())
	{
		timer.start();

#ifdef USE_SOLUTION_CUSTOM
		using func_t = function_type<function<decltype(_solution_custom)>>;
		func_t::return_type ans = _solution_custom(test_cases);
#else
		using func_t = function_type<function<decltype(_solution_run)>>;
		func_t::return_type ans = func_t::call(_solution_run, test_cases);
#endif

		timer.stop();

#ifdef USE_CHECKANSWER_CUSTOM
		_checkAnswer_custom(ans, test_cases);
#else
		func_t::return_type answer = test_cases.get<func_t::return_type>();
		cout << checkAnswer<decltype(ans)>(ans, answer) << endl;
#endif

		timer.end();
	}
}
