# `（简单）`  [290.word-pattern 单词规律](https://leetcode-cn.com/problems/word-pattern/)

### 题目描述
<p>给定一种规律 <code>pattern</code>&nbsp;和一个字符串&nbsp;<code>str</code>&nbsp;，判断 <code>str</code> 是否遵循相同的规律。</p>

<p>这里的&nbsp;<strong>遵循&nbsp;</strong>指完全匹配，例如，&nbsp;<code>pattern</code>&nbsp;里的每个字母和字符串&nbsp;<code>str</code><strong>&nbsp;</strong>中的每个非空单词之间存在着双向连接的对应规律。</p>

<p><strong>示例1:</strong></p>

<pre><strong>输入:</strong> pattern = <code>"abba"</code>, str = <code>"dog cat cat dog"</code>
<strong>输出:</strong> true</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong>pattern = <code>"abba"</code>, str = <code>"dog cat cat fish"</code>
<strong>输出:</strong> false</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> pattern = <code>"aaaa"</code>, str = <code>"dog cat cat dog"</code>
<strong>输出:</strong> false</pre>

<p><strong>示例&nbsp;4:</strong></p>

<pre><strong>输入:</strong> pattern = <code>"abba"</code>, str = <code>"dog dog dog dog"</code>
<strong>输出:</strong> false</pre>

<p><strong>说明:</strong><br>
你可以假设&nbsp;<code>pattern</code>&nbsp;只包含小写字母，&nbsp;<code>str</code>&nbsp;包含了由单个空格分隔的小写字母。&nbsp; &nbsp;&nbsp;</p>


---
### 思路
```
```

### 答题
``` C++
bool wordPattern(string pattern, string str)
{
	unordered_set<string> s;
	unordered_map<char, string> m;
	vector<string> vec;
	istringstream ss(str);
	string item;
	char delim = ' ';
	while (getline(ss, item, delim))
	{
		vec.push_back(item);
	}
	if (pattern.size() != vec.size()) return false;
	for (auto i = 0; i < pattern.size(); i++)
	{
		if (m.count(pattern[i]) != 0)
		{
			if (m[pattern[i]] != vec[i]) return false;
		}
		else
		{
			if (s.count(vec[i]) != 0) return false;
			m[pattern[i]] = vec[i];
			s.insert(vec[i]);
		}
	}
	return true;
}
```

### 其它
使用两个map，分别将两个元素对应到int。  
判断的比较巧妙。
``` C++
bool wordPattern(string pattern, string str) 
{
	map<char, int> m1;
	map<string, int> m2;
	int i = 0, n = pattern.size();
	istringstream in(str);

	for (string word; in >> word; i++)
	{
		if (i == n || m1[pattern[i]] != m2[word]) return false;
		m1[pattern[i]] = m2[word] = i + 1;
	}

	return i == n;
}
```

