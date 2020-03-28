# `（简单）` [520.detect-capital 检测大写字母](https://leetcode-cn.com/problems/detect-capital/)

### 题目描述
<p>给定一个单词，你需要判断单词的大写使用是否正确。</p>

<p>我们定义，在以下情况时，单词的大写用法是正确的：</p>

<ol>
	<li>全部字母都是大写，比如"USA"。</li>
	<li>单词中所有字母都不是大写，比如"leetcode"。</li>
	<li>如果单词不只含有一个字母，只有首字母大写，&nbsp;比如&nbsp;"Google"。</li>
</ol>

<p>否则，我们定义这个单词没有正确使用大写字母。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> "USA"
<strong>输出:</strong> True
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> "FlaG"
<strong>输出:</strong> False
</pre>

<p><strong>注意:</strong> 输入是由大写和小写拉丁字母组成的非空单词。</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/detect-capital/solution/detect-capital-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    bool detectCapitalUse(string word)
    {
        if (word.size() < 2) return true;
        bool flag_first = isupper(word[0]);
        bool flag_second = isupper(word[1]);
        if (!flag_first && flag_second) return false;

        for (int i = 2; i < word.size(); i++)
        {
            bool flag_cur = isupper(word[i]);
            if (flag_second != flag_cur) return false;
        }
        return true;
    }
};
```




