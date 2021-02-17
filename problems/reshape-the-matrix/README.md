# `（简单）` [566.reshape-the-matrix 重塑矩阵](https://leetcode-cn.com/problems/reshape-the-matrix/)

### 题目描述
<div class="notranslate"><p>在MATLAB中，有一个非常有用的函数 <code>reshape</code>，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。</p>

<p>给出一个由二维数组表示的矩阵，以及两个正整数<code>r</code>和<code>c</code>，分别表示想要的重构的矩阵的行数和列数。</p>

<p>重构后的矩阵需要将原始矩阵的所有元素以相同的<strong>行遍历顺序</strong>填充。</p>

<p>如果具有给定参数的<code>reshape</code>操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
<strong>输出:</strong> 
[[1,2,3,4]]
<strong>解释:</strong>
行遍历nums的结果是 [1,2,3,4]。新的矩阵是 1 * 4 矩阵, 用之前的元素值一行一行填充新矩阵。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
<strong>输出:</strong> 
[[1,2],
 [3,4]]
<strong>解释:</strong>
没有办法将 2 * 2 矩阵转化为 2 * 4 矩阵。 所以输出原矩阵。
</pre>

<p><strong>注意：</strong></p>

<ol>
	<li>给定矩阵的宽和高范围在 [1, 100]。</li>
	<li>给定的 r 和 c 都是正数。</li>
</ol>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (r * c != nums.size() * nums[0].size()) return nums;

        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                int idx = i * nums[0].size() + j;
                int di = idx / c;
                int dj = idx % c;
                ans[di][dj] = nums[i][j];
            }
        }

        return ans;
    }
};
```




