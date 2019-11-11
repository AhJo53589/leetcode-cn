# `（简单）` [5255.cells-with-odd-values-in-a-matrix 奇数值单元格的数目](https://leetcode-cn.com/problems/cells-with-odd-values-in-a-matrix/)

[contest](https://leetcode-cn.com/contest/weekly-contest-162/problems/cells-with-odd-values-in-a-matrix/)

### 题目描述
<p>给你一个&nbsp;<code>n</code>&nbsp;行&nbsp;<code>m</code>&nbsp;列的矩阵，最开始的时候，每个单元格中的值都是 <code>0</code>。</p>

<p>另有一个索引数组&nbsp;<code>indices</code>，<code>indices[i] = [ri, ci]</code>&nbsp;中的&nbsp;<code>ri</code> 和 <code>ci</code> 分别表示指定的行和列（从 <code>0</code> 开始编号）。</p>

<p>你需要将每对&nbsp;<code>[ri, ci]</code>&nbsp;指定的行和列上的所有单元格的值加 <code>1</code>。</p>

<p>请你在执行完所有&nbsp;<code>indices</code>&nbsp;指定的增量操作后，返回矩阵中 「奇数值单元格」 的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/06/e1.png" style="height: 118px; width: 600px;"></p>

<pre><strong>输入：</strong>n = 2, m = 3, indices = [[0,1],[1,1]]
<strong>输出：</strong>6
<strong>解释：</strong>最开始的矩阵是 [[0,0,0],[0,0,0]]。
第一次增量操作后得到 [[1,2,1],[0,1,0]]。
最后的矩阵是 [[1,3,1],[1,3,1]]，里面有 6 个奇数。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/06/e2.png" style="height: 150px; width: 600px;"></p>

<pre><strong>输入：</strong>n = 2, m = 2, indices = [[1,1],[0,0]]
<strong>输出：</strong>0
<strong>解释：</strong>最后的矩阵是 [[2,2],[2,2]]，里面没有奇数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= m &lt;= 50</code></li>
	<li><code>1 &lt;= indices.length &lt;= 100</code></li>
	<li><code>0 &lt;= indices[i][0] &lt;&nbsp;n</code></li>
	<li><code>0 &lt;= indices[i][1] &lt;&nbsp;m</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
int oddCells(int n, int m, vector<vector<int>>& indices)
{
    vector<vector<int>> matrix(n, vector<int>());
    for (auto &ma : matrix) ma.resize(m);

    for (auto in : indices)
    {
        for (auto x = 0; x < n; x++)
        {
            matrix[x][in[1]]++;
        }
        for (auto y = 0; y < m; y++)
        {
            matrix[in[0]][y]++;
        }
    }

    int ans = 0;
    for (auto a : matrix)
    {
        for (auto b : a)
        {
            ans += (b & 1);
        }
    }
    return ans;
}
```




