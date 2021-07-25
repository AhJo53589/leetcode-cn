# `（中等）` [5824.largest-number-after-mutating-substring 子字符串突变后可能得到的最大整数](https://leetcode-cn.com/problems/largest-number-after-mutating-substring/)

[contest](https://leetcode-cn.com/contest/weekly-contest-251/problems/largest-number-after-mutating-substring/)

### 题目描述
<div class="notranslate"><p>给你一个字符串 <code>num</code> ，该字符串表示一个大整数。另给你一个长度为 <code>10</code> 且 <strong>下标从 0&nbsp; 开始</strong> 的整数数组 <code>change</code> ，该数组将 <code>0-9</code> 中的每个数字映射到另一个数字。更规范的说法是，数字 <code>d</code> 映射为数字 <code>change[d]</code> 。</p>

<p>你可以选择 <strong>突变</strong>&nbsp; <code>num</code> 的任一子字符串。<strong>突变</strong> 子字符串意味着将每位数字 <code>num[i]</code> 替换为该数字在 <code>change</code> 中的映射（也就是说，将 <code>num[i]</code> 替换为 <code>change[num[i]]</code>）。</p>

<p>请你找出在对 <code>num</code> 的任一子字符串执行突变操作（也可以不执行）后，可能得到的 <strong>最大整数</strong> ，并用字符串表示返回。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = "<strong><em>1</em></strong>32", change = [9,8,5,0,3,6,4,2,6,8]
<strong>输出：</strong>"<strong><em>8</em></strong>32"
<strong>解释：</strong>替换子字符串 "1"：
- 1 映射为 change[1] = 8 。
因此 "<strong><em>1</em></strong>32" 变为 "<strong><em>8</em></strong>32" 。
"832" 是可以构造的最大整数，所以返回它的字符串表示。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = "<strong><em>021</em></strong>", change = [9,4,3,5,7,2,1,9,0,6]
<strong>输出：</strong>"<strong><em>934</em></strong>"
<strong>解释：</strong>替换子字符串 "021"：
- 0 映射为 change[0] = 9 。
- 2 映射为 change[2] = 3 。
- 1 映射为 change[1] = 4 。
因此，"<strong><em>021</em></strong>" 变为 "<strong><em>934</em></strong>" 。
"934" 是可以构造的最大整数，所以返回它的字符串表示。 
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = "5", change = [1,4,7,5,3,2,5,6,9,4]
<strong>输出：</strong>"5"
<strong>解释：</strong>"5" 已经是可以构造的最大整数，所以返回它的字符串表示。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 10<sup>5</sup></code></li>
	<li><code>num</code> 仅由数字 <code>0-9</code> 组成</li>
	<li><code>change.length == 10</code></li>
	<li><code>0 &lt;= change[d] &lt;= 9</code></li>
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
    string maximumNumber(string num, vector<int>& change) {
        int state = 0;
        for (auto& c : num) {
            int n = c - '0';
            if (state == 0 and n >= change[n]) continue;
            if (state == 1 and n > change[n]) break;
            c = (char)('0' + change[n]);
            state = 1;
        }
        return num;
    }
};
```




