# `（中等）` [424.longest-repeating-character-replacement 替换后的最长重复字符](https://leetcode-cn.com/problems/longest-repeating-character-replacement/)

### 题目描述
<p>给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换&nbsp;<em>k&nbsp;</em>次。在执行上述操作后，找到包含重复字母的最长子串的长度。</p>

<p><strong>注意：</strong>字符串长度 和 <em>k </em>不会超过&nbsp;10<sup>4</sup>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "ABAB", k = 2
<strong>输出：</strong>4
<strong>解释：</strong>用两个'A'替换为两个'B',反之亦然。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "AABABBA", k = 1
<strong>输出：</strong>4
<strong>解释：</strong>
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。
</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int maxn = 0;
        int i = 0;
        int j = 0;
        for (; j < s.size(); j++) {
            cnt[s[j] - 'A']++;
            maxn = max(maxn, cnt[s[j] - 'A']);
            if (j - i + 1 > maxn + k) {
                cnt[s[i] - 'A']--;
                i++;
            }
        }
        return j - i;
    }
};
```




