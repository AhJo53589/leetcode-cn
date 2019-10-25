// 621.task-scheduler.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

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
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//int leastInterval(vector<char>& tasks, int n) {
//	int nums[26] = { 0 };
//	int len = tasks.size();
//	int max = 0;
//	for (int i = 0; i < len; i++) {
//		nums[tasks[i] - 'A']++;
//	}
//	for (int i = 0; i < 26; i++) {
//		if (max < nums[i])
//			max = nums[i];
//	}
//	int count = 0;
//	for (int i = 0; i < 26; i++) {
//		if (max == nums[i])
//			count++;
//	}
//	int res = (max - 1)*(n + 1) + count;
//	return res < len ? len : res;
//}

//////////////////////////////////////////////////////////////////////////
int leastInterval(vector<char>& tasks, int n)
{
	array<int, 26> task_count = {};
	vector<int> task_order;

	for (auto &c : tasks)
	{
		task_count[c - 'A']++;
	}
	for (int i = 0; i < task_count.size(); i++)
	{
		if (task_count[i] == 0) continue;
		task_order.push_back(task_count[i]);
	}
	sort(task_order.rbegin(), task_order.rend());

	int res = 0;
	while (!task_order.empty())
	{
		int count = 0;
		for (int i = 0; i < task_order.size(); i++)
		{
			task_order[i]--;
			count++;
			if (count == n + 1) break;
		}
		sort(task_order.rbegin(), task_order.rend());
		while (!task_order.empty() && task_order.back() == 0) task_order.pop_back();

		res += task_order.empty() ? count : n + 1;
	}

	return res;
}



int main()
{
	vector<vector<char>> TESTS;
	vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ 'A','A','A','B','B','B' });
	K.push_back(2);
	ANSWERS.push_back(8);

	TESTS.push_back({ 'A','B','C','B','C','C','D','E' });
	K.push_back(2);
	ANSWERS.push_back(8);

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = leastInterval(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}