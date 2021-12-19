# `（中等）` [419.battleships-in-a-board 甲板上的战舰](https://leetcode-cn.com/problems/battleships-in-a-board/)

### 题目描述
<div class="notranslate"><p>给你一个大小为 <code>m x n</code> 的矩阵 <code>board</code> 表示甲板，其中，每个单元格可以是一艘战舰 <code>'X'</code> 或者是一个空位 <code>'.'</code> ，返回在甲板 <code>board</code> 上放置的 <strong>战舰</strong> 的数量。</p>

<p><strong>战舰</strong> 只能水平或者垂直放置在 <code>board</code> 上。换句话说，战舰只能按 <code>1 x k</code>（<code>1</code> 行，<code>k</code> 列）或 <code>k x 1</code>（<code>k</code> 行，<code>1</code> 列）的形状建造，其中 <code>k</code> 可以是任意大小。两艘战舰之间至少有一个水平或垂直的空位分隔 （即没有相邻的战舰）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 333px; height: 333px;" src="https://assets.leetcode.com/uploads/2021/04/10/battelship-grid.jpg" alt="">
<pre><strong>输入：</strong>board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>board = [["."]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>board[i][j]</code> 是 <code>'.'</code> 或 <code>'X'</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以实现一次扫描算法，并只使用<strong> </strong><code>O(1)</code><strong> </strong>额外空间，并且不修改 <code>board</code> 的值来解决这个问题吗？</p>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        int ans = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) { 
                if (board[i][j] == 'X') {
                    if (i > 0 && board[i - 1][j] == 'X') {
                        continue;
                    }
                    if (j > 0 && board[i][j - 1] == 'X') {
                        continue;
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};
```




