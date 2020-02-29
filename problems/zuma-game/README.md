# `（困难）` [488.zuma-game 祖玛游戏](https://leetcode-cn.com/problems/zuma-game/)

### 题目描述
<p>回忆一下祖玛游戏。现在桌上有一串球，颜色有红色(R)，黄色(Y)，蓝色(B)，绿色(G)，还有白色(W)。 现在你手里也有几个球。</p>

<p>每一次，你可以从手里的球选一个，然后把这个球插入到一串球中的某个位置上（包括最左端，最右端）。接着，如果有出现三个或者三个以上颜色相同的球相连的话，就把它们移除掉。重复这一步骤直到桌上所有的球都被移除。</p>

<p>找到插入并可以移除掉桌上所有球所需的最少的球数。如果不能移除桌上所有的球，输出 -1 。</p>

<pre><strong>示例:</strong>
<strong>输入:</strong> "WRRBBW", "RB" 
<strong>输出:</strong> -1 
<strong>解释:</strong> WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW （翻译者标注：手上球已经用完，桌上还剩两个球无法消除，返回-1）

<strong>输入:</strong> "WWRRBBWW", "WRBRW" 
<strong>输出:</strong> 2 
<strong>解释:</strong> WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty

<strong>输入:</strong>"G", "GGGGG" 
<strong>输出:</strong> 2 
<strong>解释:</strong> G -> G[G] -> GG[G] -> empty 

<strong>输入:</strong> "RBYYBBRRB", "YRBGB" 
<strong>输出:</strong> 3 
<strong>解释:</strong> RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty 
</pre>

<p><strong>标注:</strong></p>

<ol>
	<li>你可以假设桌上一开始的球中，不会有三个及三个以上颜色相同且连着的球。</li>
	<li>桌上的球不会超过20个，输入的数据中代表这些球的字符串的名字是 "board" 。</li>
	<li>你手中的球不会超过5个，输入的数据中代表这些球的字符串的名字是 "hand"。</li>
	<li>输入的两个字符串均为非空字符串，且只包含字符 'R','Y','B','G','W'。</li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/zuma-game/solution/488-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    vector<int> getSame(string& board, int idx)
    {
        if (idx < 0 || idx >= board.size()) return {};
        int left = idx;
        int right = idx;
        while (left > 0 && board[left - 1] == board[left]) --left;
        while (right < board.size() - 1 && board[right + 1] == board[right]) ++right;
        return { left, right };
    }

    void shoot(string &board, int idx)
    {
        auto rg = getSame(board, idx);
        if (rg.empty()) return;
        if (rg[1] - rg[0] + 1 < 3) return;
        board = board.substr(0, rg[0]) + board.substr(rg[1] + 1);
        shoot(board, max(rg[0] - 1, 0));
    }

    void findMinStep(string board, unordered_map<char, int>& cntHand, int step, int& ans)
    {
        if (step >= ans) return;
        if (board.empty())
        {
            ans = min(ans, step);
            return;
        }

        for (int i = 0; i < board.size(); i++)
        {
            if (i != 0 && board[i] == board[i - 1]) continue;
            set<string> insertList;
            auto rg = getSame(board, i);
            if (rg[1] - rg[0] == 0)
            {
                insertList.insert({ board[i],board[i] });
            }
            else
            {
                insertList.insert({ board[i] });

                vector<int> flag(2, 0);
                char c = board[i];
                for (int d = 0; d <= 1; d++)
                {
                    int td = d * 2 - 1;
                    for (int j = i; j >= 0 && j < board.size(); j += td)
                    {
                        if (td == 1 && j == 0) continue;
                        if (td == -1 && j == board.size() - 1) continue;
                        flag[d] += (board[j - td] == c && board[j] != c) ? 1 : 0;
                        flag[d] += (board[j - td] != c && board[j] == c) ? 1 : 0;
                        if (flag[d] <= 2) continue;
                        insertList.insert({ board[j] });
                    }
                }
            }
            for (auto& item : insertList)
            {
                if (cntHand[item[0]] < item.size()) continue;

                cntHand[item[0]] -= item.size();
                string newBoard = board;
                newBoard = newBoard.insert(i + 1, item);
                shoot(newBoard, i);
                findMinStep(newBoard, cntHand, step + item.size(), ans);
                cntHand[item[0]] += item.size();
            }
        }
    }

    int findMinStep(string board, string hand) 
    {
        unordered_map<char, int> cntBoard;
        unordered_map<char, int> cntHand;
        for (auto& c : board)
        {
            cntBoard[c]++;
        }
        for (auto& c : hand)
        {
            cntHand[c]++;
        }
        for (auto& p : cntBoard)
        {
            if (p.second < 3 && cntHand[p.first] + p.second < 3) return -1;
        }

        int ans = INT_MAX;
        findMinStep(board, cntHand, 0, ans);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
```




