# `（困难）` [329.longest-increasing-path-in-a-matrix 矩阵中的最长递增路径](https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/)

### 题目描述
<p>给定一个整数矩阵，找出最长递增路径的长度。</p>

<p>对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>nums = 
[
  [<strong>9</strong>,9,4],
  [<strong>6</strong>,6,8],
  [<strong>2</strong>,<strong>1</strong>,1]
] 
<strong>输出:</strong> 4 
<strong>解释:</strong> 最长递增路径为&nbsp;<code>[1, 2, 6, 9]</code>。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> nums = 
[
  [<strong>3</strong>,<strong>4</strong>,<strong>5</strong>],
  [3,2,<strong>6</strong>],
  [2,2,1]
] 
<strong>输出: </strong>4 
<strong>解释: </strong>最长递增路径是&nbsp;<code>[3, 4, 5, 6]</code>。注意不允许在对角线方向上移动。
</pre>


---
### 思路
```
```



### 答题
``` C++
void calc(vector<vector<int>>& m, int x, int y, vector<vector<int>>& c, vector<vector<int>>& dd)
{
    if (x < 0 || x >= m.size() || y < 0 || y >= m[0].size()) return;

    int cnt = -1;
    for (auto i = 0; i < dd.size(); i++)
    {
        int dx = x + dd[i][0];
        int dy = y + dd[i][1];
        if (dx < 0 || dx >= m.size() || dy < 0 || dy >= m[0].size())
        {
            continue;
        }
        if (m[dx][dy] < m[x][y])
        {
            if (c[dx][dy] == -1) return;
            cnt = max(cnt, c[dx][dy]);
        }
    }
    c[x][y] = cnt + 1;
}

int longestIncreasingPath(vector<vector<int>>& matrix) 
{
    if (matrix.size() == 0) return 0;
    vector<vector<int>> dd = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> c(matrix.size(), vector<int>(matrix[0].size(), -1));

    int ans = 0;
    bool flag = false;
    while (!flag)
    {
        flag = true;
        for (int x = 0; x < matrix.size(); x++)
        {
            for (int y = 0; y < matrix[0].size(); y++)
            {
                if (c[x][y] < 0)
                {
                    calc(matrix, x, y, c, dd);
                }
                if (c[x][y] < 0)
                {
                    flag = false;
                }
                ans = max(ans, c[x][y]);
            }
        }
    }
    return ans + 1;
}
```




