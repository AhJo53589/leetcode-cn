# `（中等）` [1914.cyclically-rotating-a-grid 循环轮转矩阵](https://leetcode-cn.com/problems/cyclically-rotating-a-grid/)

[contest](https://leetcode-cn.com/contest/weekly-contest-247/problems/cyclically-rotating-a-grid/)

### 题目描述
<div class="notranslate"><p>给你一个大小为 <code>m x n</code> 的整数矩阵 <code>grid</code>​​​ ，其中 <code>m</code> 和 <code>n</code> 都是 <strong>偶数</strong> ；另给你一个整数 <code>k</code> 。</p>

<p>矩阵由若干层组成，如下图所示，每种颜色代表一层：</p>

<p><img style="width: 231px; height: 258px;" src="https://assets.leetcode.com/uploads/2021/06/10/ringofgrid.png" alt=""></p>

<p>矩阵的循环轮转是通过分别循环轮转矩阵中的每一层完成的。在对某一层进行一次循环旋转操作时，层中的每一个元素将会取代其&nbsp;<strong>逆时针 </strong>方向的相邻元素。轮转示例如下：</p>
<img style="width: 500px; height: 268px;" src="https://assets.leetcode.com/uploads/2021/06/22/explanation_grid.jpg" alt="">
<p>返回执行 <code>k</code> 次循环轮转操作后的矩阵。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 421px; height: 191px;" src="https://assets.leetcode.com/uploads/2021/06/19/rod2.png" alt="">
<pre><strong>输入：</strong>grid = [[40,10],[30,20]], k = 1
<strong>输出：</strong>[[10,20],[40,30]]
<strong>解释：</strong>上图展示了矩阵在执行循环轮转操作时每一步的状态。</pre>

<p><strong>示例 2：</strong></p>
<strong><img style="width: 231px; height: 262px;" src="https://assets.leetcode.com/uploads/2021/06/10/ringofgrid5.png" alt=""></strong> <strong><img style="width: 231px; height: 262px;" src="https://assets.leetcode.com/uploads/2021/06/10/ringofgrid6.png" alt=""></strong> <strong><img style="width: 231px; height: 262px;" src="https://assets.leetcode.com/uploads/2021/06/10/ringofgrid7.png" alt=""></strong>

<pre><strong>输入：</strong>grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
<strong>输出：</strong>[[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
<strong>解释：</strong>上图展示了矩阵在执行循环轮转操作时每一步的状态。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 50</code></li>
	<li><code>m</code> 和 <code>n</code> 都是 <strong>偶数</strong></li>
	<li><code>1 &lt;= grid[i][j] &lt;=<sup> </sup>5000</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
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
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<vector<pair<int, int>>> lines;
        transToLines(grid, lines);
        for (auto& line : lines) {
            rotate(line.begin(), line.begin() + k % line.size(), line.end());
        }
        return transToGrid(grid, lines);
    }

    void transToLines(vector<vector<int>>& grid, vector<vector<pair<int, int>>>& lines) {
        for (int lv = 0; lv < grid.size() / 2 && lv < grid[0].size() / 2; lv++) {
            vector<pair<int, int>> line;
            int i = lv;
            int j = lv;
            int d = 0;
            while (true) {
                line.emplace_back(i, j);
                d += (i + dd[d][0] == grid.size() - lv || i + dd[d][0] < lv
                    || j + dd[d][1] == grid[0].size() - lv || j + dd[d][1] < lv);
                if (d == dd.size()) break;
                i += dd[d][0];
                j += dd[d][1];
            }
            line.pop_back();
            lines.emplace_back(line);
        }
    }

    vector<vector<int>> transToGrid(vector<vector<int>>& grid, vector<vector<pair<int, int>>>& lines) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        for (int lv = 0; lv < grid.size() / 2 && lv < grid[0].size() / 2; lv++) {
            int i = lv;
            int j = lv;
            int d = 0;
            for (auto [di, dj] : lines[lv]) {
                ans[i][j] = grid[di][dj];
                d += (i + dd[d][0] == grid.size() - lv || i + dd[d][0] < lv
                    || j + dd[d][1] == grid[0].size() - lv || j + dd[d][1] < lv);
                if (d == dd.size()) break;
                i += dd[d][0];
                j += dd[d][1];
            }
        }
        return ans;
    }

private:
    vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
};
```




