# `（困难）` [664.strange-printer 奇怪的打印机](https://leetcode-cn.com/problems/strange-printer/)

### 题目描述
<p>有台奇怪的打印机有以下两个特殊要求：</p>

<ul>
	<li>打印机每次只能打印由 <strong>同一个字符</strong> 组成的序列。</li>
	<li>每次可以在任意起始和结束位置打印新字符，并且会覆盖掉原来已有的字符。</li>
</ul>

<p>给你一个字符串 <code>s</code> ，你的任务是计算这个打印机打印它需要的最少打印次数。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "aaabbb"
<strong>输出：</strong>2
<strong>解释：</strong>首先打印 "aaa" 然后打印 "bbb"。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "aba"
<strong>输出：</strong>2
<strong>解释：</strong>首先打印 "aaa" 然后在第二个位置打印 "b" 覆盖掉原来的字符 'a'。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int strangePrinter(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), INT_MAX));
        for (int i = (int)s.size() - 1; ~i; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                    continue;
                }

                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        return dp.front().back();
    }
};
```




