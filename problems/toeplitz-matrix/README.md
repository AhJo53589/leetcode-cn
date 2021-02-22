# `（简单）` [766.toeplitz-matrix 托普利茨矩阵](https://leetcode-cn.com/problems/toeplitz-matrix/)

### 题目描述
<p>给你一个 <code>m x n</code> 的矩阵 <code>matrix</code> 。如果这个矩阵是托普利茨矩阵，返回 <code>true</code> ；否则，返回<em> </em><code>false</code><em> 。</em></p>

<p>如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是<em> </em><strong>托普利茨矩阵</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 322px; height: 242px;" src="https://assets.leetcode.com/uploads/2020/11/04/ex1.jpg" alt="">
<pre><strong>输入：</strong>matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
<strong>输出：</strong>true
<strong>解释：</strong>
在上述矩阵中, 其对角线为: 
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。 
各条对角线上的所有元素均相同, 因此答案是 True 。
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 162px; height: 162px;" src="https://assets.leetcode.com/uploads/2020/11/04/ex2.jpg" alt="">
<pre><strong>输入：</strong>matrix = [[1,2],[2,2]]
<strong>输出：</strong>false
<strong>解释：</strong>
对角线 "[1, 2]" 上的元素不同。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 20</code></li>
	<li><code>0 &lt;= matrix[i][j] &lt;= 99</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>如果矩阵存储在磁盘上，并且内存有限，以至于一次最多只能将矩阵的一行加载到内存中，该怎么办？</li>
	<li>如果矩阵太大，以至于一次只能将不完整的一行加载到内存中，该怎么办？</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) return false;
            }
        }
        return true;
    }
};
```




