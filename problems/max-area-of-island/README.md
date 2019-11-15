# `（中等）` [695.max-area-of-island 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)

### 题目描述
<p>给定一个包含了一些 0 和 1的非空二维数组&nbsp;<code>grid</code>&nbsp;, 一个&nbsp;<strong>岛屿</strong>&nbsp;是由四个方向 (水平或垂直) 的&nbsp;<code>1</code>&nbsp;(代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。</p>

<p>找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)</p>

<p><strong>示例 1:</strong></p>

<pre>[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,<strong>1</strong>,0,<strong>1</strong>,0,0],
 [0,1,0,0,1,1,0,0,<strong>1</strong>,<strong>1</strong>,<strong>1</strong>,0,0],
 [0,0,0,0,0,0,0,0,0,0,<strong>1</strong>,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
</pre>

<p>对于上面这个给定矩阵应返回&nbsp;<code>6</code>。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。</p>

<p><strong>示例 2:</strong></p>

<pre>[[0,0,0,0,0,0,0,0]]</pre>

<p>对于上面这个给定的矩阵, 返回&nbsp;<code>0</code>。</p>

<p><strong>注意:&nbsp;</strong>给定的矩阵<code>grid</code>&nbsp;的长度和宽度都不超过 50。</p>


---
### 思路
```
```

### 答题
``` C++
void dfs(vector<vector<int>> &grid, int i, int j, int &ans)
{
	int m = grid.size();
	if (m == 0) return;
	int n = grid[0].size();
	if (n == 0) return;
	if (i >= m || i < 0) return;
	if (j >= n || j < 0) return;
	if (grid[i][j] == 0) return;

	ans++;
	grid[i][j] = 0;
	dfs(grid, i - 1, j, ans);
	dfs(grid, i + 1, j, ans);
	dfs(grid, i, j - 1, ans);
	dfs(grid, i, j + 1, ans);
}

int maxAreaOfIsland(vector<vector<int>>& grid) 
{
	int ans = 0;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			int temp = 0;
			dfs(grid, i, j, temp);
			ans = max(ans, temp);
		}
	}
	return ans;
}
```

### 其它
``` C++
```

