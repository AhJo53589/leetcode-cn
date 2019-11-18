# `（中等）` [79.word-search 单词搜索](https://leetcode-cn.com/problems/word-search/)

### 题目描述
<p>给定一个二维网格和一个单词，找出该单词是否存在于网格中。</p>

<p>单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。</p>

<p><strong>示例:</strong></p>

<pre>board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "<strong>ABCCED</strong>", 返回 <strong>true</strong>.
给定 word = "<strong>SEE</strong>", 返回 <strong>true</strong>.
给定 word = "<strong>ABCB</strong>", 返回 <strong>false</strong>.</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/word-search/solution/79-by-ikaruga/)

### 答题
``` C++
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
```

### 其它
``` C++
```

