# `（中等）` [1000081.YesdPw 主题空间](https://leetcode-cn.com/problems/YesdPw/)

[contest](https://leetcode-cn.com/contest/lc-vscode/problems/YesdPw/)

### 题目描述
<div class="question-content default-content"><p>「以扣会友」线下活动所在场地由若干主题空间与走廊组成，场地的地图记作由一维字符串型数组 <code>grid</code>，字符串中仅包含 <code>"0"～"5"</code> 这 6 个字符。地图上每一个字符代表面积为 1 的区域，其中 <code>"0"</code> 表示走廊，其他字符表示主题空间。相同且连续（连续指上、下、左、右四个方向连接）的字符组成同一个主题空间。</p>
<p>假如整个 <code>grid</code> 区域的外侧均为走廊。请问，不与走廊直接相邻的主题空间的最大面积是多少？如果不存在这样的空间请返回 <code>0</code>。</p>
<p><strong>示例 1:</strong></p>
<blockquote>
<p>输入：<code>grid = ["110","231","221"]</code></p>
<p>输出：<code>1</code></p>
<p>解释：4 个主题空间中，只有 1 个不与走廊相邻，面积为 1。<br>
<img src="https://pic.leetcode-cn.com/1613708145-rscctN-image.png" alt="image.png"></p>
</blockquote>
<p><strong>示例 2:</strong></p>
<blockquote>
<p>输入：<code>grid = ["11111100000","21243101111","21224101221","11111101111"]</code></p>
<p>输出：<code>3</code></p>
<p>解释：8 个主题空间中，有 5 个不与走廊相邻，面积分别为 3、1、1、1、2，最大面积为 3。<br>
<img src="https://pic.leetcode-cn.com/1613707985-KJyiXJ-image.png" alt="image.png"></p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= grid.length &lt;= 500</code></li>
<li><code>1 &lt;= grid[i].length &lt;= 500</code></li>
<li><code>grid[i][j]</code> 仅可能是 <code>"0"～"5"</code></li>
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
    int largestArea(vector<string>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '0' || grid[i][j] == '-') continue;
                int cnt = 0;
                bool flag = true;
                dfs(grid, i, j, cnt, flag);
                if (!flag) continue;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }

    bool check(vector<string>& grid, int i, int j) {
        if (i == 0 || i == grid.size() - 1) return false;
        if (j == 0 || j == grid[0].size() - 1) return false;
        for (auto d : dd) {
            int dx = i + d[0];
            int dy = j + d[1];
            if (grid[dx][dy] == '0') return false;
        }
        return true;
    }

    void dfs(vector<string>& grid, int i, int j, int& cnt, bool& flag) {
        flag &= check(grid, i, j);
        char val = grid[i][j];
        grid[i][j] = '-';
        cnt++;
        for (auto d : dd) {
            int dx = i + d[0];
            int dy = j + d[1];
            if (dx < 0 || dx == grid.size()) continue;
            if (dy < 0 || dy == grid[0].size()) continue;
            if (grid[dx][dy] != val) continue;
            dfs(grid, dx, dy, cnt, flag);
        }
    }

private:
    vector<vector<int>> dd = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
};
```




