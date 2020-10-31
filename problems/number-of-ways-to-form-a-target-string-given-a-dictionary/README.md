# `（困难）` [5542.number-of-ways-to-form-a-target-string-given-a-dictionary 通过给定词典构造目标字符串的方案数](https://leetcode-cn.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-38/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/)

### 题目描述
<p>给你一个字符串列表 <code>words</code>&nbsp;和一个目标字符串&nbsp;<code>target</code> 。<code>words</code> 中所有字符串都&nbsp;<strong>长度相同</strong>&nbsp;&nbsp;。</p>

<p>你的目标是使用给定的 <code>words</code>&nbsp;字符串列表按照下述规则构造&nbsp;<code>target</code>&nbsp;：</p>

<ul>
	<li>从左到右依次构造&nbsp;<code>target</code>&nbsp;的每一个字符。</li>
	<li>为了得到&nbsp;<code>target</code> 第&nbsp;<code>i</code>&nbsp;个字符（下标从 <strong>0</strong>&nbsp;开始），当&nbsp;<code>target[i] = words[j][k]</code>&nbsp;时，你可以使用&nbsp;<code>words</code>&nbsp;列表中第 <code>j</code>&nbsp;个字符串的第 <code>k</code>&nbsp;个字符。</li>
	<li>一旦你使用了 <code>words</code>&nbsp;中第 <code>j</code>&nbsp;个字符串的第 <code>k</code>&nbsp;个字符，你不能再使用 <code>words</code>&nbsp;字符串列表中任意单词的第 <code>x</code>&nbsp;个字符（<code>x &lt;= k</code>）。也就是说，所有单词下标小于等于 <code>k</code>&nbsp;的字符都不能再被使用。</li>
	<li>请你重复此过程直到得到目标字符串&nbsp;<code>target</code>&nbsp;。</li>
</ul>

<p><strong>请注意</strong>， 在构造目标字符串的过程中，你可以按照上述规定使用 <code>words</code>&nbsp;列表中 <strong>同一个字符串</strong>&nbsp;的 <strong>多个字符</strong>&nbsp;。</p>

<p>请你返回使用 <code>words</code>&nbsp;构造 <code>target</code>&nbsp;的方案数。由于答案可能会很大，请对 <code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>（译者注：此题目求的是有多少个不同的 <code>k</code>&nbsp;序列，详情请见示例。）</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>words = ["acca","bbbb","caca"], target = "aba"
<b>输出：</b>6
<b>解释：</b>总共有 6 种方法构造目标串。
"aba" -&gt; 下标为 0 ("<strong>a</strong>cca")，下标为 1 ("b<strong>b</strong>bb")，下标为 3 ("cac<strong>a</strong>")
"aba" -&gt; 下标为 0 ("<strong>a</strong>cca")，下标为 2 ("bb<strong>b</strong>b")，下标为 3 ("cac<strong>a</strong>")
"aba" -&gt; 下标为 0 ("<strong>a</strong>cca")，下标为 1 ("b<strong>b</strong>bb")，下标为 3 ("acc<strong>a</strong>")
"aba" -&gt; 下标为 0 ("<strong>a</strong>cca")，下标为 2 ("bb<strong>b</strong>b")，下标为 3 ("acc<strong>a</strong>")
"aba" -&gt; 下标为 1 ("c<strong>a</strong>ca")，下标为 2 ("bb<strong>b</strong>b")，下标为 3 ("acc<strong>a</strong>")
"aba" -&gt; 下标为 1 ("c<strong>a</strong>ca")，下标为 2 ("bb<strong>b</strong>b")，下标为 3 ("cac<strong>a</strong>")
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>words = ["abba","baab"], target = "bab"
<b>输出：</b>4
<b>解释：</b>总共有 4 种不同形成 target 的方法。
"bab" -&gt; 下标为 0 ("<strong>b</strong>aab")，下标为 1 ("b<strong>a</strong>ab")，下标为 2 ("ab<strong>b</strong>a")
"bab" -&gt; 下标为 0 ("<strong>b</strong>aab")，下标为 1 ("b<strong>a</strong>ab")，下标为 3 ("baa<strong>b</strong>")
"bab" -&gt; 下标为 0 ("<strong>b</strong>aab")，下标为 2 ("ba<strong>a</strong>b")，下标为 3 ("baa<strong>b</strong>")
"bab" -&gt; 下标为 1 ("a<strong>b</strong>ba")，下标为 2 ("ba<strong>a</strong>b")，下标为 3 ("baa<strong>b</strong>")
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>words = ["abcd"], target = "abcd"
<b>输出：</b>1
</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>words = ["abab","baba","abba","baab"], target = "abba"
<b>输出：</b>16
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 1000</code></li>
	<li><code>words</code>&nbsp;中所有单词长度相同。</li>
	<li><code>1 &lt;= target.length &lt;= 1000</code></li>
	<li><code>words[i]</code>&nbsp;和&nbsp;<code>target</code>&nbsp;都仅包含小写英文字母。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int numWays(vector<string>& words, string target) {

    }
};
```




