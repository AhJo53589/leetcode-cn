# `（中等）`  [50.MyPow](https://leetcode-cn.com/problems/powx-n/)

### 题目描述
<p>实现&nbsp;<a href="https://www.cplusplus.com/reference/valarray/pow/">pow(<em>x</em>, <em>n</em>)</a>&nbsp;，即计算 x 的 n 次幂函数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 2.00000, 10
<strong>输出:</strong> 1024.00000
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> 2.10000, 3
<strong>输出:</strong> 9.26100
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre><strong>输入:</strong> 2.00000, -2
<strong>输出:</strong> 0.25000
<strong>解释:</strong> 2<sup>-2</sup> = 1/2<sup>2</sup> = 1/4 = 0.25</pre>

<p><strong>说明:</strong></p>

<ul>
	<li>-100.0 &lt;&nbsp;<em>x</em>&nbsp;&lt; 100.0</li>
	<li><em>n</em>&nbsp;是 32 位有符号整数，其数值范围是&nbsp;[−2<sup>31</sup>,&nbsp;2<sup>31&nbsp;</sup>− 1] 。</li>
</ul>



---
### 思路
```

```


### 答题
``` C++
double myPow(double x, int n)	// 4ms
{
	switch (n)
	{
	case -1:
		return 1 / x;
	case 0:
		return 1.0;
	case 1:
		return x;
	case 2:
		return x * x;
	}

	return myPow(myPow(x, 2), n / 2) * myPow(x, n % 2);
}
``` 