# `（中等）` [131.palindrome-partitioning 分割回文串](https://leetcode-cn.com/problems/palindrome-partitioning/)

### 题目描述
<p>给定一个字符串 <em>s</em>，将<em> s </em>分割成一些子串，使每个子串都是回文串。</p>

<p>返回 <em>s</em> 所有可能的分割方案。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>&nbsp;"aab"
<strong>输出:</strong>
[
  ["aa","b"],
  ["a","a","b"]
]</pre>


---
### 思路
```
```



### 答题
``` C++
bool check(string& s, int beg, int end)
{
	if (beg > end) return false;
	while (beg < end)
	{
		if (s[beg++] != s[end--]) return false;
	}
	return true;
}

void partition(string& s, int beg, vector<string> &part, set<vector<string>>& ans)
{
	if (beg == s.size())
	{
		ans.insert(part);
		return;
	}

	string sub;
	for (int i = beg; i < s.size(); i++)
	{
		sub += s[i];
		if (!check(s, beg, i)) continue;
		part.push_back(sub);
		partition(s, i + 1, part, ans);
		part.pop_back();
	}
}

vector<vector<string>> partition(string s) 
{
	set<vector<string>> ans;
	vector<string> part;
	partition(s, 0, part, ans);

	vector<vector<string>> ret(ans.begin(), ans.end());
	return ret;
}
```




