// 17.letter-combinations-of-a-phone-number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
vector<string> letterCombinations(string digits)
{
	if (digits.empty()) return {};
	vector<string> data{ "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> res;
	res.push_back("");

	for (int i = 0; i < digits.size(); i++)
	{
		int d = digits[i] - '2';
		int len = res.size();
		for (int j = 0; j < len; j++)
		{
			for (auto m : data[d])
			{
				res.push_back(res[j] + m);
			}
		}
		res.erase(res.begin(), res.begin() + len);
	}
	return res;
}


int main()
{
	vector<string> TESTS;
	//vector<int> K;
	vector<vector<string>> ANSWERS;

	TESTS.push_back("23");
	ANSWERS.push_back({ "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" });

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = letterCombinations(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}