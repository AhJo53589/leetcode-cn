# `（困难）` [52.n-queens-ii N皇后 II](https://leetcode-cn.com/problems/n-queens-ii/)

### 题目描述
<p><em>n&nbsp;</em>皇后问题研究的是如何将 <em>n</em>&nbsp;个皇后放置在 <em>n</em>×<em>n</em> 的棋盘上，并且使皇后彼此之间不能相互攻击。</p>

<p><img style="height: 276px; width: 258px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png"></p>

<p><small>上图为 8 皇后问题的一种解法。</small></p>

<p>给定一个整数 <em>n</em>，返回 <em>n</em> 皇后不同的解决方案的数量。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 4
<strong>输出:</strong> 2
<strong>解释:</strong> 4 皇后问题存在如下两个不同的解法。
[
&nbsp;[".Q..", &nbsp;// 解法 1
&nbsp; "...Q",
&nbsp; "Q...",
&nbsp; "..Q."],

&nbsp;["..Q.", &nbsp;// 解法 2
&nbsp; "Q...",
&nbsp; "...Q",
&nbsp; ".Q.."]
]
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/friend-circles/solution/547-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int totalNQueens(int n) 
    {
        dfs(n, 0, 0, 0, 0);
        return ans;
    }

    void dfs(int n, int row, int col, int ld, int rd) 
    {
        if (row >= n)
        { 
            ans++;
            return;
        }

        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while (bits > 0) 
        {
            int pick = bits & -bits;
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1);
            bits &= bits - 1;
        }
    }

private:
    int ans = 0;
};
```




