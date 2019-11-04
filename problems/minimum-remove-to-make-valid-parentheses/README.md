# `（中等）` [1249.minimum-remove-to-make-valid-parentheses 移除无效的括号](https://leetcode-cn.com/problems/minimum-remove-to-make-valid-parentheses/)

[contest](https://leetcode-cn.com/contest/weekly-contest-161/problems/minimum-remove-to-make-valid-parentheses/)

### 题目描述
<p>给你一个由 <code>'('</code>、<code>')'</code> 和小写字母组成的字符串 <code>s</code>。</p>

<p>你需要从字符串中删除最少数目的 <code>'('</code> 或者 <code>')'</code>&nbsp;（可以删除任意位置的括号)，使得剩下的「括号字符串」有效。</p>

<p>请返回任意一个合法字符串。</p>

<p>有效「括号字符串」应当符合以下&nbsp;<strong>任意一条&nbsp;</strong>要求：</p>

<ul>
	<li>空字符串或只包含小写字母的字符串</li>
	<li>可以被写作&nbsp;<code>AB</code>（<code>A</code>&nbsp;连接&nbsp;<code>B</code>）的字符串，其中&nbsp;<code>A</code>&nbsp;和&nbsp;<code>B</code>&nbsp;都是有效「括号字符串」</li>
	<li>可以被写作&nbsp;<code>(A)</code>&nbsp;的字符串，其中&nbsp;<code>A</code>&nbsp;是一个有效的「括号字符串」</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "lee(t(c)o)de)"
<strong>输出：</strong>"lee(t(c)o)de"
<strong>解释：</strong>"lee(t(co)de)" , "lee(t(c)ode)" 也是一个可行答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "a)b(c)d"
<strong>输出：</strong>"ab(c)d"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "))(("
<strong>输出：</strong>""
<strong>解释：</strong>空字符串也是有效的
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = "(a(b(c)d)"
<strong>输出：</strong>"a(b(c)d)"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s[i]</code>&nbsp;可能是&nbsp;<code>'('</code>、<code>')'</code>&nbsp;或英文小写字母</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
string valid(string s, char da, char db)
{
    int a = 0;
    string ans;
    for (auto c : s)
    {
        if (c == da)
        {
            a++;
        }
        else if (c == db)
        {
            if (a == 0) continue;
            a--;
        }
        ans += c;
    }

    return ans;
}

string minRemoveToMakeValid(string s) 
{
    s = valid(s, '(', ')');
    reverse(s.begin(), s.end());
    s = valid(s, ')', '(');
    reverse(s.begin(), s.end());
    return s;
}
```




