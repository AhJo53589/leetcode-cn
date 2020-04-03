# `（中等）` [289.game-of-life 生命游戏](https://leetcode-cn.com/problems/game-of-life/)

### 题目描述
<p>根据<a href="https://baike.baidu.com/item/%E7%94%9F%E5%91%BD%E6%B8%B8%E6%88%8F/2926434?fr=aladdin">百度百科</a>，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在1970年发明的细胞自动机。</p>
<p>给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞具有一个初始状态 <em>live</em>（1）即为活细胞， 或 <em>dead</em>（0）即为死细胞。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：</p>
<ol>
	<li>如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；</li>
	<li>如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；</li>
	<li>如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；</li>
	<li>如果死细胞周围正好有三个活细胞，则该位置死细胞复活；</li>
</ol>

<p>根据当前状态，写一个函数来计算面板上细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。</p>
<p><strong>示例:</strong></p>
<pre><strong>输入: 
</strong>[
&nbsp; [0,1,0],
&nbsp; [0,0,1],
&nbsp; [1,1,1],
&nbsp; [0,0,0]
]
<strong>输出: 
</strong>[
&nbsp; [0,0,0],
&nbsp; [1,0,1],
&nbsp; [0,1,1],
&nbsp; [0,1,0]
]</pre>

<p><strong>进阶:</strong></p>
<ul>
	<li>你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。</li>
	<li>本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？</li>
</ul>

---
### 思路
```

```

[发布的题解](https://leetcode-cn.com/problems/game-of-life/solution/289-by-ikaruga/)

### 答题
``` C++
void aliveReport(vector<vector<int>>& board, int x, int y)
{
    for (int i = max(0, x - 1); i < min((int)board.size(), x + 2); i++)
    {
        for (int j = max(0, y - 1); j < min((int)board[0].size(), y + 2); j++)
        {
            if (i == x && j == y) continue;
            board[i][j] += (board[i][j] > 0) ? 1 : -1;
        }
    }
}

void gameOfLife(vector<vector<int>>& board)
{
    if (board.empty() || board[0].empty()) return;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] <= 0) continue;
            aliveReport(board, i, j);
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            int& x = board[i][j];
            x = (x == 2 + 1 || x == 3 + 1 || x == -3) ? 1 : 0;
        }
    }
}
```

### 其它
``` C++
int countAlive(vector<vector<int>>& board, int x, int y)
{
    int cnt = 0;
    for (int i = max(0, x - 1); i < min((int)board.size(), x + 2); i++)
    {
        for (int j = max(0, y - 1); j < min((int)board[0].size(), y + 2); j++)
        {
            if (i == x && j == y) continue;
            cnt += (i < x || (i == x && j < y)) ? ((0b10 & board[i][j]) != 0) : ((0b01 & board[i][j]) != 0);
        }
    }
    return cnt;
}

void gameOfLife(vector<vector<int>>& board)
{
    if (board.empty() || board[0].empty()) return;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            int cnt = countAlive(board, i, j);
            board[i][j] <<= 1;
            if ((board[i][j] & 0b10) != 0)
            {
                board[i][j] |= (cnt == 2 || cnt == 3);
            }
            else
            {
                board[i][j] |= (cnt == 3);
            }
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            board[i][j] &= 1;
        }
    }
}
```

