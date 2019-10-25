// 79.word-search.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
bool exist(vector<vector<char>> &board, size_t i, size_t j, string word, unordered_set<size_t> visited)
{
	if (word.empty()) return true;
	if (board.size() == 0 || board.size() <= i) return false;
	if (board[0].size() == 0 || board[0].size() <= j) return false;
	if (visited.count(i * board[0].size() + j)) return false;

	if (board[i][j] != word.front()) return false;
	word = word.substr(1, word.size() - 1);
	visited.insert(i * board[0].size() + j);

	if (exist(board, i - 1, j, word, visited)) return true;
	if (exist(board, i + 1, j, word, visited)) return true;
	if (exist(board, i, j - 1, word, visited)) return true;
	if (exist(board, i, j + 1, word, visited)) return true;

	return false;
}

bool exist(vector<vector<char>>& board, string word)
{
	unordered_map<char, int> map_board;
	unordered_map<char, int> map_word;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			map_board[board[i][j]]++;
		}
	}
	for (auto &c : word)
	{
		map_word[c]++;
		if (map_word[c] > map_board[c]) return false;
	}

	unordered_set<size_t> visited;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == word.front())
			{
				if (exist(board, i, j, word, visited)) return true;
			}
		}
	}
	return false;
}



int main()
{
	vector<vector<vector<char>>> TESTS;
	vector<string> K;
	vector<bool> ANSWERS;

	TESTS.push_back(StringToVectorVectorChar("[['A', 'B', 'C', 'E'],['S', 'F', 'C', 'S'],['A', 'D', 'E', 'E']]"));
	K.push_back("ABCCED");
	ANSWERS.push_back(true);

	TESTS.push_back(StringToVectorVectorChar("[['A', 'B', 'C', 'E'],['S', 'F', 'C', 'S'],['A', 'D', 'E', 'E']]"));
	K.push_back("SEE");
	ANSWERS.push_back(true);

	TESTS.push_back(StringToVectorVectorChar("[['A', 'B', 'C', 'E'],['S', 'F', 'C', 'S'],['A', 'D', 'E', 'E']]"));
	K.push_back("ABCB");
	ANSWERS.push_back(false);

	TESTS.push_back(StringToVectorVectorChar("[['A', 'B', 'C', 'E'],['S', 'F', 'E', 'S'],['A', 'D', 'E', 'E']]"));
	K.push_back("ABCESEEEFS");
	ANSWERS.push_back(true);

	TESTS.push_back(StringToVectorVectorChar("[[a,a,a,a],[a,a,a,a],[a,a,a,a],[a,a,a,a],[a,a,a,b]"));
	K.push_back("aaaaaaaaaaaaaaaaaaaa");
	ANSWERS.push_back(false);

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = exist(TESTS[i], K[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}