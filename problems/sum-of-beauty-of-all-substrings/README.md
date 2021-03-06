# `（中等）` [5682.sum-of-beauty-of-all-substrings 所有子字符串美丽值之和](https://leetcode-cn.com/problems/sum-of-beauty-of-all-substrings/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-47/problems/sum-of-beauty-of-all-substrings/)

### 题目描述
<div class="notranslate"><p>一个字符串的 <strong>美丽值</strong>&nbsp;定义为：出现频率最高字符与出现频率最低字符的出现次数之差。</p>

<ul>
	<li>比方说，<code>"abaacc"</code>&nbsp;的美丽值为&nbsp;<code>3 - 1 = 2</code>&nbsp;。</li>
</ul>

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，请你返回它所有子字符串的&nbsp;<strong>美丽值</strong>&nbsp;之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "aabcb"
<b>输出：</b>5
<strong>解释：</strong>美丽值不为零的字符串包括 ["aab","aabc","aabcb","abcb","bcb"] ，每一个字符串的美丽值都为 1 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "aabcbaa"
<b>输出：</b>17
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;=<sup> </sup>500</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/sum-of-beauty-of-all-substrings/solution/sum-of-beauty-of-all-substrings-by-ikaru-14da/)

### 答题
``` C++
class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> cnt(26, 0);
            multiset<int> ms;
            for (int j = i; j < s.size(); j++) {
                int c = s[j] - 'a';
                if (cnt[c] != 0) {
                    ms.erase(ms.find(cnt[c]));
                }
                cnt[c]++;
                ms.insert(cnt[c]);
                if (ms.size() < 2) continue;
                ans += *ms.rbegin() - *ms.begin();
            }
        }
        return ans;
    }
};
```




