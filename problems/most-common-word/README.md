# `（简单）` [819.most-common-word 最常见的单词](https://leetcode-cn.com/problems/most-common-word/)

### 题目描述
<p>给定一个段落 (paragraph) 和一个禁用单词列表 (banned)。返回出现次数最多，同时不在禁用列表中的单词。</p>

<p>题目保证至少有一个词不在禁用列表中，而且答案唯一。</p>

<p>禁用列表中的单词用小写字母表示，不含标点符号。段落中的单词不区分大小写。答案都是小写字母。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入:</strong> 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
<strong>输出:</strong> "ball"
<strong>解释:</strong> 
"hit" 出现了3次，但它是一个禁用的单词。
"ball" 出现了2次 (同时没有其他单词出现2次)，所以它是段落里出现次数最多的，且不在禁用列表中的单词。 
注意，所有这些单词在段落里不区分大小写，标点符号需要忽略（即使是紧挨着单词也忽略， 比如 "ball,"）， 
"hit"不是最终的答案，虽然它出现次数更多，但它在禁用单词列表中。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= 段落长度 <= 1000</code></li>
	<li><code>0 <= 禁用单词个数 <= 100</code></li>
	<li><code>1 <= 禁用单词长度 <= 10</code></li>
	<li>答案是唯一的, 且都是小写字母&nbsp;(即使在 <code>paragraph</code> 里是大写的，即使是一些特定的名词，答案都是小写的。)</li>
	<li><code>paragraph</code>&nbsp;只包含字母、空格和下列标点符号<code>!?',;.</code></li>
	<li>不存在没有连字符或者带有连字符的单词。</li>
	<li>单词里只包含字母，不会出现省略号或者其他标点符号。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/most-common-word/solution/most-common-word-by-ikaruga/)

### 答题
``` C++
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
        unordered_map<string, int> cnt;
        unordered_set<string> ban;
        for (auto& w : banned)
        {
            ban.insert(w);
        }

        int maxcnt = 0;
        string ans;

        for (auto& c : paragraph)
        {
            c = isalpha(c) ? c : ' ';
        }
        stringstream ss(paragraph);
        string temp;
        while (ss >> temp)
        {
            for (auto& c : temp)
            {
                c = tolower(c);
            }
            //transform(temp.begin(), temp.end(), temp.begin(), tolower);
            if (ban.count(temp) != 0) continue;
            cnt[temp]++;
            if (cnt[temp] > maxcnt)
            {
                maxcnt = cnt[temp];
                ans = temp;
            }
        }
        return ans;
    }
```




