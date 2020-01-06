# `（中等）` [516.longest-palindromic-subsequence 最长回文子序列](https://leetcode-cn.com/problems/longest-palindromic-subsequence/)

### 题目描述
<p>给定一个字符串<code>s</code>，找到其中最长的回文子序列。可以假设<code>s</code>的最大长度为<code>1000</code>。</p>

<p><strong>示例 1:</strong><br>
输入:</p>

<pre>"bbbab"
</pre>

<p>输出:</p>

<pre>4
</pre>

<p>一个可能的最长回文子序列为 "bbbb"。</p>

<p><strong>示例 2:</strong><br>
输入:</p>

<pre>"cbbd"
</pre>

<p>输出:</p>

<pre>2
</pre>

<p>一个可能的最长回文子序列为 "bb"。</p>


---
### 思路
```
```



### 答题
``` C++
int longestPalindromeSubseq(string s) 
{
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
	for (size_t i = s.size() - 1; i < s.size(); i--)
	{
		dp[i][i] = 1;
		for (size_t j = i + 1; j < s.size(); j++)
		{
			if (s[i] == s[j])
			{
				dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			else
			{
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[0].back();
}
```




