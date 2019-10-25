# `（中等）` [1230.toss-strange-coins 抛掷硬币](https://leetcode-cn.com/problems/toss-strange-coins/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-11/problems/toss-strange-coins/)

### 题目描述
<p>有一些不规则的硬币。在这些硬币中，<code>prob[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;枚硬币正面朝上的概率。</p>

<p>请对每一枚硬币抛掷&nbsp;<strong>一次</strong>，然后返回正面朝上的硬币数等于&nbsp;<code>target</code>&nbsp;的概率。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>prob = [0.4], target = 1
<strong>输出：</strong>0.40000
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>prob = [0.5,0.5,0.5,0.5,0.5], target = 0
<strong>输出：</strong>0.03125
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prob.length &lt;= 1000</code></li>
	<li><code>0 &lt;= prob[i] &lt;= 1</code></li>
	<li><code>0 &lt;= target&nbsp;</code><code>&lt;= prob.length</code></li>
	<li>如果答案与标准答案的误差在&nbsp;<code>10^-5</code>&nbsp;内，则被视为正确答案。</li>
</ul>

---
### 思路
```
```



### 答题
``` C++
double probabilityOfHeads(vector<double>& prob, int target)
{
	int N = prob.size();
	vector<vector<double>> dp(N, vector<double>(target + 2));
	dp[0][0] = 1 - prob[0];
	dp[0][1] = prob[0];
	for (int i = 1; i < N; i++) 
	{
		dp[i][0] = dp[i - 1][0] * (1 - prob[i]);
		for (int j = 1; j <= target; j++) 
		{
			dp[i][j] = dp[i - 1][j] * (1 - prob[i]) + dp[i - 1][j - 1] * prob[i];
		}
	}

	return dp[N - 1][target];
}
```


### 其它
``` C++
double probabilityOfHeads(vector<double>& prob, int target) {
	int len = prob.size();
	vector<double> res(target+1, 0);
	// 初试，掷出 0 的概率为 1
	res[0] = 1.0;
	for (int i = 1; i <= len; i++)
		// 倒着更新，省一维空间
		for (int j = min(i, target); j >= 0; j--)
			// 当前掷出 j 个    当前掷出的为反面 * 上次掷出了 j 个    当前掷出的为正面 * 上次掷出了 j - 1 个
			res[j] = res[j] * (1 - prob[i-1]) + (j > 0 ? res[j-1] * prob[i-1] : 0);
	
	return res[target];
}
```


