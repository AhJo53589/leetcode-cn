// 240.SearchMatrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Init()
{
	//[
	//	[1, 4, 7, 11, 15],
	//	[2, 5, 8, 12, 19],
	//	[3, 6, 9, 16, 22],
	//	[10, 13, 14, 17, 24],
	//	[18, 21, 23, 26, 30]
	//]
	vector<int> A1 = { 1,4,7,11,15 };
	vector<int> A2 = { 2, 5, 8, 12, 19 };
	vector<int> A3 = { 3, 6, 9, 16, 22 };
	vector<int> A4 = { 10, 13, 14, 17, 29 };
	vector<int> A5 = { 18, 21, 23, 26, 30 };
	vector<vector<int>> matrix;
	matrix.push_back(A1);
	matrix.push_back(A2);
	matrix.push_back(A3);
	matrix.push_back(A4);
	matrix.push_back(A5);

	return matrix;
}

vector<vector<int>> Init2()
{
	//[
	//	[1, 3, 5, 7, 9], 
	//	[2, 4, 6, 8, 10], 
	//	[11, 13, 15, 17, 19], 
	//	[12, 14, 16, 18, 20], 
	//	[21, 22, 23, 24, 25]
	//]

	vector<int> A1 = { 1, 3, 5, 7, 9 };
	vector<int> A2 = { 2, 4, 6, 8, 10 };
	vector<int> A3 = { 11, 13, 15, 17, 19 };
	vector<int> A4 = { 12, 14, 16, 18, 20 };
	vector<int> A5 = { 21, 22, 23, 24, 25 };
	vector<vector<int>> matrix;
	matrix.push_back(A1);
	matrix.push_back(A2);
	matrix.push_back(A3);
	matrix.push_back(A4);
	matrix.push_back(A5);

	return matrix;
}


vector<vector<int>> Init3()
{
	vector<int> A1 = { -1 };
	vector<vector<int>> matrix;
	matrix.push_back(A1);
	matrix.push_back(A1);

	return matrix;
}


void PrintMartix(vector<vector<int>> &m)
{
	cout << "Martix = " << endl;
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
		{
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}

}

//bool searchTarget(vector<vector<int>>& matrix, int i, int j, int target)
//{
//	if (i >= matrix.size()) return false;
//	if (j >= matrix[i].size()) return false;
//
//	if (matrix[i][j] == target) return true;
//	if (matrix[i][j] < target)
//	{
//		if (searchTarget(matrix, i + 1, j, target) || searchTarget(matrix, i, j + 1, target))
//		{
//			return true;
//		}
//	}
//	return false;
//}

//bool searchMatrix(vector<vector<int>>& matrix, int target) 
//{
//	if (matrix.size() == 0) return false;
//	return searchTarget(matrix, 0, 0, target);
//}

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int r = matrix.size();
	if (r == 0) return false;

	int c = matrix[0].size();
	for (int i = 0, j = c - 1; i<r && j>-1;)
	{
		if (target < matrix[i][j])
		{
			j--;
		}
		else if (target > matrix[i][j])
		{
			i++;
		}
		else
		{
			return true;
		}
	}
	return false;
}


int main()
{
	vector<vector<int>> matrix = Init();
	PrintMartix(matrix);

	int target[10] = { 1,8,9,12,13,17,19,20,21,25 };
	for (int i : target)
	{
		bool b = searchMatrix(matrix, i);
		string str = b ? "True" : "False";
		cout << "Find " << i << " = " << str.c_str() << endl;;
	}

}
