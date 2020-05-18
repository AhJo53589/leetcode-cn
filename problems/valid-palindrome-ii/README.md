# `（简单）` [680.valid-palindrome-ii 验证回文字符串 Ⅱ](https://leetcode-cn.com/problems/valid-palindrome-ii/)

### 题目描述
<p>给定一个非空字符串&nbsp;<code>s</code>，<strong>最多</strong>删除一个字符。判断是否能成为回文字符串。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> "aba"
<strong>输出:</strong> True
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> "abca"
<strong>输出:</strong> True
<strong>解释:</strong> 你可以删除c字符。
</pre>

<p><strong>注意:</strong></p>

<ol>
	<li>字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。</li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/valid-palindrome-ii/solution/valid-palindrome-ii-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    bool validPalindrome(string s) {
        return valid(s, 0, s.size() - 1, 0);
    }

    bool valid(string& s, int l, int r, int del) {
        if (l >= r) return true;

        if (s[l] != s[r]) {
            del++;
            if (del > 1) return false;
            return (valid(s, l + 1, r, del) || valid(s, l, r - 1, del));
        }

        return valid(s, l + 1, r - 1, del);
    }
};
```




