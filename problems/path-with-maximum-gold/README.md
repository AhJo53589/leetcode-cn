# `（中等）` [1219.path-with-maximum-gold 黄金矿工](https://leetcode-cn.com/problems/path-with-maximum-gold/)

[contest](https://leetcode-cn.com/contest/weekly-contest-157/problems/path-with-maximum-gold/)

### 题目描述

<p>你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为&nbsp;<code>m * n</code> 的网格 <code>grid</code> 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 <code>0</code>。</p>
<p>为了使收益最大化，矿工需要按以下规则来开采黄金：</p>
<ul>
	<li>每当矿工进入一个单元，就会收集该单元格中的所有黄金。</li>
	<li>矿工每次可以从当前位置向上下左右四个方向走。</li>
	<li>每个单元格只能被开采（进入）一次。</li>
	<li><strong>不得开采</strong>（进入）黄金数目为 <code>0</code> 的单元格。</li>
	<li>矿工可以从网格中 <strong>任意一个</strong> 有黄金的单元格出发或者是停止。</li>
</ul>

<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong>grid = [[0,6,0],[5,8,7],[0,9,0]]
<strong>输出：</strong>24
<strong>解释：</strong>
[[0,6,0],
 [5,8,7],
 [0,9,0]]
一种收集最多黄金的路线是：9 -&gt; 8 -&gt; 7。
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
<strong>输出：</strong>28
<strong>解释：</strong>
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
一种收集最多黄金的路线是：1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 5 -&gt; 6 -&gt; 7。
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>1 &lt;= grid.length,&nbsp;grid[i].length &lt;= 15</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
	<li>最多 <strong>25 </strong>个单元格中有黄金。</li>
</ul>

---
### 思路
```

```

[发布的题解](https://leetcode-cn.com/problems/path-with-maximum-gold/solution/1219-by-ikaruga/)

### 答题
``` C++
int getNextNum(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& dd, vector<vector<int>>& m)
{
	int i = 0;	
	int flag = 0;
	for (auto& d : dd)
	{
		int dx = x + d[0];
		int dy = y + d[1];
		if (dx < 0 || dx >= grid.size()) continue;
		if (dy < 0 || dy >= grid[0].size()) continue;
		if (grid[dx][dy] == 0) continue;

		i += 1;
		flag += d[0] + d[1];
	}
	if (flag == 2)	// 记录拐角结点
	{
		m.push_back({ x, y });
	}
	return i;
}

void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& dd, vector<vector<int>>& vi, int gain, int &ans)
{
	gain += grid[x][y];
	ans = max(ans, gain);
	for (auto &d : dd)
	{
		int dx = x + d[0];
		int dy = y + d[1];
		if (dx < 0 || dx >= grid.size()) continue;
		if (dy < 0 || dy >= grid[0].size()) continue;
		if (grid[dx][dy] == 0) continue;
		if (vi[dx][dy] == 1) continue;
		vi[dx][dy] = 1;	// 回溯
		dfs(grid, dx, dy, dd, vi, gain, ans);
		vi[dx][dy] = 0;
	}
}

int getMaximumGold(vector<vector<int>>& grid) 
{
	vector<vector<int>> dd = { {0,1},{0,-1},{1,0},{-1,0} };
	vector<vector<int>> vi(grid.size(), vector<int>(grid[0].size(), 0));

	vector<vector<int>> m;
	int ans = 0;
	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j] == 0) continue;
			int nextNum = getNextNum(grid, i, j, dd, m);
			if (nextNum == 0)
			{
				ans = max(ans, grid[i][j]);
				continue;
			}

			if (nextNum > 1) continue;
			// 处理突出结点
			vi[i][j] = 1;	// 永久
			dfs(grid, i, j, dd, vi, 0, ans);
		}
	}
    if (!m.empty())	// 处理拐角结点
	{
		for (auto &v : m)
		{
			int i = v[0];
			int j = v[1];
			vi[i][j] = 1;	// 回溯
			dfs(grid, i, j, dd, vi, 0, ans);
			vi[i][j] = 0;	// 回溯
		}
    }
	return ans;
}
```




