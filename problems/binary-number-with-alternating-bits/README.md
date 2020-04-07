# `（简单）` [693.binary-number-with-alternating-bits 交替位二进制数](https://leetcode-cn.com/problems/binary-number-with-alternating-bits/)

### 题目描述
<p>给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 5
<strong>输出:</strong> True
<strong>解释:</strong>
5的二进制数是: 101
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 7
<strong>输出:</strong> False
<strong>解释:</strong>
7的二进制数是: 111
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre><strong>输入:</strong> 11
<strong>输出:</strong> False
<strong>解释:</strong>
11的二进制数是: 1011
</pre>

<p><strong>&nbsp;示例 4:</strong></p>

<pre><strong>输入:</strong> 10
<strong>输出:</strong> True
<strong>解释:</strong>
10的二进制数是: 1010
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/binary-number-with-alternating-bits/solution/binary-number-with-alternating-bits-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        n = (n ^ (n >> 1));
        return (n & ((long)n + 1)) == 0;
    }
};
```




