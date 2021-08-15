# `（中等）` [576.out-of-boundary-paths 出界的路径数](https://leetcode-cn.com/problems/out-of-boundary-paths/)

### 题目描述
<div class="notranslate"><p>给你一个大小为 <code>m x n</code> 的网格和一个球。球的起始坐标为 <code>[startRow, startColumn]</code> 。你可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。你 <strong>最多</strong> 可以移动 <code>maxMove</code> 次球。</p>

<p>给你五个整数 <code>m</code>、<code>n</code>、<code>maxMove</code>、<code>startRow</code> 以及 <code>startColumn</code> ，找出并返回可以将球移出边界的路径数量。因为答案可能非常大，返回对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 后的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 500px; height: 296px;" src="https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_1.png" alt="">
<pre><strong>输入：</strong>m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
<strong>输出：</strong>6
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 500px; height: 293px;" src="https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_2.png" alt="">
<pre><strong>输入：</strong>m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
<strong>输出：</strong>12
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>0 &lt;= maxMove &lt;= 50</code></li>
	<li><code>0 &lt;= startRow &lt; m</code></li>
	<li><code>0 &lt;= startColumn &lt; n</code></li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;
        const int mod = 1e9 + 7;

        vector<vector<int>> grid(m, vector<int>(n, 0));
        grid[startRow][startColumn] = 1;

        vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        while(maxMove-- > 0) {
            vector<vector<int>> grid_new(m, vector<int>(n, 0));
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    for (auto d : dd) {
                        int dx = i + d[0];
                        int dy = j + d[1];
                        if (dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size()) {
                            ans += grid[i][j];
                            ans %= mod;
                            continue;
                        }
                        grid_new[dx][dy] += grid[i][j];
                        grid_new[dx][dy] %= mod;
                    }
                }
            }
            swap(grid, grid_new);
        }

        return ans;
    }
};
```




