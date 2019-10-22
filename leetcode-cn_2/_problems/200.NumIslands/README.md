# `（中等）`  [200.NumIslands 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)

### 题目描述
<p>给定一个由&nbsp;<code>'1'</code>（陆地）和 <code>'0'</code>（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong>
11110
11010
11000
00000

<strong>输出:</strong>&nbsp;1
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong>
11000
11000
00100
00011

<strong>输出: </strong>3
</pre>





---
### 思路
``` 
遍历，当发现这个格子时个新岛的时候，  
把这个岛所有相连的都标记成‘2’。  
```


### 答题
``` C++
void checkIsland(vector<vector<char>>& grid, pair<int,int> posStart)
{
	queue<pair<int, int>> q;
	q.push(posStart);

	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();

		if (p.first >= 0 && p.first < grid.size() && p.second >= 0 && p.second < grid[0].size())
		{
			if (grid[p.first][p.second] == '1')
			{
				grid[p.first][p.second] = '2';

				q.push(make_pair(p.first, p.second - 1));
				q.push(make_pair(p.first, p.second + 1));
				q.push(make_pair(p.first - 1, p.second));
				q.push(make_pair(p.first + 1, p.second));
			}
		}
	}
}

int numIslands(vector<vector<char>>& grid) 
{
	int iLen_i = grid.size();
	if (iLen_i == 0) return 0;
	int iLen_j = grid[0].size();
	if (iLen_j == 0) return 0;

	int num = 0;
	for (int i = 0; i < iLen_i; i++)
	{
		for (int j = 0; j < iLen_j; j++)
		{
			if (grid[i][j] == '1')
			{
				checkIsland(grid, make_pair(i, j));
				num++;
			}
		}
	}

	return num;
}
``` 