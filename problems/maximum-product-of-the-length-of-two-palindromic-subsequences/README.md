# `（中等）` [5869.maximum-product-of-the-length-of-two-palindromic-subsequences 两个回文子序列长度的最大乘积](https://leetcode-cn.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/)

[contest](https://leetcode-cn.com/contest/weekly-contest-258/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/)

### 题目描述
<div class="notranslate"><p>给你一个字符串&nbsp;<code>s</code>&nbsp;，请你找到&nbsp;<code>s</code>&nbsp;中两个&nbsp;<strong>不相交回文子序列</strong>&nbsp;，使得它们长度的&nbsp;<strong>乘积最大</strong>&nbsp;。两个子序列在原字符串中如果没有任何相同下标的字符，则它们是&nbsp;<strong>不相交</strong>&nbsp;的。</p>

<p>请你返回两个回文子序列长度可以达到的<strong>&nbsp;最大乘积</strong>&nbsp;。</p>

<p><strong>子序列</strong>&nbsp;指的是从原字符串中删除若干个字符（可以一个也不删除）后，剩余字符不改变顺序而得到的结果。如果一个字符串从前往后读和从后往前读一模一样，那么这个字符串是一个 <strong>回文字符串</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="width: 550px; height: 124px;" src="https://assets.leetcode.com/uploads/2021/08/24/two-palindromic-subsequences.png" alt="example-1"></p>

<pre><b>输入：</b>s = "leetcodecom"
<b>输出：</b>9
<b>解释：</b>最优方案是选择 "ete" 作为第一个子序列，"cdc" 作为第二个子序列。
它们的乘积为 3 * 3 = 9 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "bb"
<b>输出：</b>1
<b>解释：</b>最优方案为选择 "b" （第一个字符）作为第一个子序列，"b" （第二个字符）作为第二个子序列。
它们的乘积为 1 * 1 = 1 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>s = "accbcaxxcxx"
<b>输出：</b>25
<b>解释：</b>最优方案为选择 "accca" 作为第一个子序列，"xxcxx" 作为第二个子序列。
它们的乘积为 5 * 5 = 25 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 12</code></li>
	<li><code>s</code>&nbsp;只含有小写英文字母。</li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/solution/maximum-product-of-the-length-by-ikaruga-35c3/)

### 答题
``` C++
class Solution {
public:
    int maxProduct(string s) {
        int ans = 0;
        for (int i = 0; i < (1 << s.size()); i++) {
            string a, b;
            for (int j = 0; j < s.size(); j++) {
                if (i & (1 << j)) {
                    a += s[j];
                }
                else {
                    b += s[j];
                }
            }
            
            if (a.empty() || b.empty()) continue;
            int x = longestPalindromeSubseq(a);
            int y = longestPalindromeSubseq(b);
            ans = max(ans, x * y);
        }
        return ans;
    }

    int longestPalindromeSubseq(string& s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = (int)s.size() - 1; ~i; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp.front().back();
    }
};
```




