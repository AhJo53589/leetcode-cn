# `（中等）` [221.maximal-square 最大正方形](https://leetcode-cn.com/problems/maximal-square/)

### 题目描述
<p>在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入: 
</strong>
1 0 1 0 0
1 0 <strong>1 1</strong> 1
1 1 <strong>1 1 </strong>1
1 0 0 1 0

<strong>输出: </strong>4</pre>


---
### 思路
```
动态规划，更新当前位置作为正方形右下角能够多大。
```

### 答题
``` C++
int maximalSquare(vector<vector<char>>& matrix)
{
	if (matrix.empty()) return 0;
	int res = 0;
	vector<vector<int>> m(matrix.size(), vector<int>{});
	for (auto &_m : m) _m.resize(matrix[0].size());

	for (int i = 0; i < matrix.size(); i++)
	{
		m[i][0] = matrix[i][0] - '0';
		if (m[i][0] == 1) res = 1;
		if (matrix[0].size() == 1 && m[i][0] == 1) return res;
	}
	for (int j = 0; j < matrix[0].size(); j++)
	{
		m[0][j] = matrix[0][j] - '0';
		if (m[0][j] == 1) res = 1;
		if (matrix.size() == 1 && m[0][j] == 1) return res;
	}
	for (int i = 1; i < matrix.size(); i++)
	{
		for (int j = 1; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == '1')
			{
				m[i][j] = min(min(m[i - 1][j], m[i][j - 1]), m[i - 1][j - 1]) + 1;
				res = max(res, m[i][j]);
			}
		}
	}
	return pow(res, 2);
}
```

