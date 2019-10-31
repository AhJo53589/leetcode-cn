# `（简单）` [387.first-unique-character-in-a-string 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)

### 题目描述
<p>给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。</p>

<p><strong>案例:</strong></p>

<pre>s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
</pre>

<p>&nbsp;</p>

<p><strong>注意事项：</strong>您可以假定该字符串只包含小写字母。</p>



---
### 思路
```
```


### 答题
``` C++
int firstUniqChar(string s)
{
	vector<int> charCount(26, 0);
	for (int i = 0; i < s.size(); i++)
	{
		charCount[s[i] - 'a'] ++;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (charCount[s[i] - 'a'] == 1)
		{
			return i;
		}
	}
	return -1; 
}
``` 
