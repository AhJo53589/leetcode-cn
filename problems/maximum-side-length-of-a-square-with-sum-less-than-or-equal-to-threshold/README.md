# `（中等）` [1292.maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold 元素和小于等于阈值的正方形的最大边长](https://leetcode-cn.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/)

[contest](https://leetcode-cn.com/contest/weekly-contest-167/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/)

### 题目描述
<p>给你一个大小为&nbsp;<code>m x n</code>&nbsp;的矩阵&nbsp;<code>mat</code>&nbsp;和一个整数阈值&nbsp;<code>threshold</code>。</p>

<p>请你返回元素总和小于或等于阈值的正方形区域的最大边长；如果没有这样的正方形区域，则返回 <strong>0&nbsp;</strong>。<br>
&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 186px; width: 335px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/12/15/e1.png" alt=""></p>

<pre><strong>输入：</strong>mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
<strong>输出：</strong>2
<strong>解释：</strong>总和小于 4 的正方形的最大边长为 2，如图所示。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
<strong>输出：</strong>0
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
<strong>输出：</strong>3
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], threshold = 40184
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>0 &lt;= mat[i][j] &lt;= 10000</code></li>
	<li><code>0 &lt;= threshold&nbsp;&lt;= 10^5</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
int maxSideLength(vector<vector<int>>& mat, int threshold) 
{
    vector<vector<int>> dp(mat.size() + 1, vector<int>());
    for (auto &d : dp) d.resize(mat[0].size() + 1);

    int ans = 0;
    dp[0][0] = mat[0][0];
    for (size_t i = 1; i < mat.size(); i++)
    {
        dp[i][0] = mat[i][0] + dp[i - 1][0];
    }
    for (size_t j = 1; j < mat[0].size(); j++)
    {
        dp[0][j] = mat[0][j] + dp[0][j - 1];
    }
    for (size_t i = 1; i <= mat.size(); i++)
    {
        for (size_t j = 1; j <= mat[0].size(); j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            if (i != mat.size() && j != mat[0].size())
            {
                dp[i][j] += mat[i][j];
            }
        }
    }

    for (int len = 1; len <= min(mat.size(), mat[0].size()); len++)
    {
        for (size_t i = len - 1; i < mat.size(); i++)
        {
            if (ans == len) break;
            for (size_t j = len - 1; j < mat[0].size(); j++)
            {
                int ts = dp[i][j];
                if (i - len < dp.size())
                {
                    ts -= dp[i - len][j];
                }
                if (j - len < dp[0].size())
                {
                    ts -= dp[i][j - len];
                }
                if (i - len < dp.size() && j - len < dp[0].size())
                {
                    ts += dp[i - len][j - len];
                }
                if (ts > threshold) continue;
                ans = max(ans, len);
                break;
            }
        }
    }
    return ans;
}
```




