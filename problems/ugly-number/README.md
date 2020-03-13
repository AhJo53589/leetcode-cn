# `（简单）` [263.ugly-number 丑数](https://leetcode-cn.com/problems/ugly-number/)

### 题目描述
<p>编写一个程序判断给定的数是否为丑数。</p>

<p>丑数就是只包含质因数&nbsp;<code>2, 3, 5</code>&nbsp;的<strong>正整数</strong>。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 6
<strong>输出:</strong> true
<strong>解释: </strong>6 = 2 ×&nbsp;3</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 8
<strong>输出:</strong> true
<strong>解释: </strong>8 = 2 × 2 ×&nbsp;2
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre><strong>输入:</strong> 14
<strong>输出:</strong> false 
<strong>解释: </strong><code>14</code> 不是丑数，因为它包含了另外一个质因数&nbsp;<code>7</code>。</pre>

<p><strong>说明：</strong></p>

<ol>
	<li><code>1</code>&nbsp;是丑数。</li>
	<li>输入不会超过 32 位有符号整数的范围:&nbsp;[−2<sup>31</sup>,&nbsp; 2<sup>31&nbsp;</sup>− 1]。</li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/bulls-and-cows/solution/299-by-ikaruga/)

### 答题
``` C++
bool isUgly(int num) 
{
    if (num == 0) return false;
    while (num % 2 == 0)
    {
        num /= 2;
    }
    while (num % 3 == 0)
    {
        num /= 3;
    }
    while (num % 5 == 0)
    {
        num /= 5;
    }
    return num == 1;
}
```




