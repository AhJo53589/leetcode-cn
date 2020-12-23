# `（中等）` [1653.minimum-deletions-to-make-string-balanced 使字符串平衡的最少删除次数](https://leetcode-cn.com/problems/minimum-deletions-to-make-string-balanced/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-39/problems/minimum-deletions-to-make-string-balanced/)

### 题目描述
<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，它仅包含字符&nbsp;<code>'a'</code> 和&nbsp;<code>'b'</code>​​​​ 。</p>
<p>你可以删除&nbsp;<code>s</code>&nbsp;中任意数目的字符，使得&nbsp;<code>s</code> <strong>平衡</strong>&nbsp;。我们称&nbsp;<code>s</code>&nbsp;<strong>平衡的</strong>&nbsp;当不存在下标对&nbsp;<code>(i,j)</code>&nbsp;满足&nbsp;<code>i &lt; j</code> 且&nbsp;<code>s[i] = 'b'</code>&nbsp;同时&nbsp;<code>s[j]= 'a'</code>&nbsp;。</p>
<p>请你返回使 <code>s</code>&nbsp;<strong>平衡</strong>&nbsp;的 <strong>最少</strong>&nbsp;删除次数。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><b>输入：</b>s = "aababbab"
<b>输出：</b>2
<b>解释：</b>你可以选择以下任意一种方案：
下标从 0 开始，删除第 2 和第 6 个字符（"aa<strong>b</strong>abb<strong>a</strong>b" -&gt; "aaabbb"），
下标从 0 开始，删除第 3 和第 6 个字符（"aab<strong>a</strong>bb<strong>a</strong>b" -&gt; "aabbbb"）。
</pre>

<p><strong>示例 2：</strong></p>
<pre><b>输入：</b>s = "bbaaaaabb"
<b>输出：</b>2
<b>解释：</b>唯一的最优解是删除最前面两个字符。
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code>&nbsp;要么是&nbsp;<code>'a'</code> 要么是&nbsp;<code>'b'</code>​<strong>&nbsp;</strong>。​</li>
</ul>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-deletions-to-make-string-balanced/solution/minimum-deletions-to-make-string-balanced-by-ikaru/)

### 答题
``` C++
class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> del_a(s.size(), 0);
        vector<int> del_b(s.size(), 0);
        del_b[0] = (s[0] == 'b');
        for (int i = 1; i < s.size(); i++) {
            del_b[i] = del_b[i - 1] + (s[i] == 'b');
        }
        del_a.back() = (s.back() == 'a');
        for (int i = s.size() - 2; i >= 0; i--) {
            del_a[i] = del_a[i + 1] + (s[i] == 'a');
        }

        int ans = INT_MAX;
        for (int i = 0; i < s.size() - 1; i++) {
            ans = min(ans, del_b[i] + del_a[i + 1]);
        }
        ans = min(ans, del_a.front());
        ans = min(ans, del_b.back());

        return ans;
    }
};
```




