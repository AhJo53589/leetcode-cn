# `（简单）` [1572.matrix-diagonal-sum 矩阵对角线元素的和](https://leetcode-cn.com/problems/matrix-diagonal-sum/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-34/problems/matrix-diagonal-sum/)

### 题目描述
<p>给你一个正方形矩阵 <code>mat</code>，请你返回矩阵对角线元素的和。</p>

<p>请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp; 1：</strong></p>

<p><img style="height:174px; width:336px" src="https://assets.leetcode.com/uploads/2020/08/14/sample_1911.png" alt=""></p>

<pre><strong>输入：</strong>mat = [[<strong>1</strong>,2,<strong>3</strong>],
&nbsp;           [4,<strong>5</strong>,6],
&nbsp;           [<strong>7</strong>,8,<strong>9</strong>]]
<strong>输出：</strong>25
<strong>解释：</strong>对角线的和为：1 + 5 + 9 + 3 + 7 = 25
请注意，元素 mat[1][1] = 5 只会被计算一次。
</pre>

<p><strong>示例&nbsp; 2：</strong></p>

<pre><strong>输入：</strong>mat = [[<strong>1</strong>,1,1,<strong>1</strong>],
&nbsp;           [1,<strong>1</strong>,<strong>1</strong>,1],
&nbsp;           [1,<strong>1</strong>,<strong>1</strong>,1],
&nbsp;           [<strong>1</strong>,1,1,<strong>1</strong>]]
<strong>输出：</strong>8
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>mat = [[<strong>5</strong>]]
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == mat.length == mat[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 100</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (i == j || i + j == mat.size() - 1) {
                    ans += mat[i][j];
                }
            }
        }
        return ans;
    }
};
```




