# `（简单）` [709.to-lower-case 转换成小写字母](https://leetcode-cn.com/problems/to-lower-case/)

### 题目描述
<div class="notranslate"><p>给你一个字符串 <code>s</code> ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "Hello"
<strong>输出：</strong>"hello"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "here"
<strong>输出：</strong>"here"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "LOVELY"
<strong>输出：</strong>"lovely"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 由 ASCII 字符集中的可打印字符组成</li>
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
    string toLowerCase(string s) {
        transform(s.begin(), s.end(), s.begin(), [](char c) {
            return tolower(c);
        });
        return s;
    }
};
```




