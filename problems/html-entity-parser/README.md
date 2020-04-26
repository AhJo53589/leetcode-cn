# `（中等）` [1410.html-entity-parser HTML 实体解析器](https://leetcode-cn.com/problems/html-entity-parser/)

[contest](https://leetcode-cn.com/contest/weekly-contest-184/problems/html-entity-parser/)

### 题目描述
<p>「HTML&nbsp;实体解析器」 是一种特殊的解析器，它将 HTML 代码作为输入，并用字符本身替换掉所有这些特殊的字符实体。</p>

<p>HTML 里这些特殊字符和它们对应的字符实体包括：</p>

<ul>
	<li><strong>双引号：</strong>字符实体为&nbsp;<code>&amp;quot;</code>&nbsp;，对应的字符是&nbsp;<code>"</code>&nbsp;。</li>
	<li><strong>单引号：</strong>字符实体为&nbsp;<code>&amp;apos;</code>&nbsp;，对应的字符是&nbsp;<code>'</code>&nbsp;。</li>
	<li><strong>与符号：</strong>字符实体为&nbsp;<code>&amp;amp;</code>&nbsp;，对应对的字符是&nbsp;<code>&amp;</code>&nbsp;。</li>
	<li><strong>大于号：</strong>字符实体为&nbsp;<code>&amp;gt;</code>&nbsp;，对应的字符是&nbsp;<code>&gt;</code>&nbsp;。</li>
	<li><strong>小于号：</strong>字符实体为&nbsp;<code>&amp;lt;</code>&nbsp;，对应的字符是&nbsp;<code>&lt;</code>&nbsp;。</li>
	<li><strong>斜线号：</strong>字符实体为&nbsp;<code>&amp;frasl;</code>&nbsp;，对应的字符是&nbsp;<code>/</code>&nbsp;。</li>
</ul>

<p>给你输入字符串&nbsp;<code>text</code>&nbsp;，请你实现一个 HTML&nbsp;实体解析器，返回解析器解析后的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>text = "&amp;amp; is an HTML entity but &amp;ambassador; is not."
<strong>输出：</strong>"&amp; is an HTML entity but &amp;ambassador; is not."
<strong>解释：</strong>解析器把字符实体 &amp;amp; 用 &amp; 替换
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre><strong>输入：</strong>text = "and I quote: &amp;quot;...&amp;quot;"
<strong>输出：</strong>"and I quote: \"...\""
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>text = "Stay home! Practice on Leetcode :)"
<strong>输出：</strong>"Stay home! Practice on Leetcode :)"
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>text = "x &amp;gt; y &amp;amp;&amp;amp; x &amp;lt; y is always false"
<strong>输出：</strong>"x &gt; y &amp;&amp; x &lt; y is always false"
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>text = "leetcode.com&amp;frasl;problemset&amp;frasl;all"
<strong>输出：</strong>"leetcode.com/problemset/all"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10^5</code></li>
	<li>字符串可能包含 256 个ASCII 字符中的任意字符。</li>
</ul>

            

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/html-entity-parser/solution/problemshtml-entity-parser-by-ikaruga/)

### 答题
``` C++
    string entityParser(string text) 
    {
        vector<string> words = { "&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;" };
        vector<char> chars = { '\"', '\'', '&', '>', '<', '/' };

        string ans = "";
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == '&')
            {
                bool flag = false;
                for (int j = 0; j < words.size(); j++)
                {
                    if (i + words[j].size() > text.size()) continue;
                    if (memcmp(&text[i], &words[j][0], words[j].size()) != 0) continue;
                    ans.push_back(chars[j]);
                    i += (words[j].size() - 1);
                    flag = true;
                    break;
                }
                if (flag) continue;
            }

            ans.push_back(text[i]);
        }
        return ans;
    }
```




