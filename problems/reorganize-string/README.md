# `（中等）` [767.reorganize-string 重构字符串](https://leetcode-cn.com/problems/reorganize-string/)

### 题目描述
<p>给定一个字符串<code>S</code>，检查是否能重新排布其中的字母，使得两相邻的字符不同。</p>

<p>若可行，输出任意可行的结果。若不可行，返回空字符串。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> S = "aab"
<strong>输出:</strong> "aba"
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> S = "aaab"
<strong>输出:</strong> ""
</pre>

<p><strong>注意:</strong></p>

<ul>
	<li><code>S</code> 只包含小写字母并且长度在<code>[1, 500]</code>区间内。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> cnt(26);
        for (auto c : S) {
            cnt[c - 'a']++;
        }
        vector<pair<int, char>> vp;
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] == 0) continue;
            vp.push_back({cnt[i], 'a' + i});
        }
        sort(vp.rbegin(), vp.rend());

        if (vp.front().first > S.size() / 2 + (S.size() % 2)) return "";

        int pos = 0;
        for (auto [n, c] : vp) {
            for (int i = 0; i < n; i++) {
                S[getIndex(S.size(), pos++)] = c;
            }
        }

        return S;
    }

    int getIndex(int len, int i) {
        return (i * 2 >= len) ? i * 2 - len + (len % 2 == 0) : i * 2;
    }
};
```




