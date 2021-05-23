# `（简单）` [5763.longer-contiguous-segments-of-ones-than-zeros 哪种连续子字符串更长](https://leetcode-cn.com/problems/longer-contiguous-segments-of-ones-than-zeros/)

[contest](https://leetcode-cn.com/contest/weekly-contest-242/problems/longer-contiguous-segments-of-ones-than-zeros/)

### 题目描述
<div class="notranslate"><p>给你一个二进制字符串 <code>s</code> 。如果字符串中由 <code>1</code> 组成的 <strong>最长</strong> 连续子字符串 <strong>严格长于</strong> 由 <code>0</code> 组成的 <strong>最长</strong> 连续子字符串，返回 <code>true</code> ；否则，返回 <code>false</code><em> </em>。</p>

<ul>
	<li>例如，<code>s = "<strong>11</strong>01<strong>000</strong>10"</code> 中，由 <code>1</code> 组成的最长连续子字符串的长度是 <code>2</code> ，由 <code>0</code> 组成的最长连续子字符串的长度是 <code>3</code> 。</li>
</ul>

<p>注意，如果字符串中不存在 <code>0</code> ，此时认为由 <code>0</code> 组成的最长连续子字符串的长度是 <code>0</code> 。字符串中不存在 <code>1</code> 的情况也适用此规则。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "1101"
<strong>输出：</strong>true
<strong>解释：</strong>
由 <code>1</code> 组成的最长连续子字符串的长度是 2："<strong>11</strong>01"
由 <code>0</code> 组成的最长连续子字符串的长度是 1："11<strong>0</strong>1"
由 1 组成的子字符串更长，故返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "111000"
<strong>输出：</strong>false
<strong>解释：</strong>
由 <code>1</code> 组成的最长连续子字符串的长度是 3："<strong>111</strong>000"
由<code> 0</code> 组成的最长连续子字符串的长度是 3："111<strong>000</strong>"
由 1 组成的子字符串不比由 0 组成的子字符串长，故返回 false 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "110100010"
<strong>输出：</strong>false
<strong>解释：</strong>
由 <code>1</code> 组成的最长连续子字符串的长度是 2："<strong>11</strong>0100010"
由 <code>0</code> 组成的最长连续子字符串的长度是 3："1101<strong>000</strong>10"
由 1 组成的子字符串不比由 0 组成的子字符串长，故返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s[i]</code> 不是 <code>'0'</code> 就是 <code>'1'</code></li>
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
    bool checkZeroOnes(string s) {
        vector<int> cnt(3);
        for (int i = 1; i <= s.size(); i++) {
            if (i != s.size() && s[i] == s[i - 1]) {
                cnt[2]++;
            }
            else {
                int last = s[i - 1] - '0';
                cnt[last] = max(cnt[last], cnt[2] + 1);
                cnt[2] = 0;
            }
        }
        return cnt[0] < cnt[1];
    }
};
```




