# `（中等）` [29.divide-two-integers 两数相除](https://leetcode-cn.com/problems/divide-two-integers/)

### 题目描述
<p>给定两个整数，被除数&nbsp;<code>dividend</code>&nbsp;和除数&nbsp;<code>divisor</code>。将两数相除，要求不使用乘法、除法和 mod 运算符。</p>

<p>返回被除数&nbsp;<code>dividend</code>&nbsp;除以除数&nbsp;<code>divisor</code>&nbsp;得到的商。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> dividend = 10, divisor = 3
<strong>输出:</strong> 3</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> dividend = 7, divisor = -3
<strong>输出:</strong> -2</pre>

<p><strong>说明:</strong></p>

<ul>
	<li>被除数和除数均为 32 位有符号整数。</li>
	<li>除数不为&nbsp;0。</li>
	<li>假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2<sup>31</sup>,&nbsp; 2<sup>31&nbsp;</sup>− 1]。本题中，如果除法结果溢出，则返回 2<sup>31&nbsp;</sup>− 1。</li>
</ul>


---
### 思路
```
使用位移加速。
```

### 答题
``` C++
int divide(int dividend, int divisor) 
{
	if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
	int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
	long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
	while (m >= n)
	{
		long long t = n, p = 1;
		while (m >= (t << 1))
		{
			t <<= 1;
			p <<= 1;
		}
		m -= t;
		res += p;
	}
	return sign == 1 ? res : -res;
}
```
