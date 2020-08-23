# `（中等）` [201.bitwise-and-of-numbers-range 数字范围按位与](https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/)

### 题目描述
<p>给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。</p>

<p><strong>示例 1:&nbsp;</strong></p>

<pre><strong>输入:</strong> [5,7]
<strong>输出:</strong> 4</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [0,1]
<strong>输出:</strong> 0</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            // 抹去最右边的 1
            n = n & (n - 1);
        }
        return n;
    }
};
```




