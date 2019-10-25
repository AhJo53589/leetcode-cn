# `（中等）` [LCP 3.programmable-robot 机器人大冒险](https://leetcode-cn.com/problems/programmable-robot/)

[contest](https://leetcode-cn.com/contest/season/2019-fall/problems/programmable-robot/)

### 题目描述
<p>力扣团队买了一个可编程机器人，机器人初始位置在原点<code>(0, 0)</code>。小伙伴事先给机器人输入一串指令<code>command</code>，机器人就会<strong>无限循环</strong>这条指令的步骤进行移动。指令有两种：</p>
<ol>
	<li><code>U</code>: 向<code>y</code>轴正方向移动一格</li>
	<li><code>R</code>: 向<code>x</code>轴正方向移动一格。</li>
</ol>

<p>不幸的是，在 xy 平面上还有一些障碍物，他们的坐标用<code>obstacles</code>表示。机器人一旦碰到障碍物就会被<strong>损毁</strong>。</p>
<p>给定终点坐标<code>(x, y)</code>，返回机器人能否<strong>完好</strong>地到达终点。如果能，返回<code>true</code>；否则返回<code>false</code>。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong>command = "URR", obstacles = [], x = 3, y = 2
<strong>输出：</strong>true
<strong>解释：</strong>U(0, 1) -&gt; R(1, 1) -&gt; R(2, 1) -&gt; U(2, 2) -&gt; R(3, 2)。</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>command = "URR", obstacles = [[2, 2]], x = 3, y = 2
<strong>输出：</strong>false
<strong>解释：</strong>机器人在到达终点前会碰到(2, 2)的障碍物。</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>command = "URR", obstacles = [[4, 2]], x = 3, y = 2
<strong>输出：</strong>true
<strong>解释：</strong>到达终点后，再碰到障碍物也不影响返回结果。</pre>

<p>&nbsp;</p>
<p><strong>限制：</strong></p>
<ol>
	<li><code>2 &lt;= command的长度 &lt;= 1000</code></li>
	<li><code>command</code>由<code>U，R</code>构成，且至少有一个<code>U</code>，至少有一个<code>R</code></li>
	<li><code>0 &lt;= x &lt;= 1e9, 0 &lt;= y &lt;= 1e9</code></li>
	<li><code>0 &lt;= obstacles的长度 &lt;= 1000</code></li>
	<li><code>obstacles[i]</code>不为原点或者终点</li>
</ol>

---
### 思路
```

```



### 答题
``` C++
bool robot(string command, vector<vector<int>>& obstacles, int x, int y)
{
	vector<vector<int>> ob2(obstacles.begin(), obstacles.end());
	sort(obstacles.begin(), obstacles.end(), [](const vector<int>& a, const vector<int>& b)
	{
		return a[0] < b[0];
	});
	sort(ob2.begin(), ob2.end(), [](const vector<int>& a, const vector<int>& b)
	{
		return a[1] < b[1];
	});

	size_t i_x = 0;
	size_t i_y = 0;

	vector<int> pos(2, 0);
	while (true)
	{
		for (auto &c : command)
		{
			if (pos[0] == x && pos[1] == y) return true;
			if (pos[0] > x || pos[1] > y) return false;

			if (c == 'R')
			{
				pos[0]++;
				if (obstacles.size() == 0) continue;
				while (i_x < obstacles.size() && obstacles[i_x][0] < pos[0]) i_x++;
				while (i_x < obstacles.size() && obstacles[i_x][0] == pos[0])
				{
					if (obstacles[i_x][1] == pos[1]) return false;
					i_x++;
				}
			}
			else if (c == 'U')
			{
				pos[1]++;
				if (ob2.size() == 0) continue;
				while (i_y < ob2.size() && ob2[i_y][1] < pos[1]) i_y++;
				while (i_y < ob2.size() && ob2[i_y][1] == pos[1])
				{
					if (ob2[i_y][0] == pos[0]) return false;
					i_y++;
				}
			}
		}
	}
	return false;
}
```


### 其它
``` C++
bool robot(string command, vector<vector<int>>& obstacles, int x, int y) 
{
	int a = 0, b = 0, u = 0, v = 0;
	for (auto i : command)
	{
		if (i == 'R')
			a++;
		else 
			b++;
	}

	bool c = false;
	for (auto i : command)
	{
		for (auto j : obstacles)
		{
			if (j[0] <= x && j[1] <= y
				&& (j[0] - u) % a == 0
				&& (j[1] - v) % b == 0
				&& (j[0] - u) / a == (j[1] - v) / b)
			{
				return false;
			}
		}
		if ((x - u) % a == 0
			&& (y - v) % b == 0
			&& (x - u) / a == (y - v) / b)
		{
			c = true;
		}

		if (i == 'R')
		{
			u++;
		}
		else
		{
			v++;
		}
	}
	return c;
}
```


