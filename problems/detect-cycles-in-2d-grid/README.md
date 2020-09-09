# `（困难）` [1559.detect-cycles-in-2d-grid 二维网格图中探测环](https://leetcode-cn.com/problems/detect-cycles-in-2d-grid/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-33/problems/detect-cycles-in-2d-grid/)

### 题目描述
<p>给你一个二维字符网格数组&nbsp;<code>grid</code>&nbsp;，大小为&nbsp;<code>m x n</code>&nbsp;，你需要检查&nbsp;<code>grid</code>&nbsp;中是否存在 <strong>相同值</strong> 形成的环。</p>

<p>一个环是一条开始和结束于同一个格子的长度 <strong>大于等于 4</strong>&nbsp;的路径。对于一个给定的格子，你可以移动到它上、下、左、右四个方向相邻的格子之一，可以移动的前提是这两个格子有 <strong>相同的值&nbsp;</strong>。</p>

<p>同时，你也不能回到上一次移动时所在的格子。比方说，环&nbsp;&nbsp;<code>(1, 1) -> (1, 2) -> (1, 1)</code>&nbsp;是不合法的，因为从 <code>(1, 2)</code>&nbsp;移动到 <code>(1, 1)</code> 回到了上一次移动时的格子。</p>

<p>如果 <code>grid</code>&nbsp;中有相同值形成的环，请你返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="height: 152px; width: 231px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/22/1559e1.png" alt=""></strong></p>

<pre><strong>输入：</strong>grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
<strong>输出：</strong>true
<strong>解释：</strong>如下图所示，有 2 个用不同颜色标出来的环：
<img style="height: 163px; width: 225px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/22/1559e11.png" alt="">
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img style="height: 154px; width: 236px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/22/1559e2.png" alt=""></strong></p>

<pre><strong>输入：</strong>grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
<strong>输出：</strong>true
<strong>解释：</strong>如下图所示，只有高亮所示的一个合法环：
<img style="height: 157px; width: 229px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/22/1559e22.png" alt="">
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img style="height: 120px; width: 183px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/22/1559e3.png" alt=""></strong></p>

<pre><strong>输入：</strong>grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 <= m <= 500</code></li>
	<li><code>1 <= n <= 500</code></li>
	<li><code>grid</code>&nbsp;只包含小写英文字母。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/detect-cycles-in-2d-grid/solution/detect-cycles-in-2d-grid-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        g = grid;
        vi = vector<vector<bool>>(g.size(), vector<bool>(g[0].size(), false));

        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (g[i][j] == '.') continue;
                if (dfs(g[i][j], i, j, -1, -1)) return true;
            }
        }
        return false;
    }

    bool dfs(char c, int x, int y, int px, int py) {
        if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size()) return false;
        if (g[x][y] != c) return false;
        if (vi[x][y]) return true;
        vi[x][y] = true;
        for (auto d : dd) {
            int dx = x + d[0];
            int dy = y + d[1];
            if (dx == px && dy == py) continue;
            if (dfs(c, dx, dy, x, y)) return true;
        }
        vi[x][y] = false;
        g[x][y] = '.';
        return false;
    }

private:
    vector<vector<char>> g;
    vector<vector<bool>> vi;
    vector<vector<int>> dd = { {0,1}, {0,-1}, {1,0}, {-1,0} };
};
```




