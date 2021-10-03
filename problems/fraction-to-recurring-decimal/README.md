# `（中等）` [166.fraction-to-recurring-decimal 分数到小数](https://leetcode-cn.com/problems/fraction-to-recurring-decimal/)

### 题目描述
<div class="notranslate"><p>给定两个整数，分别表示分数的分子&nbsp;<code>numerator</code> 和分母 <code>denominator</code>，以 <strong>字符串形式返回小数</strong> 。</p>

<p>如果小数部分为循环小数，则将循环的部分括在括号内。</p>

<p class="MachineTrans-lang-zh-CN">如果存在多个答案，只需返回 <strong>任意一个</strong> 。</p>

<p class="MachineTrans-lang-zh-CN">对于所有给定的输入，<strong>保证</strong> 答案字符串的长度小于 <code>10<sup>4</sup></code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>numerator = 1, denominator = 2
<strong>输出：</strong>"0.5"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>numerator = 2, denominator = 1
<strong>输出：</strong>"2"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>numerator = 2, denominator = 3
<strong>输出：</strong>"0.(6)"
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>numerator = 4, denominator = 333
<strong>输出：</strong>"0.(012)"
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>numerator = 1, denominator = 5
<strong>输出：</strong>"0.2"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;=&nbsp;numerator, denominator &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>denominator != 0</code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/fraction-to-recurring-decimal/solution/fraction-to-recurring-decimal-by-ikaruga-uggy/)

### 答题
``` C++
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        int na = (numerator < 0) ? -1 : 1;
        int nb = (denominator < 0) ? -1 : 1;
        long long lln = 1LL * numerator * na;
        long long lld = 1LL * denominator * nb;

        string ans = (na * nb == -1) ? "-" : "";
        ans += to_string(lln / lld);
        lln %= lld;
        lln *= 10;

        ans = (lln != 0) ? ans + '.' : ans;
        unordered_map<long long, int> um;
        while (lln != 0) {
            if (um.find(lln) != um.end()) {
                ans.insert(um[lln], 1, '(');
                ans += ')';
                break;
            }

            um[lln] = (int)ans.size();
            ans += to_string(lln / lld);
            lln %= lld;
            lln *= 10;
        }
        
        return ans;
    }
};
```




