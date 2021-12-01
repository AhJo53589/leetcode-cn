# `（简单）` [1446.consecutive-characters 连续字符](https://leetcode-cn.com/problems/consecutive-characters/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-26/problems/consecutive-characters/)

### 题目描述
<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。</p>

<p>请你返回字符串的能量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "leetcode"
<strong>输出：</strong>2
<strong>解释：</strong>子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abbcccddddeeeeedcba"
<strong>输出：</strong>5
<strong>解释：</strong>子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "triplepillooooow"
<strong>输出：</strong>5
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = "hooraaaaaaaaaaay"
<strong>输出：</strong>11
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>s = "tourist"
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

            

---
### 思路
```
```


[发布的题解](https://leetcode-cn.com/problems/consecutive-characters/solution/consecutive-characters-by-ikaruga-afg5/)

### 答题
``` C++
class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int dp = 1;
        for (int i = 1; i < s.size(); i++) {
            dp = (s[i] == s[i - 1]) ? dp + 1 : 1;
            ans = max(ans, dp);
        }
        return ans;
    }
};
```




