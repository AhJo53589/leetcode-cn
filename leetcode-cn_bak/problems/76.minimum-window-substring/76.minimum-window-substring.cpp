// 76.minimum-window-substring.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
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
#include <sstream>

#include "..\Common\Common.h"
using namespace std;


//////////////////////////////////////////////////////////////////////////
//string minWindow(string s, string t) {
//	int count[256] = { 0 };
//
//	for (auto c : t) {
//		++count[c];
//	}
//
//	int l = 0;
//	int r = 0;
//	int len = 0; // 当前窗口匹配 t 中字符的数目
//	int minLen = s.size();
//	string res;
//
//	for (; r < s.size(); r++) {
//		if (count[s[r]] > 0) {
//			len++;
//		}
//		count[s[r]]--;
//
//		while (len == t.size()) {
//			if (r - l + 1 <= minLen) {
//				minLen = r - l + 1;
//				res = s.substr(l, r - l + 1);
//			}
//			count[s[l]]++; // 移动窗口的左指针
//			if (count[s[l]] > 0) {
//				len--;
//			}
//			l++;
//		}
//	}
//
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
string minWindow(string s, string t)
{
	if (s.size() < t.size()) return "";
	if (t.size() == 1 && s.find(t[0]) != string::npos) return t;

	queue<size_t> _window;
	unordered_map<char, int> _map;
	string ans;
	size_t ans_len = UINT_MAX;
	bool bMapFlag = false;

	for (auto c : t)
	{
		_map[c]--;
	}

	auto f_check_map = [&_map, &bMapFlag]()
	{
		if (bMapFlag) return true;
		for (auto m : _map)
		{
			if (m.second < 0) return false;
		}
		bMapFlag = true;
		return true;
	};

	for (size_t i = 0; i < s.size(); i++)
	{
		if (_map.count(s[i]) == 0) continue;
		_window.push(i);
		_map[s[i]]++;
		while (_map[s[_window.front()]] > 0)
		{
			auto j = _window.front();
			_window.pop();
			_map[s[j]]--;
		}
		if (f_check_map())
		{
			auto k = (_window.size() > 1) ? _window.back() - _window.front() + 1 : UINT_MAX;
			if (k < ans_len)
			{
				ans = s.substr(_window.front(), k);
				ans_len = k;
			}
		}
	}
	return ans;
}

int main()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);

	auto f_time_begin = [&time, &nFreq, &nBeginTime, &nEndTime]()
	{
		cout << endl << "/////////////////////////////" << endl;
		QueryPerformanceCounter(&nBeginTime);
	};

	auto f_time_end = [&time, &nFreq, &nBeginTime, &nEndTime]()
	{
		QueryPerformanceCounter(&nEndTime);
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << endl;
	};

	//////////////////////////////////////////////////////////////////////////
	vector<string> TESTS;
	vector<string> K;
	vector<string> ANSWERS;

	TESTS.push_back("ADOBECODEBANC");
	K.push_back("ABC");
	ANSWERS.push_back("BANC");

	TESTS.push_back("A");
	K.push_back("AA");
	ANSWERS.push_back("");

	TESTS.push_back("abcabdebac");
	K.push_back("cda");
	ANSWERS.push_back("cabd");

	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		auto ans = minWindow(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		f_time_end();
	}
}