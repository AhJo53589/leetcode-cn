# `（简单）` [383.ransom-note 赎金信](https://leetcode-cn.com/problems/ransom-note/)

### 题目描述
<p>给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。如果可以构成，返回 true ；否则返回 false。</p>

<p>(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)</p>

<p><strong>注意：</strong></p>

<p>你可以假设两个字符串均只含有小写字母。</p>

<pre>canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> cnt;
        for (auto c : magazine)
        {
            cnt[c]++;
        }
        for (auto c : ransomNote)
        {
            cnt[c]--;
            if (cnt[c] < 0) return false;
        }
        return true;
    }
};
```




