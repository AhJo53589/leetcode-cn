// 22.generate-parentheses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
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

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//vector<string> generateParenthesis(int n) {
//	vector<string> ans;
//	if (n == 0)
//		return ans;
//	string cur;
//	search(ans, cur, 0, 0, n);
//	return ans;
//}
//void search(vector<string> &ans, string cur, int open, int close, int n)
//{
//	if (cur.size() == 2 * n)
//		ans.push_back(cur);
//	if (open < n)
//		search(ans, cur + '(', open + 1, close, n);
//	if (close < open)
//		search(ans, cur + ')', open, close + 1, n);
//}

//////////////////////////////////////////////////////////////////////////
vector<string> generateParenthesis(int n)
{
	vector<int> res_left;
	vector<string> res;
	res_left.push_back(0);
	res.push_back("");

	for (int i = 0; i < 2 * n; i++)
	{
		int len = res.size();
		for (int j = 0; j < len; j++)
		{
			int left = res_left[j];
			if (left < n)
			{
				res_left.push_back(left + 1);
				res.push_back(res[j] + "(");
			}

			if (i - left < left)
			{
				res_left.push_back(left);
				res.push_back(res[j] + ")");
			}
		}
		res_left.erase(res_left.begin(), res_left.begin() + len);
		res.erase(res.begin(), res.begin() + len);
	}
	return res;
}

int main()
{
	vector<int> TESTS;
	//vector<int> K;
	vector<vector<string>> ANSWERS;

	TESTS.push_back(3);
	ANSWERS.push_back({ "((()))","(()())","(())()","()(())","()()()" });

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = generateParenthesis(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}
