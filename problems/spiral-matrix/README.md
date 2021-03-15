# `（中等）` [54.spiral-matrix 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/)

### 题目描述
<p>给你一个 <code>m</code> 行 <code>n</code> 列的矩阵&nbsp;<code>matrix</code> ，请按照 <strong>顺时针螺旋顺序</strong> ，返回矩阵中的所有元素。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 242px; height: 242px;" src="https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg" alt="">
<pre><strong>输入：</strong>matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>[1,2,3,6,9,8,7,4,5]
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 322px; height: 242px;" src="https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg" alt="">
<pre><strong>输入：</strong>matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
<strong>输出：</strong>[1,2,3,4,8,12,11,10,9,5,6,7]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10</code></li>
	<li><code>-100 &lt;= matrix[i][j] &lt;= 100</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/spiral-matrix/solution/spiral-matrix-by-ikaruga-o8rt/)

### 答题
``` C++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> sz = { (int)matrix[0].size(), (int)matrix.size() };
        vector<int> ans(sz[0] * sz[1]);
        sz[1]--;

        vector<vector<int>> dd = { { 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 } };
        for (int idx = 0, d = 0, x = 0, y = -1; idx != ans.size(); d = (d + 1) % dd.size()) {
            for (int i = 0; i < sz[d % 2]; i++) {
                x += dd[d][0];
                y += dd[d][1];
                ans[idx++] = matrix[x][y];
            }
            sz[d % 2]--;
        }

        return ans;
    }
};
```




