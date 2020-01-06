# `（简单）` [1309.decrypt-string-from-alphabet-to-integer-mapping 解码字母到整数映射](https://leetcode-cn.com/problems/decrypt-string-from-alphabet-to-integer-mapping/)

[contest](https://leetcode-cn.com/contest/weekly-contest-170/problems/decrypt-string-from-alphabet-to-integer-mapping/)

### 题目描述
<p>给你一个字符串&nbsp;<code>s</code>，它由数字（<code>'0'</code> - <code>'9'</code>）和&nbsp;<code>'#'</code>&nbsp;组成。我们希望按下述规则将&nbsp;<code>s</code>&nbsp;映射为一些小写英文字符：</p>
<ul>
	<li>字符（<code>'a'</code> - <code>'i'</code>）分别用（<code>'1'</code> -&nbsp;<code>'9'</code>）表示。</li>
	<li>字符（<code>'j'</code> - <code>'z'</code>）分别用（<code>'10#'</code>&nbsp;-&nbsp;<code>'26#'</code>）表示。&nbsp;</li>
</ul>

<p>返回映射之后形成的新字符串。</p>
<p>题目数据保证映射始终唯一。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong>s = "10#11#12"
<strong>输出：</strong>"jkab"
<strong>解释：</strong>"j" -&gt; "10#" , "k" -&gt; "11#" , "a" -&gt; "1" , "b" -&gt; "2".
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>s = "1326#"
<strong>输出：</strong>"acz"
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>s = "25#"
<strong>输出：</strong>"y"
</pre>

<p><strong>示例 4：</strong></p>
<pre><strong>输入：</strong>s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
<strong>输出：</strong>"abcdefghijklmnopqrstuvwxyz"
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> 只包含数字（<code>'0'</code>-<code>'9'</code>）和&nbsp;<code>'#'</code>&nbsp;字符。</li>
	<li><code>s</code>&nbsp;是映射始终存在的有效字符串。</li>
</ul>

---
### 思路
```
逐个字符转换的话，先转换（'1' - '9'）的话，会和（'10#' - '26#'）冲突。
所以由后往前，以'#'为标志位区分。
将结果逆序。
```



### 答题
``` C++
string freqAlphabets(string s)
{
    string ans;
    for (size_t i = s.size() - 1; i < s.size(); i--)
    {
        int n = s[i] - '0';
        if (s[i] == '#')
        {
            string t;
            t += s[i - 2];
            t += s[i - 1];
            n = stoi(t);
            i -= 2;
        }
        ans.push_back('a' - 1 + n);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
```




