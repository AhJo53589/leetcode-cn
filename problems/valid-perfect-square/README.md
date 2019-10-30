# `（简单）` [367.valid-perfect-square 有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/)

### 题目描述
<p>给定一个正整数 <em>num</em>，编写一个函数，如果 <em>num</em> 是一个完全平方数，则返回 True，否则返回 False。</p>

<p><strong>说明：</strong>不要使用任何内置的库函数，如&nbsp; <code>sqrt</code>。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>16
<strong>输出：</strong>True</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>14
<strong>输出：</strong>False
</pre>


---
### 思路
```
```

### 答题
``` C++
bool isPerfectSquare(int num)
{
	if (num == 0) return true;
	if (num == 1) return true;
	long long low = 1;
	long long high = num;
	while (low < high)
	{
		long long mid = low + (high - low) / 2;
		if (mid * mid == num) return true;
		else if (mid * mid < num) low = mid + 1;
		else high = mid;
	}
	return false;
}
```
