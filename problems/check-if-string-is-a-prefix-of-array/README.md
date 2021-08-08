# `（简单）` [5838.check-if-string-is-a-prefix-of-array 检查字符串是否为数组前缀](https://leetcode-cn.com/problems/check-if-string-is-a-prefix-of-array/)

[contest](https://leetcode-cn.com/contest/weekly-contest-253/problems/check-if-string-is-a-prefix-of-array/)

### 题目描述
<p>给你一个字符串 <code>s</code> 和一个字符串数组 <code>words</code> ，请你判断 <code>s</code> 是否为 <code>words</code> 的 <strong>前缀字符串</strong> 。</p>

<p>字符串 <code>s</code> 要成为 <code>words</code> 的 <strong>前缀字符串</strong> ，需要满足：<code>s</code> 可以由 <code>words</code> 中的前 <code>k</code>（<code>k</code> 为 <strong>正数</strong> ）个字符串按顺序相连得到，且 <code>k</code> 不超过 <code>words.length</code> 。</p>

<p>如果 <code>s</code> 是 <code>words</code> 的 <strong>前缀字符串</strong> ，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "iloveleetcode", words = ["i","love","leetcode","apples"]
<strong>输出：</strong>true
<strong>解释：</strong>
s 可以由 "i"、"love" 和 "leetcode" 相连得到。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "iloveleetcode", words = ["apples","i","love","leetcode"]
<strong>输出：</strong>false
<strong>解释：</strong>
数组的前缀相连无法得到 s 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 20</code></li>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>words[i]</code> 和 <code>s</code> 仅由小写英文字母组成</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < words.size()) {
            if ((int)s.size() - i < words[j].size()) return false;
            for (int k = 0; k < words[j].size(); k++) {
                if (s[i + k] != words[j][k]) return false;
            }
            i += words[j].size();
            j++;
            if (i == s.size()) return true;
        }
        return false;
    }
};
```




