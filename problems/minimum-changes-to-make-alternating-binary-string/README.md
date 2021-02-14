# `（简单）` [5676.minimum-changes-to-make-alternating-binary-string 生成交替二进制字符串的最少操作数](https://leetcode-cn.com/problems/minimum-changes-to-make-alternating-binary-string/)

[contest](https://leetcode-cn.com/contest/weekly-contest-228/problems/minimum-changes-to-make-alternating-binary-string/)

### 题目描述
<div class="notranslate"><p>给你一个仅由字符 <code>'0'</code> 和 <code>'1'</code> 组成的字符串 <code>s</code> 。一步操作中，你可以将任一 <code>'0'</code> 变成 <code>'1'</code> ，或者将 <code>'1'</code> 变成 <code>'0'</code> 。</p>

<p><strong>交替字符串</strong> 定义为：如果字符串中不存在相邻两个字符相等的情况，那么该字符串就是交替字符串。例如，字符串 <code>"010"</code> 是交替字符串，而字符串 <code>"0100"</code> 不是。</p>

<p>返回使 <code>s</code> 变成 <strong>交替字符串</strong> 所需的 <strong>最少</strong> 操作数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "0100"
<strong>输出：</strong>1
<strong>解释：</strong>如果将最后一个字符变为 '1' ，s 就变成 "0101" ，即符合交替字符串定义。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "10"
<strong>输出：</strong>0
<strong>解释：</strong>s 已经是交替字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "1111"
<strong>输出：</strong>2
<strong>解释：</strong>需要 2 步操作得到 "0101" 或 "1010" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s[i]</code> 是 <code>'0'</code> 或 <code>'1'</code></li>
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
    int minOperations(string s) {
        return min(count(s, '0'), count(s, '1'));
    }

    int count(string s, char cur) {
        int ans = 0;
        for (auto c : s) {
            ans += (c != cur);
            cur = (cur == '0') ? '1' : '0';
        }
        return ans;
    }
};
```




