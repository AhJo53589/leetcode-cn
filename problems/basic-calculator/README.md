# `（困难）` [224.basic-calculator 基本计算器](https://leetcode-cn.com/problems/basic-calculator/)

### 题目描述
<div class="notranslate"><p>给你一个字符串表达式 <code>s</code> ，请你实现一个基本计算器来计算并返回它的值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "1 + 1"
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = " 2-1 + 2 "
<strong>输出：</strong>3
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "(1+(4+5+2)-3)+(6+8)"
<strong>输出：</strong>23
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3&nbsp;* 10<sup>5</sup></code></li>
	<li><code>s</code> 由数字、<code>'+'</code>、<code>'-'</code>、<code>'('</code>、<code>')'</code>、和 <code>' '</code> 组成</li>
	<li><code>s</code> 表示一个有效的表达式</li>
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
    int calculate(string s) {
        s += '#';

        int ans = 0;
        int op = 1;
        int real = 1;
        int cur = 0;
        stack<int> st;

        for (auto c : s) {
            if (c == ' ') continue;
            if (isdigit(c)) {
                cur = cur * 10 + (c - '0');
                continue;
            }

            ans += real * op * cur;
            cur = 0;

            if (c == '+' || c == '-') {
                op = (c == '+') ? 1 : -1;
            }
            else if (c == '(') {
                st.push(op);
                real *= op;
                op = 1;
            }
            else if (c == ')') {
                real *= st.top();
                st.pop();
            }
        }
        return ans;
    }
};
```




