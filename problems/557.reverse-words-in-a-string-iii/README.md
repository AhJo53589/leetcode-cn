# `（简单）`  [557.reverse-words-in-a-string-iii 反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)

### 题目描述
<p>给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc"<strong><strong><strong>&nbsp;</strong></strong></strong>
</pre>

<p><strong><strong><strong><strong>注意：</strong></strong></strong></strong>在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。</p>


---
### 思路
```
```

### 答题
``` C++
string reverseWords(string s) 
{
	string str;
	string sub;
	int iBegin = 0;
	int iEnd = 0;

	s += " ";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ') continue;
		for (int j = i - 1; j >= iBegin; j--)
		{
			sub += s[j];
		}
		str += sub;
		if (i != s.size() - 1)
		{
			iBegin = i + 1;
			str += " ";
			sub.clear();
		}
	}
	return str;
}
```

### 其它
``` C++
```

