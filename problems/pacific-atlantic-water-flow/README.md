# `（中等）` [417.pacific-atlantic-water-flow 太平洋大西洋水流问题](https://leetcode.cn/problems/pacific-atlantic-water-flow/)

### 题目描述
<p>有一个 <code>m × n</code> 的矩形岛屿，与 <strong>太平洋</strong> 和 <strong>大西洋</strong> 相邻。&nbsp;<strong>“太平洋”&nbsp;</strong>处于大陆的左边界和上边界，而 <strong>“大西洋”</strong> 处于大陆的右边界和下边界。</p>

<p>这个岛被分割成一个由若干方形单元格组成的网格。给定一个 <code>m x n</code> 的整数矩阵&nbsp;<code>heights</code>&nbsp;，&nbsp;<code>heights[r][c]</code>&nbsp;表示坐标 <code>(r, c)</code> 上单元格 <strong>高于海平面的高度</strong> 。</p>

<p>岛上雨水较多，如果相邻单元格的高度 <strong>小于或等于</strong> 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。</p>

<p>返回 <em>网格坐标 <code>result</code>&nbsp;的 <strong>2D列表</strong> ，其中&nbsp;<code>result[i] = [r<sub>i</sub>, c<sub>i</sub>]</code>&nbsp;表示雨水可以从单元格 <code>(ri, ci)</code> 流向 <strong>太平洋和大西洋</strong></em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/06/08/waterflow-grid.jpg"></p>

<pre><strong>输入:</strong> heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
<strong>输出:</strong> [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> heights = [[2,1],[1,2]]
<strong>输出:</strong> [[0,0],[0,1],[1,0],[1,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == heights.length</code></li>
	<li><code>n == heights[r].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= heights[r][c] &lt;= 10<sup>5</sup></code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode.cn/problems/pacific-atlantic-water-flow/solution/by-ikaruga-adt0/)

### 答题
``` C++
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {      
        vector<vector<int>> dd = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = heights.size();
        int n = heights[0].size();
        const int Pacific = 0;
        const int Atlantic = 1;
        vector<vector<int>> vi(m, vector<int>(n, 0));

        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++) {
            push(que, vi, i, 0, Pacific);
            push(que, vi, i, n - 1, Atlantic);
        }
        for (int j = 0; j < n; j++) {
            push(que, vi, 0, j, Pacific);
            push(que, vi, m - 1, j, Atlantic);
        }

        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            
            for (auto& d : dd) {
                int dx = x + d[0];
                int dy = y + d[1];
                if (dx < 0 || dx >= m || dy < 0 || dy >= n) continue;
                if (heights[x][y] > heights[dx][dy]) continue;

                if (check(vi, x, y, Pacific) && !check(vi, dx, dy, Pacific)) {
                    push(que, vi, dx, dy, Pacific);
                }
                if (check(vi, x, y, Atlantic) && !check(vi, dx, dy, Atlantic)) {
                    push(que, vi, dx, dy, Atlantic);
                }
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vi[i][j] == 3) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    bool check(vector<vector<int>>& vi, int x, int y, int mask) {
        return (vi[x][y] & (1 << mask)) != 0;
    }

    void push(queue<pair<int, int>>& que, vector<vector<int>>& vi, int x, int y, int mask) {
        vi[x][y] |= (1 << mask);
        que.push({x, y});
    }
};
```




