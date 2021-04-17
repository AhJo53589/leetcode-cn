# `（困难）` [5720.minimum-number-of-operations-to-make-string-sorted 使字符串有序的最少操作次数](https://leetcode-cn.com/problems/minimum-number-of-operations-to-make-string-sorted/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-50/problems/minimum-number-of-operations-to-make-string-sorted/)

### 题目描述
<div class="question-content default-content">
              <p>给你一个字符串&nbsp;<code>s</code>&nbsp;（<strong>下标从 0 开始</strong>）。你需要对 <code>s</code>&nbsp;执行以下操作直到它变为一个有序字符串：</p>

<ol>
	<li>找到 <strong>最大下标</strong>&nbsp;<code>i</code>&nbsp;，使得&nbsp;<code>1 &lt;= i &lt; s.length</code> 且&nbsp;<code>s[i] &lt; s[i - 1]</code>&nbsp;。</li>
	<li>找到 <strong>最大下标</strong>&nbsp;<code>j</code>&nbsp;，使得&nbsp;<code>i &lt;= j &lt; s.length</code> 且对于所有在闭区间&nbsp;<code>[i, j]</code>&nbsp;之间的&nbsp;<code>k</code>&nbsp;都有&nbsp;<code>s[k] &lt; s[i - 1]</code>&nbsp;。</li>
	<li>交换下标为&nbsp;<code>i - 1</code>​​​​ 和&nbsp;<code>j</code>​​​​ 处的两个字符。</li>
	<li>将下标 <code>i</code>&nbsp;开始的字符串后缀反转。</li>
</ol>

<p>请你返回将字符串变成有序的最少操作次数。由于答案可能会很大，请返回它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "cba"
<b>输出：</b>5
<b>解释：</b>模拟过程如下所示：
操作 1：i=2，j=2。交换 s[1] 和 s[2] 得到 s="cab" ，然后反转下标从 2 开始的后缀字符串，得到 s="cab" 。
操作 2：i=1，j=2。交换 s[0] 和 s[2] 得到 s="bac" ，然后反转下标从 1 开始的后缀字符串，得到 s="bca" 。
操作 3：i=2，j=2。交换 s[1] 和 s[2] 得到 s="bac" ，然后反转下标从 2 开始的后缀字符串，得到 s="bac" 。
操作 4：i=1，j=1。交换 s[0] 和 s[1] 得到 s="abc" ，然后反转下标从 1 开始的后缀字符串，得到 s="acb" 。
操作 5：i=2，j=2。交换 s[1] 和 s[2] 得到 s="abc" ，然后反转下标从 2 开始的后缀字符串，得到 s="abc" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "aabaa"
<b>输出：</b>2
<b>解释：</b>模拟过程如下所示：
操作 1：i=3，j=4。交换 s[2] 和 s[4] 得到 s="aaaab" ，然后反转下标从 3 开始的后缀字符串，得到 s="aaaba" 。
操作 2：i=4，j=4。交换 s[3] 和 s[4] 得到 s="aaaab" ，然后反转下标从 4 开始的后缀字符串，得到 s="aaaab" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>s = "cdbea"
<b>输出：</b>63</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>s = "leetcodeleetcodeleetcode"
<b>输出：</b>982157772
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3000</code></li>
	<li><code>s</code>​ 只包含小写英文字母。</li>
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
    int makeStringSorted(string s) {

    }
};
```




