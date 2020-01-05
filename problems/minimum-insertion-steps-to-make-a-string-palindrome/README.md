# `（困难）` [5306.minimum-insertion-steps-to-make-a-string-palindrome 让字符串成为回文串的最少插入次数](https://leetcode-cn.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)

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
void checkAndCut(string &s)
{
	int l = 0;
	int r = s.size() - 1;
	while (l < r)
	{
		if (s[l] != s[r]) break;
		l++;
		r--;
	}
	if (l < r)
	{
		s = s.substr(l, r - l + 1);
	}
	else
	{
		s.clear();
	}
}

int minInsertions(string s) 
{
	unordered_set<string> vi;
	queue<pair<string, int>> que;
	que.push({s, 0});

	while (!que.empty())
	{
		auto q = que.front();
		que.pop();

		string str = q.first;
		checkAndCut(str);
		if (vi.count(str) != 0) continue;
		vi.insert(str);
		if (str.size() == 0) return q.second;

		que.push({ str[str.size() - 1] + str, q.second + 1 });
		que.push({ str + str[0], q.second + 1 });
	}

	return s.size() - 1;
}
```




