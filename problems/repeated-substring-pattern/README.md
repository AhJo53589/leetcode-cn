# `（简单）` [459.repeated-substring-pattern 重复的子字符串](https://leetcode-cn.com/problems/repeated-substring-pattern/)

### 题目描述
<p>给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> "abab"

<strong>输出:</strong> True

<strong>解释:</strong> 可由子字符串 "ab" 重复两次构成。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> "aba"

<strong>输出:</strong> False
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> "abcabcabcabc"

<strong>输出:</strong> True

<strong>解释:</strong> 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).find(s, 1) != s.size();
    }
};
```




