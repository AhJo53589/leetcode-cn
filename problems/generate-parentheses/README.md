# `（中等）` [22.generate-parentheses 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)

### 题目描述
<p>给出&nbsp;<em>n</em>&nbsp;代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且<strong>有效的</strong>括号组合。</p>

<p>例如，给出&nbsp;<em>n </em>=<em> </em>3，生成结果为：</p>

<pre>[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
</pre>


---
### 思路
```
```

### 答题
``` C++
vector<string> generateParenthesis(int n)
{
	vector<int> res_left;
	vector<string> res;
	res_left.push_back(0);
	res.push_back("");

	for (int i = 0; i < 2 * n; i++)
	{
		int len = res.size();
		for (int j = 0; j < len; j++)
		{
			int left = res_left[j];
			if (left < n)
			{
				res_left.push_back(left + 1);
				res.push_back(res[j] + "(");
			}

			if (i - left < left)
			{
				res_left.push_back(left);
				res.push_back(res[j] + ")");
			}
		}
		res_left.erase(res_left.begin(), res_left.begin() + len);
		res.erase(res.begin(), res.begin() + len);
	}
	return res;
}
```

### 其它
``` C++
vector<string> generateParenthesis(int n) {
	vector<string> ans;
	if (n == 0)
		return ans;
	string cur;
	search(ans, cur, 0, 0, n);
	return ans;
}
void search(vector<string> &ans, string cur, int open, int close, int n)
{
	if (cur.size() == 2 * n)
		ans.push_back(cur);
	if (open < n)
		search(ans, cur + '(', open + 1, close, n);
	if (close < open)
		search(ans, cur + ')', open, close + 1, n);
}
```

