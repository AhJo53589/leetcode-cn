# `（中等）` [5501.minimum-number-of-days-to-disconnect-island 使陆地分离的最少天数](https://leetcode-cn.com/problems/minimum-number-of-days-to-disconnect-island/)

[contest](https://leetcode-cn.com/contest/weekly-contest-204/problems/minimum-number-of-days-to-disconnect-island/)

### 题目描述
<p>给你一个由若干 <code>0</code> 和 <code>1</code> 组成的二维网格 <code>grid</code> ，其中 <code>0</code> 表示水，而 <code>1</code> 表示陆地。岛屿由水平方向或竖直方向上相邻的 <code>1</code> （陆地）连接形成。</p>

<p>如果 <strong>恰好只有一座岛屿 </strong>，则认为陆地是 <strong>连通的</strong> ；否则，陆地就是 <strong>分离的</strong> 。</p>

<p>一天内，可以将任何单个陆地单元（<code>1</code>）更改为水单元（<code>0</code>）。</p>

<p>返回使陆地分离的最少天数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="height: 139px; width: 498px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/30/1926_island.png" alt=""></strong></p>

<pre><strong>输入：</strong>grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
<strong>输出：</strong>2
<strong>解释：</strong>至少需要 2 天才能得到分离的陆地。
将陆地 grid[1][1] 和 grid[0][2] 更改为水，得到两个分离的岛屿。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>grid = [[1,1]]
<strong>输出：</strong>2
<strong>解释：</strong>如果网格中都是水，也认为是分离的 ([[1,1]] -> [[0,0]])，0 岛屿。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>grid = [[1,0,1,0]]
<strong>输出：</strong>0
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>grid = [[1,1,0,1,1],
&nbsp;            [1,1,1,1,1],
&nbsp;            [1,1,0,1,1],
&nbsp;            [1,1,0,1,1]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>grid = [[1,1,0,1,1],
&nbsp;            [1,1,1,1,1],
&nbsp;            [1,1,0,1,1],
&nbsp;            [1,1,1,1,1]]
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= grid.length, grid[i].length <= 30</code></li>
	<li><code>grid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-number-of-days-to-disconnect-island/solution/minimum-number-of-days-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        vi = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != 1) continue;

                vector<vector<int>> temp = { {i,j} };
                for (int k = 0; k < dd.size(); k++) {
                    auto d = dd[k];
                    int dx = d[0] + i;
                    int dy = d[1] + j;
                    if (dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size()) continue;
                    if (grid[dx][dy] != 1) continue;
                    temp.push_back({ dx, dy });
                }
                if (temp.size() == 2) {
                    water.push_back(temp.back());
                }
                if (temp.size() == 3) {
                    water.push_back(temp.front());
                }
            }
        }

        if (check(grid)) return 0;
        for (auto& s : water) {
            grid[s[0]][s[1]] = 0;
            if (check(grid)) return 1;
            grid[s[0]][s[1]] = 1;

        }
        return 2;
    }

    bool check(vector<vector<int>>& grid) {
        vi = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

        int land = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !vi[i][j]) {
                    land++;
                    dfs(grid, i, j);
                }
            }
        }
        return land != 1;
    }

    void dfs(vector<vector<int>>& grid, int x, int y) {
        vi[x][y] = true;
        for (auto d : dd) {
            int dx = d[0] + x;
            int dy = d[1] + y;
            if (dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size()) continue;
            if (grid[dx][dy] == 0) continue;
            if (vi[dx][dy]) continue;
            dfs(grid, dx, dy);
        }
    }

private:
    vector<vector<int>> dd = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    vector<vector<bool>> vi;
    vector<vector<int>> water;
};
```




