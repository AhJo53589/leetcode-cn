// 59.spiral-matrix-ii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//vector<vector<int>> generateMatrix(int n) {
//	if (n == 0)
//		return {};
//
//	vector<vector<int>> matrix(n, vector<int>(n, 0));
//	int count = 1;
//	int up = 0, down = n - 1, left = 0, right = n - 1;
//
//	while (count <= n * n) {
//		for (int i = left; i <= right; i++) {
//			matrix[up][i] = count;
//			++count;
//		}
//		++up;
//		for (int i = up; i <= down; i++) {
//			matrix[i][right] = count;
//			++count;
//		}
//		--right;
//		for (int i = right; i >= left; i--) {
//			matrix[down][i] = count;
//			++count;
//		}
//		--down;
//		for (int i = down; i >= up; i--) {
//			matrix[i][left] = count;
//			++count;
//		}
//		++left;
//	}
//	return matrix;
//}

vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> ret(n, vector<int>(n));

	int i = 0;
	int j = 0;
	int val = 1;
	int direction = 0;
	while (val <= n * n)
	{
		ret[i][j] = val++;

		if (direction == 0 && (j == n - 1 || ret[i][j + 1] != 0)) direction = 1;
		else if (direction == 1 && (i == n - 1 || ret[i + 1][j] != 0)) direction = 2;
		else if (direction == 2 && (j == 0 || ret[i][j - 1] != 0)) direction = 3;
		else if (direction == 3 && (i == 0 || ret[i - 1][j] != 0)) direction = 0;

		if (direction == 0) j++;
		else if (direction == 1) i++;
		else if (direction == 2) j--;
		else if (direction == 3) i--;
	}
	return ret;
}

int main()
{
	vector<int> N;
	N.push_back(1);
	N.push_back(2);
	N.push_back(3);
	N.push_back(4);
	N.push_back(5);

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "/////////////////////////////////" << endl;
		cout << N[i] << " = " << endl;
		vector<vector<int>> ans = generateMatrix(N[i]);
		printVectorVectorT(ans);
	}
}