// 93.restore-ip-addresses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
vector<string> restoreIpAddresses(string &s, int id, int iBegin)
{
	int len = s.length();
	vector<string> ret;
	for (int i = iBegin; i < iBegin + 3; i++)
	{
		if (id == 0 && i != len - 1) continue;
		if ((len - i - 1) > (id * 3)) continue;
		if ((len - i - 1) < (id * 1)) continue;

		string sub = s.substr(iBegin, i - iBegin + 1);
		int ip = stoi(sub);
		if (ip < 0 || ip > 255) continue;
		if (to_string(ip) != sub) break;

		if (id == 0)
		{
			ret.push_back(sub);
		}
		vector<string> vs = restoreIpAddresses(s, id - 1, i + 1);
		for (auto &v : vs)
		{
			ret.push_back(sub + "." + v);
		}
	}
	return ret;
}

vector<string> restoreIpAddresses(string s)
{
	return restoreIpAddresses(s, 3, 0);
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
	vector<vector<string>> ANSWERS;

	TESTS.push_back("25525511135");
	ANSWERS.push_back({ "255.255.11.135", "255.255.111.35" });

	TESTS.push_back("010010");
	ANSWERS.push_back({ "0.10.0.10","0.100.1.0" });

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = restoreIpAddresses(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}
