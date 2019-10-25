# `（中等）` [1208.get-equal-substrings-within-budget 尽可能使字符串相等](https://leetcode-cn.com/problems/get-equal-substrings-within-budget/)

[contest](https://leetcode-cn.com/contest/weekly-contest-156/problems/get-equal-substrings-within-budget/)

### 题目描述
<p>给你两个长度相同的字符串，<code>s</code> 和 <code>t</code>。</p>

<p>将 <code>s</code>&nbsp;中的第&nbsp;<code>i</code>&nbsp;个字符变到&nbsp;<code>t</code>&nbsp;中的第 <code>i</code> 个字符需要&nbsp;<code>|s[i] - t[i]|</code>&nbsp;的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。</p>

<p>用于变更字符串的最大预算是&nbsp;<code>maxCost</code>。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。</p>

<p>如果你可以将 <code>s</code> 的子字符串转化为它在 <code>t</code> 中对应的子字符串，则返回可以转化的最大长度。</p>

<p>如果 <code>s</code> 中没有子字符串可以转化成 <code>t</code> 中对应的子字符串，则返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abcd", t = "bcdf", cost = 3
<strong>输出：</strong>3
<strong>解释：</strong>s<strong> </strong>中的<strong> </strong>"abc" 可以变为 "bcd"。开销为 3，所以最大长度为 3。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abcd", t = "cdef", cost = 3
<strong>输出：</strong>1
<strong>解释：</strong>s 中的任一字符要想变成 t 中对应的字符，其开销都是 2。因此，最大长度为<code> 1。</code>
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "abcd", t = "acde", cost = 0
<strong>输出：</strong>1
<strong>解释：</strong>你无法作出任何改动，所以最大长度为 1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= maxCost &lt;= 10^6</code></li>
	<li><code>s</code> 和&nbsp;<code>t</code>&nbsp;都只含小写英文字母。</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
int equalSubstring(string s, string t, int maxCost)
{
	auto f_cost = [s, t](size_t i)
	{
		return abs(s[i] - t[i]);
	};

	size_t start = 0;
	int c = 0;
	int ans = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		c += f_cost(i);
		while (c > maxCost)
		{
			c -= f_cost(start++);
		}
		ans = max(ans, (int)(i - start) + 1);
	}
	return ans;
}
```




