# `（简单）` [541.reverse-string-ii 反转字符串 II](https://leetcode-cn.com/problems/reverse-string-ii/)

### 题目描述
<p>给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> s = "abcdefg", k = 2
<strong>输出:</strong> "bacdfeg"
</pre>

<p><strong>要求:</strong></p>

<ol>
	<li>该字符串只包含小写的英文字母。</li>
	<li>给定字符串的长度和 k 在[1, 10000]范围内。</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
void swapStr(string &s, size_t bg, size_t ed)
{
    if (bg >= s.size()) return;
    if (ed >= s.size()) 
    {
        ed = s.size() - 1;
    }
    while (bg < ed)
    {
        swap(s[bg++], s[ed--]);
    }
}

string reverseStr(string s, int k)
{
    for (int i = 0; i < s.size(); i += k * 2)
    {
        swapStr(s, i, i + k - 1);
    }
    return s;
}
```




