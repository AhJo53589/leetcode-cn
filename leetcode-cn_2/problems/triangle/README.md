# `（中等）` [120.triangle 三角形最小路径和](https://leetcode-cn.com/problems/triangle/)

### 题目描述
<p>给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。</p>

<p>例如，给定三角形：</p>

<pre>[
     [<strong>2</strong>],
    [<strong>3</strong>,4],
   [6,<strong>5</strong>,7],
  [4,<strong>1</strong>,8,3]
]
</pre>

<p>自顶向下的最小路径和为&nbsp;<code>11</code>（即，<strong>2&nbsp;</strong>+&nbsp;<strong>3</strong>&nbsp;+&nbsp;<strong>5&nbsp;</strong>+&nbsp;<strong>1</strong>&nbsp;= 11）。</p>

<p><strong>说明：</strong></p>

<p>如果你可以只使用 <em>O</em>(<em>n</em>)&nbsp;的额外空间（<em>n</em> 为三角形的总行数）来解决这个问题，那么你的算法会很加分。</p>


---
### 思路
```
动态规划，从底向上不断选择最小的分支。

vector初始化的时候注意一下可以提高一些时间。
```

### 答题
``` C++
int minimumTotal(vector<vector<int>>& triangle) 
{
	if (triangle.empty()) return 0;
	vector<int> dp(triangle.back().begin(), triangle.back().end());

	for (int i = triangle.size() - 2; i >= 0; i--)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
		}
	}
	return dp[0];
}
```


