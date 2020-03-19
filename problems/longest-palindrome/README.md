# `（简单）` [409.longest-palindrome 最长回文串](https://leetcode-cn.com/problems/longest-palindrome/)

### 题目描述
<p>给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。</p>

<p>在构造过程中，请注意区分大小写。比如&nbsp;<code>"Aa"</code>&nbsp;不能当做一个回文字符串。</p>

<p><strong>注意:</strong><br>
假设字符串的长度不会超过 1010。</p>

<p><strong>示例 1: </strong></p>

<pre>输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/longest-palindrome/solution/409-by-ikaruga/)

### 答题
``` C++
int longestPalindrome(string s)
{
    unordered_map<char, int> cnt;
    for (auto c : s)
    {
        cnt[c]++;
    }
    int ans = 0;
    int odd = 0;
    for (auto& p : cnt)
    {
        odd = (odd == 1 || p.second % 2 == 1);
        ans += (p.second / 2 * 2);
    }
    return ans + odd;
}
```




