# `（中等）` [529.minesweeper 扫雷游戏](https://leetcode-cn.com/problems/minesweeper/)

### 题目描述
<p>让我们一起来玩扫雷游戏！</p>

<p>给定一个代表游戏板的二维字符矩阵。&nbsp;<strong>'M'</strong>&nbsp;代表一个<strong>未挖出的</strong>地雷，<strong>'E'</strong>&nbsp;代表一个<strong>未挖出的</strong>空方块，<strong>'B'&nbsp;</strong>代表没有相邻（上，下，左，右，和所有4个对角线）地雷的<strong>已挖出的</strong>空白方块，<strong>数字</strong>（'1' 到 '8'）表示有多少地雷与这块<strong>已挖出的</strong>方块相邻，<strong>'X'</strong>&nbsp;则表示一个<strong>已挖出的</strong>地雷。</p>

<p>现在给出在所有<strong>未挖出的</strong>方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：</p>

<ol>
	<li>如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为&nbsp;<strong>'X'</strong>。</li>
	<li>如果一个<strong>没有相邻地雷</strong>的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的<strong>未挖出</strong>方块都应该被递归地揭露。</li>
	<li>如果一个<strong>至少与一个地雷相邻</strong>的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。</li>
	<li>如果在此次点击中，若无更多方块可被揭露，则返回面板。</li>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> 

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

<strong>输出:</strong> 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

<strong>解释:</strong>
<img style="width: 100%;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/minesweeper_example_1.png">
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

<strong>输出:</strong> 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

<strong>解释:</strong>
<img style="width: 100%;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/minesweeper_example_2.png">
</pre>

<p>&nbsp;</p>

<p><strong>注意：</strong></p>

<ol>
	<li>输入矩阵的宽和高的范围为 [1,50]。</li>
	<li>点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。</li>
	<li>输入面板不会是游戏结束的状态（即有地雷已被挖出）。</li>
	<li>简单起见，未提及的规则在这个问题中可被忽略。例如，当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        mine = vector<vector<int>>(board.size(), vector<int>(board[0].size(), -1));
        dfs(board, click[0], click[1]);
        return board;
    }

    void dfs(vector<vector<char>>& board, int x , int y) {
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }
        if (board[x][y] != 'E') return;

        int cnt = getCnt(board, x, y);
        if (cnt != 0) {
            board[x][y] = '0' + cnt;
            return;
        }

        board[x][y] = 'B';
        for (int i = max(0, x - 1); i < min((int)board.size(), x + 2); i++) {
            for (int j = max(0, y - 1); j < min((int)board[0].size(), y + 2); j++) {
                dfs(board, i, j);
            }
        }
    }

    int getCnt(vector<vector<char>>& board, int x , int y) {
        if (mine[x][y] != -1) return mine[x][y];

        int cnt = 0;
        for (int i = max(0, x - 1); i < min((int)board.size(), x + 2); i++) {
            for (int j = max(0, y - 1); j < min((int)board[0].size(), y + 2); j++) {
                cnt += (board[i][j] == 'M');
            }
        }
        mine[x][y] = cnt;
        return cnt;
    }

private:
    vector<vector<int>> mine;
};
```




