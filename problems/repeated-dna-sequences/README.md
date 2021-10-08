# `（中等）` [187.repeated-dna-sequences 重复的DNA序列](https://leetcode-cn.com/problems/repeated-dna-sequences/)

### 题目描述
<p>所有 DNA 都由一系列缩写为 <code>'A'</code>，<code>'C'</code>，<code>'G'</code> 和 <code>'T'</code> 的核苷酸组成，例如：<code>"ACGAATTCCG"</code>。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。</p>

<p>编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 <code>s</code> 中出现次数超过一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
<strong>输出：</strong>["AAAAACCCCC","CCCCCAAAAA"]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "AAAAAAAAAAAAA"
<strong>输出：</strong>["AAAAAAAAAA"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 为 <code>'A'</code>、<code>'C'</code>、<code>'G'</code> 或 <code>'T'</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/repeated-dna-sequences/solution/repeated-dna-sequences-by-ikaruga-249x/)

### 答题
``` C++
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int len = 10;
        unordered_map<char, int> dic = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_map<int, int> cnt;
        vector<string> ans;

        int t = 0;
        for (int i = 0; i < s.size(); i++) {
            t = ((t << 2) | dic[s[i]]) & ((1 << (len * 2)) - 1);
            if (i < len - 1) continue;
            if (++cnt[t] == 2) {
                ans.push_back(s.substr(i - len + 1, len));
            }
        }
        return ans;
    }
};
```




