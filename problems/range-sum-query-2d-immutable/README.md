# `（中等）` [304.range-sum-query-2d-immutable 二维区域和检索 - 矩阵不可变](https://leetcode-cn.com/problems/range-sum-query-2d-immutable/submissions/)

### 题目描述
<p>给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (<em>row</em>1,&nbsp;<em>col</em>1) ，右下角为 (<em>row</em>2,&nbsp;<em>col</em>2)。</p>
<p><img style="width: 130px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/images/304.png" alt="Range Sum Query 2D"><br>
<small>上图子矩阵左上角&nbsp;(row1, col1) = <strong>(2, 1)</strong>&nbsp;，右下角(row2, col2) = <strong>(4, 3)，</strong>该子矩形内元素的总和为 8。</small></p>

<p><strong>示例:</strong></p>
<pre>给定 matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -&gt; 8
sumRegion(1, 1, 2, 2) -&gt; 11
sumRegion(1, 2, 2, 4) -&gt; 12
</pre>

<p><strong>说明:</strong></p>
<ol>
	<li>你可以假设矩阵不可变。</li>
	<li>会多次调用&nbsp;<em>sumRegion&nbsp;</em>方法<em>。</em></li>
	<li>你可以假设&nbsp;<em>row</em>1 ≤ <em>row</em>2 且&nbsp;<em>col</em>1 ≤ <em>col</em>2。</li>
</ol>

---
### 思路
```
使用dp存储矩阵的和，比如dp[3][4]代表前3行，前4列的和
（为了更好处理数组越界，实际代码在矩阵前各加了空一行空一列，所以代表的是前2行，前3列的和）
求和时只需使用公式，如下图。
A|B|C
D|E|F
G|H|I
[E-I] = [A-I] - [A-C] - [A-G] + [A-A]
```



### 答题
``` C++
class NumMatrix
{
public:
	NumMatrix(vector<vector<int>>& matrix) : dp(matrix.size() + 1, vector<int>())
	{
        if (matrix.empty()) return;

		for (size_t i = 0; i < dp.size(); i++)
		{
			dp[i].resize(matrix[0].size() + 1);
		}

		dp[1][1] = matrix[0][0];
		for (size_t i = 1; i < matrix[0].size(); i++)
		{
			dp[1][i + 1] = matrix[0][i] + dp[1][i];
		}
		for (size_t i = 1; i < matrix.size(); i++)
		{
			dp[i + 1][1] = matrix[i][0] + dp[i][1];
		}
		for (size_t i = 1; i < matrix.size(); i++)
		{
			for (size_t j = 1; j < matrix[i].size(); j++)
			{
				dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
	}
	vector<vector<int>> dp;
};
```




