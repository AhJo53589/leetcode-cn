# `（困难）` [30.substring-with-concatenation-of-all-words 串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/)

### 题目描述
<p>给定一个字符串&nbsp;<strong>s&nbsp;</strong>和一些长度相同的单词&nbsp;<strong>words。</strong>找出 <strong>s </strong>中恰好可以由&nbsp;<strong>words </strong>中所有单词串联形成的子串的起始位置。</p>

<p>注意子串要与&nbsp;<strong>words </strong>中的单词完全匹配，中间不能有其他字符，但不需要考虑&nbsp;<strong>words&nbsp;</strong>中单词串联的顺序。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：
  s =</strong> "barfoothefoobarman",
<strong>  words = </strong>["foo","bar"]
<strong>输出：</strong><code>[0,9]</code>
<strong>解释：</strong>
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：
  s =</strong> "wordgoodgoodgoodbestword",
<strong>  words = </strong>["word","good","best","word"]
<code><strong>输出：</strong>[]</code>
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/solution/30-by-ikaruga/)

### 答题
``` C++
vector<int> findSubstring(string s, vector<string>& words) 
{
    if (words.size() == 0) return {};
    unordered_map<string, int> wordcnt;
    for (auto& w : words)
    {
        wordcnt[w]++;
    }
    int len = words[0].size();

    vector<int> ans;
    for (int i = 0; i < len; i++)
    {
        int left = i;
        int right = left;
        int cnt = 0;

        unordered_map<string, int> window;
        while (left + words.size() * len <= s.size())
        {
            string temp = "";
            while (cnt < words.size())
            {
                temp = s.substr(right, len);
                if (wordcnt.find(temp) == wordcnt.end() || window[temp] >= wordcnt[temp]) break;
                window[temp]++;
                cnt++;
                right += len;
            }

            if (window == wordcnt)
            {
                ans.push_back(left);
            }

            if (wordcnt.find(temp) != wordcnt.end())
            {
                window[s.substr(left, len)]--;
                cnt--;
                left += len;
            }
            else
            {
                right += len;
                left = right;
                cnt = 0;
                window.clear();
            }
        }
    }
    return ans;
}
```




