# `（简单）` [5380.string-matching-in-an-array 数组中的字符串匹配](https://leetcode-cn.com/problems/string-matching-in-an-array/)

[contest](https://leetcode-cn.com/contest/weekly-contest-184/problems/string-matching-in-an-array/)

### 题目描述
<p>给你一个字符串数组 <code>words</code> ，数组中的每个字符串都可以看作是一个单词。请你按 <strong>任意</strong> 顺序返回 <code>words</code> 中是其他单词的子字符串的所有单词。</p>

<p>如果你可以删除 <code>words[j]</code>&nbsp;最左侧和/或最右侧的若干字符得到 <code>word[i]</code> ，那么字符串 <code>words[i]</code> 就是 <code>words[j]</code> 的一个子字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = ["mass","as","hero","superhero"]
<strong>输出：</strong>["as","hero"]
<strong>解释：</strong>"as" 是 "mass" 的子字符串，"hero" 是 "superhero" 的子字符串。
["hero","as"] 也是有效的答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = ["leetcode","et","code"]
<strong>输出：</strong>["et","code"]
<strong>解释：</strong>"et" 和 "code" 都是 "leetcode" 的子字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>words = ["blue","green","bu"]
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 30</code></li>
	<li><code>words[i]</code> 仅包含小写英文字母。</li>
	<li>题目数据 <strong>保证</strong> 每个 <code>words[i]</code> 都是独一无二的。</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
    vector<string> stringMatching(vector<string>& words) 
    {
        vector<string> ans;
        sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.size() < b.size(); });
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                for (int k = 0; k + words[i].size() <= words[j].size(); k++)
                {
                    if (memcmp(&words[i][0], &words[j][k], words[i].size()) != 0) continue;
                    ans.push_back(words[i]);
                    j = words.size();
                    break;
                }
            }
        }
        return ans;
    }
```




