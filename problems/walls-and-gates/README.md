# `（中等）` [286.walls-and-gates 墙与门](https://leetcode-cn.com/problems/walls-and-gates/)

### 题目描述
<p>你被给定一个&nbsp;<em>m × n</em>&nbsp;的二维网格，网格中有以下三种可能的初始化值：</p>

<ol>
	<li><code>-1</code>&nbsp;表示墙或是障碍物</li>
	<li><code>0</code>&nbsp;表示一扇门</li>
	<li><code>INF</code>&nbsp;无限表示一个空的房间。然后，我们用&nbsp;<code>2<sup>31</sup> - 1 = 2147483647</code>&nbsp;代表&nbsp;<code>INF</code>。你可以认为通往门的距离总是小于&nbsp;<code>2147483647</code>&nbsp;的。</li>
</ol>

<p>你要给每个空房间位上填上该房间到&nbsp;<em>最近&nbsp;</em>门的距离，如果无法到达门，则填&nbsp;<code>INF</code>&nbsp;即可。</p>

<p><strong>示例：</strong></p>

<p>给定二维网格：</p>

<pre>INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
</pre>

<p>运行完你的函数后，该网格应该变成：</p>

<pre>  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/walls-and-gates/solution/walls-and-gates-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> que;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                if (rooms[i][j] != 0) continue;
                que.push({i, j});
            }
        }

        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            for (auto d : dd) {
                int dx = x + d[0];
                int dy = y + d[1];
                if (dx < 0 || dx >= rooms.size()) continue;
                if (dy < 0 || dy >= rooms[0].size()) continue;
                if (rooms[dx][dy] <= rooms[x][y] + 1) continue;

                rooms[dx][dy] = rooms[x][y] + 1;
                que.push({dx, dy});
            }
        }
    }

private:
    vector<vector<int>> dd = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
};
```




