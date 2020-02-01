# `（困难）` [1335.minimum-difficulty-of-a-job-schedule 工作计划的最低难度](https://leetcode-cn.com/problems/minimum-difficulty-of-a-job-schedule/)

[contest](https://leetcode-cn.com/contest/weekly-contest-173/problems/minimum-difficulty-of-a-job-schedule/)

### 题目描述
<p>你需要制定一份&nbsp;<code>d</code>&nbsp;天的工作计划表。工作之间存在依赖，要想执行第&nbsp;<code>i</code>&nbsp;项工作，你必须完成全部&nbsp;<code>j</code>&nbsp;项工作（&nbsp;<code>0 &lt;= j &lt; i</code>）。</p>
<p>你每天 <strong>至少</strong>&nbsp;需要完成一项任务。工作计划的总难度是这&nbsp;<code>d</code>&nbsp;天每一天的难度之和，而一天的工作难度是当天应该完成工作的最大难度。</p>
<p>给你一个整数数组&nbsp;<code>jobDifficulty</code>&nbsp;和一个整数&nbsp;<code>d</code>，分别代表工作难度和需要计划的天数。第&nbsp;<code>i</code>&nbsp;项工作的难度是&nbsp;<code>jobDifficulty[i]</code>。</p>
<p>返回整个工作计划的最低难度。如果无法制定作业计划，则返回&nbsp;<strong>-1&nbsp;</strong>。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<p><img alt="" src="./untitled.png" style="height: 230px; width: 365px;"></p>
<pre><strong>输入：</strong>jobDifficulty = [6,5,4,3,2,1], d = 2
<strong>输出：</strong>7
<strong>解释：</strong>第一天，您可以完成前 5 项工作，总难度 = 6.
第二天，您可以完成最后一项工作，总难度 = 1.
计划表的难度 = 6 + 1 = 7 
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>jobDifficulty = [9,9,9], d = 4
<strong>输出：</strong>-1
<strong>解释：</strong>就算你每天完成一项工作，仍然有一天是空闲的，你无法制定一份能够满足既定工作时间的计划表。
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>jobDifficulty = [1,1,1], d = 3
<strong>输出：</strong>3
<strong>解释：</strong>工作计划为每天一项工作，总难度为 3 。
</pre>

<p><strong>示例 4：</strong></p>
<pre><strong>输入：</strong>jobDifficulty = [7,1,7,1,7,1], d = 3
<strong>输出：</strong>15
</pre>

<p><strong>示例 5：</strong></p>
<pre><strong>输入：</strong>jobDifficulty = [11,111,22,222,33,333,44,444], d = 6
<strong>输出：</strong>843
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>1 &lt;= jobDifficulty.length &lt;= 300</code></li>
	<li><code>0 &lt;=&nbsp;jobDifficulty[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= d &lt;= 10</code></li>
</ul>

​            

---
### 思路
```

```



### 答题
``` C++
int minDifficulty(vector<int>& jobDifficulty, int d)
{
	int n = jobDifficulty.size();
	vector<vector<int>> dp(d + 1, vector<int>(n + 1, INT_MAX));
	dp[0][0] = 0;

	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int mx = 0;
			for (int k = j - 1; k >= 0; k--)
			{
				mx = max(mx, jobDifficulty[k]);
				if (dp[i - 1][k] == INT_MAX) continue;
				dp[i][j] = min(dp[i][j], mx + dp[i - 1][k]);
			}
		}
	}

	return (dp[d][n] == INT_MAX) ? -1 : dp[d][n];
}
```




