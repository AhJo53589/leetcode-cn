# `（简单）` [326.power-of-three 3的幂](https://leetcode-cn.com/problems/power-of-three/)

### 题目描述
<p>给定一个整数，写一个函数来判断它是否是 3&nbsp;的幂次方。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 27
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 0
<strong>输出:</strong> false</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> 9
<strong>输出:</strong> true</pre>

<p><strong>示例 4:</strong></p>

<pre><strong>输入:</strong> 45
<strong>输出:</strong> false</pre>

<p><strong>进阶：</strong><br>
你能不使用循环或者递归来完成本题吗？</p>




---
### 思路
``` 
```


### 答题
``` C++
bool isPowerOfThree(int n)
{
	return n > 0 && 1162261467 % n == 0;
}
``` 
