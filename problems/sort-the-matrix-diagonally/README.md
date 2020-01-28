# `（中等）` [1329.sort-the-matrix-diagonally 将矩阵按对角线排序](https://leetcode-cn.com/problems/sort-the-matrix-diagonally/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-18/problems/sort-the-matrix-diagonally/)

### 题目描述
<p>给你一个&nbsp;<code>m * n</code>&nbsp;的整数矩阵&nbsp;<code>mat</code>&nbsp;，请你将同一条对角线上的元素（从左上到右下）按升序排序后，返回排好序的矩阵。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<p><img alt="" src="./1482_example_1_2.png" style="height: 198px; width: 500px;"></p>
<pre><strong>输入：</strong>mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
<strong>输出：</strong>[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>m ==&nbsp;mat.length</code></li>
	<li><code>n ==&nbsp;mat[i].length</code></li>
	<li><code>1 &lt;= m, n&nbsp;&lt;= 100</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 100</code></li>
</ul>

​            

---
### 思路
```

```



### 答题
``` C++
vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
{
	vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));

	int m = mat.size();
	int n = mat[0].size();
	for (int x = 0; x < m + n - 1; x++)
	{
		int ti = (x < m) ? m - 1 - x : 0;
		int tj = (x < m) ? 0 : x - (m - 1);
		vector<int> temp;
		while (ti < m && tj < n)
		{
			temp.push_back(mat[ti++][tj++]);
		}
		sort(temp.begin(), temp.end());

		ti = (x < m) ? m - 1 - x : 0;
		tj = (x < m) ? 0 : x - (m - 1);
		int i = 0;
		while (ti < m && tj < n)
		{
			ans[ti++][tj++] = temp[i++];
		}
	}
	return ans;
}
```




