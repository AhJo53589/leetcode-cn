# `（简单）` [5776.determine-whether-matrix-can-be-obtained-by-rotation 判断矩阵经轮转后是否一致](https://leetcode-cn.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)

[contest](https://leetcode-cn.com/contest/weekly-contest-244/problems/determine-whether-matrix-can-be-obtained-by-rotation/)

### 题目描述
<div class="notranslate"><p>给你两个大小为 <code>n x n</code> 的二进制矩阵 <code>mat</code> 和 <code>target</code> 。现<strong> 以 90 度顺时针轮转 </strong>矩阵 <code>mat</code> 中的元素 <strong>若干次</strong> ，如果能够使 <code>mat</code> 与&nbsp;<code>target</code> 一致，返回 <code>true</code> ；否则，返回<em> </em><code>false</code><em> 。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 301px; height: 121px;" src="https://assets.leetcode.com/uploads/2021/05/20/grid3.png" alt="">
<pre><strong>输入：</strong>mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
<strong>输出：</strong>true
<strong>解释：</strong>顺时针轮转 90 度一次可以使 mat 和 target 一致。
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 301px; height: 121px;" src="https://assets.leetcode.com/uploads/2021/05/20/grid4.png" alt="">
<pre><strong>输入：</strong>mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
<strong>输出：</strong>false
<strong>解释：</strong>无法通过轮转矩阵中的元素使 equal 与 target 一致。
</pre>

<p><strong>示例 3：</strong></p>
<img style="width: 661px; height: 184px;" src="https://assets.leetcode.com/uploads/2021/05/26/grid4.png" alt="">
<pre><strong>输入：</strong>mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
<strong>输出：</strong>true
<strong>解释：</strong>顺时针轮转 90 度两次可以使 mat 和 target 一致。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == mat.length == target.length</code></li>
	<li><code>n == mat[i].length == target[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>mat[i][j]</code> 和 <code>target[i][j]</code> 不是 <code>0</code> 就是 <code>1</code></li>
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
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) return true;
        for (int i = 0; i < 3; i++) {
            rotate(mat);
            if (mat == target) return true;
        }
        return false;
    }

    void rotate(vector<vector<int>>& matrix) {
        int temp;
        int end = matrix.size() - 1;
        float mid_line = end / 2;
        for (int i = 0; i <= end; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i <= end; i++) {
            for (int j = 0; j <= mid_line; j++) {
                swap(matrix[i][j], matrix[i][end - j]);
            }
        }
    }
};
```




