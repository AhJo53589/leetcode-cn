# `（困难）` [1611.minimum-one-bit-operations-to-make-integers-zero 使整数变为 0 的最少操作次数](https://leetcode-cn.com/problems/minimum-one-bit-operations-to-make-integers-zero/)

[contest](https://leetcode-cn.com/contest/weekly-contest-209/problems/minimum-one-bit-operations-to-make-integers-zero/)

### 题目描述
<p>给你一个整数 <code>n</code>，你需要重复执行多次下述操作将其转换为 <code>0</code> ：</p>

<ul>
	<li>翻转 <code>n</code> 的二进制表示中最右侧位（第 <code>0</code> 位）。</li>
	<li>如果第 <code>(i-1)</code> 位为 <code>1</code> 且从第 <code>(i-2)</code> 位到第 <code>0</code> 位都为 <code>0</code>，则翻转 <code>n</code> 的二进制表示中的第 <code>i</code> 位。</li>
</ul>

<p>返回将 <code>n</code> 转换为 <code>0</code> 的最小操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 0
<strong>输出：</strong>0
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 3
<strong>输出：</strong>2
<strong>解释：</strong>3 的二进制表示为 "11"
"<strong>1</strong>1" -&gt; "<strong>0</strong>1" ，执行的是第 2 种操作，因为第 0 位为 1 。
"0<strong>1</strong>" -&gt; "0<strong>0</strong>" ，执行的是第 1 种操作。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 6
<strong>输出：</strong>4
<strong>解释：</strong>6 的二进制表示为 "110".
"<strong>1</strong>10" -&gt; "<strong>0</strong>10" ，执行的是第 2 种操作，因为第 1 位为 1 ，第 0 到 0 位为 0 。
"01<strong>0</strong>" -&gt; "01<strong>1</strong>" ，执行的是第 1 种操作。
"0<strong>1</strong>1" -&gt; "0<strong>0</strong>1" ，执行的是第 2 种操作，因为第 0 位为 1 。
"00<strong>1</strong>" -&gt; "00<strong>0</strong>" ，执行的是第 1 种操作。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 9
<strong>输出：</strong>14
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>n = 333
<strong>输出：</strong>393
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int minimumOneBitOperations(int n) {

    }
};
```




