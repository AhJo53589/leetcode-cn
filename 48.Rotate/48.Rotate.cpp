// 48.Rotate.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;


//firstly exchange elements by diagonal, then exchange elements by mid-line.
void rotate(vector<vector<int>>& matrix)
{
	int temp;
	int end = matrix.size() - 1;
	float mid_line = end / 2;
	for (int i = 0; i <= end; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}
	for (int i = 0; i <= end; i++)
	{
		for (int j = 0; j <= mid_line; j++)
		{
			swap(matrix[i][j], matrix[i][end - j]);
		}
	}
}

int main()
{
    std::cout << "Hello World!\n"; 
}

