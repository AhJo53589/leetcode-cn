# `（中等）` [5919.vowels-of-all-substrings 所有子字符串中的元音](https://leetcode-cn.com/problems/vowels-of-all-substrings/)

[contest](https://leetcode-cn.com/contest/weekly-contest-266/problems/vowels-of-all-substrings/)

### 题目描述
<div class="notranslate"><p>给你一个字符串 <code>word</code> ，返回 <code>word</code> 的所有子字符串中 <strong>元音的总数</strong> ，元音是指 <code>'a'</code>、<code>'e'</code><em>、</em><code>'i'</code><em>、</em><code>'o'</code><em> </em>和 <code>'u'</code><em> 。</em></p>

<p><strong>子字符串</strong> 是字符串中一个连续（非空）的字符序列。</p>

<p><strong>注意：</strong>由于对 <code>word</code> 长度的限制比较宽松，答案可能超过有符号 32 位整数的范围。计算时需当心。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>word = "aba"
<strong>输出：</strong>6
<strong>解释：</strong>
所有子字符串是："a"、"ab"、"aba"、"b"、"ba" 和 "a" 。
- "b" 中有 0 个元音
- "a"、"ab"、"ba" 和 "a" 每个都有 1 个元音
- "aba" 中有 2 个元音
因此，元音总数 = 0 + 1 + 1 + 1 + 1 + 2 = 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>word = "abc"
<strong>输出：</strong>3
<strong>解释：</strong>
所有子字符串是："a"、"ab"、"abc"、"b"、"bc" 和 "c" 。
- "a"、"ab" 和 "abc" 每个都有 1 个元音
- "b"、"bc" 和 "c" 每个都有 0 个元音
因此，元音总数 = 1 + 1 + 1 + 0 + 0 + 0 = 3 。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>word = "ltcd"
<strong>输出：</strong>0
<strong>解释：</strong>"ltcd" 的子字符串均不含元音。</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>word = "noosabasboosa"
<strong>输出：</strong>237
<strong>解释：</strong>所有子字符串中共有 237 个元音。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code> 由小写英文字母组成</li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/vowels-of-all-substrings/solution/vowels-of-all-substrings-by-ikaruga-y0gy/)

### 答题
``` C++
class Solution {
public:
    long long countVowels(string word) {
        unordered_set<char> ci{ 'a', 'e', 'i', 'o', 'u' };

        long long ans = 0;
        for (int i = 0; i < word.size(); i++) {
            if (ci.find(word[i]) == ci.end()) continue;

            int left = i + 1;
            int right = (int)word.size() - i;
            ans += 1LL * left * right;
        }
        return ans;
    }
};
```




