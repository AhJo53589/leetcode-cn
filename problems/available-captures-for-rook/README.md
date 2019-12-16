# `（简单）` [999.available-captures-for-rook 车的可用捕获量](https://leetcode-cn.com/problems/available-captures-for-rook/)

### 题目描述
<p>在一个 8 x 8 的棋盘上，有一个白色车（rook）。也可能有空方块，白色的象（bishop）和黑色的卒（pawn）。它们分别以字符 “R”，“.”，“B” 和 “p” 给出。大写字符表示白棋，小写字符表示黑棋。</p>

<p>车按国际象棋中的规则移动：它选择四个基本方向中的一个（北，东，西和南），然后朝那个方向移动，直到它选择停止、到达棋盘的边缘或移动到同一方格来捕获该方格上颜色相反的卒。另外，车不能与其他友方（白色）象进入同一个方格。</p>

<p>返回车能够在一次移动中捕获到的卒的数量。<br>
&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 305px; width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/23/1253_example_1_improved.PNG" alt=""></p>

<pre><strong>输入：</strong>[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
<strong>输出：</strong>3
<strong>解释：
</strong>在本例中，车能够捕获所有的卒。
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="height: 306px; width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/23/1253_example_2_improved.PNG" alt=""></p>

<pre><strong>输入：</strong>[[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
<strong>输出：</strong>0
<strong>解释：
</strong>象阻止了车捕获任何卒。
</pre>

<p><strong>示例 3：</strong></p>

<p><img style="height: 305px; width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/23/1253_example_3_improved.PNG" alt=""></p>

<pre><strong>输入：</strong>[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
<strong>输出：</strong>3
<strong>解释： </strong>
车可以捕获位置 b5，d6 和 f5 的卒。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>board.length == board[i].length == 8</code></li>
	<li><code>board[i][j]</code> 可以是&nbsp;<code>'R'</code>，<code>'.'</code>，<code>'B'</code>&nbsp;或&nbsp;<code>'p'</code></li>
	<li>只有一个格子上存在&nbsp;<code>board[i][j] == 'R'</code></li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/available-captures-for-rook/solution/999-by-ikaruga/)

### 答题
``` C++
int getp(vector<vector<char>>& b, vector<vector<int>>& dd, int x, int y)
{
    int cnt = 0;
    for (auto d : dd)
    {
        int dx = x;
        int dy = y;
        while (true)
        {
            dx += d[0];
            dy += d[1];
            if (dx < 0 || dx >= b.size()) break;
            if (dy < 0 || dy >= b[0].size()) break;
            if (b[dx][dy] == 'B') break;
            if (b[dx][dy] == 'p') 
            {
                cnt++;
                break;
            }  
        }
    }
    return cnt;
}

int numRookCaptures(vector<vector<char>>& board)
{
    vector<vector<int>> dd = {{0,1},{0,-1},{1,0},{-1,0}};

    for (int x = 0; x < board.size(); x++)
    {
        for (int y = 0; y < board[0].size(); y++)
        {
            if (board[x][y] != 'R') continue;
            return getp(board, dd, x, y);
        }
    }
    return 0;
}
```




