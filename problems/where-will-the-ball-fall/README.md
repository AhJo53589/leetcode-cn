# `（中等）` [1706.where-will-the-ball-fall 球会落何处](https://leetcode-cn.com/problems/where-will-the-ball-fall/)

[contest](https://leetcode-cn.com/contest/weekly-contest-221/problems/where-will-the-ball-fall/)

### 题目描述
<div class="notranslate"><p>用一个大小为 <code>m x n</code> 的二维网格 <code>grid</code> 表示一个箱子。你有 <code>n</code> 颗球。箱子的顶部和底部都是开着的。</p>

<p>箱子中的每个单元格都有一个对角线挡板，跨过单元格的两个角，可以将球导向左侧或者右侧。</p>

<ul>
	<li>将球导向右侧的挡板跨过左上角和右下角，在网格中用 <code>1</code> 表示。</li>
	<li>将球导向左侧的挡板跨过右上角和左下角，在网格中用 <code>-1</code> 表示。</li>
</ul>

<p>在箱子每一列的顶端各放一颗球。每颗球都可能卡在箱子里或从底部掉出来。如果球恰好卡在两块挡板之间的 "V" 形图案，或者被一块挡导向到箱子的任意一侧边上，就会卡住。</p>

<p>返回一个大小为 <code>n</code> 的数组 <code>answer</code> ，其中 <code>answer[i]</code> 是球放在顶部的第 <code>i</code> 列后从底部掉出来的那一列对应的下标，如果球卡在盒子里，则返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="width: 500px; height: 385px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/12/26/ball.jpg" alt=""></strong></p>

<pre><strong>输入：</strong>grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
<strong>输出：</strong>[1,-1,-1,-1,-1]
<strong>解释：</strong>示例如图：
b0 球开始放在第 0 列上，最终从箱子底部第 1 列掉出。
b1 球开始放在第 1 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
b2 球开始放在第 2 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
b3 球开始放在第 3 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
b4 球开始放在第 4 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>grid = [[-1]]
<strong>输出：</strong>[-1]
<strong>解释：</strong>球被卡在箱子左侧边上。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>grid[i][j]</code> 为 <code>1</code> 或 <code>-1</code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/where-will-the-ball-fall/solution/where-will-the-ball-fall-by-ikaruga-ftwp/)

### 答题
``` C++
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = dfs(grid, 0, i);
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x == grid.size()) return y;

        int dy = (grid[x][y] == 1) ? y + 1 : y - 1;
        if (dy >= 0 && dy < grid[x].size() && grid[x][dy] == grid[x][y]) {
            return dfs(grid, x + 1, dy);
        }
        return -1;
    }
};
```




