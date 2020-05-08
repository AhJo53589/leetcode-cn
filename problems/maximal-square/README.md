# `（中等）` [221.maximal-square 最大正方形](https://leetcode-cn.com/problems/maximal-square/)

### 题目描述
<p>在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入: 
</strong>
1 0 1 0 0
1 0 <strong>1 1</strong> 1
1 1 <strong>1 1 </strong>1
1 0 0 1 0

<strong>输出: </strong>4</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximal-square/solution/maximal-square-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        vector<vector<int>> m(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int ans = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '0') continue;
                m[i + 1][j + 1] = min(min(m[i][j + 1], m[i + 1][j]), m[i][j]) + 1;
                ans = max(ans, m[i + 1][j + 1]);
            }
        }

        return ans * ans;
    }
};
```




