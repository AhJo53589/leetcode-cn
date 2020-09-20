# `（中等）` [5520.split-a-string-into-the-max-number-of-unique-substrings 拆分字符串使唯一子字符串的数目最大](https://leetcode-cn.com/problems/split-a-string-into-the-max-number-of-unique-substrings/)

[contest](https://leetcode-cn.com/contest/weekly-contest-207/problems/split-a-string-into-the-max-number-of-unique-substrings/)

### 题目描述
<p>给你一个字符串 <code>s</code> ，请你拆分该字符串，并返回拆分后唯一子字符串的最大数目。</p>

<p>字符串 <code>s</code> 拆分后可以得到若干 <strong>非空子字符串</strong> ，这些子字符串连接后应当能够还原为原字符串。但是拆分出来的每个子字符串都必须是 <strong>唯一的</strong> 。</p>

<p>注意：<strong>子字符串</strong> 是字符串中的一个连续字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "ababccc"
<strong>输出：</strong>5
<strong>解释：</strong>一种最大拆分方法为 ['a', 'b', 'ab', 'c', 'cc'] 。像 ['a', 'b', 'a', 'b', 'c', 'cc'] 这样拆分不满足题目要求，因为其中的 'a' 和 'b' 都出现了不止一次。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "aba"
<strong>输出：</strong>2
<strong>解释：</strong>一种最大拆分方法为 ['a', 'ba'] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "aa"
<strong>输出：</strong>1
<strong>解释：</strong>无法进一步拆分字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>
	<p><code>1 <= s.length&nbsp;<= 16</code></p>
	</li>
	<li>
	<p><code>s</code> 仅包含小写英文字母</p>
	</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/split-a-string-into-the-max-number-of-unique-substrings/solution/split-a-string-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int maxUniqueSplit(string s) {
        dfs(s, 0);
        return ans;
    }

    void dfs(string& s, int pos) {
        if (s.size() - pos + us.size() <= ans) return;
        if (pos == s.size()) {
            ans = max(ans, (int)us.size());
            return;
        }

        string temp;
        for (int i = pos; i < s.size(); i++) {
            temp += s[i];
            if (us.find(temp) == us.end()) {
                us.insert(temp);
                dfs(s, i + 1);
                us.erase(temp);
            }
        }
    }
private:
    int ans = 0;
    unordered_set<string> us;
};
```




