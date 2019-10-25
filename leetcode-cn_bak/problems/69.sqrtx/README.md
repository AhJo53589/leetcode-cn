# `（简单）`  [69.sqrtx x 的平方根](https://leetcode-cn.com/problems/sqrtx/)

### 题目描述
<p>实现&nbsp;<code>int sqrt(int x)</code>&nbsp;函数。</p>

<p>计算并返回&nbsp;<em>x</em>&nbsp;的平方根，其中&nbsp;<em>x </em>是非负整数。</p>

<p>由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 4
<strong>输出:</strong> 2
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 8
<strong>输出:</strong> 2
<strong>说明:</strong> 8 的平方根是 2.82842..., 
&nbsp;    由于返回类型是整数，小数部分将被舍去。
</pre>


---
### 思路
```
```

### 答题
``` C++
int mySqrt(int x) 
{
	if (x == 0) return 0;
	if (x < 4) return 1;
	long long low = 1;
	long long high = x;
	while (low < high)
	{
		long long mid = low + (high - low) / 2;
		if (mid * mid <= x) low = mid + 1;
		else high = mid;
	}
	return low - 1;
}
```

### 其它
牛顿迭代法
``` C++
int mySqrt(int x) {
	if (x == 0) return 0;
	double last=0;
	double res=1;
	while(res!=last)
	{
		last=res;
		res=(res+x/res)/2;
	}
	return int(res);
}
```

