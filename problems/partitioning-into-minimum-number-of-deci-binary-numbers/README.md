# `（中等）` [5626.partitioning-into-minimum-number-of-deci-binary-numbers 十-二进制数的最少数目](https://leetcode-cn.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/)

[contest](https://leetcode-cn.com/contest/weekly-contest-219/problems/partitioning-into-minimum-number-of-deci-binary-numbers/)

### 题目描述
<div class="notranslate"><p>如果一个十进制数字不含任何前导零，且每一位上的数字不是 <code>0</code> 就是 <code>1</code> ，那么该数字就是一个 <strong>十-二进制数</strong> 。例如，<code>101</code> 和 <code>1100</code> 都是 <strong>十-二进制数</strong>，而 <code>112</code> 和 <code>3001</code> 不是。</p>

<p>给你一个表示十进制整数的字符串 <code>n</code> ，返回和为 <code>n</code> 的 <strong>十-二进制数 </strong>的最少数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = "32"
<strong>输出：</strong>3
<strong>解释：</strong>10 + 11 + 11 = 32
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = "82734"
<strong>输出：</strong>8
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = "27346209830709182346"
<strong>输出：</strong>9
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n.length &lt;= 10<sup>5</sup></code></li>
	<li><code>n</code> 仅由数字组成</li>
	<li><code>n</code> 不含任何前导零并总是表示正整数</li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (auto c : n) {
            ans = max(ans, (int)(c - '0'));
        }
        return (n == "0") ? 1 : ans;
    }
};
```




