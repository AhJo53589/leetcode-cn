# `（简单）` [504.base-7 七进制数](https://leetcode-cn.com/problems/base-7/)

### 题目描述
<p>给定一个整数，将其转化为7进制，并以字符串形式输出。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 100
<strong>输出:</strong> "202"
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> -7
<strong>输出:</strong> "-10"
</pre>

<p><strong>注意:</strong> 输入范围是&nbsp;[-1e7, 1e7] 。</p>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    string convertToBase7(int num) 
    {
        if (num < 0) return "-" + convertToBase7(-1 * num);
        if (num < 7) return to_string(num);
        return convertToBase7(num / 7) + to_string(num % 7);
    }
};
```




