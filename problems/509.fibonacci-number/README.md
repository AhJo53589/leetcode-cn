# `（简单）`  [509.fibonacci-number 斐波那契数](https://leetcode-cn.com/problems/fibonacci-number/)

### 题目描述
<p><strong>斐波那契数</strong>，通常用&nbsp;<code>F(n)</code> 表示，形成的序列称为<strong>斐波那契数列</strong>。该数列由&nbsp;<code>0</code> 和 <code>1</code> 开始，后面的每一项数字都是前面两项数字的和。也就是：</p>

<pre>F(0) = 0,&nbsp; &nbsp;F(1)&nbsp;= 1
F(N) = F(N - 1) + F(N - 2), 其中 N &gt; 1.
</pre>

<p>给定&nbsp;<code>N</code>，计算&nbsp;<code>F(N)</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>2
<strong>输出：</strong>1
<strong>解释：</strong>F(2) = F(1) + F(0) = 1 + 0 = 1.
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>3
<strong>输出：</strong>2
<strong>解释：</strong>F(3) = F(2) + F(1) = 1 + 1 = 2.
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>4
<strong>输出：</strong>3
<strong>解释：</strong>F(4) = F(3) + F(2) = 2 + 1 = 3.
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>0 ≤ <code>N</code> ≤ 30</li>
</ul>


---
### 思路
```
为了消除上述情况中的重复计算，正如许多人已经指出的那样，其中一个想法是将中间结果存储在缓存中，以便我们以后可以重用它们，而不需要重新计算。

这个想法也被称为记忆化，这是一种经常与递归一起使用的技术。
```

### 答题
``` C++
unordered_map<int, int> cache;

int fib(int N) 
{
	if (cache.count(N)) return cache[N];

	if (N == 0) return 0;
	if (N == 1) return 1;
	return fib(N - 1) + fib(N - 2);
}
```

