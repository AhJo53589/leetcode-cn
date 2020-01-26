# `（简单）` [5319.remove-palindromic-subsequences 删除回文子序列](https://leetcode-cn.com/problems/remove-palindromic-subsequences/)

[contest](https://leetcode-cn.com/contest/weekly-contest-173/problems/remove-palindromic-subsequences/)

### 题目描述
<p>给你一个字符串&nbsp;<code>s</code>，它仅由字母&nbsp;<code>'a'</code> 和 <code>'b'</code>&nbsp;组成。每一次删除操作都可以从 <code>s</code> 中删除一个回文 <strong>子序列</strong>。</p>

<p>返回删除给定字符串中所有字符（字符串为空）的最小删除次数。</p>

<p>「子序列」定义：如果一个字符串可以通过删除原字符串某些字符而不改变原字符顺序得到，那么这个字符串就是原字符串的一个子序列。</p>

<p>「回文」定义：如果一个字符串向后和向前读是一致的，那么这个字符串就是一个回文。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "ababa"
<strong>输出：</strong>1
<strong>解释：</strong>字符串本身就是回文序列，只需要删除一次。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abb"
<strong>输出：</strong>2
<strong>解释：</strong>"<strong>a</strong>bb" -&gt; "<strong>bb</strong>" -&gt; "". 
先删除回文子序列 "a"，然后再删除 "bb"。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "baabb"
<strong>输出：</strong>2
<strong>解释：</strong>"<strong>baa</strong>b<strong>b</strong>" -&gt; "b" -&gt; "". 
先删除回文子序列 "baab"，然后再删除 "b"。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = ""
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> 仅包含字母&nbsp;'a'&nbsp; 和 'b'</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
bool valid(string& s, int start, int end)
{
	if (start >= end) return false;

	for (int i = 0; i < end - start; i++)
	{
		int a = start + i;
		int b = end - i;
		if (a >= b) break;
		if (s[a] != s[b]) return false;
	}
	return true;
}
    
int removePalindromeSub(string s) 
{
	if (s.size() == 0) return 0;
	if (s.size() == 1) return 1;
	if (valid(s, 0, s.size() - 1)) return 1;
	return 2;
}
```




