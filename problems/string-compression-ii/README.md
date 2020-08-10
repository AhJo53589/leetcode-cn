# `（困难）` [1531.string-compression-ii 压缩字符串 II](https://leetcode-cn.com/problems/string-compression-ii/)

[contest](https://leetcode-cn.com/contest/weekly-contest-199/problems/string-compression-ii/)

### 题目描述
<p><a href="https://baike.baidu.com/item/%E8%A1%8C%E7%A8%8B%E9%95%BF%E5%BA%A6%E7%BC%96%E7%A0%81/2931940?fr=aladdin" target="_blank">行程长度编码</a> 是一种常用的字符串压缩方法，它将连续的相同字符（重复 2 次或更多次）替换为字符和表示字符计数的数字（行程长度）。例如，用此方法压缩字符串 <code>"aabccc"</code> ，将 <code>"aa"</code> 替换为 <code>"a2"</code> ，<code>"ccc"</code> 替换为` <code>"c3"</code> 。因此压缩后的字符串变为 <code>"a2bc3"</code> 。</p>

<p>注意，本问题中，压缩时没有在单个字符后附加计数 <code>'1'</code> 。</p>

<p>给你一个字符串 <code>s</code> 和一个整数 <code>k</code> 。你需要从字符串 <code>s</code> 中删除最多 <code>k</code> 个字符，以使 <code>s</code> 的行程长度编码长度最小。</p>

<p>请你返回删除最多 <code>k</code> 个字符后，<code>s</code> <strong>行程长度编码的最小长度</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "aaabcccd", k = 2
<strong>输出：</strong>4
<strong>解释：</strong>在不删除任何内容的情况下，压缩后的字符串是 "a3bc3d" ，长度为 6 。最优的方案是删除 'b' 和 'd'，这样一来，压缩后的字符串为 "a3c3" ，长度是 4 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "aabbaa", k = 2
<strong>输出：</strong>2
<strong>解释：</strong>如果删去两个 'b' 字符，那么压缩后的字符串是长度为 2 的 "a4" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "aaaaaaaaaaa", k = 0
<strong>输出：</strong>3
<strong>解释：</strong>由于 k 等于 0 ，不能删去任何字符。压缩后的字符串是 "a11" ，长度为 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= s.length</code></li>
	<li><code>s</code> 仅包含小写英文字母</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        
    }
};
```




