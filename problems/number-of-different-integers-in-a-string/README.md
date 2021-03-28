# `（简单）` [5713.number-of-different-integers-in-a-string 字符串中不同整数的数目](https://leetcode-cn.com/problems/number-of-different-integers-in-a-string/)

[contest](https://leetcode-cn.com/contest/weekly-contest-234/problems/number-of-different-integers-in-a-string/)

### 题目描述
<p>给你一个字符串 <code>word</code> ，该字符串由数字和小写英文字母组成。</p>

<p>请你用空格替换每个不是数字的字符。例如，<code>"a123bc34d8ef34"</code> 将会变成 <code>" 123&nbsp; 34 8&nbsp; 34"</code> 。注意，剩下的这些整数间至少要用一个空格隔开：<code>"123"</code>、<code>"34"</code>、<code>"8"</code> 和 <code>"34"</code> 。</p>

<p>返回对 <code>word</code> 完成替换后形成的 <strong>不同</strong> 整数的数目。</p>

<p>如果两个整数的 <strong>不含前导零</strong> 的十进制表示不同，则认为这两个整数也不同。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>word = "a<strong>123</strong>bc<strong>34</strong>d<strong>8</strong>ef<strong>34</strong>"
<strong>输出：</strong>3
<strong>解释：</strong>不同的整数有 "123"、"34" 和 "8" 。注意，"34" 只计数一次。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>word = "leet<strong>1234</strong>code<strong>234</strong>"
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>word = "a<strong>1</strong>b<strong>01</strong>c<strong>001</strong>"
<strong>输出：</strong>1
<strong>解释：</strong>"1"、"01" 和 "001" 视为同一个整数的十进制表示，因为在比较十进制值时会忽略前导零的存在。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 1000</code></li>
	<li><code>word</code> 由数字和小写英文字母组成</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/number-of-different-integers-in-a-string/solution/number-of-different-integers-by-ikaruga-qmh2/)

### 答题
``` C++
class Solution {
public:
    int numDifferentIntegers(string word) {
        word += "-";
        unordered_set<string> ans;
        string val = "-";
        for (auto c : word) {
            if (!isdigit(c)) {
                if (val == "-") continue;
                ans.insert(val);
                val = "-";
            }
            else {
                val = (val == "-") ? "0" : val;
                val = (val == "0") ? "" : val;
                val += c;
            }
        }
        return ans.size();
    }
};
```




