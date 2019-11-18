# `（简单）` [1260.shift-2d-grid 二维网格迁移](https://leetcode-cn.com/problems/shift-2d-grid/)

[contest](https://leetcode-cn.com/contest/weekly-contest-163/problems/shift-2d-grid/)

### 题目描述
<p>给你一个 <code>n</code> 行 <code>m</code> 列的二维网格&nbsp;<code>grid</code>&nbsp;和一个整数&nbsp;<code>k</code>。你需要将&nbsp;<code>grid</code>&nbsp;迁移&nbsp;<code>k</code>&nbsp;次。</p>

<p>每次「迁移」操作将会引发下述活动：</p>

<ul>
	<li>位于 <code>grid[i][j]</code>&nbsp;的元素将会移动到&nbsp;<code>grid[i][j + 1]</code>。</li>
	<li>位于&nbsp;<code>grid[i][m - 1]</code> 的元素将会移动到&nbsp;<code>grid[i + 1][0]</code>。</li>
	<li>位于 <code>grid[n - 1][m - 1]</code>&nbsp;的元素将会移动到&nbsp;<code>grid[0][0]</code>。</li>
</ul>

<p>请你返回&nbsp;<code>k</code> 次迁移操作后最终得到的 <strong>二维网格</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/16/e1-1.png" style="height: 158px; width: 400px;"></p>

<pre><code><strong>输入：</strong>grid</code> = [[1,2,3],[4,5,6],[7,8,9]], k = 1
<strong>输出：</strong>[[9,1,2],[3,4,5],[6,7,8]]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/16/e2-1.png" style="height: 166px; width: 400px;"></p>

<pre><code><strong>输入：</strong>grid</code> = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
<strong>输出：</strong>[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
</pre>

<p><strong>示例 3：</strong></p>

<pre><code><strong>输入：</strong>grid</code> = [[1,2,3],[4,5,6],[7,8,9]], k = 9
<strong>输出：</strong>[[1,2,3],[4,5,6],[7,8,9]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i].length &lt;= 50</code></li>
	<li><code>-1000 &lt;= grid[i][j] &lt;= 1000</code></li>
	<li><code>0 &lt;= k &lt;= 100</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
{
    if (k-- == 0) return grid;

    vector<vector<int>> t(grid);
    for (int i = 0; i < t.size(); i++)
    {
        for (int j = 1; j < t[0].size(); j++)
        {
            grid[i][j] = t[i][j - 1];
        }
    }
    for (int i = 1; i < t.size(); i++)
    {
        grid[i][0] = t[i - 1][t[0].size() - 1];
    }
    grid[0][0] = t.back().back();

    return shiftGrid(grid, k);
}
```




