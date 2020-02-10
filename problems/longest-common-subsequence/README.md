# `（中等）` [1143.longest-common-subsequence 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)

### 题目描述
<p>给定两个字符串&nbsp;<code>text1</code> 和&nbsp;<code>text2</code>，返回这两个字符串的最长公共子序列。</p>

<p>一个字符串的&nbsp;<em>子序列&nbsp;</em>是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。<br>
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。</p>

<p>若这两个字符串没有公共子序列，则返回 0。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入：</strong>text1 = "abcde", text2 = "ace" 
<strong>输出：</strong>3  
<strong>解释：</strong>最长公共子序列是 "ace"，它的长度为 3。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入：</strong>text1 = "abc", text2 = "abc"
<strong>输出：</strong>3
<strong>解释：</strong>最长公共子序列是 "abc"，它的长度为 3。
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入：</strong>text1 = "abc", text2 = "def"
<strong>输出：</strong>0
<strong>解释：</strong>两个字符串没有公共子序列，返回 0。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= text1.length &lt;= 1000</code></li>
	<li><code>1 &lt;= text2.length &lt;= 1000</code></li>
	<li>输入的字符串只含有小写英文字符。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
int longestCommonSubsequence(string text1, string text2)
{
    int ans = 0;
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = 1; i <= text1.size(); i++)
    {
        for (int j = 1; j <= text2.size(); j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}
```




