# `（中等）` [64.minimum-path-sum 最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)

### 题目描述
<p>给定一个包含非负整数的 <em>m</em>&nbsp;x&nbsp;<em>n</em>&nbsp;网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。</p>

<p><strong>说明：</strong>每次只能向下或者向右移动一步。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>
[
&nbsp; [1,3,1],
  [1,5,1],
  [4,2,1]
]
<strong>输出:</strong> 7
<strong>解释:</strong> 因为路径 1→3→1→1→1 的总和最小。
</pre>


---
### 思路
```
```



### 答题
``` C++
int minPathSum(vector<vector<int>>& grid) 
{
	vector<vector<int>> dp(grid.size(), vector<int>());
	for (auto &p : dp)
	{
		p.resize(grid[0].size());
	}

	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t j = 0; j < grid[i].size(); j++)
		{
			if (i == 0 && j == 0)
			{
				dp[i][j] = grid[i][j];
			}
			else if (i == 0)
			{
				dp[i][j] = dp[i][j - 1] + grid[i][j];
			}
			else if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + grid[i][j];
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}
	}
	return dp.back().back();
}
```




