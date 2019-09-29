// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//#include "..\Common\GraphNode.Hi"
//#include "..\Common\TreeNode.Hi"
//#include "..\Common\ListNode.Hi"
using namespace std;


//////////////////////////////////////////////////////////////////////////
bool uniqueOccurrences(vector<int>& arr)
{
	map<int, int> m;
	for (auto n : arr)
	{
		m[n]++;
	}
	unordered_set<int> s;
	for (auto k : m)
	{
		if (s.find(k.second) != s.end()) return false;
		s.insert(k.second);
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
int equalSubstring(string s, string t, int maxCost)
{
	auto f_cost = [s, t](size_t i)
	{
		return abs(s[i] - t[i]);
	};

	size_t start = 0;
	int c = 0;
	int ans = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		c += f_cost(i);
		while (c > maxCost)
		{
			c -= f_cost(start++);		
		}
		ans = max(ans, (int)(i - start) + 1);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
string removeDuplicates(string s, int k) 
{
	string ans;
	int cnt = 1;
	for (size_t i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i - 1])
		{
			cnt = (cnt + 1) % k;
		}

		if (s[i] != s[i - 1] || i == s.size() - 1)
		{
			while (cnt > 0)
			{
				cnt--;
				ans.push_back(s[i - 1]);
			} 
			cnt = 1;
			if (s[i] != s[i - 1] && i == s.size() - 1)
			{
				ans.push_back(s[i]);
			}
		}
	}

	return (ans.size() == s.size()) ? ans : removeDuplicates(ans, k);
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
	//vector<vector<int>> TESTS;
	////vector<int> K;
	//vector<bool> ANSWERS;

	//TESTS.push_back({ 1,2,2,1,1,3 });
	//ANSWERS.push_back(true);

	//TESTS.push_back({ 1,2 });
	//ANSWERS.push_back(false);

	//TESTS.push_back({ -3,0,1,-3,1,1,1,-3,10,0 });
	//ANSWERS.push_back(true);

	//////////////////////////////////////////////////////////////////////////
	vector<string> TESTS;
	vector<string> T;
	vector<int> M;
	vector<int> ANSWERS;

	TESTS.push_back("abcd");
	T.push_back("bcdf");
	M.push_back(3);
	ANSWERS.push_back(3);

	TESTS.push_back("abcd");
	T.push_back("cdef");
	M.push_back(3);
	ANSWERS.push_back(1);

	TESTS.push_back("abcd");
	T.push_back("acde");
	M.push_back(0);
	ANSWERS.push_back(1);

	TESTS.push_back("krrgw");
	T.push_back("zjxss");
	M.push_back(19);
	ANSWERS.push_back(2);

	//////////////////////////////////////////////////////////////////////////
	//vector<string> TESTS;
	//vector<int> K;
	//vector<string> ANSWERS;

	//TESTS.push_back("abcd");
	//K.push_back(2);
	//ANSWERS.push_back("abcd");

	//TESTS.push_back("deeedbbcccbdaa");
	//K.push_back(3);
	//ANSWERS.push_back("aa");

	//TESTS.push_back("pbbcggttciiippooaais");
	//K.push_back(2);
	//ANSWERS.push_back("ps");

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		//auto ans = uniqueOccurrences(TESTS[i]);
		//cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		auto ans = equalSubstring(TESTS[i], T[i], M[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		//auto ans = removeDuplicates(TESTS[i], K[i]);
		//cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
		//solve(TESTS[i]);
		//cout << checkAnswer<vector<vector<char>>>(TESTS[i], ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}


//////////////////////////////////////////////////////////////////////////
// TreeNode
//int main()
//{
//	vector<TreeNode *> N;
//	vector<int> K;
//	vector<bool> A;
//
//	N.push_back(StringToTreeNode("3,9,20,null,null,15,7"));
//	//K.push_back(3);
//	A.push_back(true);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,null,null,4,4"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	for (int i = 0; i < N.size(); i++)
//	{
//		cout << endl << "///////////////////////////////////////" << endl;
//		cout << N[i] << endl;
//		//DrawTreeNode(N[i]);
//
//		bool ans = isBalanced(N[i]);
//		cout << checkAnswer<bool>(ans, A[i]) << endl;
//		//DrawTreeNode(ans);
//
//	}
//}


//////////////////////////////////////////////////////////////////////////
// List Node
//int main()
//{
//	vector<ListNode *> lists;
//	ListNode *pHead = StringToListNode("[4,7,5,3]");
//	lists.push_back(pHead);
//	pHead = nullptr;
//
//	for (auto i : lists)
//	{
//		cout << i << endl;
//		pHead = sortList(i);
//		cout << pHead << endl;
//		cout << endl;
//	}
//}


