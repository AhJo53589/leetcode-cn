# `（简单）` [14.longest-common-prefix 最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/)

### 题目描述
<p>编写一个函数来查找字符串数组中的最长公共前缀。</p>

<p>如果不存在公共前缀，返回空字符串&nbsp;<code>""</code>。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入: </strong>["flower","flow","flight"]
<strong>输出:</strong> "fl"
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入: </strong>["dog","racecar","car"]
<strong>输出:</strong> ""
<strong>解释:</strong> 输入不存在公共前缀。
</pre>

<p><strong>说明:</strong></p>

<p>所有输入只包含小写字母&nbsp;<code>a-z</code>&nbsp;。</p>




---
### 思路
```
```


### 答题
``` C++
string longestCommonPrefix(vector<string>& strs)
{
	if (strs.size() == 0) return "";
	if (strs.size() == 1) return strs[0];
	int i = 0;
	while (true)
	{
		for (int j = 1; j < strs.size(); j++)
		{
			if ((i == strs[0].size()) || (i == strs[j].size()) || (strs[0][i] != strs[j][i]))
			{
				if (i == 0) return "";
				return strs[0].substr(0, i);
			}
		}
		++i;
	}
	return "";
}
``` 
