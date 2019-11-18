# `（困难）` [1263.minimum-moves-to-move-a-box-to-their-target-location 推箱子](https://leetcode-cn.com/problems/minimum-moves-to-move-a-box-to-their-target-location/)

[contest](https://leetcode-cn.com/contest/weekly-contest-163/problems/minimum-moves-to-move-a-box-to-their-target-location/)

### 题目描述
<p>「推箱子」是一款风靡全球的益智小游戏，玩家需要将箱子推到仓库中的目标位置。</p>

<p>游戏地图用大小为 <code>n * m</code> 的网格 <code>grid</code> 表示，其中每个元素可以是墙、地板或者是箱子。</p>

<p>现在你将作为玩家参与游戏，按规则将箱子&nbsp;<code>'B'</code>&nbsp;移动到目标位置&nbsp;<code>'T'</code> ：</p>

<ul>
	<li>玩家用字符&nbsp;<code>'S'</code>&nbsp;表示，只要他在地板上，就可以在网格中向上、下、左、右四个方向移动。</li>
	<li>地板用字符&nbsp;<code>'.'</code>&nbsp;表示，意味着可以自由行走。</li>
	<li>墙用字符&nbsp;<code>'#'</code>&nbsp;表示，意味着障碍物，不能通行。&nbsp;</li>
	<li>箱子仅有一个，用字符&nbsp;<code>'B'</code>&nbsp;表示。相应地，网格上有一个目标位置&nbsp;<code>'T'</code>。</li>
	<li>玩家需要站在箱子旁边，然后沿着箱子的方向进行移动，此时箱子会被移动到相邻的地板单元格。记作一次「推动」。</li>
	<li>玩家无法越过箱子。</li>
</ul>

<p>返回将箱子推到目标位置的最小 <strong>推动</strong> 次数，如果无法做到，请返回&nbsp;<code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/16/sample_1_1620.png" style="height: 349px; width: 520px;"></strong></p>

<pre><strong>输入：</strong>grid = [["#","#","#","#","#","#"],
             ["#","T","#","#","#","#"],
&nbsp;            ["#",".",".","B",".","#"],
&nbsp;            ["#",".","#","#",".","#"],
&nbsp;            ["#",".",".",".","S","#"],
&nbsp;            ["#","#","#","#","#","#"]]
<strong>输出：</strong>3
<strong>解释：</strong>我们只需要返回推箱子的次数。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>grid = [["#","#","#","#","#","#"],
             ["#","T","#","#","#","#"],
&nbsp;            ["#",".",".","B",".","#"],
&nbsp;            ["#","#","#","#",".","#"],
&nbsp;            ["#",".",".",".","S","#"],
&nbsp;            ["#","#","#","#","#","#"]]
<strong>输出：</strong>-1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>grid = [["#","#","#","#","#","#"],
&nbsp;            ["#","T",".",".","#","#"],
&nbsp;            ["#",".","#","B",".","#"],
&nbsp;            ["#",".",".",".",".","#"],
&nbsp;            ["#",".",".",".","S","#"],
&nbsp;            ["#","#","#","#","#","#"]]
<strong>输出：</strong>5
<strong>解释：</strong>向下、向左、向左、向上再向上。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>grid = [["#","#","#","#","#","#","#"],
&nbsp;            ["#","S","#",".","B","T","#"],
&nbsp;            ["#","#","#","#","#","#","#"]]
<strong>输出：</strong>-1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length &lt;= 20</code></li>
	<li><code>1 &lt;= grid[i].length &lt;= 20</code></li>
	<li><code>grid</code> 仅包含字符&nbsp;<code>'.'</code>, <code>'#'</code>,&nbsp; <code>'S'</code> , <code>'T'</code>, 以及&nbsp;<code>'B'</code>。</li>
	<li><code>grid</code>&nbsp;中&nbsp;<code>'S'</code>, <code>'B'</code>&nbsp;和&nbsp;<code>'T'</code>&nbsp;各只能出现一个。</li>
</ul>

            

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-moves-to-move-a-box-to-their-target-location/solution/1263-by-ikaruga/)

### 答题
``` C++
int minPushBox(vector<vector<char>>& grid) 
{
	// pq，[0]当前状态最小推箱子次数 [1]人的坐标x [2]人的坐标y [3]箱子的坐标x [4]箱子的坐标y
	priority_queue<vector<size_t>, vector<vector<size_t>>, greater<vector<size_t>>> pq;
	size_t m = grid.size();
	size_t n = grid[0].size();

	vector<size_t> a(5, 0);
	for (size_t x = 0; x < m; x++)
	{
		for (size_t y = 0; y < n; y++)
		{
			if (grid[x][y] == 'S')
			{
				a[1] = x;
				a[2] = y;
				grid[x][y] = '.';
			}
			else if (grid[x][y] == 'B')
			{
				a[3] = x;
				a[4] = y;
				grid[x][y] = '.';
			}
		}
	}
	pq.push(a);

	map<vector<size_t>, size_t> dist;
	dist[{ a[1], a[2], a[3], a[4] }] = 0;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	while (!pq.empty())
	{
		auto v = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			vector<size_t> next_s = { v[1] + dx[i], v[2] + dy[i] };
			if (next_s[0] >= m || next_s[1] >= n || grid[next_s[0]][next_s[1]] == '#')
			{
				continue;
			}
			vector<size_t> next_b = { v[3], v[4] };
			size_t d = v[0];
			if (next_s == next_b)
			{
				next_b[0] += dx[i];
				next_b[1] += dy[i];
				if (next_b[0] >= m || next_b[1] >= n || grid[next_b[0]][next_b[1]] == '#')
				{
					continue;
				}
				d++;
			}
			if (grid[next_b[0]][next_b[1]] == 'T')
			{
				return (int)d;
			}

			if (dist.find({next_s[0], next_s[1], next_b[0], next_b[1]}) != dist.end())
			{
				continue;
			}
			dist[{next_s[0], next_s[1], next_b[0], next_b[1]}] = d;
			pq.push({ d, next_s[0], next_s[1], next_b[0], next_b[1] });
		}
	}
	return -1;
}
```




