# `（简单）` [832.flipping-an-image 翻转图像](https://leetcode-cn.com/problems/flipping-an-image/)

### 题目描述
<p>给定一个二进制矩阵&nbsp;<code>A</code>，我们想先水平翻转图像，然后反转图像并返回结果。</p>

<p>水平翻转图片就是将图片的每一行都进行翻转，即逆序。例如，水平翻转&nbsp;<code>[1, 1, 0]</code>&nbsp;的结果是&nbsp;<code>[0, 1, 1]</code>。</p>

<p>反转图片的意思是图片中的&nbsp;<code>0</code>&nbsp;全部被&nbsp;<code>1</code>&nbsp;替换，&nbsp;<code>1</code>&nbsp;全部被&nbsp;<code>0</code>&nbsp;替换。例如，反转&nbsp;<code>[0, 1, 1]</code>&nbsp;的结果是&nbsp;<code>[1, 0, 0]</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[[1,1,0],[1,0,1],[0,0,0]]
<strong>输出：</strong>[[1,0,0],[0,1,0],[1,1,1]]
<strong>解释：</strong>首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
     然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
<strong>输出：</strong>[[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
<strong>解释：</strong>首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
     然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= A.length = A[0].length &lt;= 20</code></li>
	<li><code>0 &lt;= A[i][j]&nbsp;&lt;=&nbsp;1</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A[0].size();
        for (int i = 0; i < A.size(); i++) {
            for (int x = 0; x < n / 2; x++) {
                int y = n - x - 1;
                swap(A[i][x], A[i][y]);
                A[i][x] ^= 1;
                A[i][y] ^= 1;
            }
            if (n % 2 == 0) continue;
            A[i][n / 2] ^= 1;

        }
        return A;
    }
};
```




