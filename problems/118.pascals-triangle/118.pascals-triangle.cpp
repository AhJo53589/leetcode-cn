// 118.pascals-triangle.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>

#include "..\Common\Common.h"
using namespace std;

vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> m;
	for (int i = 1; i <= numRows; i++)
	{
		vector<int> n;
		for (int j = 0; j < i; j++)
		{
			if (j == 0 || j == i - 1) n.push_back(1);
			else n.push_back(m[i - 2][j - 1] + m[i - 2][j]);
		}
		m.push_back(n);
	}
	return m;
}

//vector<vector<int>> generate(int numRows)
//{
//	vector<vector<int>> m;
//	for (int i = 1; i <= numRows; i++)
//	{
//		vector<int> n;
//		for (int j = 0; j < i; j++)
//		{
//			if (j == 0 || j == i - 1) n.emplace_back(1);
//			else n.emplace_back(m[i - 2][j - 1] + m[i - 2][j]);
//		}
//		m.emplace_back(n);
//	}
//	return m;
//}

int main()
{
	vector<vector<int>> matrix = generate(10);
	printVectorVectorT(matrix);
}
