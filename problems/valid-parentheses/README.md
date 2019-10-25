# `（简单）` [20.valid-parentheses 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)

### 题目描述
<p>给定一个只包括 <code>'('</code>，<code>')'</code>，<code>'{'</code>，<code>'}'</code>，<code>'['</code>，<code>']'</code>&nbsp;的字符串，判断字符串是否有效。</p>

<p>有效字符串需满足：</p>

<ol>
	<li>左括号必须用相同类型的右括号闭合。</li>
	<li>左括号必须以正确的顺序闭合。</li>
</ol>

<p>注意空字符串可被认为是有效字符串。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> "()"
<strong>输出:</strong> true
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> "()[]{}"
<strong>输出:</strong> true
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre><strong>输入:</strong> "(]"
<strong>输出:</strong> false
</pre>

<p><strong>示例&nbsp;4:</strong></p>

<pre><strong>输入:</strong> "([)]"
<strong>输出:</strong> false
</pre>

<p><strong>示例&nbsp;5:</strong></p>

<pre><strong>输入:</strong> "{[]}"
<strong>输出:</strong> true</pre>





---
### 思路
``` 
```


### 答题
``` C++
bool isValid(string str)
{
	stack<char> s;
	for (int i = 0; i < str.size(); i++)
	{
		if (s.empty())
		{
			s.push(str[i]);
			continue;
		}

		if (s.top() != '(' && s.top() != '[' && s.top() != '{') return false;

		if ((s.top() == '(' && str[i] == ')')
			|| (s.top() == '[' && str[i] == ']')
			|| (s.top() == '{' && str[i] == '}'))
		{
			s.pop();
		}
		else
		{
			s.push(str[i]);
		}
	}
	return s.empty();
}
``` 
