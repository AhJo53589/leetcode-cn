# `（中等）` [1239.maximum-length-of-a-concatenated-string-with-unique-characters 串联字符串的最大长度](https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/)

[contest](https://leetcode-cn.com/contest/weekly-contest-160/problems/maximum-length-of-a-concatenated-string-with-unique-characters/)

### 题目描述
<p>给定一个字符串数组 <code>arr</code>，字符串 <code>s</code> 是将 <code>arr</code> 某一子序列字符串连接所得的字符串，如果 <code>s</code> 中的每一个字符都只出现过一次，那么它就是一个可行解。</p>

<p>请返回所有可行解 <code>s</code> 中最长长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = ["un","iq","ue"]
<strong>输出：</strong>4
<strong>解释：</strong>所有可能的串联组合是 "","un","iq","ue","uniq" 和 "ique"，最大长度为 4。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = ["cha","r","act","ers"]
<strong>输出：</strong>6
<strong>解释：</strong>可能的解答有 "chaers" 和 "acters"。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = ["abcdefghijklmnopqrstuvwxyz"]
<strong>输出：</strong>26
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 16</code></li>
	<li><code>1 &lt;= arr[i].length &lt;= 26</code></li>
	<li><code>arr[i]</code>&nbsp;中只含有小写英文字母</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
bool check(vector<bool> &a, vector<bool> &b, string s)
{
	for (auto c : s)
	{
		if (a[c - 'a'] || b[c - 'a']) return false;
		b[c - 'a'] = true;
	}
	return true;
}

void add(vector<bool> &a, vector<bool> &b)
{
	for (auto i = 0; i < a.size(); i++)
	{
		if (b[i]) a[i] = true;
	}
}

int maxLength(vector<string>& arr)
{
	sort(arr.rbegin(), arr.rend(), [](const string &a, const string &b)
	{
		return a.size() < b.size();
	});

	int ans = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		vector<bool> f(26, false);
		int cnt = 0;
		for (int j = i; j < arr.size(); j++)
		{
			vector<bool> temp(26, false);
			if (!check(f, temp, arr[j])) continue;
			add(f, temp);
			cnt += arr[j].size();
			ans = max(ans, cnt);
		}
	}
	return ans;
}
```




