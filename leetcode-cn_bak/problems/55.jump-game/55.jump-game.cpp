// 55.jump-game.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//////////////////////////////////////////////////////////////////////////
bool canJump(vector<int>& nums)
{
	int k = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > k) return false;
		k = max(k, i + nums[i]);
	}
	return true;
}


int main()
{
	vector<vector<int>> TESTS;
	//vector<string> K;
	vector<bool> ANSWERS;

	TESTS.push_back({ 2,3,1,1,4 });
	ANSWERS.push_back(true);

	TESTS.push_back({ 3,2,1,0,4 });
	ANSWERS.push_back(false);

	TESTS.push_back({ 0,1 });
	ANSWERS.push_back(false);

	TESTS.push_back({ 0 });
	ANSWERS.push_back(true);

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = canJump(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}