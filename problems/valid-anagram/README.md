# `（简单）` [242.valid-anagram 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)

### 题目描述
<p>给定两个字符串 <em>s</em> 和 <em>t</em> ，编写一个函数来判断 <em>t</em> 是否是 <em>s</em> 的字母异位词。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> <em>s</em> = "anagram", <em>t</em> = "nagaram"
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> <em>s</em> = "rat", <em>t</em> = "car"
<strong>输出: </strong>false</pre>

<p><strong>说明:</strong><br>
你可以假设字符串只包含小写字母。</p>

<p><strong>进阶:</strong><br>
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？</p>



---
### 思路
```
```


### 答题
``` C++
bool isAnagram(string s, string t)
{
	if (s.size() != t.size()) return false;

	vector<int> charCount_s(26, 0);
	vector<int> charCount_t(26, 0);
	for (int i = 0; i < s.size(); i++)
	{
		charCount_s[s[i] - 'a'] ++;
		charCount_t[t[i] - 'a'] ++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (charCount_s[i] != charCount_t[i])
		{
			return false;
		}
	}
	return true;
}
``` 
