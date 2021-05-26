# `（中等）` [1190.reverse-substrings-between-each-pair-of-parentheses 反转每对括号间的子串](https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/)

### 题目描述
<p>给出一个字符串&nbsp;<code>s</code>（仅含有小写英文字母和括号）。</p>

<p>请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。</p>

<p>注意，您的结果中 <strong>不应</strong> 包含任何括号。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "(abcd)"
<strong>输出：</strong>"dcba"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "(u(love)i)"
<strong>输出：</strong>"iloveu"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "(ed(et(oc))el)"
<strong>输出：</strong>"leetcode"
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = "a(bcdefghijkl(mno)p)q"
<strong>输出：</strong>"apmnolkjihgfedcbq"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> 中只有小写英文字母和括号</li>
	<li>我们确保所有括号都是成对出现的</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/solution/reverse-substrings-by-ikaruga-m3gi/)

### 答题
``` C++
class Solution {
public:
    string reverseParentheses(string s) {
        int i = 0;
        return re(s, i);
    }

    string re(string& s, int& i) {
        string str;
        for (; i < s.size(); i++) {
            if (s[i] == '(') {
                str += re(s, ++i);
            }
            else if (s[i] == ')') {
                reverse(str.begin(), str.end());
                return str;
            }
            else {
                str += s[i];
            }
        }
        return str;
    }
};
```




