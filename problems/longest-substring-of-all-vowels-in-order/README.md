# `（中等）` [5740.longest-substring-of-all-vowels-in-order 所有元音按顺序排布的最长子字符串](https://leetcode-cn.com/problems/longest-substring-of-all-vowels-in-order/)

[contest](https://leetcode-cn.com/contest/weekly-contest-238/problems/longest-substring-of-all-vowels-in-order/)

### 题目描述
<p>当一个字符串满足如下条件时，我们称它是 <b>美丽的</b>&nbsp;：</p>

<ul>
	<li>所有 5 个英文元音字母（<code>'a'</code>&nbsp;，<code>'e'</code>&nbsp;，<code>'i'</code>&nbsp;，<code>'o'</code>&nbsp;，<code>'u'</code>）都必须&nbsp;<strong>至少</strong>&nbsp;出现一次。</li>
	<li>这些元音字母的顺序都必须按照 <strong>字典序</strong>&nbsp;升序排布（也就是说所有的 <code>'a'</code>&nbsp;都在 <code>'e'</code>&nbsp;前面，所有的 <code>'e'</code>&nbsp;都在 <code>'i'</code>&nbsp;前面，以此类推）</li>
</ul>

<p>比方说，字符串&nbsp;<code>"aeiou"</code> 和&nbsp;<code>"aaaaaaeiiiioou"</code>&nbsp;都是 <strong>美丽的</strong>&nbsp;，但是&nbsp;<code>"uaeio"</code>&nbsp;，<code>"aeoiu"</code>&nbsp;和&nbsp;<code>"aaaeeeooo"</code>&nbsp;<strong>不是美丽的</strong>&nbsp;。</p>

<p>给你一个只包含英文元音字母的字符串&nbsp;<code>word</code>&nbsp;，请你返回&nbsp;<code>word</code> 中 <strong>最长美丽子字符串的长度</strong>&nbsp;。如果不存在这样的子字符串，请返回 <code>0</code>&nbsp;。</p>

<p><strong>子字符串</strong> 是字符串中一个连续的字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>word = "aeiaaio<strong>aaaaeiiiiouuu</strong>ooaauuaeiu"
<b>输出：</b>13
<b>解释：</b>最长子字符串是 "aaaaeiiiiouuu" ，长度为 13 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>word = "aeeeiiiioooauuu<strong>aeiou</strong>"
<b>输出：</b>5
<b>解释：</b>最长子字符串是 "aeiou" ，长度为 5 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>word = "a"
<b>输出：</b>0
<b>解释：</b>没有美丽子字符串，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>word</code>&nbsp;只包含字符&nbsp;<code>'a'</code>，<code>'e'</code>，<code>'i'</code>，<code>'o'</code>&nbsp;和&nbsp;<code>'u'</code>&nbsp;。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans = 0;
        int st = 0;
        string stand = "aeiou";

        int i = 0;
        int j = 0;
        while (i < word.size()) {
            st = 0;
            j = i;
            if (word[i] != stand[st]) {
                i++;
                continue;
            }
            while (j < word.size()) {
                if (word[j] == stand[st]) {
                    if (st + 1 == stand.size()) {
                        ans = max(ans, j - i + 1);
                    }
                    j++;
                    continue;
                }
                if (st == stand.size() || word[j] != stand[st + 1]) {
                    i = j;
                    break;
                }
                st++;
                if (st + 1 == stand.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
            if (j == word.size()) break;
        }
        return ans;
    }
};
```




