# `（简单）` [463.island-perimeter 岛屿的周长](https://leetcode-cn.com/problems/island-perimeter/)

### 题目描述
<p>给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地&nbsp;0 表示水域。</p>

<p>网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。</p>

<p>岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。</p>

<p>&nbsp;</p>

<p><strong>示例 :</strong></p>

<pre><strong>输入:</strong>
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

<strong>输出:</strong> 16

<strong>解释:</strong> 它的周长是下面图片中的 16 个黄色的边：

<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/island.png">
</pre>


---
### 思路
```
```



### 答题
``` C++
void dfs(vector<vector<int>> &grid, size_t x, size_t y, int &ans)
{
	if (x >= grid.size() || y >= grid[0].size()) return;
	if (grid[x][y] != 1) return;

	grid[x][y] = 2;

	const int dx[4] = { 1,-1,0,0 };
	const int dy[4] = { 0,0,1,-1 };
	for (int i = 0; i < 4; i++)
	{
		size_t tx = x + dx[i];
		size_t ty = y + dy[i];

		ans += (tx >= grid.size());
		ans += (ty >= grid[0].size());
		if (tx >= grid.size() || ty >= grid[0].size()) continue;
		ans += (grid[tx][ty] == 0);

		dfs(grid, tx, ty, ans);
	}
}

int islandPerimeter(vector<vector<int>>& grid) 
{
	int ans = 0;
	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j] == 1)
			{
				dfs(grid, i, j, ans);
				return ans;
			}
		}
	}
	return ans;
}
```




