# `（中等）` [5454.count-submatrices-with-all-ones 统计全 1 子矩形](https://leetcode-cn.com/problems/count-submatrices-with-all-ones/)

[contest](https://leetcode-cn.com/contest/weekly-contest-196/problems/count-submatrices-with-all-ones/)

### 题目描述
<p>给你一个只包含 0 和 1 的&nbsp;<code>rows * columns</code>&nbsp;矩阵&nbsp;<code>mat</code>&nbsp;，请你返回有多少个&nbsp;<strong>子矩形</strong>&nbsp;的元素全部都是 1 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>mat = [[1,0,1],
&nbsp;           [1,1,0],
&nbsp;           [1,1,0]]
<strong>输出：</strong>13
<strong>解释：
</strong>有 <strong>6</strong>&nbsp;个 1x1 的矩形。
有 <strong>2</strong> 个 1x2 的矩形。
有 <strong>3</strong> 个 2x1 的矩形。
有 <strong>1</strong> 个 2x2 的矩形。
有 <strong>1</strong> 个 3x1 的矩形。
矩形数目总共 = 6 + 2 + 3 + 1 + 1 = <strong>13</strong>&nbsp;。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>mat = [[0,1,1,0],
&nbsp;           [0,1,1,1],
&nbsp;           [1,1,1,0]]
<strong>输出：</strong>24
<strong>解释：</strong>
有 <strong>8</strong> 个 1x1 的子矩形。
有 <strong>5</strong> 个 1x2 的子矩形。
有 <strong>2</strong> 个 1x3 的子矩形。
有 <strong>4</strong> 个 2x1 的子矩形。
有 <strong>2</strong> 个 2x2 的子矩形。
有 <strong>2</strong> 个 3x1 的子矩形。
有 <strong>1</strong> 个 3x2 的子矩形。
矩形数目总共 = 8 + 5 + 2 + 4 + 2 + 2 + 1 = <strong>24</strong><strong> 。</strong>
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>mat = [[1,1,1,1,1,1]]
<strong>输出：</strong>21
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>mat = [[1,0,1],[0,1,0],[1,0,1]]
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= rows&nbsp;<= 150</code></li>
	<li><code>1 <= columns&nbsp;<= 150</code></li>
	<li><code>0 <= mat[i][j] <= 1</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int numSubmat(vector<vector<int>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (!matrix[i][j]) continue;
                dp[i][j] = (j == 0) ? 1 : dp[i][j - 1] + 1;

                int width = dp[i][j];
                for (int k = i; k >= 0; k--) {
                    width = min(width, dp[k][j]);
                    ans += width;
                    if (width == 0) break;
                }
            }
        }
        return ans;
    }
};
```




