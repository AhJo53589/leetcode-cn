// 71.simplify-path.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
string simplifyPath(string &path)
{
	for (size_t i = path.size(); i > 0; )
	{
		i--;
		path[i] = (path[i] == '/' ? ' ' : path[i]);
	}
	stringstream istr(path);
	vector<string> vs;
	string str;
	while (istr >> str)
	{
		if (str == ".") continue;
		if (str != "..") vs.push_back(str);
		else if (vs.size()) vs.pop_back();
	}
	str.clear();
	for (auto &s : vs)
	{
		str.append("/" + s);
	}
	return str.empty() ? "/" : str;
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
	vector<string> TESTS;
	//vector<string> K;
	vector<string> ANSWERS;

	TESTS.push_back("/home/");
	ANSWERS.push_back("/home");

	TESTS.push_back("/../");
	ANSWERS.push_back("/");

	TESTS.push_back("/home//foo/");
	ANSWERS.push_back("/home/foo");

	TESTS.push_back("/a/./b/../../c/");
	ANSWERS.push_back("/c");

	TESTS.push_back("/a/../../b/../c//.//");
	ANSWERS.push_back("/c");

	TESTS.push_back("/a//b////c/d//././/..");
	ANSWERS.push_back("/a/b/c");

	TESTS.push_back("/.../");
	ANSWERS.push_back("/...");

	TESTS.push_back("/...");
	ANSWERS.push_back("/...");

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = simplifyPath(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}