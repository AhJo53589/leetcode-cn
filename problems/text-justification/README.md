# `（困难）` [68.text-justification 文本左右对齐](https://leetcode-cn.com/problems/text-justification/)

### 题目描述
<p>给定一个单词数组和一个长度&nbsp;<em>maxWidth</em>，重新排版单词，使其成为每行恰好有&nbsp;<em>maxWidth</em>&nbsp;个字符，且左右两端对齐的文本。</p>

<p>你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格&nbsp;<code>' '</code>&nbsp;填充，使得每行恰好有 <em>maxWidth</em>&nbsp;个字符。</p>

<p>要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。</p>

<p>文本的最后一行应为左对齐，且单词之间不插入<strong>额外的</strong>空格。</p>

<p><strong>说明:</strong></p>

<ul>
	<li>单词是指由非空格字符组成的字符序列。</li>
	<li>每个单词的长度大于 0，小于等于&nbsp;<em>maxWidth</em>。</li>
	<li>输入单词数组 <code>words</code>&nbsp;至少包含一个单词。</li>
</ul>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
<strong>输出:</strong>
[
&nbsp; &nbsp;"This &nbsp; &nbsp;is &nbsp; &nbsp;an",
&nbsp; &nbsp;"example &nbsp;of text",
&nbsp; &nbsp;"justification. &nbsp;"
]
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong>
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
<strong>输出:</strong>
[
&nbsp; "What &nbsp; must &nbsp; be",
&nbsp; "acknowledgment &nbsp;",
&nbsp; "shall be &nbsp; &nbsp; &nbsp; &nbsp;"
]
<strong>解释: </strong>注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
&nbsp;    因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre><strong>输入:</strong>
words = ["Science","is","what","we","understand","well","enough","to","explain",
&nbsp;        "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
<strong>输出:</strong>
[
&nbsp; "Science &nbsp;is &nbsp;what we",
  "understand &nbsp; &nbsp; &nbsp;well",
&nbsp; "enough to explain to",
&nbsp; "a &nbsp;computer. &nbsp;Art is",
&nbsp; "everything &nbsp;else &nbsp;we",
&nbsp; "do &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;"
]
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/text-justification/solution/text-justification-by-ikaruga/)

### 答题
``` C++
string fillWords(vector<string>& words, int bg, int ed, int maxWidth, bool lastLine = false)
{
    string ans;
    int wordCount = ed - bg + 1;
    int spaceCount = maxWidth + 1 - wordCount;
    for (int i = bg; i <= ed; i++)
    {
        spaceCount -= words[i].size();
    }

    int t = (wordCount == 1) ? 0 : spaceCount % (wordCount - 1);
    spaceCount /= (wordCount == 1) ? 1 : (wordCount - 1);

    for (int i = bg; i < ed; i++)
    {
        ans += words[i];
        if (lastLine)
        {
            fill_n(back_inserter(ans), 1, ' ');
            continue;
        }
        fill_n(back_inserter(ans), spaceCount + 1 + ((i - bg) < t), ' ');
    }
    ans += words[ed];
    fill_n(back_inserter(ans), maxWidth - ans.size(), ' ');
    return ans;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) 
{
    if (words.empty()) return {};
    vector<string> ans;
    int cnt = 0;
    int bg = 0;
    for (int i = 0; i < words.size(); i++)
    {
        cnt += words[i].size() + 1;

        if (i + 1 == words.size() || cnt + words[i + 1].size() > maxWidth)
        {
            ans.push_back(fillWords(words, bg, i, maxWidth, i + 1 == words.size()));
            bg = i + 1;
            cnt = 0;
        }
    }
    return ans;
}
```




