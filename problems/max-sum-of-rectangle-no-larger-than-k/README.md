# `（困难）` [363.max-sum-of-rectangle-no-larger-than-k 矩形区域不超过 K 的最大数值和](https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/)

### 题目描述
<p>给你一个 <code>m x n</code> 的矩阵 <code>matrix</code> 和一个整数 <code>k</code> ，找出并返回矩阵内部矩形区域的不超过 <code>k</code> 的最大数值和。</p>

<p>题目数据保证总会存在一个数值和不超过 <code>k</code> 的矩形区域。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 255px; height: 176px;" src="https://assets.leetcode.com/uploads/2021/03/18/sum-grid.jpg" alt="">
<pre><strong>输入：</strong>matrix = [[1,0,1],[0,-2,3]], k = 2
<strong>输出：</strong>2
<strong>解释：</strong>蓝色边框圈出来的矩形区域&nbsp;<code>[[0, 1], [-2, 3]]</code>&nbsp;的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>matrix = [[2,2,-1]], k = 3
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>-100 &lt;= matrix[i][j] &lt;= 100</code></li>
	<li><code>-10<sup>5</sup> &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果行数远大于列数，该如何设计解决方案？</p>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int ans = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) { // 枚举上边界
            vector<int> sum(n);
            for (int j = i; j < m; ++j) { // 枚举下边界
                for (int c = 0; c < n; ++c) {
                    sum[c] += matrix[j][c]; // 更新每列的元素和
                }
                set<int> sumSet{0};
                int s = 0;
                for (int v : sum) {
                    s += v;
                    auto lb = sumSet.lower_bound(s - k);
                    if (lb != sumSet.end()) {
                        ans = max(ans, s - *lb);
                    }
                    sumSet.insert(s);
                }
            }
        }
        return ans;
    }
};
```




