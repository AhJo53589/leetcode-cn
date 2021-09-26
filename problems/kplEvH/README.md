# `（中等）` [LCP 45.kplEvH 自行车炫技赛场](https://leetcode-cn.com/problems/kplEvH/)

[contest](https://leetcode-cn.com/contest/season/2021-fall/problems/kplEvH/)

### 题目描述
<p>「力扣挑战赛」中 <code>N*M</code> 大小的自行车炫技赛场的场地由一片连绵起伏的上下坡组成，场地的高度值记录于二维数组 <code>terrain</code> 中，场地的减速值记录于二维数组 <code>obstacle</code> 中。</p>
<ul>
<li>若选手骑着自行车从高度为 <code>h1</code> 且减速值为 <code>o1</code> 的位置到高度为 <code>h2</code> 且减速值为 <code>o2</code> 的相邻位置，速度变化值为 <code>h1-h2-o2</code>（负值减速，正值增速）。</li>
</ul>
<p>选手初始位于坐标 <code>position</code> 处且初始速度为 1，请问选手可以刚好到其他哪些位置时速度依旧为 1。请以二维数组形式返回这些位置。若有多个位置则按行坐标升序排列，若有多个位置行坐标相同则按列坐标升序排列。</p>
<p><strong>注意：</strong> 骑行过程中速度不能为零或负值</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>position = [0,0], terrain = [[0,0],[0,0]], obstacle = [[0,0],[0,0]]</code></p>
<p>输出：<code>[[0,1],[1,0],[1,1]]</code></p>
<p>解释：<br>
由于当前场地属于平地，根据上面的规则，选手从<code>[0,0]</code>的位置出发都能刚好在其他处的位置速度为 1。</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>position = [1,1], terrain = [[5,0],[0,6]], obstacle = [[0,6],[7,0]]</code></p>
<p>输出：<code>[[0,1]]</code></p>
<p>解释：<br>
选手从 <code>[1,1]</code> 处的位置出发，到 <code>[0,1]</code> 处的位置时恰好速度为 1。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>n == terrain.length == obstacle.length</code></li>
<li><code>m == terrain[i].length == obstacle[i].length</code></li>
<li><code>1 &lt;= n &lt;= 100</code></li>
<li><code>1 &lt;= m &lt;= 100</code></li>
<li><code>0 &lt;= terrain[i][j], obstacle[i][j] &lt;= 100</code></li>
<li><code>position.length == 2</code></li>
<li><code>0 &lt;= position[0] &lt; n</code></li>
<li><code>0 &lt;= position[1] &lt; m</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<vector<int>> bicycleYard(vector<int>& position, vector<vector<int>>& terrain, vector<vector<int>>& obstacle) {
        vector<vector<int>> dd = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        vector<vector<int>> ans;
        
        set<tuple<int, int, int>> vi;
        vi.insert({ 1, position[0], position[1] });

        priority_queue<tuple<int, int, int>> pq;
        pq.push({ 1, position[0], position[1] });

        while (!pq.empty()) {
            auto [speed, x, y] = pq.top();
            pq.pop();

            for (auto& d : dd) {
                int dx = x + d[0];
                int dy = y + d[1];
                if (dx < 0 || dx >= terrain.size()) continue;
                if (dy < 0 || dy >= terrain[0].size()) continue;
                int s = speed + terrain[x][y] - terrain[dx][dy] - obstacle[dx][dy];
                if (s <= 0) continue;
                if (vi.find({s, dx, dy}) != vi.end()) continue;
                vi.insert({ s, dx, dy });
                pq.push({ s, dx, dy });
                if (s == 1) {
                    ans.push_back({ dx, dy });
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```




