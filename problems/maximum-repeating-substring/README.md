# `（简单）` [1668.maximum-repeating-substring 最大重复子字符串](https://leetcode-cn.com/problems/maximum-repeating-substring/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-40/problems/maximum-repeating-substring/)

### 题目描述
<div class="question-content default-content">
              <p>给你一个字符串&nbsp;<code>sequence</code>&nbsp;，如果字符串 <code>word</code>&nbsp;连续重复&nbsp;<code>k</code>&nbsp;次形成的字符串是&nbsp;<code>sequence</code>&nbsp;的一个子字符串，那么单词&nbsp;<code>word</code> 的 <strong>重复值为 <code>k</code></strong><strong> </strong>。单词 <code>word</code>&nbsp;的 <strong>最</strong><strong>大重复值</strong>&nbsp;是单词&nbsp;<code>word</code>&nbsp;在&nbsp;<code>sequence</code>&nbsp;中最大的重复值。如果&nbsp;<code>word</code>&nbsp;不是&nbsp;<code>sequence</code>&nbsp;的子串，那么重复值&nbsp;<code>k</code>&nbsp;为 <code>0</code> 。</p>

<p>给你一个字符串 <code>sequence</code>&nbsp;和 <code>word</code>&nbsp;，请你返回 <strong>最大重复值&nbsp;<code>k</code> </strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>sequence = "ababc", word = "ab"
<b>输出：</b>2
<strong>解释：</strong>"abab" 是 "<strong>abab</strong>c" 的子字符串。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>sequence = "ababc", word = "ba"
<b>输出：</b>1
<strong>解释：</strong>"ba" 是 "a<strong>ba</strong>bc" 的子字符串，但 "baba" 不是 "ababc" 的子字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>sequence = "ababc", word = "ac"
<b>输出：</b>0
<strong>解释：</strong>"ac" 不是 "ababc" 的子字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sequence.length &lt;= 100</code></li>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>sequence</code> 和&nbsp;<code>word</code>&nbsp;都只包含小写英文字母。</li>
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
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        for (int i = 0; i < sequence.size(); i++) {
            int k = 0;
            for (int j = i; j < sequence.size(); j++) {
                if (sequence[j] != word[(j - i) % word.size()]) break;
                if ((j - i + 1) % word.size() == 0) {
                    ans = max(ans, ++k);
                }
            }
        }
        return ans;
    }
};
```




