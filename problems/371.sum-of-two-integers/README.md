# `（简单）`  [371.sum-of-two-integers 两整数之和](https://leetcode-cn.com/problems/sum-of-two-integers/)

### 题目描述
<p><strong>不使用</strong>运算符&nbsp;<code>+</code> 和&nbsp;<code>-</code>&nbsp;​​​​​​​，计算两整数&nbsp;​​​​​​​<code>a</code>&nbsp;、<code>b</code>&nbsp;​​​​​​​之和。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>a = 1, b = 2
<strong>输出: </strong>3
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>a = -2, b = 3
<strong>输出: </strong>1</pre>


---
### 思路
```
c = a ^ b得到不包括进位的和
d = a & b得到哪些是进位
当d不为0时，只要再计算c与(d<<1)的和即可
```

### 答题
``` C++
    int getSum(int a, int b)
    {
        int c = a ^ b;
        unsigned int d = a & b;
#if 0
    // method one(faster but expend too much memory)
    return 0 != d ? getSum(c, d << 1) : c;
#else
    // method two(lower memory but slow)
    while (d)
    {
        d <<= 1;
        int t = c ^ d;
        d = c & d;
        c = t;
    }
    return c;
#endif
    }
```

### 其它
``` C++
```

