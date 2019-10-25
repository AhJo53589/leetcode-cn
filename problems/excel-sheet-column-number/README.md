# `（简单）` [171.excel-sheet-column-number Excel表列序号](https://leetcode-cn.com/problems/excel-sheet-column-number/)

### 题目描述
<p>给定一个Excel表格中的列名称，返回其相应的列序号。</p>

<p>例如，</p>

<pre>    A -&gt; 1
    B -&gt; 2
    C -&gt; 3
    ...
    Z -&gt; 26
    AA -&gt; 27
    AB -&gt; 28 
    ...
</pre>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> "A"
<strong>输出:</strong> 1
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入: </strong>"AB"
<strong>输出:</strong> 28
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre><strong>输入: </strong>"ZY"
<strong>输出:</strong> 701</pre>

<p><strong>致谢：</strong><br>
特别感谢&nbsp;<a href="http://leetcode.com/discuss/user/ts">@ts</a>&nbsp;添加此问题并创建所有测试用例。</p>


---
### 思路
```
```

### 答题
``` C++
int titleToNumber(string s)
{
	int res = 0;
	double i = 1;
	while (!s.empty())
	{
		res += (s.back() - 'A' + 1) * i;
		s.pop_back();
		i *= 26;
	}
	return res;
}
```


