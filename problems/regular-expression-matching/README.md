# `（困难）` [10.regular-expression-matching 正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/)

### 题目描述
<p>给你一个字符串&nbsp;<code>s</code>&nbsp;和一个字符规律&nbsp;<code>p</code>，请你来实现一个支持 <code>'.'</code>&nbsp;和&nbsp;<code>'*'</code>&nbsp;的正则表达式匹配。</p>

<pre>'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
</pre>

<p>所谓匹配，是要涵盖&nbsp;<strong>整个&nbsp;</strong>字符串&nbsp;<code>s</code>的，而不是部分字符串。</p>

<p><strong>说明:</strong></p>

<ul>
	<li><code>s</code>&nbsp;可能为空，且只包含从&nbsp;<code>a-z</code>&nbsp;的小写字母。</li>
	<li><code>p</code>&nbsp;可能为空，且只包含从&nbsp;<code>a-z</code>&nbsp;的小写字母，以及字符&nbsp;<code>.</code>&nbsp;和&nbsp;<code>*</code>。</li>
</ul>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong>
s = "aa"
p = "a"
<strong>输出:</strong> false
<strong>解释:</strong> "a" 无法匹配 "aa" 整个字符串。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong>
s = "aa"
p = "a*"
<strong>输出:</strong> true
<strong>解释:</strong>&nbsp;因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre><strong>输入:</strong>
s = "ab"
p = ".*"
<strong>输出:</strong> true
<strong>解释:</strong>&nbsp;".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
</pre>

<p><strong>示例 4:</strong></p>

<pre><strong>输入:</strong>
s = "aab"
p = "c*a*b"
<strong>输出:</strong> true
<strong>解释:</strong>&nbsp;因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
</pre>

<p><strong>示例 5:</strong></p>

<pre><strong>输入:</strong>
s = "mississippi"
p = "mis*is*p*."
<strong>输出:</strong> false</pre>


---
### 思路
```
```



### 答题
``` C++
bool isMatch(string& s, string& p, int si, int pi, int ti = -1)
{
	if (si == s.size() && pi == p.size()) return true;
	if (pi >= p.size()) return false;
	if (si >= s.size())
	{
		while (pi < p.size())
		{
			if (pi + 1 == p.size() || p[pi + 1] != '*') return false;
			pi += 2;
		}
		return true;
	}

	if (ti != -1)
	{
		if (p[ti] != '.' && s[si] != p[ti]) return false;
		return isMatch(s, p, si + 1, pi + 1);
	}

	if (pi + 1 != p.size() && p[pi + 1] == '*')
	{
		if (isMatch(s, p, si, pi + 2)) return true;
		for (int i = 1; i <= s.size() - si; i++)
		{
			if (p[pi] != '.' && s[si + i - 1] != p[pi]) break;
			if (isMatch(s, p, si + i - 1, pi + 1, pi)) return true;
		}
		return false;
	}

	if (isalpha(p[pi]))
	{
		if (s[si] != p[pi]) return false;
		return isMatch(s, p, si + 1, pi + 1);
	}

	if (p[pi] == '.')
	{
		return isMatch(s, p, si + 1, pi + 1);
	}

	return false;
}

bool isMatch(string s, string p) 
{
	return isMatch(s, p, 0, 0);
}
```


### 其它
``` C++
    bool isMatch(string s, string p) {
        return regex_match(s, regex(p));
    }


```


