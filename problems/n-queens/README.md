# `（困难）` [51.n-queens N皇后](https://leetcode-cn.com/problems/n-queens/)

### 题目描述
<p><em>n&nbsp;</em>皇后问题研究的是如何将 <em>n</em>&nbsp;个皇后放置在 <em>n</em>×<em>n</em> 的棋盘上，并且使皇后彼此之间不能相互攻击。</p>

<p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png"></p>

<p><small>上图为 8 皇后问题的一种解法。</small></p>

<p>给定一个整数 <em>n</em>，返回所有不同的&nbsp;<em>n&nbsp;</em>皇后问题的解决方案。</p>

<p>每一种解法包含一个明确的&nbsp;<em>n</em> 皇后问题的棋子放置方案，该方案中 <code>'Q'</code> 和 <code>'.'</code> 分别代表了皇后和空位。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 4
<strong>输出:</strong> [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
<strong>解释:</strong> 4 皇后问题存在两个不同的解法。
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/n-queens/solution/51-by-ikaruga/)

### 答题
``` C++
void dfs(int n, int row, int col, int ld, int rd, vector<int>& pick, vector<vector<string>>& ans)
{
    if (row == n)
    {
        vector<string> str(n, string(n, '.'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pick[i] & (1 << j))
                {
                    str[i][j] = 'Q';
                    break;
                }
            }
        }
        ans.push_back(str);
        return;
    }

    int bits = ~(col | ld | rd) & ((1 << n) - 1);
    while (bits != 0)
    {
        pick[row] = (bits & -bits);
        dfs(n, row + 1, (col | pick[row]), ((ld | pick[row]) << 1), ((rd | pick[row]) >> 1), pick, ans);
        bits &= (bits - 1);
    }
}

vector<vector<string>> solveNQueens(int n) 
{
    vector<vector<string>> ans;
    vector<int> pick(n, 0);
    dfs(n, 0, 0, 0, 0, pick, ans);
    return ans;
}
```




