# `（中等）` [1347.minimum-number-of-steps-to-make-two-strings-anagram 制造字母异位词的最小步骤数](https://leetcode-cn.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/)

[contest](https://leetcode-cn.com/contest/weekly-contest-175/problems/minimum-number-of-steps-to-make-two-strings-anagram/)

### 题目描述
<p>给你两个长度相等的字符串&nbsp;<code>s</code> 和 <code>t</code>。每一个步骤中，你可以选择将&nbsp;<code>t</code>&nbsp;中的 <strong>任一字符</strong> 替换为 <strong>另一个字符</strong>。</p>

<p>返回使&nbsp;<code>t</code>&nbsp;成为&nbsp;<code>s</code>&nbsp;的字母异位词的最小步骤数。</p>

<p><strong>字母异位词</strong> 指字母相同，但排列不同的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输出：</strong>s = "bab", t = "aba"
<strong>输出：</strong>1
<strong>提示：</strong>用 'b' 替换 t 中的第一个 'a'，t = "bba" 是 s 的一个字母异位词。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输出：</strong>s = "leetcode", t = "practice"
<strong>输出：</strong>5
<strong>提示：</strong>用合适的字符替换 t 中的 'p', 'r', 'a', 'i' 和 'c'，使 t 变成 s 的字母异位词。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输出：</strong>s = "anagram", t = "mangaar"
<strong>输出：</strong>0
<strong>提示：</strong>"anagram" 和 "mangaar" 本身就是一组字母异位词。 
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输出：</strong>s = "xxyyzz", t = "xxyyzz"
<strong>输出：</strong>0
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输出：</strong>s = "friend", t = "family"
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50000</code></li>
	<li><code>s.length == t.length</code></li>
	<li><code>s</code> 和 <code>t</code>&nbsp;只包含小写英文字母</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
int minSteps(string s, string t) 
{
    vector<int> char_s(26, 0);
    vector<int> char_t(26, 0);
    for (auto c : s)
    {
        char_s[c - 'a']++;
    }
    for (auto c : t)
    {
        char_t[c - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        ans += (char_s[i] > char_t[i]) ? char_s[i] - char_t[i] : 0;
    }
    return ans;
}
```




