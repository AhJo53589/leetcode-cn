# `（中等）` [5144.matrix-block-sum 矩阵区域和](https://leetcode-cn.com/problems/matrix-block-sum/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-17/problems/matrix-block-sum/)

### 题目描述
<p>给你一个&nbsp;<code>m * n</code>&nbsp;的矩阵&nbsp;<code>mat</code>&nbsp;和一个整数&nbsp;<code>K</code> ，请你返回一个矩阵&nbsp;<code>answer</code>&nbsp;，其中每个&nbsp;<code>answer[i][j]</code>&nbsp;是所有满足下述条件的元素&nbsp;<code>mat[r][c]</code> 的和：&nbsp;</p>

<ul>
	<li><code>i - K &lt;= r &lt;= i + K, j - K &lt;= c &lt;= j + K</code>&nbsp;</li>
	<li><code>(r, c)</code>&nbsp;在矩阵内。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
<strong>输出：</strong>[[12,21,16],[27,45,33],[24,39,28]]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
<strong>输出：</strong>[[45,45,45],[45,45,45],[45,45,45]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m ==&nbsp;mat.length</code></li>
	<li><code>n ==&nbsp;mat[i].length</code></li>
	<li><code>1 &lt;= m, n, K &lt;= 100</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 100</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) 
{
	vector<vector<int>> ans(mat);
	vector<vector<int>> _m(mat);
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 1; j < mat[0].size(); j++)
		{
			_m[i][j] += _m[i][j - 1];
		}
	}

	int m = mat.size();
	int n = mat[0].size();
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[0].size(); j++)
		{
			int m1 = max(i - K, 0);
			int m2 = min(i + K, m - 1);
			int n1 = j - K - 1;
			int n2 = j + K;
			ans[i][j] = 0;
			for (int ii = m1; ii <= m2; ii++)
			{
				ans[i][j] += (n2 < n) ? _m[ii][n2] : _m[ii][n - 1];
				ans[i][j] -= (n1 >= 0) ? _m[ii][n1] : 0;
			}
		}
	}
	return ans;
}
```




