# `（中等）` [1277.count-square-submatrices-with-all-ones 统计全为 1 的正方形子矩阵](https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/)

[contest](https://leetcode-cn.com/contest/weekly-contest-165/problems/count-square-submatrices-with-all-ones/)

### 题目描述
<p>给你一个&nbsp;<code>m * n</code>&nbsp;的矩阵，矩阵中的元素不是 <code>0</code> 就是 <code>1</code>，请你统计并返回其中完全由 <code>1</code> 组成的 <strong>正方形</strong> 子矩阵的个数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>matrix =
[
&nbsp; [0,1,1,1],
&nbsp; [1,1,1,1],
&nbsp; [0,1,1,1]
]
<strong>输出：</strong>15
<strong>解释：</strong> 
边长为 1 的正方形有 <strong>10</strong> 个。
边长为 2 的正方形有 <strong>4</strong> 个。
边长为 3 的正方形有 <strong>1</strong> 个。
正方形的总数 = 10 + 4 + 1 = <strong>15</strong>.
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
<strong>输出：</strong>7
<strong>解释：</strong>
边长为 1 的正方形有 <strong>6</strong> 个。 
边长为 2 的正方形有 <strong>1</strong> 个。
正方形的总数 = 6 + 1 = <strong>7</strong>.
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length&nbsp;&lt;= 300</code></li>
	<li><code>1 &lt;= arr[0].length&nbsp;&lt;= 300</code></li>
	<li><code>0 &lt;= arr[i][j] &lt;= 1</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
int countSquares(vector<vector<int>>& matrix)
{
    int ans = 0;

    int len = 1;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] != len) continue;
                int dx = i + len;
                int dy = j + len;
                if (dx > matrix.size() || dy > matrix[i].size()) continue;

				bool ok = true;
				for (size_t ii = i; ii < dx && ok; ii++)
				{
					if (matrix[ii][dy - 1] == 0)
					{
						ok = false;
					}
				}
				for (size_t ii = j; ii < dy && ok; ii++)
				{
					if (matrix[dx - 1][ii] == 0)
					{
						ok = false;
					}
				}
				if (ok)
				{
					flag = true;
					matrix[i][j]++;
					ans++;
				}
			}
        }
        len++;
    }
    return ans;
}
```




