# `（简单）` [1624.largest-substring-between-two-equal-characters 两个相同字符之间的最长子字符串](https://leetcode-cn.com/problems/largest-substring-between-two-equal-characters/)

[contest](https://leetcode-cn.com/contest/weekly-contest-211/problems/largest-substring-between-two-equal-characters/)

### 题目描述
<p>给你一个字符串 <code>s</code>，请你返回 <strong>两个相同字符之间的最长子字符串的长度</strong> <em>，</em>计算长度时不含这两个字符。如果不存在这样的子字符串，返回 <code>-1</code> 。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "aa"
<strong>输出：</strong>0
<strong>解释：</strong>最优的子字符串是两个 'a' 之间的空子字符串。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abca"
<strong>输出：</strong>2
<strong>解释：</strong>最优的子字符串是 "bc" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "cbzxy"
<strong>输出：</strong>-1
<strong>解释：</strong>s 中不存在出现出现两次的字符，所以返回 -1 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = "cabbac"
<strong>输出：</strong>4
<strong>解释：</strong>最优的子字符串是 "abba" ，其他的非最优解包括 "bb" 和 "" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 300</code></li>
	<li><code>s</code> 只含小写英文字母</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        vector<vector<int>> pos(26, vector<int>(2, -1));
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            pos[c][1] = (pos[c][0] != -1) ? i : pos[c][1];
            pos[c][0] = (pos[c][0] == -1) ? i : pos[c][0];
            ans = (pos[c][1] != -1) ? max(ans, pos[c][1] - pos[c][0] - 1) : ans;
        }
        return ans;
    }
};
```




