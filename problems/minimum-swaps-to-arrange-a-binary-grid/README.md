# `（中等）` [1536.minimum-swaps-to-arrange-a-binary-grid 排布二进制网格的最少交换次数](https://leetcode-cn.com/problems/minimum-swaps-to-arrange-a-binary-grid/)

[contest](https://leetcode-cn.com/contest/weekly-contest-200/problems/minimum-swaps-to-arrange-a-binary-grid/)

### 题目描述
<p>给你一个&nbsp;<code>n&nbsp;x n</code>&nbsp;的二进制网格&nbsp;<code>grid</code>，每一次操作中，你可以选择网格的&nbsp;<strong>相邻两行</strong>&nbsp;进行交换。</p>

<p>一个符合要求的网格需要满足主对角线以上的格子全部都是 <strong>0</strong>&nbsp;。</p>

<p>请你返回使网格满足要求的最少操作次数，如果无法使网格符合要求，请你返回 <strong>-1</strong>&nbsp;。</p>

<p>主对角线指的是从&nbsp;<code>(1, 1)</code>&nbsp;到&nbsp;<code>(n, n)</code>&nbsp;的这些格子。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 141px; width: 750px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/02/fw.jpg" alt=""></p>

<pre><strong>输入：</strong>grid = [[0,0,1],[1,1,0],[1,0,0]]
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="height: 270px; width: 270px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/02/e2.jpg" alt=""></p>

<pre><strong>输入：</strong>grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
<strong>输出：</strong>-1
<strong>解释：</strong>所有行都是一样的，交换相邻行无法使网格符合要求。
</pre>

<p><strong>示例 3：</strong></p>

<p><img style="height: 210px; width: 210px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/02/e3.jpg" alt=""></p>

<pre><strong>输入：</strong>grid = [[1,0,0],[1,1,0],[1,1,1]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 <= n&nbsp;<= 200</code></li>
	<li><code>grid[i][j]</code>&nbsp;要么是&nbsp;<code>0</code>&nbsp;要么是&nbsp;<code>1</code>&nbsp;。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-swaps-to-arrange-a-binary-grid/solution/minimum-swaps-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> zeroCnt(grid.size(), grid.size());
        for (int i = 0; i < grid.size(); i++) {
            for (int j = grid[i].size() - 1; j >= 0; j--) {
                if (grid[i][j] == 0) continue;
                zeroCnt[i] = grid[i].size() - j - 1;
                break;
            }
        }

        int ans = 0;
        for (int row = 0; row < grid.size() - 1; row++) {
            int t = findRow(zeroCnt, row);
            if (t == -1) return -1;
            ans += t - row;
        }
        return ans;
    }

    int findRow(vector<int>& zeroCnt, int row) {
        int cnt = zeroCnt.size() - row - 1;
        if (zeroCnt[row] >= cnt) return row;

        int prev = zeroCnt[row];
        for (int i = row + 1; i < zeroCnt.size(); i++) {
            swap(zeroCnt[i], prev);
            if (prev >= cnt) return i;
        }
        return -1;
    }
};
```




