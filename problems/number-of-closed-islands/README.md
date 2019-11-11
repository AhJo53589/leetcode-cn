# `（中等）` [5257.number-of-closed-islands 统计封闭岛屿的数目](https://leetcode-cn.com/problems/number-of-closed-islands/)

[contest](https://leetcode-cn.com/contest/weekly-contest-162/problems/number-of-closed-islands/)

### 题目描述
<p>有一个二维矩阵 <code>grid</code>&nbsp;，每个位置要么是陆地（记号为&nbsp;<code>0</code> ）要么是水域（记号为&nbsp;<code>1</code> ）。</p>

<p>我们从一块陆地出发，每次可以往上下左右&nbsp;4 个方向相邻区域走，能走到的所有陆地区域，我们将其称为一座「<strong>岛屿</strong>」。</p>

<p>如果一座岛屿&nbsp;<strong>完全</strong>&nbsp;由水域包围，即陆地边缘上下左右所有相邻区域都是水域，那么我们将其称为 「<strong>封闭岛屿</strong>」。</p>

<p>请返回封闭岛屿的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/07/sample_3_1610.png"></p>

<pre><strong>输入：</strong>grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
<strong>输出：</strong>2
<strong>解释：</strong>
灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/07/sample_4_1610.png"></p>

<pre><strong>输入：</strong>grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>grid = [[1,1,1,1,1,1,1],
&nbsp;            [1,0,0,0,0,0,1],
&nbsp;            [1,0,1,1,1,0,1],
&nbsp;            [1,0,1,0,1,0,1],
&nbsp;            [1,0,1,1,1,0,1],
&nbsp;            [1,0,0,0,0,0,1],
             [1,1,1,1,1,1,1]]
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length, grid[0].length &lt;= 100</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;=1</code></li>
</ul>

            

---
### 思路
```
```
[发布的题解](https://leetcode-cn.com/problems/number-of-closed-islands/solution/5257-by-ikaruga/)


### 答题
``` C++
void dfs(vector<vector<int>>& g, size_t x, size_t y, int &val)
{
    if (x >= g.size() || y >= g[0].size())
    {
        val = 0;
        return;
    }

    if (g[x][y] != 0) return;
    g[x][y] = -1;

    dfs(g, x + 1, y, val);
    dfs(g, x - 1, y, val);
    dfs(g, x, y + 1, val);
    dfs(g, x, y - 1, val);       
}

int closedIsland(vector<vector<int>>& grid)
{
    int ans = 0;
    for (size_t x = 0; x < grid.size(); x++)
    {
        for (size_t y = 0; y < grid[0].size(); y++)
        {
            if (grid[x][y] == 0)
            {
                int val = 1;
                dfs(grid, x, y, val);
                ans += val;
            }
        }
    }
    return ans;
}
```




