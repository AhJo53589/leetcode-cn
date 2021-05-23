# `（中等）` [5765.jump-game-vii 跳跃游戏 VII](https://leetcode-cn.com/problems/jump-game-vii/)

[contest](https://leetcode-cn.com/contest/weekly-contest-242/problems/jump-game-vii/)

### 题目描述
<div class="notranslate"><p>给你一个下标从 <strong>0 </strong>开始的二进制字符串&nbsp;<code>s</code>&nbsp;和两个整数&nbsp;<code>minJump</code> 和&nbsp;<code>maxJump</code>&nbsp;。一开始，你在下标&nbsp;<code>0</code>&nbsp;处，且该位置的值一定为&nbsp;<code>'0'</code>&nbsp;。当同时满足如下条件时，你可以从下标&nbsp;<code>i</code>&nbsp;移动到下标&nbsp;<code>j</code>&nbsp;处：</p>

<ul>
	<li><code>i + minJump &lt;= j &lt;= min(i + maxJump, s.length - 1)</code>&nbsp;且</li>
	<li><code>s[j] == '0'</code>.</li>
</ul>

<p>如果你可以到达 <code>s</code>&nbsp;的下标<i>&nbsp;</i><code>s.length - 1</code>&nbsp;处，请你返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "<strong>0</strong>11<strong>0</strong>1<strong>0</strong>", minJump = 2, maxJump = 3
<b>输出：</b>true
<strong>解释：</strong>
第一步，从下标 0 移动到下标 3 。
第二步，从下标 3 移动到下标 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "01101110", minJump = 2, maxJump = 3
<b>输出：</b>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code>&nbsp;要么是&nbsp;<code>'0'</code>&nbsp;，要么是&nbsp;<code>'1'</code></li>
	<li><code>s[0] == '0'</code></li>
	<li><code>1 &lt;= minJump &lt;= maxJump &lt; s.length</code></li>
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
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool> dp(s.size(), false);
        dp.front() = true;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1') continue;
            for (int j = minJump; j <= maxJump && i - j >= 0; j++) {
                if (!dp[i - j]) continue;
                dp[i] = true;
                break;
            }
            if (i > maxJump && !dp[i]) return false;
        }
        return dp.back();
    }
};
```




