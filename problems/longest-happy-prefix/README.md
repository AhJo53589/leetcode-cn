# `（困难）` [1392.longest-happy-prefix 最长快乐前缀](https://leetcode-cn.com/problems/longest-happy-prefix/)

[contest](https://leetcode-cn.com/contest/weekly-contest-181/problems/longest-happy-prefix/)

### 题目描述
<p>「快乐前缀」是一个既是前缀也是后缀（不包括其自身）的 <strong>非空</strong> 字符串。</p>
<p>给你一个字符串 <code>s</code>，请你返回它的 <strong>最长快乐前缀</strong> <code>s</code> 。</p>
<p>如果不存在满足题意的前缀，则返回一个空字符串。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong>s = "level"
<strong>输出：</strong>"l"
<strong>解释：</strong>不包括 s 自己，一共有 4 个前缀（"l", "le", "lev", "leve"）和 4 个后缀（"l", "el", "vel", "evel"）。最长的既是前缀也是后缀的字符串是 "l" 。
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>s = "ababab"
<strong>输出：</strong>"abab"
<strong>解释：</strong>"abab" 是最长的既是前缀也是后缀的字符串。题目允许前后缀在原字符串中重叠的情况出现。
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>s = "leetcodeleet"
<strong>输出：</strong>"leet"
</pre>

<p><strong>示例 4：</strong></p>
<pre><strong>输入：</strong>s = "a"
<strong>输出：</strong>""
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code> 只含有小写英文字母</li>
</ul>

​            

---
### 思路
```

```



### 答题
``` C++
typedef unsigned long long ULL;
class Solution {
public:
    string longestPrefix(string s) {
        int base = 131;
        ULL p[100002];
        p[0] = 1;
        ULL hash[100002];
        hash[0] = 0;
        for (int i = 1; i <= s.size(); i++) {
            hash[i] = hash[i - 1] * base + s[i - 1] - 'a' + 1;
            p[i] = p[i - 1] * base;
        }
        for (int i = s.size() - 1; i >= 1; i--) {
            ULL pre = hash[i];
            ULL suf = hash[s.size()] - hash[s.size() - i] * p[i];
            if (pre == suf) {
                return s.substr(0, i);
            }
        }
        return "";
    }
};
```




