# `（简单）`  [205.isomorphic-strings 同构字符串](https://leetcode-cn.com/problems/isomorphic-strings/)

### 题目描述
<p>给定两个字符串&nbsp;<em><strong>s&nbsp;</strong></em>和&nbsp;<strong><em>t</em></strong>，判断它们是否是同构的。</p>

<p>如果&nbsp;<em><strong>s&nbsp;</strong></em>中的字符可以被替换得到&nbsp;<strong><em>t&nbsp;</em></strong>，那么这两个字符串是同构的。</p>

<p>所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <strong><em>s</em></strong> = <code>"egg", </code><strong><em>t = </em></strong><code>"add"</code>
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> <strong><em>s</em></strong> = <code>"foo", </code><strong><em>t = </em></strong><code>"bar"</code>
<strong>输出:</strong> false</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> <strong><em>s</em></strong> = <code>"paper", </code><strong><em>t = </em></strong><code>"title"</code>
<strong>输出:</strong> true</pre>

<p><strong>说明:</strong><br>
你可以假设&nbsp;<em><strong>s&nbsp;</strong></em>和 <strong><em>t </em></strong>具有相同的长度。</p>


---
### 思路
```
```

### 答题
``` C++
unordered_map<char, char> m;
unordered_set<char> c;
bool isIsomorphic(string s, string t) 
{
	for (int i = 0; i < s.size(); i++)
	{
		if (m.count(s[i]))
		{
			if (m[s[i]] != t[i]) return false;
		}
		else
		{
			if (c.count(t[i])) return false;
			m[s[i]] = t[i];
			c.insert(t[i]);
		}
	}
	return true;
}
```

### 其它
对比两个字符串对应位置的字符在字符串内第一次出现的位置。  
``` C++
bool isIsomorphic(string s, string t) {
	for(int i=0;i<s.size();i++){
		if(s.find(s[i])!=t.find(t[i]))
		return false;
	}
	return true;
}
```