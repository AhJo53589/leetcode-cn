# `（困难）` [5298.verbal-arithmetic-puzzle 口算难题](https://leetcode-cn.com/problems/verbal-arithmetic-puzzle/)

[contest](https://leetcode-cn.com/contest/weekly-contest-169/problems/verbal-arithmetic-puzzle/)

### 题目描述
<p>给你一个方程，左边用&nbsp;<code>words</code>&nbsp;表示，右边用&nbsp;<code>result</code> 表示。</p>

<p>你需要根据以下规则检查方程是否可解：</p>

<ul>
	<li>每个字符都会被解码成一位数字（0 - 9）。</li>
	<li>每对不同的字符必须映射到不同的数字。</li>
	<li>每个 <code>words[i]</code> 和 <code>result</code>&nbsp;都会被解码成一个没有前导零的数字。</li>
	<li>左侧数字之和（<code>words</code>）等于右侧数字（<code>result</code>）。&nbsp;</li>
</ul>

<p>如果方程可解，返回&nbsp;<code>True</code>，否则返回&nbsp;<code>False</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = ["SEND","MORE"], result = "MONEY"
<strong>输出：</strong>true
<strong>解释：</strong>映射 'S'-&gt; 9, 'E'-&gt;5, 'N'-&gt;6, 'D'-&gt;7, 'M'-&gt;1, 'O'-&gt;0, 'R'-&gt;8, 'Y'-&gt;'2'
所以 "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
<strong>输出：</strong>true
<strong>解释：</strong>映射 'S'-&gt; 6, 'I'-&gt;5, 'X'-&gt;0, 'E'-&gt;8, 'V'-&gt;7, 'N'-&gt;2, 'T'-&gt;1, 'W'-&gt;'3', 'Y'-&gt;4
所以 "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>words = ["THIS","IS","TOO"], result = "FUNNY"
<strong>输出：</strong>true
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>words = ["LEET","CODE"], result = "POINT"
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= words.length &lt;= 5</code></li>
	<li><code>1 &lt;= words[i].length,&nbsp;results.length&nbsp;&lt;= 7</code></li>
	<li><code>words[i], result</code>&nbsp;只含有大写英文字母</li>
	<li>表达式中使用的不同字符数最大为&nbsp;10</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
bool isSolvable(vector<string>& words, string result) 
{

}
```




