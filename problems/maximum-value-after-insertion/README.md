# `（中等）` [5773.maximum-value-after-insertion 插入后的最大值](https://leetcode-cn.com/problems/maximum-value-after-insertion/)

[contest](https://leetcode-cn.com/contest/weekly-contest-243/problems/maximum-value-after-insertion/)

### 题目描述
<div class="notranslate"><p>给你一个非常大的整数 <code>n</code> 和一个整数数字 <code>x</code> ，大整数 <code>n</code>&nbsp;用一个字符串表示。<code>n</code> 中每一位数字和数字 <code>x</code> 都处于闭区间 <code>[1, 9]</code> 中，且 <code>n</code> 可能表示一个 <strong>负数</strong> 。</p>

<p>你打算通过在 <code>n</code> 的十进制表示的任意位置插入 <code>x</code> 来 <strong>最大化</strong> <code>n</code> 的 <strong>数值</strong> ​​​​​​。但 <strong>不能</strong> 在负号的左边插入 <code>x</code> 。</p>

<ul>
	<li>例如，如果 <code>n = 73</code> 且 <code>x = 6</code> ，那么最佳方案是将 <code>6</code> 插入 <code>7</code> 和 <code>3</code> 之间，使 <code>n = 763</code> 。</li>
	<li>如果 <code>n = -55</code> 且 <code>x = 2</code> ，那么最佳方案是将 <code>2</code> 插在第一个 <code>5</code> 之前，使 <code>n = -255</code> 。</li>
</ul>

<p>返回插入操作后，用字符串表示的&nbsp;<code>n</code> 的最大值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = "99", x = 9
<strong>输出：</strong>"999"
<strong>解释：</strong>不管在哪里插入 9 ，结果都是相同的。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = "-13", x = 2
<strong>输出：</strong>"-123"
<strong>解释：</strong>向 n 中插入 x 可以得到 -213、-123 或者 -132 ，三者中最大的是 -123 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= x &lt;= 9</code></li>
	<li><code>n</code>​​​ 中每一位的数字都在闭区间 <code>[1, 9]</code> 中。</li>
	<li><code>n</code>&nbsp;代表一个有效的整数。</li>
	<li>当 <code>n</code> 表示负数时，将会以字符 <code>'-'</code> 开始。</li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-value-after-insertion/solution/maximum-value-after-insertion-by-ikaruga-b83v/)

### 答题
``` C++
class Solution {
public:
    string maxValue(string n, int x) {
        int flag = (n[0] == '-') ? -1 : 1;
        int i = (flag == -1) ? 1 : 0;
        for (; i < n.size(); i++) {
            if ((n[i] - '0') * flag < x * flag) break;
        }
        n.insert(i, 1, '0' + x);
        return n;
    }
};
```




