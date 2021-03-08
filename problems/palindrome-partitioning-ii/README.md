# `（困难）` [132.palindrome-partitioning-ii 分割回文串 II](https://leetcode-cn.com/problems/palindrome-partitioning-ii/)

### 题目描述
<p>给你一个字符串 <code>s</code>，请你将 <code>s</code> 分割成一些子串，使每个子串都是回文。</p>

<p>返回符合要求的 <strong>最少分割次数</strong> 。</p>

<div class="original__bRMd">
<div>
<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "aab"
<strong>输出：</strong>1
<strong>解释：</strong>只需一次分割就可将&nbsp;<em>s </em>分割成 ["aa","b"] 这样两个回文子串。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "a"
<strong>输出：</strong>0
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "ab"
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>
</div>
</div>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/palindrome-partitioning-ii/solution/palindrome-partitioning-ii-by-ikaruga-o5xp/)

### 答题
``` C++
class Solution {
public:
    int minCut(string s) {
        vector<int> v(s.size(), 0);
        for (int i = 1; i < s.size(); i++) {
            calc(s, i, i, v);
            calc(s, i, i - 1, v);
        }

        
        for (auto n : v) cout << n << ", "; cout << endl;

        vector<int> dp(s.size() + 1, INT_MAX);
        dp[0] = -1;
        for (int i = 0; i < dp.size(); i++) {
            if (i != 0) {
                dp[i] = min(dp[i - 1] + 1, dp[i]);
            }
            if (i != s.size()) {
                dp[v[i] + 1] = min(dp[v[i] + 1], dp[i] + 1);
            }
        }
        return dp.back();
    }

    void calc(string& s, int l, int r, vector<int>& v) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            v[l] = max(v[l], r);
            l--;
            r++;
        }
    }
};
```




