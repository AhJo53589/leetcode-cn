# `（困难）` [1312.minimum-insertion-steps-to-make-a-string-palindrome 让字符串成为回文串的最少插入次数](https://leetcode-cn.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)

[contest](https://leetcode-cn.com/contest/weekly-contest-170/problems/minimum-insertion-steps-to-make-a-string-palindrome/)

### 题目描述
<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，每一次操作你都可以在字符串的任意位置插入任意字符。</p>
<p>请你返回让&nbsp;<code>s</code>&nbsp;成为回文串的&nbsp;<strong>最少操作次数</strong>&nbsp;。</p>
<p>「回文串」是正读和反读都相同的字符串。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong>s = "zzazz"
<strong>输出：</strong>0
<strong>解释：</strong>字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>s = "mbadm"
<strong>输出：</strong>2
<strong>解释：</strong>字符串可变为 "mbdadbm" 或者 "mdbabdm" 。
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>s = "leetcode"
<strong>输出：</strong>5
<strong>解释：</strong>插入 5 个字符后字符串变为 "leetcodocteel" 。
</pre>

<p><strong>示例 4：</strong></p>
<pre><strong>输入：</strong>s = "g"
<strong>输出：</strong>0
</pre>

<p><strong>示例 5：</strong></p>
<pre><strong>输入：</strong>s = "no"
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code>&nbsp;中所有字符都是小写字母。</li>
</ul>

---
### 思路
```

```



### 答题
``` C++
int minInsertions(string s) 
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
	return s.size() - dp[0].back();
}
```




