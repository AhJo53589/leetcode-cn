# `（简单）` [1351.count-negative-numbers-in-a-sorted-matrix 统计有序矩阵中的负数](https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix/)

[contest](https://leetcode-cn.com/contest/weekly-contest-176/problems/count-negative-numbers-in-a-sorted-matrix/)

### 题目描述
<p>给你一个&nbsp;<code>m&nbsp;* n</code>&nbsp;的矩阵&nbsp;<code>grid</code>，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。&nbsp;</p>

<p>请你统计并返回&nbsp;<code>grid</code>&nbsp;中 <strong>负数</strong> 的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
<strong>输出：</strong>8
<strong>解释：</strong>矩阵中共有 8 个负数。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>grid = [[3,2],[1,0]]
<strong>输出：</strong>0
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>grid = [[1,-1],[-1,-1]]
<strong>输出：</strong>3
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>grid = [[-1]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>-100 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
int countNegatives(vector<vector<int>>& grid) 
{
    int ans = 0;
    for (auto i = 0; i < grid.size(); i++)
    {
        for (auto j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] >= 0) continue;
            ans += (grid[i].size() - j);
            break;
        }
    }
    return ans;
}
```




