# `（中等）` [1362.closest-divisors 最接近的因数](https://leetcode-cn.com/problems/closest-divisors/)

[contest](https://leetcode-cn.com/contest/weekly-contest-177/problems/closest-divisors/)

### 题目描述
<p>给你一个整数&nbsp;<code>num</code>，请你找出同时满足下面全部要求的两个整数：</p>

<ul>
	<li>两数乘积等于 &nbsp;<code>num + 1</code>&nbsp;或&nbsp;<code>num + 2</code></li>
	<li>以绝对差进行度量，两数大小最接近</li>
</ul>

<p>你可以按任意顺序返回这两个整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 8
<strong>输出：</strong>[3,3]
<strong>解释：</strong>对于 num + 1 = 9，最接近的两个因数是 3 &amp; 3；对于 num + 2 = 10, 最接近的两个因数是 2 &amp; 5，因此返回 3 &amp; 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 123
<strong>输出：</strong>[5,25]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = 999
<strong>输出：</strong>[40,25]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10^9</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
	vector<int> getClose(int num)
	{
		for (int a = pow(num, 0.5) + 1; a >= 1; a--)
		{
			int b = num / a;
			if (a * b == num) return { a, b };
		}
		return {};
	}

    vector<int> closestDivisors(int num) 
	{
		auto a = getClose(num + 1);
		auto b = getClose(num + 2);
		if (a.empty()) return b;
		if (b.empty()) return a;
		return abs(a[0] - a[1]) <= abs(b[0] - b[1]) ? a : b;
    }
};
```




