# `（中等）` [1034.coloring-a-border 边界着色](https://leetcode-cn.com/problems/coloring-a-border/)

### 题目描述
<p>给你一个大小为 <code>m x n</code> 的整数矩阵 <code>grid</code> ，表示一个网格。另给你三个整数&nbsp;<code>row</code>、<code>col</code> 和 <code>color</code> 。网格中的每个值表示该位置处的网格块的颜色。</p>

<p>当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一<strong> 连通分量 </strong>。</p>

<p><strong>连通分量的边界</strong><strong> </strong>是指连通分量中的所有与不在分量中的网格块相邻（四个方向上）的所有网格块，或者在网格的边界上（第一行/列或最后一行/列）的所有网格块。</p>

<p>请你使用指定颜色&nbsp;<code>color</code> 为所有包含网格块&nbsp;<code>grid[row][col]</code> 的 <strong>连通分量的边界</strong> 进行着色，并返回最终的网格&nbsp;<code>grid</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
<strong>输出：</strong>[[3,3],[3,2]]</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
<strong>输出：</strong>[[1,3,3],[2,3,3]]</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
<strong>输出：</strong>[[2,2,2],[2,1,2],[2,2,2]]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j], color &lt;= 1000</code></li>
	<li><code>0 &lt;= row &lt; m</code></li>
	<li><code>0 &lt;= col &lt; n</code></li>
</ul>

<p>&nbsp;</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/coloring-a-border/solution/coloring-a-border-by-ikaruga-dznk/)

### 答题
``` C++
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int old = grid[row][col];
        if (old == color) return grid;
        dfs(grid, row, col, old);

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                grid[i][j] = (grid[i][j] == -2) ? color : grid[i][j];
                grid[i][j] = (grid[i][j] == -1) ? old : grid[i][j];
            }
        }
        return grid;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int old) {
        grid[row][col] = -2;
        int flag = 0;
        for (auto& d : dd) {
            int r = row + d[0];
            int c = col + d[1];
            if (r < 0 || r >= grid.size()) continue;
            if (c < 0 || c >= grid[0].size()) continue;
            flag += (grid[r][c] == old || grid[r][c] < 0);
            if (grid[r][c] != old) continue;
            dfs(grid, r, c, old);
        }
        grid[row][col] = (flag == 4) ? -1 : -2;
    }

private:
    vector<vector<int>> dd = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
```




