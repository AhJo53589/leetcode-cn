# `（中等）`  [5206.remove-all-adjacent-duplicates-in-string-ii 删除字符串中的所有相邻重复项 II](https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string-ii/)

### 题目描述
<p>给你一个字符串&nbsp;<code>s</code>，「<code>k</code> 倍重复项删除操作」将会从 <code>s</code>&nbsp;中选择&nbsp;<code>k</code>&nbsp;个相邻且相等的字母，并删除它们，使被删去的字符串的左侧和右侧连在一起。</p>

<p>你需要对&nbsp;<code>s</code>&nbsp;重复进行无限次这样的删除操作，直到无法继续为止。</p>

<p>在执行完所有删除操作后，返回最终得到的字符串。</p>

<p>本题答案保证唯一。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abcd", k = 2
<strong>输出：</strong>"abcd"
<strong>解释：</strong>没有要删除的内容。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "deeedbbcccbdaa", k = 3
<strong>输出：</strong>"aa"
<strong>解释： 
</strong>先删除 "eee" 和 "ccc"，得到 "ddbbbdaa"
再删除 "bbb"，得到 "dddaa"
最后删除 "ddd"，得到 "aa"</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "pbbcggttciiippooaais", k = 2
<strong>输出：</strong>"ps"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>2 &lt;= k &lt;= 10^4</code></li>
	<li><code>s</code>&nbsp;中只含有小写英文字母。</li>
</ul>


---
### 思路
```
```
[发布的题解](https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string-ii/solution/5206-by-ikaruga/) 

### 答题
``` C++
string removeDuplicates(string s, int k)
{
	string ans;
	int cnt = 1;
	for (size_t i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i - 1])
		{
			cnt = (cnt + 1) % k;
		}

		if (s[i] != s[i - 1] || i == s.size() - 1)
		{
			while (cnt > 0)
			{
				cnt--;
				ans.push_back(s[i - 1]);
			}
			cnt = 1;
			if (s[i] != s[i - 1] && i == s.size() - 1)
			{
				ans.push_back(s[i]);
			}
		}
	}

	return (ans.size() == s.size()) ? ans : removeDuplicates(ans, k);
}
```
