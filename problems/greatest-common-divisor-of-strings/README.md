# `（简单）` [1071.greatest-common-divisor-of-strings 字符串的最大公因子](https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/)

### 题目描述
<p>对于字符串&nbsp;<code>S</code> 和&nbsp;<code>T</code>，只有在 <code>S = T + ... + T</code>（<code>T</code>&nbsp;与自身连接 1 次或多次）时，我们才认定&nbsp;“<code>T</code> 能除尽 <code>S</code>”。</p>

<p>返回最长字符串&nbsp;<code>X</code>，要求满足&nbsp;<code>X</code> 能除尽 <code>str1</code> 且&nbsp;<code>X</code> 能除尽 <code>str2</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>str1 = "ABCABC", str2 = "ABC"
<strong>输出：</strong>"ABC"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>str1 = "ABABAB", str2 = "ABAB"
<strong>输出：</strong>"AB"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>str1 = "LEET", str2 = "CODE"
<strong>输出：</strong>""
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= str1.length <= 1000</code></li>
	<li><code>1 <= str2.length <= 1000</code></li>
	<li><code>str1[i]</code> 和&nbsp;<code>str2[i]</code> 为大写英文字母</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
//class Solution {
//public:
//    string gcdOfStrings(string str1, string str2) {
//        if (str1 + str2 != str2 + str1) return "";
//        return str1.substr(0, __gcd((int)str1.length(), (int)str2.length())); // __gcd() 为c++自带的求最大公约数的函数
//    }
//};
class Solution {
public:
    int gcd(int a, int b)
    {
        return (b == 0) ? a : gcd(b, a % b);
    }

    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd((int)str1.size(), (int)str2.size()));
    }
};
```




