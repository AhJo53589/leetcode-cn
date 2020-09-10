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
    int findMinStep(string board, string hand) {
        cnt = hand.size();
        for (auto c : hand) {
            h[c - 'A']++;
        }

        dfs(board, 0);
        return ans == INT_MAX ? -1 : ans;
    }

    void dfs(string board, int step) {
        shoot(board);

        if (board.empty()) {
            ans = min(ans, step);
        }
        if (step == cnt) return;
        if (step >= ans) return;

        set<pair<int, char>> ins;
        for (int i = 0; i < board.size(); i++) {
            int t = board[i] - 'A';
            if (i == 0 || board[i] != board[i - 1]) {
                if (h[t] != 0) {
                    ins.insert({ i, 'A' + t });
                }
            }
            if (i != 0 && board[i] == board[i - 1]) {
                for (int j = 0; j < h.size(); j++) {
                    if (j == t || h[j] == 0) continue;
                    ins.insert({ i, 'A' + j });
                }
            }
        }

        for (auto[i, c] : ins) {
            h[c - 'A']--;
            board.insert(i, 1, c);
            dfs(board, step + 1);
            board.erase(i, 1);
            h[c - 'A']++;
        }
    }

    void shoot(string& board) {
        for (int i = 0; i < (int)board.size() - 2; i++) {
            int j = i + 1;
            while (j < board.size() && board[i] == board[j]) j++;
            if (j - i < 3) {
                i = j - 1;
                continue;
            }
            board.erase(i, j - i);
            shoot(board);
            break;
        }
    }

private:
    int ans = INT_MAX;
    int cnt = 0;
    vector<int> h = vector<int>(26, 0);
};
```




