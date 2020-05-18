# `（中等）` [1451.rearrange-words-in-a-sentence 重新排列句子中的单词](https://leetcode-cn.com/problems/rearrange-words-in-a-sentence/)

[contest](https://leetcode-cn.com/contest/weekly-contest-189/problems/rearrange-words-in-a-sentence/)

### 题目描述

              <p>「句子」是一个用空格分隔单词的字符串。给你一个满足下述格式的句子 <code>text</code> :</p>

<ul>
	<li>句子的首字母大写</li>
	<li><code>text</code> 中的每个单词都用单个空格分隔。</li>
</ul>

<p>请你重新排列 <code>text</code> 中的单词，使所有单词按其长度的升序排列。如果两个单词的长度相同，则保留其在原句子中的相对顺序。</p>

<p>请同样按上述格式返回新的句子。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>text = "Leetcode is cool"
<strong>输出：</strong>"Is cool leetcode"
<strong>解释：</strong>句子中共有 3 个单词，长度为 8 的 "Leetcode" ，长度为 2 的 "is" 以及长度为 4 的 "cool" 。
输出需要按单词的长度升序排列，新句子中的第一个单词首字母需要大写。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>text = "Keep calm and code on"
<strong>输出：</strong>"On and keep calm code"
<strong>解释：</strong>输出的排序情况如下：
"On" 2 个字母。
"and" 3 个字母。
"keep" 4 个字母，因为存在长度相同的其他单词，所以它们之间需要保留在原句子中的相对顺序。
"calm" 4 个字母。
"code" 4 个字母。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>text = "To be or not to be"
<strong>输出：</strong>"To be or to be not"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>text</code> 以大写字母开头，然后包含若干小写字母以及单词间的单个空格。</li>
	<li><code>1 &lt;= text.length &lt;= 10^5</code></li>
</ul>

            

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/rearrange-words-in-a-sentence/solution/rearrange-words-in-a-sentence-by-ikaruga/)

### 答题
``` C++
    string arrangeWords(string text) {
        vector<string> words;
        stringstream ss(text);
        string temp;
        while (ss >> temp) {
            words.push_back(temp);
        }
        if (!words.empty()) {
            words[0][0] = tolower(words[0][0]);
        }

        stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        string ans = "";
        for (auto& s : words) {
            ans += s;
            ans += " ";
        }
        if (!ans.empty()) {
            ans[0] = toupper(ans[0]);
        }
        ans.pop_back();
        return ans;
    }
```




