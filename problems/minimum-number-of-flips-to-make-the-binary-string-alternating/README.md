# `（中等）` [5778.minimum-number-of-flips-to-make-the-binary-string-alternating 使二进制字符串字符交替的最少反转次数](https://leetcode-cn.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/)

[contest](https://leetcode-cn.com/contest/weekly-contest-244/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/)

### 题目描述
<div class="notranslate"><p>给你一个二进制字符串&nbsp;<code>s</code>&nbsp;。你可以按任意顺序执行以下两种操作任意次：</p>

<ul>
	<li><strong>类型 1 ：删除</strong> 字符串&nbsp;<code>s</code>&nbsp;的第一个字符并将它 <strong>添加</strong>&nbsp;到字符串结尾。</li>
	<li><strong>类型 2 ：选择 </strong>字符串&nbsp;<code>s</code>&nbsp;中任意一个字符并将该字符&nbsp;<strong>反转&nbsp;</strong>，也就是如果值为&nbsp;<code>'0'</code>&nbsp;，则反转得到&nbsp;<code>'1'</code>&nbsp;，反之亦然。</li>
</ul>

<p>请你返回使 <code>s</code>&nbsp;变成 <strong>交替</strong> 字符串的前提下，&nbsp;<strong>类型 2&nbsp;</strong>的 <strong>最少</strong>&nbsp;操作次数&nbsp;。</p>

<p>我们称一个字符串是 <strong>交替</strong>&nbsp;的，需要满足任意相邻字符都不同。</p>

<ul>
	<li>比方说，字符串&nbsp;<code>"010"</code> 和&nbsp;<code>"1010"</code>&nbsp;都是交替的，但是字符串&nbsp;<code>"0100"</code>&nbsp;不是。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "111000"
<b>输出：</b>2
<b>解释：</b>执行第一种操作两次，得到 s = "100011" 。
然后对第三个和第六个字符执行第二种操作，得到 s = "10<strong>1</strong>01<strong>0</strong>" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "010"
<b>输出：</b>0
<strong>解释：</strong>字符串已经是交替的。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>s = "1110"
<b>输出：</b>1
<b>解释：</b>对第二个字符执行第二种操作，得到 s = "1<strong>0</strong>10" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code>&nbsp;要么是&nbsp;<code>'0'</code>&nbsp;，要么是&nbsp;<code>'1'</code>&nbsp;。</li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/solution/minimum-number-of-flips-by-ikaruga-lu32/)

### 答题
``` C++
class Solution {
public:
    int minFlips(string s) {
        int len = s.size();
        string target = "01";

        int cnt = 0;
        for (int i = 0; i < len; i++) {
            cnt += (s[i] != target[i % 2]);
        }

        s += s;
        int ans = min({ cnt, len - cnt });
        for (int i = 0; i < len; i++) {
            cnt -= (s[i] != target[i % 2]);
            cnt += (s[i + len] != target[(i + len) % 2]);
            ans = min({ ans, cnt, len - cnt });
        }

        return ans;
    }
};
```




