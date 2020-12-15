# `（中等）` [738.monotone-increasing-digits 单调递增的数字](https://leetcode-cn.com/problems/monotone-increasing-digits/)

### 题目描述
<p>给定一个非负整数&nbsp;<code>N</code>，找出小于或等于&nbsp;<code>N</code>&nbsp;的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。</p>

<p>（当且仅当每个相邻位数上的数字&nbsp;<code>x</code>&nbsp;和&nbsp;<code>y</code>&nbsp;满足&nbsp;<code>x &lt;= y</code>&nbsp;时，我们称这个整数是单调递增的。）</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> N = 10
<strong>输出:</strong> 9
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> N = 1234
<strong>输出:</strong> 1234
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> N = 332
<strong>输出:</strong> 299
</pre>

<p><strong>说明:</strong> <code>N</code>&nbsp;是在&nbsp;<code>[0, 10^9]</code>&nbsp;范围内的一个整数。</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/monotone-increasing-digits/solution/monotone-increasing-digits-by-ikaruga-05cd/)

### 答题
``` C++
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int pos = INT_MAX;
        for (int i = str.size() - 2; i >= 0; i--) {
            pos = (str[i] > str[i + 1]) ? i : pos;
            pos = (pos == i + 1 && str[i] == str[i + 1]) ? i : pos;
        }
        for (int i = 0; i < str.size(); i++) {
            str[i] = (i > pos) ? '9' : (i == pos) ? (char)(str[i] - 1) : str[i];
        }
        return stoi(str);
    }
};
```




