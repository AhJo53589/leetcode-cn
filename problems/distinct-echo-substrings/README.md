# `（困难）` [1316.distinct-echo-substrings 不同的循环子字符串](https://leetcode-cn.com/problems/distinct-echo-substrings/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-17/problems/distinct-echo-substrings/)

### 题目描述
<p>给你一个字符串&nbsp;<code>text</code> ，请你返回满足下述条件的&nbsp;<strong>不同</strong> 非空子字符串的数目：</p>

<ul>
	<li>可以写成某个字符串与其自身相连接的形式。</li>
</ul>

<p>例如，<code>abcabc</code>&nbsp;就是&nbsp;<code>abc</code>&nbsp;和它自身连接形成的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>text = "abcabcabc"
<strong>输出：</strong>3
<strong>解释：</strong>3 个子字符串分别为 "abcabc" ， "bcabca" 和 "cabcab" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>text = "leetcodeleetcode"
<strong>输出：</strong>2
<strong>解释：</strong>2 个子字符串为 "ee" 和 "leetcodeleetcode" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 2000</code></li>
	<li><code>text</code>&nbsp;只包含小写英文字母。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/distinct-echo-substrings/solution/5146-by-ikaruga/)

### 答题
``` C++
int distinctEchoSubstrings(string text)
{
	unordered_set<string> ans;
	const char* t = text.c_str();
	for (size_t i = 0; i < text.size(); i++)
	{
		for (size_t j = 1; i + 2 * j <= text.size(); j++)
		{
			if (memcmp(t + i, t + i + j, j) == 0)
			{
				ans.insert(text.substr(i, j));
			}
		}
	}
	return (int)ans.size();
}
```




