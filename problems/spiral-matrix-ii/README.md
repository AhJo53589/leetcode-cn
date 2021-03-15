# `（中等）` [59.spiral-matrix-ii 螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/)

### 题目描述
<p>给你一个正整数&nbsp;<code>n</code> ，生成一个包含 <code>1</code> 到&nbsp;<code>n<sup>2</sup></code>&nbsp;所有元素，且元素按顺时针顺序螺旋排列的&nbsp;<code>n x n</code> 正方形矩阵 <code>matrix</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 242px; height: 242px;" src="https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg" alt="">
<pre><strong>输入：</strong>n = 3
<strong>输出：</strong>[[1,2,3],[8,9,4],[7,6,5]]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 1
<strong>输出：</strong>[[1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        vector<int> sz = { n, n - 1 };
        vector<vector<int>> dd = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        
        for (int val = 1, d = 0, x = 0, y = -1; val <= n * n; d = (d + 1) % dd.size()) {
            for (int i = 0; i < sz[d % 2]; i++) {
                x += dd[d][0];
                y += dd[d][1];
                ans[x][y] = val++;
            }
            sz[d % 2]--;
        }

        return ans;
    }
};
```




