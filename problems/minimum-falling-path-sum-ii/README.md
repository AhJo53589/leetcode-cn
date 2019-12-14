# `（困难）` [5129.minimum-falling-path-sum-ii 下降路径最小和 II](https://leetcode-cn.com/problems/minimum-falling-path-sum-ii/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-15/problems/minimum-falling-path-sum-ii/)

### 题目描述
<p>给你一个整数方阵&nbsp;<code>arr</code>&nbsp;，定义「非零偏移下降路径」为：从&nbsp;<code>arr</code> 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。</p>

<p>请你返回非零偏移下降路径数字和的最小值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>13
<strong>解释：</strong>
所有非零偏移下降路径包括：
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
下降路径中数字和最小的是&nbsp;[1,5,7] ，所以答案是&nbsp;13 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length == arr[i].length &lt;= 200</code></li>
	<li><code>-99 &lt;= arr[i][j] &lt;= 99</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
int minFallingPathSum(vector<vector<int>>& arr) 
{
	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		size_t min1 = arr[i][0] < arr[i][1] ? 0 : 1;
		size_t min2 = arr[i][0] < arr[i][1] ? 1 : 0;
		for (size_t j = 2; j < arr[0].size(); j++)
		{
			if (arr[i][min1] > arr[i][j])
			{
				min2 = min1;
				min1 = j;
			}
			else if (arr[i][min2] > arr[i][j])
			{
				min2 = j;
			}
		}
		for (size_t j = 0; j < arr[0].size(); j++)
		{
			if (j == min1)
			{
				arr[i + 1][j] += arr[i][min2];
			}
			else
			{
				arr[i + 1][j] += arr[i][min1];
			}
		}
	}

	int ans = INT_MAX;
	for (size_t j = 0; j < arr[0].size(); j++)
	{
		ans = min(ans, arr[arr.size() - 1][j]);
	}
	return ans;
}
```




