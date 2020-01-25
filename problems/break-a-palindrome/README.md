# `（中等）` [5151.break-a-palindrome 破坏回文串](https://leetcode-cn.com/problems/break-a-palindrome/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-18/problems/break-a-palindrome/)

### 题目描述
<p>给你一个回文字符串&nbsp;<code>palindrome</code> ，请你将其中&nbsp;<strong>一个</strong> 字符用任意小写英文字母替换，使得结果字符串的字典序最小，且&nbsp;<strong>不是</strong>&nbsp;回文串。</p>

<p>请你返回结果字符串。如果无法做到，则返回一个空串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>palindrome = "abccba"
<strong>输出：</strong>"aaccba"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>palindrome = "a"
<strong>输出：</strong>""
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= palindrome.length &lt;= 1000</code></li>
	<li><code>palindrome</code>&nbsp;只包含小写英文字母。</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
string breakPalindrome(string palindrome)
{
	if (palindrome.size() <= 1) return "";
	for (size_t i = 0; i < palindrome.size(); i++)
	{
		if (palindrome[i] == 'a' && i != palindrome.size() - 1) continue;
		if (palindrome.size() % 2 == 1 && i == palindrome.size() / 2) continue;
		palindrome[i] = (palindrome[i] == 'a') ? 'b' : 'a';
		break;
	}
	return palindrome;
}
```




