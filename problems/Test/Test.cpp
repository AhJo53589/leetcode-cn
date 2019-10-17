// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
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

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.Hi"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.Hi"
using namespace std;

//////////////////////////////////////////////////////////////////////////
int jump(vector<int>& nums) 
{
	if (nums.size() < 2) return 0;
	int ans = 0;
	int l = 0;
	int r = 1;
	while (r < nums.size())
	{
		int temp = 0;
		for (int i = l; i < r && i < nums.size(); i++)
		{
			temp = max(temp, i + nums[i]);
		}
		l = r;
		r = temp + 1;
		ans++;
	}
	return ans;
}

int main()
{
	PerformanceTimer timer;
	ifstream f("tests.txt");
	TestCases testcases(f);

	//////////////////////////////////////////////////////////////////////////
	vector<vector<int>> TESTS;
	//vector<int> K;
	vector<int> ANSWERS;

	while (!testcases.empty())
	{
		TESTS.push_back(StringToVectorInt(testcases.popString()));
		ANSWERS.push_back(stoi(testcases.popString()));
	}

	for (int i = 0; i < TESTS.size(); i++)
	{
		timer.start();

		auto ans = jump(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
		//sortArray(TESTS[i]);
		//cout << checkAnswer<vector<int>>(TESTS[i], ANSWERS[i]) << endl;

		timer.stop();
	}
}


//////////////////////////////////////////////////////////////////////////
// TreeNode
//	vector<TreeNode *> N;
//	N.push_back(StringToTreeNode("3,9,20,null,null,15,7"));


//////////////////////////////////////////////////////////////////////////
// List Node
//	ListNode *pHead = StringToListNode("[4,7,5,3]");


