# `（中等）` [794.valid-tic-tac-toe-state 有效的井字游戏](https://leetcode-cn.com/problems/valid-tic-tac-toe-state/)

### 题目描述
<p>给你一个字符串数组 <code>board</code> 表示井字游戏的棋盘。当且仅当在井字游戏过程中，棋盘有可能达到 <code>board</code> 所显示的状态时，才返回 <code>true</code> 。</p>

<p>井字游戏的棋盘是一个 <code>3 x 3</code> 数组，由字符 <code>' '</code>，<code>'X'</code> 和 <code>'O'</code> 组成。字符 <code>' '</code> 代表一个空位。</p>

<p>以下是井字游戏的规则：</p>

<ul>
	<li>玩家轮流将字符放入空位（<code>' '</code>）中。</li>
	<li>玩家 1 总是放字符 <code>'X'</code> ，而玩家 2 总是放字符 <code>'O'</code> 。</li>
	<li><code>'X'</code> 和 <code>'O'</code> 只允许放置在空位中，不允许对已放有字符的位置进行填充。</li>
	<li>当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。</li>
	<li>当所有位置非空时，也算为游戏结束。</li>
	<li>如果游戏结束，玩家不允许再放置字符。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 253px; height: 253px;" src="https://assets.leetcode.com/uploads/2021/05/15/tictactoe1-grid.jpg" alt="">
<pre><strong>输入：</strong>board = ["O  ","   ","   "]
<strong>输出：</strong>false
<strong>解释：</strong>玩家 1 总是放字符 "X" 。
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 253px; height: 253px;" src="https://assets.leetcode.com/uploads/2021/05/15/tictactoe2-grid.jpg" alt="">
<pre><strong>输入：</strong>board = ["XOX"," X ","   "]
<strong>输出：</strong>false
<strong>解释：</strong>玩家应该轮流放字符。</pre>

<p><strong>示例 3：</strong></p>
<img style="width: 253px; height: 253px;" src="https://assets.leetcode.com/uploads/2021/05/15/tictactoe3-grid.jpg" alt="">
<pre><strong>输入：</strong>board = ["XXX","   ","OOO"]
<strong>输出：</strong>false
</pre>

<p><strong>Example 4:</strong></p>
<img style="width: 253px; height: 253px;" src="https://assets.leetcode.com/uploads/2021/05/15/tictactoe4-grid.jpg" alt="">
<pre><strong>输入：</strong>board = ["XOX","O O","XOX"]
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>board.length == 3</code></li>
	<li><code>board[i].length == 3</code></li>
	<li><code>board[i][j]</code> 为 <code>'X'</code>、<code>'O'</code> 或 <code>' '</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cnt = 0;
        for (auto& s : board) {
            for (auto& c : s) {
                cnt += (c == 'X');
                cnt -= (c == 'O');
            }
        }

        int win[128]{};
        for (int i = 0; i < 3; i++) {
            ++win[board[i][0] | board[i][1] | board[i][2]];
            ++win[board[0][i] | board[1][i] | board[2][i]];
        }
        ++win[board[0][0] | board[1][1] | board[2][2]];
        ++win[board[2][0] | board[1][1] | board[0][2]];

        return cnt == 1 && !win['O'] || cnt == 0 && !win['X'];
    }
};
```




