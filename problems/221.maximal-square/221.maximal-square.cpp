// 221.maximal-square.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//////////////////////////////////////////////////////////////////////////

int maximalSquare(vector<vector<char>>& matrix)
{
	if (matrix.empty()) return 0;
	int res = 0;
	vector<vector<int>> m(matrix.size(), vector<int>{});
	for (auto &_m : m) _m.resize(matrix[0].size());

	for (int i = 0; i < matrix.size(); i++)
	{
		m[i][0] = matrix[i][0] - '0';
		if (m[i][0] == 1) res = 1;
		if (matrix[0].size() == 1 && m[i][0] == 1) return res;
	}
	for (int j = 0; j < matrix[0].size(); j++)
	{
		m[0][j] = matrix[0][j] - '0';
		if (m[0][j] == 1) res = 1;
		if (matrix.size() == 1 && m[0][j] == 1) return res;
	}
	for (int i = 1; i < matrix.size(); i++)
	{
		for (int j = 1; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == '1')
			{
				m[i][j] = min(min(m[i - 1][j], m[i][j - 1]), m[i - 1][j - 1]) + 1;
				res = max(res, m[i][j]);
			}
		}
	}
	return pow(res, 2);
}



int main()
{
	vector<vector<vector<char>>> TESTS;
	//vector<vector<int>> K;
	vector<int> ANSWERS;

	TESTS.push_back({ { '1' } });
	ANSWERS.push_back(1);

	TESTS.push_back({ { '0','1' }, {'1','0'} });
	ANSWERS.push_back(1);

	TESTS.push_back({ { '1','0','1','0','0' }, { '1','0','1','1','1' }, { '1','1','1','1','1' }, { '1','0','0','1','0' } });
	ANSWERS.push_back(4);

	TESTS.push_back({ { '1','0','1','0','0' }, { '1','0','1','1','1' }, { '1','1','1','1','1' }, { '1','0','1','1','1' } });
	ANSWERS.push_back(9);


	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = maximalSquare(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}