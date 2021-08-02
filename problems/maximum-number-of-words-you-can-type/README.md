# `（简单）` [5161.maximum-number-of-words-you-can-type 可以输入的最大单词数](https://leetcode-cn.com/problems/maximum-number-of-words-you-can-type/)

[contest](https://leetcode-cn.com/contest/weekly-contest-250/problems/maximum-number-of-words-you-can-type/)

### 题目描述
<div class="notranslate"><p>键盘出现了一些故障，有些字母键无法正常工作。而键盘上所有其他键都能够正常工作。</p>

<p>给你一个由若干单词组成的字符串 <code>text</code> ，单词间由单个空格组成（不含前导和尾随空格）；另有一个字符串 <code>brokenLetters</code> ，由所有已损坏的不同字母键组成，返回你可以使用此键盘完全输入的 <code>text</code> 中单词的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>text = "hello world", brokenLetters = "ad"
<strong>输出：</strong>1
<strong>解释：</strong>无法输入 "world" ，因为字母键 'd' 已损坏。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>text = "leet code", brokenLetters = "lt"
<strong>输出：</strong>1
<strong>解释：</strong>无法输入 "leet" ，因为字母键 'l' 和 't' 已损坏。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>text = "leet code", brokenLetters = "e"
<strong>输出：</strong>0
<strong>解释：</strong>无法输入任何单词，因为字母键 'e' 已损坏。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= brokenLetters.length &lt;= 26</code></li>
	<li><code>text</code> 由若干用单个空格分隔的单词组成，且不含任何前导和尾随空格</li>
	<li>每个单词仅由小写英文字母组成</li>
	<li><code>brokenLetters</code> 由 <strong>互不相同</strong> 的小写英文字母组成</li>
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
    int canBeTypedWords(string text, string brokenLetters) {
        bitset<26> broken;
        for (auto c : brokenLetters) {
            broken[c - 'a'] = 1;
        }

        int ans = 0;
        string temp;
        stringstream ss(text);
        while (ss >> temp) {
            int t = temp.size();
            for (auto c : temp) {
                if (broken.test(c - 'a')) break;
                t--;
            }
            ans += (t == 0);
        }
        return ans;
    }
};
```




