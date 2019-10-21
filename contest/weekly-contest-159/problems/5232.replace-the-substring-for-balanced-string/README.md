# `（中等）`  [5232.replace-the-substring-for-balanced-string 替换子串得到平衡字符串](https://leetcode-cn.com/contest/weekly-contest-159/problems/replace-the-substring-for-balanced-string/)

### 题目描述
<p>有一个只含有&nbsp;<code>'Q', 'W', 'E',&nbsp;'R'</code>&nbsp;四种字符，且长度为 <code>n</code>&nbsp;的字符串。</p>
<p>假如在该字符串中，这四个字符都恰好出现&nbsp;<code>n/4</code>&nbsp;次，那么它就是一个「平衡字符串」。</p>
<p>&nbsp;</p>
<p>给你一个这样的字符串 <code>s</code>，请通过「替换子串」的方式，使原字符串 <code>s</code> 变成一个「平衡字符串」。</p>
<p>你可以用和「待替换子串」长度相同的&nbsp;<strong>任何</strong> 其他字符串来完成替换。</p>
<p>请返回待替换子串的最小可能长度。</p>
<p>如果原字符串自身就是一个平衡字符串，则返回 <code>0</code>。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong>s = "QWER"
<strong>输出：</strong>0
<strong>解释：</strong>s 已经是平衡的了。</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>s = "QQWE"
<strong>输出：</strong>1
<strong>解释：</strong>我们需要把一个 'Q' 替换成 'R'，这样得到的 "RQWE" (或 "QRWE") 是平衡的。
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>s = "QQQW"
<strong>输出：</strong>2
<strong>解释：</strong>我们可以把前面的 "QQ" 替换成 "ER"。 
</pre>

<p><strong>示例 4：</strong></p>
<pre><strong>输入：</strong>s = "QQQQ"
<strong>输出：</strong>3
<strong>解释：</strong>我们可以替换后 3 个 'Q'，使 s = "QWER"。
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s.length</code>&nbsp;是&nbsp;<code>4</code>&nbsp;的倍数</li>
	<li><code>s</code>&nbsp;中只含有&nbsp;<code>'Q'</code>, <code>'W'</code>, <code>'E'</code>,&nbsp;<code>'R'</code>&nbsp;四种字符</li>
</ul>

---
### 思路
```
注意题目要求是用一个子串替换，子串的意思是连续的，而不是单个字母替换多少次。

使用滑动窗口，
当 字符串中各字符数 - 替换掉的子串中各字符数 符合不超过s.size() / 4个数，
符合题目要求，记录最小值。
```

### 答题
``` C++
int balancedString(string s) 
{
	int ans = s.size();
	int n = s.size() / 4;
	unordered_map<char, int> um_count;
	unordered_map<char, int> um_replace;
	auto f_check = [&um_count, &um_replace, n]()
	{
		return (um_count['Q'] - um_replace['Q'] <= n
			&& um_count['W'] - um_replace['W'] <= n
			&& um_count['E'] - um_replace['E'] <= n
			&& um_count['R'] - um_replace['R'] <= n);
	};

	for (auto c : s)
	{
		um_count[c]++;
	}

	int i = 0, j = 0;
	while (i < s.size())
	{
		while (j < s.size() && !f_check())
		{
			um_replace[s[j++]]++;
		}
		if (f_check())
		{
			ans = min(ans, j - i);
		}
		um_replace[s[i++]]--;
	}
	return ans;
}
```
