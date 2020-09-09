# `（简单）` [1556.thousand-separator 千位分隔数](https://leetcode-cn.com/problems/thousand-separator/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-33/problems/thousand-separator/)

### 题目描述
<p>给你一个整数&nbsp;<code>n</code>，请你每隔三位添加点（即 "." 符号）作为千位分隔符，并将结果以字符串格式返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 987
<strong>输出：</strong>"987"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 1234
<strong>输出：</strong>"1.234"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 123456789
<strong>输出：</strong>"123.456.789"
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 0
<strong>输出：</strong>"0"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= n < 2^31</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/thousand-separator/solution/thousand-separator-by-ikaruga/)

### 答题
``` C++
    string thousandSeparator(int n) {
        if (n == 0) return "0";
        string ans;
        int k = 0;
        while (n > 0) {
            if ((k++) % 3 == 0) {
                ans += ".";
            }
            ans += '0' + (n % 10);
            n /= 10;
        }
        reverse(ans.begin(), ans.end());
        ans.pop_back();
        return ans;
    }
```




