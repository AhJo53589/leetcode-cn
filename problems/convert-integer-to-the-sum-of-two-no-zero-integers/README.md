# `（简单）` [1317.convert-integer-to-the-sum-of-two-no-zero-integers 将整数转换为两个无零整数的和](https://leetcode-cn.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/)

[contest](https://leetcode-cn.com/contest/weekly-contest-171/problems/convert-integer-to-the-sum-of-two-no-zero-integers/)

### 题目描述
<p>「无零整数」是十进制表示中 <strong>不含任何 0</strong>&nbsp;的正整数。</p>

<p>给你一个整数&nbsp;<code>n</code>，请你返回一个 <strong>由两个整数组成的列表</strong> <code>[A, B]</code>，满足：</p>

<ul>
	<li><code>A</code> 和 <code>B</code>&nbsp;都是无零整数</li>
	<li><code>A + B = n</code></li>
</ul>

<p>题目数据保证至少有一个有效的解决方案。</p>

<p>如果存在多个有效解决方案，你可以返回其中任意一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>[1,1]
<strong>解释：</strong>A = 1, B = 1. A + B = n 并且 A 和 B 的十进制表示形式都不包含任何 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 11
<strong>输出：</strong>[2,9]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 10000
<strong>输出：</strong>[1,9999]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 69
<strong>输出：</strong>[1,68]
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>n = 1010
<strong>输出：</strong>[11,999]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10^4</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
bool valid(int n)
{
	string str = to_string(n);
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '0') return false;
	}
	return true;
}

int getNext(int n)
{
	n++;
	string str = to_string(n);

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '0')
		{
			for (size_t j = i; j < str.size(); j++)
			{
				str[j] = '1';
			}
		}
	}

	return stoi(str);
}

vector<int> getNoZeroIntegers(int n)
{
	int a = 1;
	int b = n - a;
	while (true)
	{
		if (valid(a) && valid(b)) return { a, b };
		a = getNext(a);
		b = n - a;
		if (a > b) break;
	}
	return {};
}
```




