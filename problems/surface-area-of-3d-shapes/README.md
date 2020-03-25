# `（简单）` [892.surface-area-of-3d-shapes 三维形体的表面积](https://leetcode-cn.com/problems/surface-area-of-3d-shapes/)

### 题目描述
<p>在&nbsp;<code>N&nbsp;*&nbsp;N</code>&nbsp;的网格上，我们放置一些&nbsp;<code>1 * 1 * 1&nbsp;</code>&nbsp;的立方体。</p>

<p>每个值&nbsp;<code>v = grid[i][j]</code>&nbsp;表示&nbsp;<code>v</code>&nbsp;个正方体叠放在对应单元格&nbsp;<code>(i, j)</code>&nbsp;上。</p>

<p>请你返回最终形体的表面积。</p>

<p>&nbsp;</p>

<ul>
</ul>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[[2]]
<strong>输出：</strong>10
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[[1,2],[3,4]]
<strong>输出：</strong>34
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>[[1,0],[0,2]]
<strong>输出：</strong>16
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>[[1,1,1],[1,0,1],[1,1,1]]
<strong>输出：</strong>32
</pre>

<p><strong>示例&nbsp;5：</strong></p>

<pre><strong>输入：</strong>[[2,2,2],[2,1,2],[2,2,2]]
<strong>输出：</strong>46
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= N <= 50</code></li>
	<li><code>0 <= grid[i][j] <= 50</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
int surfaceArea(vector<vector<int>>& grid)
{
    vector<vector<int>> dd = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            for (auto& d : dd)
            {
                int di = i + d[0];
                int dj = j + d[1];
                if (di < 0 || di >= grid.size() || dj < 0 || dj >= grid[0].size())
                {
                    ans += grid[i][j];
                }
                else
                {
                    ans += max(grid[i][j] - grid[di][dj], 0);
                }
            }
            ans += 2 * (grid[i][j] > 0);
        }
    }
    return ans;
}
```




