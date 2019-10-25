# `（简单）`  [5222.split-a-string-in-balanced-strings 分割平衡字符串](https://leetcode-cn.com/contest/weekly-contest-158/problems/split-a-string-in-balanced-strings/)

### 题目描述
<p>在一个「平衡字符串」中，'L' 和 'R' 字符的数量是相同的。</p>

<p>给出一个平衡字符串&nbsp;<code>s</code>，请你将它分割成尽可能多的平衡字符串。</p>

<p>返回可以通过分割得到的平衡字符串的最大数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "RLRRLLRLRL"
<strong>输出：</strong>4
<strong>解释：</strong>s 可以分割为 "RL", "RRLL", "RL", "RL", 每个子字符串中都包含相同数量的 'L' 和 'R'。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "RLLLLRRRLR"
<strong>输出：</strong>3
<strong>解释：</strong>s 可以分割为 "RL", "LLLRRR", "LR", 每个子字符串中都包含相同数量的 'L' 和 'R'。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "LLLLRRRR"
<strong>输出：</strong>1
<strong>解释：</strong>s 只能保持原样 "LLLLRRRR".
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i] = 'L' 或 'R'</code></li>
</ul>


---
### 思路
```
```

### 答题
``` C++
int balancedStringSplit(string s) 
{
	int l = 0;
	int ans = 0;
	for (auto c : s)
	{
		l += (c == 'L') ? 1 : -1;
		ans += (l == 0) ? 1 : 0;
	}
	return ans;
}
```

