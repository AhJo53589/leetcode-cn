# `（中等）` [5655.largest-submatrix-with-rearrangements 重新排列后的最大子矩阵](https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements/)

[contest](https://leetcode-cn.com/contest/weekly-contest-224/problems/largest-submatrix-with-rearrangements/)

### 题目描述
<div class="notranslate"><p>给你一个二进制矩阵&nbsp;<code>matrix</code>&nbsp;，它的大小为&nbsp;<code>m x n</code>&nbsp;，你可以将 <code>matrix</code>&nbsp;中的 <strong>列</strong>&nbsp;按任意顺序重新排列。</p>

<p>请你返回最优方案下将 <code>matrix</code>&nbsp;重新排列后，全是 <code>1</code>&nbsp;的子矩阵面积。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="width: 300px; height: 144px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/01/17/screenshot-2020-12-30-at-40536-pm.png" alt=""></strong></p>

<pre><b>输入：</b>matrix = [[0,0,1],[1,1,1],[1,0,1]]
<b>输出：</b>4
<b>解释：</b>你可以按照上图方式重新排列矩阵的每一列。
最大的全 1 子矩阵是上图中加粗的部分，面积为 4 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="width: 500px; height: 62px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/01/17/screenshot-2020-12-30-at-40852-pm.png" alt=""></p>

<pre><b>输入：</b>matrix = [[1,0,1,0,1]]
<b>输出：</b>3
<b>解释：</b>你可以按照上图方式重新排列矩阵的每一列。
最大的全 1 子矩阵是上图中加粗的部分，面积为 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>matrix = [[1,1,0],[1,0,1]]
<b>输出：</b>2
<b>解释：</b>由于你只能整列整列重新排布，所以没有比面积为 2 更大的全 1 子矩形。</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>matrix = [[0,0],[0,0]]
<b>输出：</b>0
<b>解释：</b>由于矩阵中没有 1 ，没有任何全 1 的子矩阵，所以面积为 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>matrix[i][j]</code>&nbsp;要么是&nbsp;<code>0</code>&nbsp;，要么是&nbsp;<code>1</code> 。</li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements/solution/largest-submatrix-with-rearrangements-by-twa9/)

### 答题
``` C++
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int ans = 0;
        vector<int> line(matrix[0].size() + 2, 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                line[j + 1] = (matrix[i][j] == 0) ? 0 : line[j + 1] + 1;
            }
            vector<int> temp(line.begin(), line.end());
            sort(temp.begin() + 1, temp.end() - 1);
            ans = max(ans, largestRectangleArea(temp));
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        vector<int> st;
        // heights.insert(heights.begin(), 0);
        // heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.back()] > heights[i]) {
                int cur = st.back();
                st.pop_back();
                int left = st.back() + 1;
                int right = i - 1;
                ans = max(ans, (right - left + 1) * heights[cur]);
            }
            st.push_back(i);
        }
        return ans;
    }
};
```




