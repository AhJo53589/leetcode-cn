# `（中等）` [1111.maximum-nesting-depth-of-two-valid-parentheses-strings 有效括号的嵌套深度](https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/)

### 题目描述
<p><strong>有效括号字符串</strong> 仅由&nbsp;<code>"("</code> 和&nbsp;<code>")"</code>&nbsp;构成，并符合下述几个条件之一：</p>

<ul>
	<li>空字符串</li>
	<li>连接，可以记作&nbsp;<code>AB</code>（<code>A</code> 与 <code>B</code> 连接），其中&nbsp;<code>A</code>&nbsp;和&nbsp;<code>B</code>&nbsp;都是有效括号字符串</li>
	<li>嵌套，可以记作&nbsp;<code>(A)</code>，其中&nbsp;<code>A</code>&nbsp;是有效括号字符串</li>
</ul>

<p>类似地，我们可以定义任意有效括号字符串 <code>s</code> 的 <strong>嵌套深度</strong>&nbsp;<code>depth(S)</code>：</p>

<ul>
	<li><code>s</code> 为空时，<code>depth("") = 0</code></li>
	<li><code>s</code> 为 <code>A</code> 与 <code>B</code> 连接时，<code>depth(A + B) = max(depth(A), depth(B))</code>，其中&nbsp;<code>A</code> 和&nbsp;<code>B</code>&nbsp;都是有效括号字符串</li>
	<li><code>s</code> 为嵌套情况，<code>depth("(" + A + ")") = 1 + depth(A)</code>，其中 A 是有效括号字符串</li>
</ul>

<p>例如：<code>""</code>，<code>"()()"</code>，和&nbsp;<code>"()(()())"</code>&nbsp;都是有效括号字符串，嵌套深度分别为 0，1，2，而&nbsp;<code>")("</code> 和&nbsp;<code>"(()"</code>&nbsp;都不是有效括号字符串。</p>

<p>&nbsp;</p>

<p>给你一个有效括号字符串 <code>seq</code>，将其分成两个不相交的子序列&nbsp;<code>A</code> 和&nbsp;<code>B</code>，且&nbsp;<code>A</code> 和&nbsp;<code>B</code>&nbsp;满足有效括号字符串的定义（注意：<code>A.length + B.length = seq.length</code>）。</p>

<p>现在，你需要从中选出 <strong>任意</strong>&nbsp;一组有效括号字符串&nbsp;<code>A</code> 和&nbsp;<code>B</code>，使&nbsp;<code>max(depth(A), depth(B))</code>&nbsp;的可能取值最小。</p>

<p>返回长度为&nbsp;<code>seq.length</code> 答案数组&nbsp;<code>answer</code>&nbsp;，选择&nbsp;<code>A</code>&nbsp;还是&nbsp;<code>B</code>&nbsp;的编码规则是：如果&nbsp;<code>seq[i]</code>&nbsp;是&nbsp;<code>A</code>&nbsp;的一部分，那么&nbsp;<code>answer[i] = 0</code>。否则，<code>answer[i] = 1</code>。即便有多个满足要求的答案存在，你也只需返回&nbsp;<strong>一个</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>seq = "(()())"
<strong>输出：</strong>[0,1,1,1,1,0]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>seq = "()(())()"
<strong>输出：</strong>[0,0,0,1,1,0,1,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= text.size <= 10000</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/solution/maximum-nesting-depth-of-two-valid-parentheses-str/)

### 答题
``` C++
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        vector<int> ans(seq.size(), 0);
        int d = 0;
        stack<int> st;
        for (int i = 0; i < seq.size(); i++)
        {
            d = max(d, (int)st.size());
            if (seq[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
            }
        }
        for (int i = 0; i < seq.size(); i++)
        {
            int j = 0;
            if (seq[i] == '(')
            {
                st.push(i);
            }
            else
            {
                j = st.top();
                st.pop();
            }
            if (st.size() < d / 2)
            {
                ans[i] = 1;
                ans[j] = 1;
            }
        }
        return ans;
    }
};
```


### 其它
``` C++
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) 
    {
        vector<int> ans(seq.size(), 0);
        int d = 0;
        for (int i = 0; i < seq.size(); i++)
        {
            if (seq[i] == '(') 
            {
                ans[i] = d % 2;
                d++;
            }
            else
            {
                d--;
                ans[i] = d % 2;
            }
        }
        return ans;
    }
};
```


