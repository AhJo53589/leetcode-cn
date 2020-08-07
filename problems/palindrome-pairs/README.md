# `（困难）` [336.palindrome-pairs 回文对](https://leetcode-cn.com/problems/palindrome-pairs/)

### 题目描述
<p>给定一组<strong> 互不相同</strong> 的单词， 找出所有<strong>不同<em>&nbsp;</em></strong>的索引对<code>(i, j)</code>，使得列表中的两个单词，&nbsp;<code>words[i] + words[j]</code>&nbsp;，可拼接成回文串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>["abcd","dcba","lls","s","sssll"]
<strong>输出：</strong>[[0,1],[1,0],[3,2],[2,4]] 
<strong>解释：</strong>可拼接成的回文串为 <code>["dcbaabcd","abcddcba","slls","llssssll"]</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>["bat","tab","cat"]
<strong>输出：</strong>[[0,1],[1,0]] 
<strong>解释：</strong>可拼接成的回文串为 <code>["battab","tabbat"]</code></pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (checkSide(words[i], words[j])) {
                    ans.push_back({i, j});
                }
                if (checkSide(words[j], words[i])) {
                    ans.push_back({j, i});
                }
            }
        }
        return ans;
    }

    bool checkSide(string& s1, string& s2) {
        int len = min(s1.size(), s2.size());
        for (int i = 0; i < len; i++) {
            if (s1[i] != s2[s2.size() - i - 1]) return false;
        }
        
        if (s1.size() < s2.size()) {
            return checkPalindrome(s2, 0, s2.size() - len - 1);
        }
        if (s1.size() > s2.size()) {
            return checkPalindrome(s1, len, s1.size() - 1);
        }
        return true;
    }

    bool checkPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};
```




