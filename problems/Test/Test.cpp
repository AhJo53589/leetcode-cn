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
int longestSubstring(string s, int k) {
	//特殊情况
	if (s.size() == 0)
		return 0;

	//count记录s中26个字母出现的次数
	//count[0]-->a的次数  count[1]-->b的次数...以此类推
	vector<int>count(26, 0);


	//numOfLessThanK记录有多少种字母的数量大于0小于k
	int numOfLessThanK = 0;
	for (char &x : s) {
		//增加了一个新的字母，则可能的小于k的字母种类+1
		if (count[x - 'a'] == 0)
			numOfLessThanK++;

		count[x - 'a']++;

		//有一种字母达到了数量k,则小于k的字母种类-1
		if (count[x - 'a'] == k)
			numOfLessThanK--;
	}
	//不存在小于数量k的字母，则说明s已经符合要求
	if (numOfLessThanK == 0)
		return s.size();

	//pre记录上s中上一个出现次数>=k的索引位置
	//cur用来记录当前遍历到的位置
	//ans用来存最大长度
	int pre = 0, cur = 0;
	int ans = 0;
	while (cur < s.size()) {
		//当前cur位置上对应的字母数量小于k
		if (count[s[cur] - 'a'] < k) {
			//递归计算[pre,cur-1]区间上的子串ss对应的答案
			string ss = s.substr(pre, cur - pre);
			// 如果子串长度小于等于当前的候补答案ans
			// 则没必要计算这个子串
			if (ss.size() > ans) {
				ans = max(ans, longestSubstring(ss, k));
			}

			int end = cur;
			//end为从cur位置开始下一个出现字母次数大于k的位置
			while (end < s.size() && count[s[end] - 'a'] < k)
				end++;
			//[cur,end-1]这个区间的字母出现次数全部小于k
			//所以下一个可能的子串开始位置pre=end
			pre = end;
			cur = end;
		}
		else
			cur++;
	}
	//前面while循环退出是cur=s.size()
	//因为循环是每到一个cur位置上对应的字母数量小于k
	//时就计算前一个子串。。
	//所以有可能最后一个子串[pre,cur-1]没计算过
	if (pre < s.size()) {
		string ss = s.substr(pre, cur - pre);
		//同样，如果子串长度小于等于当前的候补答案ans
		//则没必要递归计算
		if (ss.size() > ans) {
			ans = max(ans, longestSubstring(ss, k));
		}
	}

	return ans;
}

//////////////////////////////////////////////////////////////////////////
int longestSubstring(string s, int k) 
{
	int ans = 0;
	for (size_t i = 0; i < s.length(); i++)
	{
		int counts[26] = { 0 };
		auto check = [&counts, &k]()
		{
			for (int i = 0; i < 26; i++)
			{
				if (counts[i] != 0 && counts[i] < k) return false;
			}
			return true;
		};

		if (i != 0 && s[i] == s[i - 1]) continue;
		for (size_t j = i; j < s.length(); j++)
		{
			counts[s[j] - 'a']++;
			if (ans >= j - i + 1) continue;
			ans = check() ? max(ans, (int)(j - i + 1)) : ans;
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

	auto f_time_cout = [&]()
	{
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << endl;
	};

	//////////////////////////////////////////////////////////////////////////
	vector<string> TESTS;
	vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back("aaabb");
	K.push_back(3);
	ANSWERS.push_back(3);

	TESTS.push_back("aaabbdccccb");
	K.push_back(3);
	ANSWERS.push_back(4);

	TESTS.push_back("ababbc");
	K.push_back(2);
	ANSWERS.push_back(5);

	TESTS.push_back("cababbc");
	K.push_back(2);
	ANSWERS.push_back(7);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = longestSubstring(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

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


