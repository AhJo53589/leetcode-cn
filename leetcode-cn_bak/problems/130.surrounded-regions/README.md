# `（中等）`  [130.surrounded-regions 被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)

### 题目描述
<p>给定一个二维的矩阵，包含&nbsp;<code>'X'</code>&nbsp;和&nbsp;<code>'O'</code>（<strong>字母 O</strong>）。</p>

<p>找到所有被 <code>'X'</code> 围绕的区域，并将这些区域里所有的&nbsp;<code>'O'</code> 用 <code>'X'</code> 填充。</p>

<p><strong>示例:</strong></p>

<pre>X X X X
X O O X
X X O X
X O X X
</pre>

<p>运行你的函数后，矩阵变为：</p>

<pre>X X X X
X X X X
X X X X
X O X X
</pre>

<p><strong>解释:</strong></p>

<p>被围绕的区间不会存在于边界上，换句话说，任何边界上的&nbsp;<code>'O'</code>&nbsp;都不会被填充为&nbsp;<code>'X'</code>。 任何不在边界上，或不与边界上的&nbsp;<code>'O'</code>&nbsp;相连的&nbsp;<code>'O'</code>&nbsp;最终都会被填充为&nbsp;<code>'X'</code>。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。</p>


---
### 思路
```
X X X X           X X X X           X X X X
X X O X    ->     X X O X    ->     X X X X
X O X X           X - X X           X O X X
X O X X           X - X X           X O X X
```
[别人的题解](https://leetcode-cn.com/problems/surrounded-regions/solution/dfs-bfs-bing-cha-ji-by-powcai/) 

### 答题
``` C++
void dfs(vector<vector<char>>& board, size_t x, size_t y)
{
	if (x >= board.size() || y >= board[x].size() || board[x][y] != 'O') return;
	board[x][y] = '-';
	dfs(board, x - 1, y);
	dfs(board, x + 1, y);
	dfs(board, x, y - 1);
	dfs(board, x, y + 1);
}

void solve(vector<vector<char>>& board) 
{
	size_t m = board.size();
	if (m == 0) return;
	size_t n = board[0].size();

	for (size_t i = 0; i < m; i++)
	{
		dfs(board, i, 0);
		dfs(board, i, n - 1);
	}
	for (size_t j = 0; j < n; j++)
	{
		dfs(board, 0, j);
		dfs(board, m - 1, j);
	}

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			board[i][j] = (board[i][j] != '-') ? 'X' : 'O';
		}
	}
}
```

