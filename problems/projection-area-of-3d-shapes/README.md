# `（简单）` [883.projection-area-of-3d-shapes 三维形体投影面积](https://leetcode.cn/problems/projection-area-of-3d-shapes/)

### 题目描述
<p>在&nbsp;<code>n x n</code>&nbsp;的网格&nbsp;<code>grid</code>&nbsp;中，我们放置了一些与 x，y，z 三轴对齐的&nbsp;<code>1 x 1 x 1</code>&nbsp;立方体。</p>

<p>每个值&nbsp;<code>v = grid[i][j]</code>&nbsp;表示 <code>v</code>&nbsp;个正方体叠放在单元格&nbsp;<code>(i, j)</code>&nbsp;上。</p>

<p>现在，我们查看这些立方体在 <code>xy</code>&nbsp;、<code>yz</code>&nbsp;和 <code>zx</code>&nbsp;平面上的<em>投影</em>。</p>

<p><strong>投影</strong>&nbsp;就像影子，将 <strong>三维</strong> 形体映射到一个 <strong>二维</strong> 平面上。从顶部、前面和侧面看立方体时，我们会看到“影子”。</p>

<p>返回 <em>所有三个投影的总面积</em> 。</p>

<p>&nbsp;</p>

<ul>
</ul>

<ul>
</ul>

<ul>
</ul>

<ul>
</ul>

<p><strong>示例 1：</strong></p>

<p><img style="height: 214px; width: 800px;" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/02/shadow.png" alt=""></p>

<pre><strong>输入：</strong>[[1,2],[3,4]]
<strong>输出：</strong>17
<strong>解释：</strong>这里有该形体在三个轴对齐平面上的三个投影(“阴影部分”)。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入：</strong>grid = [[2]]
<strong>输出：</strong>5
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>[[1,0],[0,2]]
<strong>输出：</strong>8
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 50</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int x = 0;
        int y = 0;
        int z = 0;
        for (int j = 0; j < grid.size(); j++) {
            int y_max = 0;
            int z_max = 0;
            for (int i = 0; i < grid.size(); i++) {
                x += (grid[i][j] > 0);
                y_max = max(y_max, grid[i][j]);
                z_max = max(z_max, grid[j][i]);
            }
            y += y_max;
            z += z_max;
        }
        return x + y + z;
    }
};
```




