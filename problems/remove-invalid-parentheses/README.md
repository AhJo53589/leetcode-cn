# `（困难）` [301.remove-invalid-parentheses 删除无效的括号](https://leetcode-cn.com/problems/remove-invalid-parentheses/)

### 题目描述
<p>删除最小数量的无效括号，使得输入的字符串有效，返回所有可能的结果。</p>

<p><strong>说明:</strong> 输入可能包含了除&nbsp;<code>(</code>&nbsp;和&nbsp;<code>)</code>&nbsp;以外的字符。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> "()())()"
<strong>输出:</strong> ["()()()", "(())()"]
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> "(a)())()"
<strong>输出:</strong> ["(a)()()", "(a())()"]
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> ")("
<strong>输出: </strong>[""]</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/remove-invalid-parentheses/solution/301-by-ikaruga/)

### 答题
``` C++
bool valid(string& s, vector<int>& use)
{
	int st = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!use[i]) continue;
		st += (s[i] == '(');
		st -= (s[i] == ')');
		if (st < 0) return false;
	}
	return (st == 0);
}

vector<string> removeInvalidParentheses(string s) 
{	
	set<string> ans;
	vector<int> use(s.size(), 1);

	for (int k = 0; k < s.size(); k++)
	{
		for (int i = 0; i < s.size(); i++)
		{
			use[i] = (i >= k);
		}

		do
		{
			if (valid(s, use))
			{
				string a;
				for (size_t i = 0; i < s.size(); i++)
				{
					if (!use[i]) continue;
					a += s[i];
				}
				ans.insert(a);

				k = s.size();
			}
		} while (next_permutation(use.begin(), use.end()));
	}
	if (ans.empty()) return { "" };
	return vector<string>(ans.begin(), ans.end());
}
```




