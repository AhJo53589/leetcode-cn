# `（简单）` [748.shortest-completing-word 最短完整词](https://leetcode-cn.com/problems/shortest-completing-word/)

### 题目描述
<p>如果单词列表（<code>words</code>）中的一个单词包含牌照（<code>licensePlate</code>）中所有的字母，那么我们称之为完整词。在所有完整词中，最短的单词我们称之为最短完整词。</p>

<p>单词在匹配牌照中的字母时不区分大小写，比如牌照中的&nbsp;<code>"P"</code>&nbsp;依然可以匹配单词中的&nbsp;<code>"p"</code>&nbsp;字母。</p>

<p>我们保证一定存在一个最短完整词。当有多个单词都符合最短完整词的匹配条件时取单词列表中最靠前的一个。</p>

<p>牌照中可能包含多个相同的字符，比如说：对于牌照 <code>"PP"</code>，单词&nbsp;<code>"pair"</code>&nbsp;无法匹配，但是&nbsp;<code>"supper"</code>&nbsp;可以匹配。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
<strong>输出：</strong>"steps"
<strong>说明：</strong>最短完整词应该包括 "s"、"p"、"s" 以及 "t"。对于 "step" 它只包含一个 "s" 所以它不符合条件。同时在匹配过程中我们忽略牌照中的大小写。</pre>

<p>&nbsp;</p>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
<strong>输出：</strong>"pest"
<strong>说明：</strong>存在 3 个包含字母 "s" 且有着最短长度的完整词，但我们返回最先出现的完整词。
</pre>

<p>&nbsp;</p>

<p><strong>注意:</strong></p>

<ol>
	<li>牌照<code>（licensePlate）</code>的长度在区域<code>[1, 7]</code>中。</li>
	<li>牌照<code>（licensePlate）</code>将会包含数字、空格、或者字母（大写和小写）。</li>
	<li>单词列表<code>（words）</code>长度在区间&nbsp;<code>[10, 1000]</code>&nbsp;中。</li>
	<li>每一个单词&nbsp;<code>words[i]</code>&nbsp;都是小写，并且长度在区间&nbsp;<code>[1, 15]</code>&nbsp;中。</li>
</ol>

<p>&nbsp;</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/shortest-completing-word/solution/shortest-completing-word-by-ikaruga/)

### 答题
``` C++[]
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        auto s = ""s;
        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                s += tolower(ch);
            }
        }

        sort(begin(s), end(s));
        stable_sort(begin(words), end(words), [](auto&&a, auto&& b) {
            return size(a) < size(b); 
            });

        for (auto&& w : words) {
            auto ww = w;
            sort(begin(ww), end(ww));
            if (includes(begin(ww), end(ww), begin(s), end(s))) return w;
        }
        return {};
    }
};
```




