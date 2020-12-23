# `（中等）` [1680.concatenation-of-consecutive-binary-numbers 连接连续二进制数字](https://leetcode-cn.com/problems/concatenation-of-consecutive-binary-numbers/)

[contest](https://leetcode-cn.com/contest/weekly-contest-218/problems/concatenation-of-consecutive-binary-numbers/)

### 题目描述
<div class="notranslate"><p>给你一个整数&nbsp;<code>n</code>&nbsp;，请你将&nbsp;<code>1</code>&nbsp;到 <code>n</code>&nbsp;的二进制表示连接起来，并返回连接结果对应的 <strong>十进制</strong>&nbsp;数字对 <code>10<sup>9</sup>&nbsp;+ 7</code>&nbsp;取余的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 1
<b>输出：</b>1
<strong>解释：</strong>二进制的 "1" 对应着十进制的 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 3
<b>输出：</b>27
<strong>解释：</strong>二进制下，1，2 和 3 分别对应 "1" ，"10" 和 "11" 。
将它们依次连接，我们得到 "11011" ，对应着十进制的 27 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>n = 12
<b>输出：</b>505379714
<b>解释：</b>连接结果为 "1101110010111011110001001101010111100" 。
对应的十进制数字为 118505380540 。
对 10<sup>9</sup> + 7 取余后，结果为 505379714 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
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
    int concatenatedBinary(int n) {
        const long long mod = 1e9 + 7;

        string s;
        string t = "0";
        for (int i = 1; i <= n; i++) {
            addOne(t);
            s += t;
        }
        long long ans = 0;
        for (auto c : s) {
            ans *= 2;
            ans += (c == '1');
            ans %= mod;
        }
        return ans;
    }

    void addOne(string& s) {
        bool flag = true;
        for (int i = s.size() - 1; i >= 0 && flag; i--) {
            flag &= (s[i] == '1');
            s[i] = (s[i] == '1') ? '0' : '1';
        }
        if (flag) {
            s += '0';
            s.front() = '1';
        }
    }
};
```




