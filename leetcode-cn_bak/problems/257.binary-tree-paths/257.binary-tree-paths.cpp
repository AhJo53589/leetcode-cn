// 257.binary-tree-paths.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
void binaryTreePaths(TreeNode* root, string path, vector<string> &vec)
{
	path = path.empty() ? to_string(root->val) : path + "->" + to_string(root->val);
	if (root->left != nullptr)
	{
		binaryTreePaths(root->left, path, vec);
	}
	if (root->right != nullptr)
	{
		binaryTreePaths(root->right, path, vec);
	}
	if (root->left == nullptr && root->right == nullptr)
	{
		vec.push_back(path);
	}
}

vector<string> binaryTreePaths(TreeNode* root)
{
	if (root == nullptr) return {};
	string path;
	vector<string> vec;
	binaryTreePaths(root, path, vec);
	return vec;
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
	vector<TreeNode*> TESTS;
	vector<vector<string>> ANSWERS;

	TESTS.push_back(StringToTreeNode("[1,2,3,null,5]"));
	ANSWERS.push_back({ "1->2->5", "1->3" });

	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		auto ans = binaryTreePaths(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		f_time_end();
	}
}