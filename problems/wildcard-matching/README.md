# `（困难）` [44.wildcard-matching 通配符匹配](https://leetcode-cn.com/problems/wildcard-matching/)

### 题目描述
<p>给定一个字符串&nbsp;(<code>s</code>) 和一个字符模式&nbsp;(<code>p</code>) ，实现一个支持&nbsp;<code>'?'</code>&nbsp;和&nbsp;<code>'*'</code>&nbsp;的通配符匹配。</p>

<pre>'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
</pre>

<p>两个字符串<strong>完全匹配</strong>才算匹配成功。</p>

<p><strong>说明:</strong></p>

<ul>
	<li><code>s</code>&nbsp;可能为空，且只包含从&nbsp;<code>a-z</code>&nbsp;的小写字母。</li>
	<li><code>p</code>&nbsp;可能为空，且只包含从&nbsp;<code>a-z</code>&nbsp;的小写字母，以及字符&nbsp;<code>?</code>&nbsp;和&nbsp;<code>*</code>。</li>
</ul>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong>
s = "aa"
p = "a"
<strong>输出:</strong> false
<strong>解释:</strong> "a" 无法匹配 "aa" 整个字符串。</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong>
s = "aa"
p = "*"
<strong>输出:</strong> true
<strong>解释:</strong>&nbsp;'*' 可以匹配任意字符串。
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre><strong>输入:</strong>
s = "cb"
p = "?a"
<strong>输出:</strong> false
<strong>解释:</strong>&nbsp;'?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
</pre>

<p><strong>示例&nbsp;4:</strong></p>

<pre><strong>输入:</strong>
s = "adceb"
p = "*a*b"
<strong>输出:</strong> true
<strong>解释:</strong>&nbsp;第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
</pre>

<p><strong>示例&nbsp;5:</strong></p>

<pre><strong>输入:</strong>
s = "acdcb"
p = "a*c?b"
<strong>输入:</strong> false</pre>


---
### 思路
```
```



### 答题
``` C++
bool isMatch(string s, string p) 
{
	int si = 0;
	int pi = 0;
	int sStar = -1; 
	int pStar = -1;

	while (si < s.size())
	{
		if (pi < p.size() && (s[si] == p[pi] || p[pi] == '?')) 
		{
			++si, ++pi;
		}
		else if (pi < p.size() && p[pi] == '*')
		{
			sStar = si;
			pStar = pi++;
		}
		else if (sStar >= 0) 
		{
			si = ++sStar;
			pi = pStar + 1;
		}
		else
		{
			return false;
		}
	}

	while (pi < p.size() && p[pi] == '*')
	{
		++pi;
	}

	return pi == p.size();
}
```




