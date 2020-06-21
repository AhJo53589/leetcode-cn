# `（困难）` [1473.paint-house-iii 给房子涂色 III](https://leetcode-cn.com/problems/paint-house-iii/)

[contest](https://leetcode-cn.com/contest/weekly-contest-192/problems/paint-house-iii/)

### 题目描述
<p>在一个小城市里，有&nbsp;<code>m</code>&nbsp;个房子排成一排，你需要给每个房子涂上 <code>n</code>&nbsp;种颜色之一（颜色编号为 <code>1</code> 到 <code>n</code>&nbsp;）。有的房子去年夏天已经涂过颜色了，所以这些房子不需要被重新涂色。</p>

<p>我们将连续相同颜色尽可能多的房子称为一个街区。（比方说 <code>houses = [1,2,2,3,3,2,1,1]</code> ，它包含 5 个街区&nbsp;<code> [{1}, {2,2}, {3,3}, {2}, {1,1}]</code> 。）</p>

<p>给你一个数组&nbsp;<code>houses</code>&nbsp;，一个&nbsp;<code>m * n</code>&nbsp;的矩阵&nbsp;<code>cost</code>&nbsp;和一个整数&nbsp;<code>target</code>&nbsp;，其中：</p>

<ul>
	<li><code>houses[i]</code>：是第&nbsp;<code>i</code>&nbsp;个房子的颜色，<strong>0</strong>&nbsp;表示这个房子还没有被涂色。</li>
	<li><code>cost[i][j]</code>：是将第&nbsp;<code>i</code>&nbsp;个房子涂成颜色&nbsp;<code>j+1</code>&nbsp;的花费。</li>
</ul>

<p>请你返回房子涂色方案的最小总花费，使得每个房子都被涂色后，恰好组成&nbsp;<code>target</code>&nbsp;个街区。如果没有可用的涂色方案，请返回&nbsp;<strong>-1</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
<strong>输出：</strong>9
<strong>解释：</strong>房子涂色方案为 [1,2,2,1,1]
此方案包含 target = 3 个街区，分别是 [{1}, {2,2}, {1,1}]。
涂色的总花费为 (1 + 1 + 1 + 1 + 5) = 9。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
<strong>输出：</strong>11
<strong>解释：</strong>有的房子已经被涂色了，在此基础上涂色方案为 [2,2,1,2,2]
此方案包含 target = 3 个街区，分别是 [{2,2}, {1}, {2,2}]。
给第一个和最后一个房子涂色的花费为 (10 + 1) = 11。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>houses = [0,0,0,0,0], cost = [[1,10],[10,1],[1,10],[10,1],[1,10]], m = 5, n = 2, target = 5
<strong>输出：</strong>5
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
<strong>输出：</strong>-1
<strong>解释：</strong>房子已经被涂色并组成了 4 个街区，分别是 [{3},{1},{2},{3}] ，无法形成 target = 3 个街区。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == houses.length == cost.length</code></li>
	<li><code>n == cost[i].length</code></li>
	<li><code>1 <= m <= 100</code></li>
	<li><code>1 <= n <= 20</code></li>
	<li><code>1 <= target&nbsp;<= m</code></li>
	<li><code>0 <= houses[i]&nbsp;<= n</code></li>
	<li><code>1 <= cost[i][j] <= 10^4</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/paint-house-iii/solution/paint-house-iii-by-ikaruga/)

### 答题
``` C++
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // dp[索引][颜色][街区数量 - 1] = 最小花费
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(target + 1, INT_MAX)));

        if (houses[0] == 0) {
            for (int j = 1; j <= n; j++) {
                dp[0][j][0] = cost[0][j - 1];
            }
        }
        else {
            dp[0][houses[0]][0] = 0;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 0; k < target; k++) {
                    if (houses[i] == 0) {
                        for (int j_old = 1; j_old <= n; j_old++) {
                            if (dp[i - 1][j_old][k] == INT_MAX) continue;

                            if (j_old == j) {
                                dp[i][j][k] = min(dp[i - 1][j_old][k] + cost[i][j - 1], dp[i][j][k]);
                            }
                            else {
                                dp[i][j][k + 1] = min(dp[i - 1][j_old][k] + cost[i][j - 1], dp[i][j][k + 1]);
                            }
                        }
                    }
                    else {
                        if (dp[i - 1][j][k] == INT_MAX) continue;

                        if (houses[i] == j) {
                            dp[i][j][k] = min(dp[i - 1][j][k], dp[i][j][k]);
                        }
                        else {
                            dp[i][houses[i]][k + 1] = min(dp[i - 1][j][k], dp[i][houses[i]][k + 1]);
                        }
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (int j = 1; j <= n; j++) {
            ans = min(ans, dp[m - 1][j][target - 1]);
        }
        return ans == INT_MAX ? -1 : ans;
    }

```




