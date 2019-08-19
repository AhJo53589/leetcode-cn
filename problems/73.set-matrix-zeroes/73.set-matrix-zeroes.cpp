// 73.set-matrix-zeroes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
void setZeroes(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	if (m == 0) return;
	int n = matrix[0].size();

	bool bZeroH = (matrix[0][0] == 0);
	bool bZeroV = (matrix[0][0] == 0);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				if (i == 0) bZeroH = true;
				else matrix[i][0] = 0;
				if (j == 0) bZeroV = true;
				else matrix[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < m; i++)
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 1; j < n; j++) matrix[i][j] = 0;
		}
	}

	for (int j = 1; j < n; j++)
	{
		if (matrix[0][j] == 0)
		{
			for (int i = 1; i < m; i++) matrix[i][j] = 0;
		}
	}
	if (bZeroH)
	{
		for (int j = 0; j < n; j++) matrix[0][j] = 0;
	}
	if (bZeroV)
	{
		for (int i = 0; i < m; i++) matrix[i][0] = 0;
	}
}


int main()
{
	vector<vector<vector<int>>> TESTS;
	//vector<int> K;
	vector<vector<vector<int>>> ANSWERS;

	TESTS.push_back(StringToVectorVectorInt("[[1, 0]]"));
	ANSWERS.push_back(StringToVectorVectorInt("[[0, 0]]"));

	TESTS.push_back(StringToVectorVectorInt("[[1, 0, 3]]"));
	ANSWERS.push_back(StringToVectorVectorInt("[[0, 0, 0]]"));

	TESTS.push_back(StringToVectorVectorInt("[[1, 1, 1],[1, 0, 1],[1, 1, 1]]"));
	ANSWERS.push_back(StringToVectorVectorInt("[[1, 0, 1],[0, 0, 0],[1, 0, 1]]"));

	TESTS.push_back(StringToVectorVectorInt("[[0, 1, 2, 0],[3, 4, 5, 2],[1, 3, 1, 5]]"));
	ANSWERS.push_back(StringToVectorVectorInt("[[0, 0, 0, 0],[0, 4, 5, 0],[0, 3, 1, 0]]"));

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		//auto ans = setZeroes(TESTS[i]);
		printVectorVectorInt(TESTS[i]);
		setZeroes(TESTS[i]);
		cout << checkAnswer<decltype(TESTS[i])>(TESTS[i], ANSWERS[i]) << endl;
	}
}
