// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
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

//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;


//////////////////////////////////////////////////////////////////////////
// 选择测试代码

// 1.选择使用（本路径的测试代码）
//#include "SOLUTION.cpp"

// 2.或者选择使用（题库中的题，根据编号加载，使用Define_IdName.h中定义的宏）
// SOLUTION_CPP_FOLDER_NAME_ID_1 ==> 最后的数值是题目编号
#define ADD_QUOTES(A) #A
#define SOLUTION_CPP_PATH(name) ADD_QUOTES(../../problems/##name/SOLUTION.cpp)
#define SOLUTION_CPP_PATH_NAME(name) SOLUTION_CPP_PATH(name)
#include SOLUTION_CPP_PATH_NAME(SOLUTION_CPP_FOLDER_NAME_ID_5250)

// 3.或者选择使用（题库中的题，根据名字加载）
// SOLUTION_CPP_PATH(two-sum) ==> 最后的参数是题目名字
//#define ADD_QUOTES(A) #A
//#define SOLUTION_CPP_PATH(name) ADD_QUOTES(../../problems/##name/SOLUTION.cpp)
//#include SOLUTION_CPP_PATH(two-sum)




//////////////////////////////////////////////////////////////////////////
int main()
{
	PerformanceTimer timer;
#ifdef USE_GET_TEST_CASES_FILESTREAM
	ifstream f(_get_test_cases_filestream());
	TestCases test_cases(f);
#else
	TestCases test_cases(_get_test_cases_string());
#endif // USE_GET_TEST_CASES

	while (!test_cases.empty())
	{
		timer.start();

#ifdef USE_SOLUTION_CUSTOM
		auto ans = _solution_custom(test_cases);
		auto answer = test_cases.get<decltype(ans)>();
#else
		using func_t = function_type<function<decltype(_solution_run)>>;
		func_t::return_type ans = func_t::call(_solution_run, test_cases);
		func_t::return_type answer = test_cases.get<func_t::return_type>();
#endif
		cout << checkAnswer<decltype(ans)>(ans, answer) << endl;

		timer.stop();
	}
}
