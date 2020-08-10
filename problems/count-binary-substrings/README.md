# `（简单）` [696.count-binary-substrings 计数二进制子串](https://leetcode-cn.com/problems/count-binary-substrings/)

### 题目描述
<p>给定一个字符串&nbsp;<code>s</code>，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。</p>

<p>重复出现的子串要计算它们出现的次数。</p>

<p><strong>示例 1 :</strong></p>

<pre><strong>输入:</strong> "00110011"
<strong>输出:</strong> 6
<strong>解释:</strong> 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。

请注意，一些重复出现的子串要计算它们出现的次数。

另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
</pre>

<p><strong>示例 2 :</strong></p>

<pre><strong>输入:</strong> "10101"
<strong>输出:</strong> 4
<strong>解释:</strong> 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
</pre>

<p><strong>注意：</strong></p>

<ul>
	<li><code>s.length</code>&nbsp;在1到50,000之间。</li>
	<li><code>s</code>&nbsp;只包含“0”或“1”字符。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/count-binary-substrings/solution/count-binary-substrings-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int countBinarySubstrings(string s) {
        s += '-';
        int ans = 0;
        char last = '-';
        int cnt_pre = 0;
        int cnt_cur = 0;
        for (auto c : s) {
            if (last != c) {
                last = c;
                ans += min(cnt_pre, cnt_cur);
                cnt_pre = cnt_cur;
                cnt_cur = 0;
            }
            cnt_cur++;
        }
        return ans;
    }
};
```




