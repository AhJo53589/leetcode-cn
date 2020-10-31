# `（中等）` [5541.count-substrings-that-differ-by-one-character 统计只差一个字符的子串数目](https://leetcode-cn.com/problems/count-substrings-that-differ-by-one-character/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-38/problems/count-substrings-that-differ-by-one-character/)

### 题目描述
<p>给你两个字符串&nbsp;<code>s</code> 和&nbsp;<code>t</code>&nbsp;，请你找出 <code>s</code>&nbsp;中的非空子串的数目，这些子串满足替换 <strong>一个不同字符</strong>&nbsp;以后，是 <code>t</code>&nbsp;串的子串。换言之，请你找到 <code>s</code>&nbsp;和 <code>t</code>&nbsp;串中 <strong>恰好</strong>&nbsp;只有一个字符不同的子字符串对的数目。</p>

<p>比方说，&nbsp;<code>"<strong>compute</strong>r"</code> 和&nbsp;<code>"<strong>computa</strong>tion"</code> 加粗部分只有一个字符不同：&nbsp;<code>'e'</code>/<code>'a'</code>&nbsp;，所以这一对子字符串会给答案加 1 。</p>

<p>请你返回满足上述条件的不同子字符串对数目。</p>

<p>一个 <strong>子字符串</strong>&nbsp;是一个字符串中连续的字符。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "aba", t = "baba"
<b>输出：</b>6
<strong>解释：</strong>以下为只相差 1 个字符的 s 和 t 串的子字符串对：
("<strong>a</strong>ba", "<strong>b</strong>aba")
("<strong>a</strong>ba", "ba<strong>b</strong>a")
("ab<strong>a</strong>", "<strong>b</strong>aba")
("ab<strong>a</strong>", "ba<strong>b</strong>a")
("a<strong>b</strong>a", "b<strong>a</strong>ba")
("a<strong>b</strong>a", "bab<strong>a</strong>")
加粗部分分别表示 s 和 t 串选出来的子字符串。
</pre>
<strong>示例 2：</strong>

<pre><b>输入：</b>s = "ab", t = "bb"
<b>输出：</b>3
<strong>解释：</strong>以下为只相差 1 个字符的 s 和 t 串的子字符串对：
("<strong>a</strong>b", "<strong>b</strong>b")
("<strong>a</strong>b", "b<strong>b</strong>")
("<strong>ab</strong>", "<strong>bb</strong>")
加粗部分分别表示 s 和 t 串选出来的子字符串。
</pre>
<strong>示例 3：</strong>

<pre><b>输入：</b>s = "a", t = "a"
<b>输出：</b>0
</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>s = "abe", t = "bbc"
<b>输出：</b>10
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 100</code></li>
	<li><code>s</code> 和&nbsp;<code>t</code>&nbsp;都只包含小写英文字母。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/count-substrings-that-differ-by-one-character/solution/count-substrings-that-differ-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < t.size(); j++) {
                int diff = 0;
                for (int k = 0; i + k < s.size() && j + k < t.size() && diff < 2; k++) {
                    diff += (s[i + k] != t[j + k]);
                    ans += (diff == 1);
                }
            }
        }
        return ans;
    }
};
```




