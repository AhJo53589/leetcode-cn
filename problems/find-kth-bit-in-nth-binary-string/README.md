# `（中等）` [1545.find-kth-bit-in-nth-binary-string 找出第 N 个二进制字符串中的第 K 位](https://leetcode-cn.com/problems/find-kth-bit-in-nth-binary-string/)

[contest](https://leetcode-cn.com/contest/weekly-contest-201/problems/find-kth-bit-in-nth-binary-string/)

### 题目描述
<p>给你两个正整数 <code>n</code> 和 <code>k</code>，二进制字符串&nbsp; <code>S<sub>n</sub></code> 的形成规则如下：</p>

<ul>
	<li><code>S<sub>1</sub>&nbsp;= "0"</code></li>
	<li>当 <code>i > 1</code> 时，<code>S<sub>i</sub>&nbsp;=&nbsp;S<sub>i-1</sub>&nbsp;+ "1" + reverse(invert(S<sub>i-1</sub>))</code></li>
</ul>

<p>其中 <code>+</code> 表示串联操作，<code>reverse(x)</code> 返回反转 <code>x</code> 后得到的字符串，而 <code>invert(x)</code> 则会翻转 x 中的每一位（0 变为 1，而 1 变为 0）</p>

<p>例如，符合上述描述的序列的前 4 个字符串依次是：</p>

<ul>
	<li><code>S<sub>1&nbsp;</sub>= "0"</code></li>
	<li><code>S<sub>2&nbsp;</sub>= "0<strong>1</strong>1"</code></li>
	<li><code>S<sub>3&nbsp;</sub>= "011<strong>1</strong>001"</code></li>
	<li><code>S<sub>4</sub> = "0111001<strong>1</strong>0110001"</code></li>
</ul>

<p>请你返回&nbsp; <code>S<sub>n</sub></code> 的 <strong>第 <code>k</code> 位字符</strong> ，题目数据保证 <code>k</code> 一定在 <code>S<sub>n</sub></code> 长度范围以内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 3, k = 1
<strong>输出：</strong>"0"
<strong>解释：</strong>S<sub>3</sub> 为 "<strong>0</strong>111001"，其第 1 位为 "0" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 4, k = 11
<strong>输出：</strong>"1"
<strong>解释：</strong>S<sub>4</sub> 为 "0111001101<strong>1</strong>0001"，其第 11 位为 "1" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 1, k = 1
<strong>输出：</strong>"0"
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 2, k = 3
<strong>输出：</strong>"1"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 20</code></li>
	<li><code>1 <= k <= 2<sup>n</sup> - 1</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    char findKthBit(int n, int k) {
        if (k == 1) return '0';
        string s = "0";
        while (--n > 0) {
            string t = s;
            s += "1";
            for (int i = t.size() - 1; i >= 0; i--) {
                s += (t[i] == '0') ? '1' : '0';
            }
        }
        return s[k - 1];
    }
};
```




