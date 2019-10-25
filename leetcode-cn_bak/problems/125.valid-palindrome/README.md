# `（简单）`  [125.valid-palindrome 验证回文串](https://leetcode-cn.com/problems/valid-palindrome/)

### 题目描述
<p>给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。</p>

<p><strong>说明：</strong>本题中，我们将空字符串定义为有效的回文串。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> "A man, a plan, a canal: Panama"
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> "race a car"
<strong>输出:</strong> false
</pre>


---
### 思路
```
```

### 答题
``` C++
char getChar(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return c - 'A' + 'a';
	}
	else if (c >= 'a' && c <= 'z')
	{
		return c;
	}
	else if (c >= '0' && c <= '9')
	{
		return c;
	}
	return NULL;
}

string getCleanString(string s)
{
	string t;
	for (int i = 0; i < s.size(); i++)
	{
		char c = getChar(s[i]);
		if (c != NULL)
		{
			t.push_back(c);
		}
	}
	return t;
}

bool isPalindrome(string s)
{
	if (s.size() == 0) return true;

	string t = getCleanString(s);
	int len = t.size();
	for (int i = 0; i < len / 2; i++)
	{
		if (t[i] != t[len - i - 1])
		{
			return false;
		}
	}
	return true;
}
```
