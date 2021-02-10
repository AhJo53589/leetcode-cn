# `（中等）` [567.permutation-in-string 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)

### 题目描述
<p>给定两个字符串&nbsp;<strong>s1</strong>&nbsp;和&nbsp;<strong>s2</strong>，写一个函数来判断 <strong>s2</strong> 是否包含 <strong>s1&nbsp;</strong>的排列。</p>

<p>换句话说，第一个字符串的排列之一是第二个字符串的子串。</p>

<p><strong>示例1:</strong></p>

<pre><strong>输入: </strong>s1 = "ab" s2 = "eidbaooo"
<strong>输出: </strong>True
<strong>解释:</strong> s2 包含 s1 的排列之一 ("ba").
</pre>

<p>&nbsp;</p>

<p><strong>示例2:</strong></p>

<pre><strong>输入: </strong>s1= "ab" s2 = "eidboaoo"
<strong>输出:</strong> False
</pre>

<p>&nbsp;</p>

<p><strong>注意：</strong></p>

<ol>
	<li>输入的字符串只包含小写字母</li>
	<li>两个字符串的长度都在 [1, 10,000] 之间</li>
</ol>


---
### 思路
```
```

### 答题
``` C++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt_1(26, 0);
        vector<int> cnt_2(26, 0);

        for (auto &c : s1) {
            cnt_1[c - 'a']++;
        }

        for (int i = 0, j = 0; j < s2.size(); i++) {
            while (j - i < s1.size() && j < s2.size()) {
                cnt_2[s2[j] - 'a']++;
                j++;
            }

            if (j - i != s1.size()) break;
            if (cnt_1 == cnt_2) return true;

            cnt_2[s2[i] - 'a']--;
        }

        return false;
    }
};
```

