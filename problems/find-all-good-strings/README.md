# `（困难）` [1397.find-all-good-strings 找到所有好字符串](https://leetcode-cn.com/problems/find-all-good-strings/)

[contest](https://leetcode-cn.com/contest/weekly-contest-182/problems/find-all-good-strings/)

### 题目描述
<p>给你两个长度为 <code>n</code>&nbsp;的字符串&nbsp;<code>s1</code> 和&nbsp;<code>s2</code>&nbsp;，以及一个字符串&nbsp;<code>evil</code>&nbsp;。请你返回 <strong>好字符串&nbsp;</strong>的数目。</p>

<p><strong>好字符串</strong>&nbsp;的定义为：它的长度为&nbsp;<code>n</code>&nbsp;，字典序大于等于&nbsp;<code>s1</code>&nbsp;，字典序小于等于&nbsp;<code>s2</code>&nbsp;，且不包含&nbsp;<code>evil</code>&nbsp;为子字符串。</p>

<p>由于答案可能很大，请你返回答案对 10^9 + 7 取余的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2, s1 = "aa", s2 = "da", evil = "b"
<strong>输出：</strong>51 
<strong>解释：</strong>总共有 25 个以 'a' 开头的好字符串："aa"，"ac"，"ad"，...，"az"。还有 25 个以 'c' 开头的好字符串："ca"，"cc"，"cd"，...，"cz"。最后，还有一个以 'd' 开头的好字符串："da"。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"
<strong>输出：</strong>0 
<strong>解释：</strong>所有字典序大于等于 s1 且小于等于 s2 的字符串都以 evil 字符串 "leet" 开头。所以没有好字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 2, s1 = "gx", s2 = "gz", evil = "x"
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s1.length == n</code></li>
	<li><code>s2.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= evil.length &lt;= 50</code></li>
	<li>所有字符串都只包含小写英文字母。</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        
    }
};
```




