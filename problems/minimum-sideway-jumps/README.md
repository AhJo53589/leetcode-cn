# `（中等）` [5728.minimum-sideway-jumps 最少侧跳次数](https://leetcode-cn.com/problems/minimum-sideway-jumps/)

[contest](https://leetcode-cn.com/contest/weekly-contest-236/problems/minimum-sideway-jumps/)

### 题目描述
<div class="notranslate"><p>给你一个长度为&nbsp;<code>n</code>&nbsp;的&nbsp;<strong>3 跑道道路</strong>&nbsp;，它总共包含&nbsp;<code>n + 1</code>&nbsp;个&nbsp;<strong>点</strong>&nbsp;，编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n</code>&nbsp;。一只青蛙从&nbsp;<code>0</code>&nbsp;号点第二条跑道&nbsp;<strong>出发</strong>&nbsp;，它想要跳到点&nbsp;<code>n</code>&nbsp;处。然而道路上可能有一些障碍。</p>

<p>给你一个长度为 <code>n + 1</code>&nbsp;的数组&nbsp;<code>obstacles</code>&nbsp;，其中&nbsp;<code>obstacles[i]</code>&nbsp;（<b>取值范围从 0 到 3</b>）表示在点 <code>i</code>&nbsp;处的&nbsp;<code>obstacles[i]</code>&nbsp;跑道上有一个障碍。如果&nbsp;<code>obstacles[i] == 0</code>&nbsp;，那么点&nbsp;<code>i</code>&nbsp;处没有障碍。任何一个点的三条跑道中&nbsp;<strong>最多有一个</strong>&nbsp;障碍。</p>

<ul>
	<li>比方说，如果&nbsp;<code>obstacles[2] == 1</code>&nbsp;，那么说明在点 2 处跑道 1 有障碍。</li>
</ul>

<p>这只青蛙从点 <code>i</code>&nbsp;跳到点 <code>i + 1</code>&nbsp;且跑道不变的前提是点 <code>i + 1</code>&nbsp;的同一跑道上没有障碍。为了躲避障碍，这只青蛙也可以在&nbsp;<strong>同一个</strong>&nbsp;点处&nbsp;<strong>侧跳</strong>&nbsp;到 <strong>另外一条</strong>&nbsp;跑道（这两条跑道可以不相邻），但前提是跳过去的跑道该点处没有障碍。</p>

<ul>
	<li>比方说，这只青蛙可以从点 3 处的跑道 3 跳到点 3 处的跑道 1 。</li>
</ul>

<p>这只青蛙从点 0 处跑道 <code>2</code>&nbsp;出发，并想到达点 <code>n</code>&nbsp;处的 <strong>任一跑道</strong> ，请你返回 <strong>最少侧跳次数</strong>&nbsp;。</p>

<p><strong>注意</strong>：点 <code>0</code>&nbsp;处和点 <code>n</code>&nbsp;处的任一跑道都不会有障碍。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 500px; height: 244px;" src="https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex1.png" alt="">
<pre><b>输入：</b>obstacles = [0,1,2,3,0]
<b>输出：</b>2 
<b>解释：</b>最优方案如上图箭头所示。总共有 2 次侧跳（红色箭头）。
注意，这只青蛙只有当侧跳时才可以跳过障碍（如上图点 2 处所示）。
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 500px; height: 196px;" src="https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex2.png" alt="">
<pre><b>输入：</b>obstacles = [0,1,1,3,3,0]
<b>输出：</b>0
<b>解释：</b>跑道 2 没有任何障碍，所以不需要任何侧跳。
</pre>

<p><strong>示例 3：</strong></p>
<img style="width: 500px; height: 196px;" src="https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex3.png" alt="">
<pre><b>输入：</b>obstacles = [0,2,1,0,3,0]
<b>输出：</b>2
<b>解释：</b>最优方案如上图所示。总共有 2 次侧跳。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>obstacles.length == n + 1</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= obstacles[i] &lt;= 3</code></li>
	<li><code>obstacles[0] == obstacles[n] == 0</code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-sideway-jumps/solution/minimum-sideway-jumps-by-ikaruga-j1t1/)

### 答题
``` C++
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(obstacles.size(), vector<int>(3, 1e9));
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 1;
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1) continue;
                dp[i][j] = dp[i - 1][j];
            }
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1) continue;
                int a = (j + 1) % 3;
                int b = (j + 2) % 3;
                int side = min(dp[i][a], dp[i][b]) + 1;
                dp[i][j] = min(side, dp[i][j]);
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};
```




