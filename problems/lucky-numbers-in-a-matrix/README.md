# `（简单）` [5356.lucky-numbers-in-a-matrix 矩阵中的幸运数](https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix/)

[contest](https://leetcode-cn.com/contest/weekly-contest-180/problems/lucky-numbers-in-a-matrix/)

### 题目描述
<p>给你一个 <code>m * n</code> 的矩阵，矩阵中的数字 <strong>各不相同</strong> 。请你按 <strong>任意</strong> 顺序返回矩阵中的所有幸运数。</p>

<p>幸运数是指矩阵中满足同时下列两个条件的元素：</p>

<ul>
	<li>在同一行的所有元素中最小</li>
	<li>在同一列的所有元素中最大</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>matrix = [[3,7,8],[9,11,13],[15,16,17]]
<strong>输出：</strong>[15]
<strong>解释：</strong>15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
<strong>输出：</strong>[12]
<strong>解释：</strong>12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>matrix = [[7,8],[1,2]]
<strong>输出：</strong>[7]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= n, m &lt;= 50</code></li>
	<li><code>1 &lt;=&nbsp;matrix[i][j]&nbsp;&lt;= 10^5</code></li>
	<li>矩阵中的所有元素都是不同的</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            int mnj = 0;
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] > matrix[i][mnj]) continue;
                mnj = j;
            }
            int mxi = 0;
            for (int i = 1; i < matrix.size(); i++)
            {
                if (matrix[i][mnj] < matrix[mxi][mnj]) continue;
                mxi = i;
            }
            if (mxi == i) return { matrix[mxi][mnj] };
        }
        return {};
    }
};
```




