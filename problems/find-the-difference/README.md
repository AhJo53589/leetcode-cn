# `（简单）` [389.find-the-difference 找不同](https://leetcode-cn.com/problems/find-the-difference/)

### 题目描述
<p>给定两个字符串 <em><strong>s</strong></em> 和 <em><strong>t</strong></em>，它们只包含小写字母。</p>

<p>字符串&nbsp;<strong><em>t</em></strong>&nbsp;由字符串&nbsp;<strong><em>s</em></strong>&nbsp;随机重排，然后在随机位置添加一个字母。</p>

<p>请找出在 <em><strong>t</strong></em> 中被添加的字母。</p>

<p>&nbsp;</p>

<p><strong>示例:</strong></p>

<pre>输入：
s = "abcd"
t = "abcde"

输出：
e

解释：
'e' 是那个被添加的字母。
</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        unordered_map<char, int> cnt;
        for (auto c : s)
        {
            cnt[c]++;
        }
        for (auto c : t)
        {
            cnt[c]--;
            if (cnt[c] < 0) return c;
        }
        return {};
    }
};
```




