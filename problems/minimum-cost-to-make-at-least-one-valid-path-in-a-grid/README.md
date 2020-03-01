# `（困难）` [5347.minimum-cost-to-make-at-least-one-valid-path-in-a-grid 使网格图至少有一条有效路径的最小代价](https://leetcode-cn.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)

[contest](https://leetcode-cn.com/contest/weekly-contest-178/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)

### 题目描述
<p>给你一个 m x n 的网格图&nbsp;<code>grid</code>&nbsp;。&nbsp;<code>grid</code>&nbsp;中每个格子都有一个数字，对应着从该格子出发下一步走的方向。&nbsp;<code>grid[i][j]</code>&nbsp;中的数字可能为以下几种情况：</p>

<ul>
	<li><strong>1</strong>&nbsp;，下一步往右走，也就是你会从 <code>grid[i][j]</code>&nbsp;走到 <code>grid[i][j + 1]</code></li>
	<li><strong>2</strong>&nbsp;，下一步往左走，也就是你会从 <code>grid[i][j]</code>&nbsp;走到 <code>grid[i][j - 1]</code></li>
	<li><strong>3</strong>&nbsp;，下一步往下走，也就是你会从 <code>grid[i][j]</code>&nbsp;走到 <code>grid[i + 1][j]</code></li>
	<li><strong>4</strong>&nbsp;，下一步往上走，也就是你会从 <code>grid[i][j]</code>&nbsp;走到 <code>grid[i - 1][j]</code></li>
</ul>

<p>注意网格图中可能会有&nbsp;<strong>无效数字</strong>&nbsp;，因为它们可能指向&nbsp;<code>grid</code>&nbsp;以外的区域。</p>

<p>一开始，你会从最左上角的格子&nbsp;<code>(0,0)</code>&nbsp;出发。我们定义一条&nbsp;<strong>有效路径</strong>&nbsp;为从格子&nbsp;<code>(0,0)</code>&nbsp;出发，每一步都顺着数字对应方向走，最终在最右下角的格子&nbsp;<code>(m - 1, n - 1)</code>&nbsp;结束的路径。有效路径&nbsp;<strong>不需要是最短路径</strong>&nbsp;。</p>

<p>你可以花费&nbsp;<code>cost = 1</code>&nbsp;的代价修改一个格子中的数字，但每个格子中的数字&nbsp;<strong>只能修改一次</strong>&nbsp;。</p>

<p>请你返回让网格图至少有一条有效路径的最小代价。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/29/grid1.png" style="height: 528px; width: 542px;"></p>

<pre><strong>输入：</strong>grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
<strong>输出：</strong>3
<strong>解释：</strong>你将从点 (0, 0) 出发。
到达 (3, 3) 的路径为： (0, 0) --&gt; (0, 1) --&gt; (0, 2) --&gt; (0, 3) 花费代价 cost = 1 使方向向下 --&gt; (1, 3) --&gt; (1, 2) --&gt; (1, 1) --&gt; (1, 0) 花费代价 cost = 1 使方向向下 --&gt; (2, 0) --&gt; (2, 1) --&gt; (2, 2) --&gt; (2, 3) 花费代价 cost = 1 使方向向下 --&gt; (3, 3)
总花费为 cost = 3.
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/29/grid2.png" style="height: 408px; width: 419px;"></p>

<pre><strong>输入：</strong>grid = [[1,1,3],[3,2,2],[1,1,4]]
<strong>输出：</strong>0
<strong>解释：</strong>不修改任何数字你就可以从 (0, 0) 到达 (2, 2) 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/29/grid3.png" style="height: 302px; width: 314px;"></p>

<pre><strong>输入：</strong>grid = [[1,2],[4,3]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>grid = [[2,2,2],[2,2,2]]
<strong>输出：</strong>3
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>grid = [[4]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
</ul>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/solution/5347-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int minCost(vector<vector<int>>& grid)
    {
        vector<vector<int>> dd = { {}, {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        vector<vector<bool>> vi(grid.size(), vector<bool>(grid[0].size(), false));
        queue<vector<int>> cq;
        queue<vector<int>> nq;
        int ans = 0;
        cq.push({ 0, 0 });

        while (!cq.empty() || !nq.empty())
        {
            while (!cq.empty())
            {
                auto q = cq.front();
                cq.pop();
                int x = q[0];
                int y = q[1];
                if ((x < 0 || x >= grid.size()) || (y < 0 || y >= grid[0].size())) continue;
                if (vi[x][y]) continue;
                if (x == grid.size() - 1 && y == grid[0].size() - 1) return ans;
                vi[x][y] = true;

                for (int i = 1; i < dd.size(); i++)
                {
                    int dx = x + dd[i][0];
                    int dy = y + dd[i][1];
                    auto& sq = (i == grid[x][y]) ? cq : nq;
                    sq.push({ dx, dy });
                }
            }
            swap(cq, nq);
            ans++;
        }
        return ans;
    }
};
```




