// 111.minimum-depth-of-binary-tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include "..\Common\TreeNode.h"
using namespace std;



//////////////////////////////////////////////////////////////////////////
int minDepth(TreeNode* root)
{
	if (root == nullptr) return 0;
	if (root->left == nullptr && root->right == nullptr) return 1;
	int left = (root->left == nullptr) ? INT_MAX : minDepth(root->left);
	int right = (root->right == nullptr) ? INT_MAX : minDepth(root->right);
	return min(left, right) + 1;
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
	vector<TreeNode *> TESTS;
	vector<int> ANSWERS;

	TESTS.push_back(StringToTreeNode("3,9,20,null,null,15,7"));
	ANSWERS.push_back(2);

	TESTS.push_back(StringToTreeNode("1,2"));
	ANSWERS.push_back(2);


	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		auto ans = minDepth(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		f_time_end();
	}
}