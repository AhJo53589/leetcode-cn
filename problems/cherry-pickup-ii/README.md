# `（困难）` [5411.cherry-pickup-ii 摘樱桃 II](https://leetcode-cn.com/problems/cherry-pickup-ii/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-27/problems/cherry-pickup-ii/)

### 题目描述
<p>给你一个&nbsp;<code>rows x cols</code> 的矩阵&nbsp;<code>grid</code>&nbsp;来表示一块樱桃地。 <code>grid</code>&nbsp;中每个格子的数字表示你能获得的樱桃数目。</p>

<p>你有两个机器人帮你收集樱桃，机器人 1 从左上角格子 <code>(0,0)</code> 出发，机器人 2 从右上角格子 <code>(0, cols-1)</code> 出发。</p>

<p>请你按照如下规则，返回两个机器人能收集的最多樱桃数目：</p>

<ul>
	<li>从格子&nbsp;<code>(i,j)</code> 出发，机器人可以移动到格子&nbsp;<code>(i+1, j-1)</code>，<code>(i+1, j)</code> 或者&nbsp;<code>(i+1, j+1)</code>&nbsp;。</li>
	<li>当一个机器人经过某个格子时，它会把该格子内所有的樱桃都摘走，然后这个位置会变成空格子，即没有樱桃的格子。</li>
	<li>当两个机器人同时到达同一个格子时，它们中只有一个可以摘到樱桃。</li>
	<li>两个机器人在任意时刻都不能移动到 <code>grid</code>&nbsp;外面。</li>
	<li>两个机器人最后都要到达&nbsp;<code>grid</code>&nbsp;最底下一行。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="height: 182px; width: 139px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/30/sample_1_1802.png" alt=""></strong></p>

<pre><strong>输入：</strong>grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
<strong>输出：</strong>24
<strong>解释：</strong>机器人 1 和机器人 2 的路径在上图中分别用绿色和蓝色表示。
机器人 1 摘的樱桃数目为 (3 + 2 + 5 + 2) = 12 。
机器人 2 摘的樱桃数目为 (1 + 5 + 5 + 1) = 12 。
樱桃总数为： 12 + 12 = 24 。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img style="height: 257px; width: 284px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/30/sample_2_1802.png" alt=""></strong></p>

<pre><strong>输入：</strong>grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
<strong>输出：</strong>28
<strong>解释：</strong>机器人 1 和机器人 2 的路径在上图中分别用绿色和蓝色表示。
机器人 1 摘的樱桃数目为 (1 + 9 + 5 + 2) = 17 。
机器人 2 摘的樱桃数目为 (1 + 3 + 4 + 3) = 11 。
樱桃总数为： 17 + 11 = 28 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>grid = [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]
<strong>输出：</strong>22
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>grid = [[1,1],[1,1]]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>rows == grid.length</code></li>
	<li><code>cols == grid[i].length</code></li>
	<li><code>2 <= rows, cols <= 70</code></li>
	<li><code>0 <= grid[i][j] <= 100&nbsp;</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/cherry-pickup-ii/solution/cherry-pickup-ii-by-ikaruga/)

### 答题
``` C++
    int cherryPickup(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;

        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), 0)));
        dp[0][0][grid[0].size() - 1] = grid[0][0] + grid[0].back() + 1;
        
        int ans = 0;
        for (int i = 0; i < grid.size() - 1; i++) {

            for (int a = 0; a < grid[0].size(); a++) {
                for (int b = a; b < grid[0].size(); b++) {
                    if (dp[i][a][b] == 0) continue;

                    for (int ar = max(a - 1, 0); ar < min(a + 2, (int)grid[0].size()); ar++) {
                        for (int br = max(b - 1, 0); br < min(b + 2, (int)grid[0].size()); br++) {
                            int art = (ar < br) ? ar : br;
                            int brt = (ar < br) ? br : ar;

                            int newVal = dp[i][a][b] + grid[i + 1][art] + grid[i + 1][brt];
                            newVal -= (art == brt) ? grid[i + 1][art] : 0;
                            dp[i + 1][art][brt] = max(dp[i + 1][art][brt], newVal);
                        }
                    }
                }
            }
        }

        for (int a = 0; a < grid[0].size(); a++) {
            for (int b = a; b < grid[0].size(); b++) {
                ans = max(ans, dp.back()[a][b]);
            }
        }

        return ans - 1;
    }
```




