# `（中等）` [LCP 19.UlBDOe 秋叶收藏集](https://leetcode-cn.com/problems/UlBDOe/)

### 题目描述
<p>小扣出去秋游，途中收集了一些红叶和黄叶，他利用这些叶子初步整理了一份秋叶收藏集 <code>leaves</code>， 字符串 <code>leaves</code> 仅包含小写字符 <code>r</code> 和 <code>y</code>， 其中字符 <code>r</code> 表示一片红叶，字符 <code>y</code> 表示一片黄叶。<br>
出于美观整齐的考虑，小扣想要将收藏集中树叶的排列调整成「红、黄、红」三部分。每部分树叶数量可以不相等，但均需大于等于 1。每次调整操作，小扣可以将一片红叶替换成黄叶或者将一片黄叶替换成红叶。请问小扣最少需要多少次调整操作才能将秋叶收藏集调整完毕。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>leaves = "rrryyyrryyyrr"</code></p>
<p>输出：<code>2</code></p>
<p>解释：调整两次，将中间的两片红叶替换成黄叶，得到 "rrryyyyyyyyrr"</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>leaves = "ryr"</code></p>
<p>输出：<code>0</code></p>
<p>解释：已符合要求，不需要额外操作</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>3 &lt;= leaves.length &lt;= 10^5</code></li>
<li><code>leaves</code> 中只包含字符 <code>'r'</code> 和字符 <code>'y'</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/UlBDOe/solution/ulbdoe-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int minimumOperations(string leaves) {
        vector<vector<int>> dp(3, vector<int>(leaves.size(), 0));

        for (int i = 0; i < leaves.size(); i++) {
            if (i < 1) {
                dp[0][i] = (leaves[i] != 'r');
            }
            else {
                dp[0][i] = dp[0][i - 1] + (leaves[i] != 'r');
            }
            
            if (i < 1) {
                dp[1][i] = dp[0][i];
            }
            else {
                dp[1][i] = min(dp[0][i - 1] + (leaves[i] != 'y'), dp[1][i - 1] + (leaves[i] != 'y'));
            }

            if (i < 2) {
                dp[2][i] = dp[1][i];
            }
            else {
                dp[2][i] = min(dp[1][i - 1] + (leaves[i] != 'r'), dp[2][i - 1] + (leaves[i] != 'r'));
            }
        }

        return dp[2].back();
    }
};
```




