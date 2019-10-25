# `（中等）` [151.reverse-words-in-a-string 翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/)

### 题目描述
<p>给定一个字符串，逐个翻转字符串中的每个单词。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> "<code>the sky is blue</code>"
<strong>输出:&nbsp;</strong>"<code>blue is sky the</code>"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> " &nbsp;hello world! &nbsp;"
<strong>输出:&nbsp;</strong>"world! hello"
<strong>解释: </strong>输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入:</strong> "a good &nbsp; example"
<strong>输出:&nbsp;</strong>"example good a"
<strong>解释: </strong>如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
</pre>

<p>&nbsp;</p>

<p><strong>说明：</strong></p>

<ul>
	<li>无空格字符构成一个单词。</li>
	<li>输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。</li>
	<li>如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<p>请选用 C 语言的用户尝试使用&nbsp;<em>O</em>(1) 额外空间复杂度的原地解法。</p>


---
### 思路
```
```

### 答题
``` C++
string reverseWords(string s) 
{
	stack<string> st;
	string sub;
	s += " ";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			sub += s[i];
		}
		else
		{
			if (!sub.empty())
			{
				st.push(sub);
				sub.clear();
			}
		}
	}
	string str;
	while (!st.empty())
	{
		str += st.top();
		st.pop();
		str += " ";
	}
	if (!str.empty())
	{
		str = str.substr(0, str.size() - 1);
	}
	return str;
}
```

