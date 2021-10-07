# `（简单）` [434.number-of-segments-in-a-string 字符串中的单词数](https://leetcode-cn.com/problems/number-of-segments-in-a-string/)

### 题目描述
<p>统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。</p>

<p>请注意，你可以假定字符串里不包括任何不可打印的字符。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> "Hello, my name is John"
<strong>输出:</strong> 5
<strong>解释: </strong>这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string t;
        int ans = 0;
        while (ss >> t) {
            ans++;
        }
        return ans;
    }
};
```




