# `（简单）` [58.length-of-last-word 最后一个单词的长度](https://leetcode-cn.com/problems/length-of-last-word/)

### 题目描述
<p>给定一个仅包含大小写字母和空格&nbsp;<code>' '</code>&nbsp;的字符串，返回其最后一个单词的长度。</p>
<p>如果不存在最后一个单词，请返回 0&nbsp;。</p>
<p><strong>说明：</strong>一个单词是指由字母组成，但不包含任何空格的字符串。</p>
<p><strong>示例:</strong></p>
<pre><strong>输入:</strong> "Hello World"
<strong>输出:</strong> 5
</pre>

---
### 思路
```
从后往前，先去除空格。
再寻找第一个不是空格的索引，做减法。
```

[发布的题解](https://leetcode-cn.com/problems/length-of-last-word/solution/58-by-ikaruga/)

### 答题

``` C++
int lengthOfLastWord(string s)
{
	while (s.back() == ' ')
	{
		s.pop_back();
	}
	for (size_t i = s.size() - 1; i < s.size(); i--)
	{
		if (s[i] == ' ')
		{
			return s.size() - i - 1;
		}
	}
	return s.size();
}
```

### 其它

```
先反转字符串。
再使用stringstream转化单词。
返回长度。
```



``` C++
int lengthOfLastWord(string s)
{
	reverse(s.begin(), s.end());
	istringstream ss(s);
	string word;
	while (ss >> word)
	{
		return word.size();
	}
	return 0;
}
```

