# `（简单）`  [231.power-of-two 2的幂](https://leetcode-cn.com/problems/power-of-two/)

### 题目描述
<p>给定一个整数，编写一个函数来判断它是否是 2 的幂次方。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> 1
<strong>输出:</strong> true
<strong>解释: </strong>2<sup>0</sup>&nbsp;= 1</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 16
<strong>输出:</strong> true
<strong>解释: </strong>2<sup>4</sup>&nbsp;= 16</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> 218
<strong>输出:</strong> false</pre>


---
### 思路
```
```

### 答题
``` C++
bool isPowerOfTwo(int n) {
    if(n<=0) return false;
    return ((n&(n-1)) == 0);
}
```
