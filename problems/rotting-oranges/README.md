# `（简单）` [994.rotting-oranges 腐烂的橘子](https://leetcode-cn.com/problems/rotting-oranges/)

### 题目描述
<p>在给定的网格中，每个单元格可以有以下三个值之一：</p>

<ul>
	<li>值&nbsp;<code>0</code>&nbsp;代表空单元格；</li>
	<li>值&nbsp;<code>1</code>&nbsp;代表新鲜橘子；</li>
	<li>值&nbsp;<code>2</code>&nbsp;代表腐烂的橘子。</li>
</ul>

<p>每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。</p>

<p>返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回&nbsp;<code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="height: 150px; width: 712px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/16/oranges.png" alt=""></strong></p>

<pre><strong>输入：</strong>[[2,1,1],[1,1,0],[0,1,1]]
<strong>输出：</strong>4
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[[2,1,1],[0,1,1],[1,0,1]]
<strong>输出：</strong>-1
<strong>解释：</strong>左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>[[0,2]]
<strong>输出：</strong>0
<strong>解释：</strong>因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= grid.length <= 10</code></li>
	<li><code>1 <= grid[0].length <= 10</code></li>
	<li><code>grid[i][j]</code> 仅为&nbsp;<code>0</code>、<code>1</code>&nbsp;或&nbsp;<code>2</code></li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/rotting-oranges/solution/994-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

    }
};
```


### 其它
``` C++
int orangesRotting(vector<vector<int>>& grid)
{
    int cnt = 0;
    queue<vector<int>> que;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                que.push({ i, j });
            }
            else if (grid[i][j] == 1)
            {
                cnt++;
            }
        }
    }

    int ans = 0;
    vector<vector<int>> dd = { {0,1},{0,-1},{1,0},{-1,0} };
    while (!que.empty())
    {
        auto q = que.front();
        que.pop();

        for (auto d : dd)
        {
            int dx = q[0] + d[0];
            int dy = q[1] + d[1];
            if (dx < 0 || dx >= grid.size()) continue;
            if (dy < 0 || dy >= grid[0].size()) continue;
            if (grid[dx][dy] != 1) continue;
            grid[dx][dy] = grid[q[0]][q[1]] + 1;
            cnt--;
            que.push({ dx, dy });
            ans = grid[dx][dy] - 2;
        }
    }
    return (cnt == 0) ? ans : -1;
}
```


