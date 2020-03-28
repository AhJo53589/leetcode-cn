# `（中等）` [1162.as-far-from-land-as-possible 地图分析](https://leetcode-cn.com/problems/as-far-from-land-as-possible/)

### 题目描述
<p>你现在手里有一份大小为&nbsp;N x N 的『地图』（网格）&nbsp;<code>grid</code>，上面的每个『区域』（单元格）都用&nbsp;<code>0</code>&nbsp;和&nbsp;<code>1</code>&nbsp;标记好了。其中&nbsp;<code>0</code>&nbsp;代表海洋，<code>1</code>&nbsp;代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。</p>

<p>我们这里说的距离是『曼哈顿距离』（&nbsp;Manhattan Distance）：<code>(x0, y0)</code> 和&nbsp;<code>(x1, y1)</code>&nbsp;这两个区域之间的距离是&nbsp;<code>|x0 - x1| + |y0 - y1|</code>&nbsp;。</p>

<p>如果我们的地图上只有陆地或者海洋，请返回&nbsp;<code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="height: 87px; width: 185px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/08/17/1336_ex1.jpeg" alt=""></strong></p>

<pre><strong>输入：</strong>[[1,0,1],[0,0,0],[1,0,1]]
<strong>输出：</strong>2
<strong>解释： </strong>
海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img style="height: 87px; width: 184px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/08/17/1336_ex2.jpeg" alt=""></strong></p>

<pre><strong>输入：</strong>[[1,0,0],[0,0,0],[0,0,0]]
<strong>输出：</strong>4
<strong>解释： </strong>
海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= grid.length == grid[0].length&nbsp;<= 100</code></li>
	<li><code>grid[i][j]</code>&nbsp;不是&nbsp;<code>0</code>&nbsp;就是&nbsp;<code>1</code></li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/as-far-from-land-as-possible-by-ikaruga/)

### 答题
``` C++
int maxDistance(vector<vector<int>>& grid)
{
    queue<pair<int, int>> que;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0) continue;
            que.push({ i,j });
        }
    }
    if (que.empty() || que.size() == grid.size() * grid[0].size()) return -1;

    int ans = 0;
    vector<vector<int>> dd = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    while (!que.empty())
    {
        auto q = que.front();
        que.pop();
        ans = grid[q.first][q.second];

        for (auto d : dd)
        {
            int dx = q.first + d[0];
            int dy = q.second + d[1];
            if (dx < 0 || dx >= grid.size()) continue;
            if (dy < 0 || dy >= grid[0].size()) continue;
            if (grid[dx][dy] != 0) continue;
            grid[dx][dy] = ans + 1;
            que.push({ dx, dy });
        }
    }
    return ans - 1;
}
```




