// 36.IsValidSudoku.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

vector<int> convertInt(vector<char>& line)
{
	vector<int> nums;
	for (char c : line)
	{
		if (c == '.') continue;

		int n = c - 48;
		nums.push_back(n);
	}
	return nums;
}

bool checkDuplicate(vector<char>& line)
{
	vector<int> nums = convertInt(line);
	sort(nums.begin(), nums.end());

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i - 1] == nums[i]) return true;
	}

	return false;
}

bool isValidSudoku(vector<vector<char>>& board)
{
	for (int i = 0; i < 9; i++)
	{
		if (checkDuplicate(board[i])) return false;
	}

	vector<char> grid[9];
	for (int i = 0; i < 9; i++)
	{
		vector<char> line;
		for (int j = 0; j < 9; j++)
		{
			line.push_back(board[j][i]);

			// 把81宫格合并成9宫格
			int k = i / 3 + j / 3 * 3;
			grid[k].push_back(board[i][j]);
		}
		if (checkDuplicate(line)) return false;
	}

	for (int i = 0; i < 9; i++)
	{
		if (checkDuplicate(grid[i])) return false;
	}

	return true;
}

void Init(vector<vector<char>>& board)
{
	// 	["5", "3", ".", ".", "7", ".", ".", ".", "."],
	// 	["6", ".", ".", "1", "9", "5", ".", ".", "."],
	// 	[".", "9", "8", ".", ".", ".", ".", "6", "."],
	// 	["8", ".", ".", ".", "6", ".", ".", ".", "3"],
	// 	["4", ".", ".", "8", ".", "3", ".", ".", "1"],
	// 	["7", ".", ".", ".", "2", ".", ".", ".", "6"],
	// 	[".", "6", ".", ".", ".", ".", "2", "8", "."],
	// 	[".", ".", ".", "4", "1", "9", ".", ".", "5"],
	// 	[".", ".", ".", ".", "8", ".", ".", "7", "9"]

	string str[81] =
	{ "5", "3", ".", ".", "7", ".", ".", ".", ".",
		"6", ".", ".", "1", "9", "5", ".", ".", ".",
		".", "9", "8", ".", ".", ".", ".", "6", ".",
		"8", ".", ".", ".", "6", ".", ".", ".", "3",
		"4", ".", ".", "8", ".", "3", ".", ".", "1",
		"7", ".", ".", ".", "2", ".", ".", ".", "6",
		".", "6", ".", ".", ".", ".", "2", "8", ".",
		".", ".", ".", "4", "1", "9", ".", ".", "5",
		".", ".", ".", ".", "8", ".", ".", "7", "9" };

	for (int i = 0; i < 9; i++)
	{
		vector<char> vc;
		vc.clear();

		if (i == 3 || i == 6)
		{
			cout << endl;
		}

		for (int j = 0; j < 9; j++)
		{
			char tmp = str[i * 9 + j][0];
			vc.push_back(tmp);

			if (j == 3 || j == 6)
			{
				cout << "  ";
			}
			cout << tmp << " ";
		}
		board.push_back(vc);
		cout << endl;
	}
	cout << endl;
}

int main()
{
	vector<vector<char>> board;
	Init(board);

	int rst = isValidSudoku(board);
	cout << "isValidSudoku = " << rst << endl;
}
