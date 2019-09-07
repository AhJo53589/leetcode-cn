// 498.diagonal-traverse.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
{
	vector<int> nums;
	int m = matrix.size();
	if (m == 0) return nums;
	int n = matrix[0].size();
	if (n == 0) return nums;

	bool bXFlag = true;
	for (int i = 0; i < m + n; i++)
	{
		int pm = bXFlag ? m : n;
		int pn = bXFlag ? n : m;

		int x = (i < pm) ? i : pm - 1;
		int y = i - x;
		while (x >= 0 && y < pn)
		{
			nums.push_back(bXFlag ? matrix[x][y] : matrix[y][x]);
			x--;
			y++;
		}
		bXFlag = !bXFlag;
	}
	return nums;
}

//vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
//{
//	if (matrix.empty()) return vector<int>();
//	int rows = matrix.size();
//	int cols = matrix[0].size();
//	vector<int> output;
//	int i = 0, j = 0;
//	output.push_back(matrix[i][j]);
//	while (i != rows - 1 || j != cols - 1)
//	{
//		if (j + 1 < cols) j++;
//		else if (i + 1 < rows) i++;
//		output.push_back(matrix[i][j]);
//
//		while (i + 1 < rows && j - 1 >= 0)
//		{
//			i++;
//			j--;
//			output.push_back(matrix[i][j]);
//		}
//
//		if (i + 1 < rows) i++;
//		else if (j + 1 < cols) j++;
//		else return output;
//		output.push_back(matrix[i][j]);
//
//		while (i - 1 >= 0 && j + 1 < cols)
//		{
//			i--;
//			j++;
//			output.push_back(matrix[i][j]);
//		}
//	}
//	return output;
//}

int main()
{
	string str = "[[1,2,3],[4,5,6],[7,8,9]]";
	//string str = "[[2,3]]";
	//string str = "[[3],[2]]";

	vector<vector<int>> matrix = StringToVectorVectorInt(str);
	printVectorVectorT(matrix);
	vector<int> nums = findDiagonalOrder(matrix);
	printVectorT(nums);
}
