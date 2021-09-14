# `（中等）` [524.longest-word-in-dictionary-through-deleting 通过删除字母匹配到字典里最长单词](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/)

### 题目描述
<p>给你一个字符串 <code>s</code> 和一个字符串数组 <code>dictionary</code> 作为字典，找出并返回字典中最长的字符串，该字符串可以通过删除 <code>s</code> 中的某些字符得到。</p>

<p>如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
<strong>输出：</strong>"apple"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abpcplea", dictionary = ["a","b","c"]
<strong>输出：</strong>"a"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>1 &lt;= dictionary.length &lt;= 1000</code></li>
	<li><code>1 &lt;= dictionary[i].length &lt;= 1000</code></li>
	<li><code>s</code> 和 <code>dictionary[i]</code> 仅由小写英文字母组成</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/solution/longest-word-in-dictionary-through-delet-m3fa/)

### 答题
``` C++
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b) {
            return a.size() == b.size() ? a < b : a.size() > b.size();
        });

        for (auto& w : dictionary) {
            for (int i = 0, j = 0; i < s.size(); i++) {
                j += (s[i] == w[j]);
                if (j == w.size()) return w;
            }
        }
        return "";
    }
};
```




