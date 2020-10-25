# `（困难）` [5156.rank-transform-of-a-matrix 矩阵转换后的秩](https://leetcode-cn.com/problems/rank-transform-of-a-matrix/)

[contest](https://leetcode-cn.com/contest/weekly-contest-212/problems/rank-transform-of-a-matrix/)

### 题目描述
<p>给你一个&nbsp;<code>m x n</code>&nbsp;的矩阵 <code>matrix</code>&nbsp;，请你返回一个新的矩阵<em>&nbsp;</em><code>answer</code>&nbsp;，其中<em>&nbsp;</em><code>answer[row][col]</code>&nbsp;是&nbsp;<code>matrix[row][col]</code>&nbsp;的秩。</p>

<p>每个元素的&nbsp;<b>秩</b>&nbsp;是一个整数，表示这个元素相对于其他元素的大小关系，它按照如下规则计算：</p>

<ul>
	<li>如果一个元素是它所在行和列的最小值，那么它的 <strong>秩</strong>&nbsp;为 1。</li>
	<li>如果两个元素&nbsp;<code>p</code> 和&nbsp;<code>q</code>&nbsp;在 <strong>同一行</strong>&nbsp;或者 <strong>同一列</strong>&nbsp;，那么：
	<ul>
		<li>如果&nbsp;<code>p &lt; q</code> ，那么&nbsp;<code>rank(p) &lt; rank(q)</code></li>
		<li>如果&nbsp;<code>p == q</code>&nbsp;，那么&nbsp;<code>rank(p) == rank(q)</code></li>
		<li>如果&nbsp;<code>p &gt; q</code>&nbsp;，那么&nbsp;<code>rank(p) &gt; rank(q)</code></li>
	</ul>
	</li>
	<li><b>秩</b>&nbsp;需要越 <strong>小</strong>&nbsp;越好。</li>
</ul>

<p>题目保证按照上面规则&nbsp;<code>answer</code>&nbsp;数组是唯一的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 442px; height: 162px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/25/rank1.jpg" alt="">
<pre><b>输入：</b>matrix = [[1,2],[3,4]]
<b>输出：</b>[[1,2],[2,3]]
<strong>解释：</strong>
matrix[0][0] 的秩为 1 ，因为它是所在行和列的最小整数。
matrix[0][1] 的秩为 2 ，因为 matrix[0][1] &gt; matrix[0][0] 且 matrix[0][0] 的秩为 1 。
matrix[1][0] 的秩为 2 ，因为 matrix[1][0] &gt; matrix[0][0] 且 matrix[0][0] 的秩为 1 。
matrix[1][1] 的秩为 3 ，因为 matrix[1][1] &gt; matrix[0][1]， matrix[1][1] &gt; matrix[1][0] 且 matrix[0][1] 和 matrix[1][0] 的秩都为 2 。
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 442px; height: 162px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/25/rank2.jpg" alt="">
<pre><b>输入：</b>matrix = [[7,7],[7,7]]
<b>输出：</b>[[1,1],[1,1]]
</pre>

<p><strong>示例 3：</strong></p>
<img style="width: 601px; height: 322px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/25/rank3.jpg" alt="">
<pre><b>输入：</b>matrix = [[20,-21,14],[-19,4,19],[22,-47,24],[-19,4,19]]
<b>输出：</b>[[4,2,3],[1,3,4],[5,1,6],[1,3,4]]
</pre>

<p><strong>示例 4：</strong></p>
<img style="width: 601px; height: 242px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/25/rank4.jpg" alt="">
<pre><b>输入：</b>matrix = [[7,3,6],[1,4,5],[9,8,2]]
<b>输出：</b>[[5,1,4],[1,2,3],[6,3,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>-10<sup>9</sup> &lt;= matrix[row][col] &lt;= 10<sup>9</sup></code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {

    }
};
```




