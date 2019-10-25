# `（简单）` [172.factorial-trailing-zeroes 阶乘后的零](https://leetcode-cn.com/problems/factorial-trailing-zeroes/)

### 题目描述
<p>给定一个整数 <em>n</em>，返回 <em>n</em>! 结果尾数中零的数量。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 3
<strong>输出:</strong> 0
<strong>解释:</strong>&nbsp;3! = 6, 尾数中没有零。</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> 5
<strong>输出:</strong> 1
<strong>解释:</strong>&nbsp;5! = 120, 尾数中有 1 个零.</pre>

<p><strong>说明: </strong>你算法的时间复杂度应为&nbsp;<em>O</em>(log&nbsp;<em>n</em>)<em>&nbsp;</em>。</p>


---
### 思路
```
```

### 答题
``` C++
int trailingZeroes(int n) 
{
	int res = 0;
	while (n) 
	{
		res += n / 5;
		n /= 5;
	}
	return res;
}
```

### 其它
``` C++
```

