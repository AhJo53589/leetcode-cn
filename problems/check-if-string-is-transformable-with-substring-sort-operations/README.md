# `（困难）` [1585.check-if-string-is-transformable-with-substring-sort-operations 检查字符串是否可以通过排序子字符串得到另一个字符串](https://leetcode-cn.com/problems/check-if-string-is-transformable-with-substring-sort-operations/)

[contest](https://leetcode-cn.com/contest/weekly-contest-206/problems/check-if-string-is-transformable-with-substring-sort-operations/)

### 题目描述
<p>给你两个字符串&nbsp;<code>s</code> 和&nbsp;<code>t</code>&nbsp;，请你通过若干次以下操作将字符串&nbsp;<code>s</code>&nbsp;转化成字符串&nbsp;<code>t</code>&nbsp;：</p>

<ul>
	<li>选择 <code>s</code>&nbsp;中一个 <strong>非空</strong>&nbsp;子字符串并将它包含的字符就地 <strong>升序</strong>&nbsp;排序。</li>
</ul>

<p>比方说，对下划线所示的子字符串进行操作可以由&nbsp;<code>"1<strong>4234</strong>"</code>&nbsp;得到&nbsp;<code>"1<strong>2344</strong>"</code>&nbsp;。</p>

<p>如果可以将字符串 <code>s</code>&nbsp;变成 <code>t</code>&nbsp;，返回 <code>true</code>&nbsp;。否则，返回 <code>false</code>&nbsp;。</p>

<p>一个 <strong>子字符串</strong>&nbsp;定义为一个字符串中连续的若干字符。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "84532", t = "34852"
<strong>输出：</strong>true
<strong>解释：</strong>你可以按以下操作将 s 转变为 t ：
"84<strong>53</strong>2" （从下标 2 到下标 3）-> "84<strong>35</strong>2"
"<strong>843</strong>52" （从下标 0 到下标 2） -> "<strong>348</strong>52"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "34521", t = "23415"
<strong>输出：</strong>true
<strong>解释：</strong>你可以按以下操作将 s 转变为 t ：
"<strong>3452</strong>1" -> "<strong>2345</strong>1"
"234<strong>51</strong>" -> "234<strong>15</strong>"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "12345", t = "12435"
<strong>输出：</strong>false
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = "1", t = "2"
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s.length == t.length</code></li>
	<li><code>1 <= s.length <= 10<sup>5</sup></code></li>
	<li><code>s</code> 和&nbsp;<code>t</code>&nbsp;都只包含数字字符，即&nbsp;<code>'0'</code>&nbsp;到&nbsp;<code>'9'</code> 。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool isTransformable(string s, string t) {

    }
};
```




