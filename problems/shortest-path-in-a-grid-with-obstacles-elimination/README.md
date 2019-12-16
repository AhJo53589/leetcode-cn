# `（困难）` [1293.shortest-path-in-a-grid-with-obstacles-elimination 网格中的最短路径](https://leetcode-cn.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/)

[contest](https://leetcode-cn.com/contest/weekly-contest-167/problems/shortest-path-in-a-grid-with-obstacles-elimination/)

### 题目描述
<p>给你一个&nbsp;<code>m * n</code>&nbsp;的网格，其中每个单元格不是&nbsp;<code>0</code>（空）就是&nbsp;<code>1</code>（障碍物）。每一步，您都可以在空白单元格中上、下、左、右移动。</p>

<p>如果您 <strong>最多</strong> 可以消除 <code>k</code> 个障碍物，请找出从左上角 <code>(0, 0)</code> 到右下角 <code>(m-1, n-1)</code> 的最短路径，并返回通过该路径所需的步数。如果找不到这样的路径，则返回 -1。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong> 
grid = 
[[0,0,0],
&nbsp;[1,1,0],
 [0,0,0],
&nbsp;[0,1,1],
 [0,0,0]], 
k = 1
<strong>输出：</strong>6
<strong>解释：
</strong>不消除任何障碍的最短路径是 10。
消除位置 (3,2) 处的障碍后，最短路径是 6 。该路径是 <code>(0,0) -&gt; (0,1) -&gt; (0,2) -&gt; (1,2) -&gt; (2,2) -&gt; <strong>(3,2)</strong> -&gt; (4,2)</code>.
</pre>

<p>&nbsp;</p>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>
grid = 
[[0,1,1],
&nbsp;[1,1,1],
&nbsp;[1,0,0]], 
k = 1
<strong>输出：</strong>-1
<strong>解释：
</strong>我们至少需要消除两个障碍才能找到这样的路径。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>grid.length&nbsp;== m</code></li>
	<li><code>grid[0].length&nbsp;== n</code></li>
	<li><code>1 &lt;= m, n &lt;= 40</code></li>
	<li><code>1 &lt;= k &lt;= m*n</code></li>
	<li><code>grid[i][j] == 0 <strong>or</strong> 1</code></li>
	<li><code>grid[0][0] == grid[m-1][n-1] == 0</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
int shortestPath(vector<vector<int>>& grid, int k)
{
	vector<vector<int>> dd = { {0,1},{1,0},{0,-1},{-1,0} };
	int m = grid.size();
	int n = grid[0].size();

	vector<vector<vector<bool>>> vi(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
	queue<vector<int>> que;
	que.push({ 0,0,k,0 });
	vi[0][0][k] = true;

	while (!que.empty())
	{
		auto q = que.front();
		que.pop();
		if (q[0] == m - 1 && q[1] == n - 1) return q[3];

		for (auto d : dd)
		{
			int dx = q[0] + d[0];
			int dy = q[1] + d[1];
			if (dx < 0 || dx >= grid.size()) continue;
			if (dy < 0 || dy >= grid[0].size()) continue;

			int r = q[2] - grid[dx][dy];
			if (r < 0) continue;

			if (vi[dx][dy][r]) continue;
			vi[dx][dy][r] = true;

			que.push({ dx, dy, r, q[3] + 1 });
		}
	}
	return -1;
}
```




