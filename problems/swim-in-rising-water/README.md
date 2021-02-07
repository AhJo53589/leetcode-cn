# `（困难）` [778.swim-in-rising-water 水位上升的泳池中游泳](https://leetcode-cn.com/problems/swim-in-rising-water/)

### 题目描述
<div class="notranslate"><p>在一个 N x N 的坐标方格&nbsp;<code>grid</code> 中，每一个方格的值 <code>grid[i][j]</code> 表示在位置 <code>(i,j)</code> 的平台高度。</p>

<p>现在开始下雨了。当时间为&nbsp;<code>t</code>&nbsp;时，此时雨水导致水池中任意位置的水位为&nbsp;<code>t</code>&nbsp;。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。</p>

<p>你从坐标方格的左上平台 (0，0) 出发。最少耗时多久你才能到达坐标方格的右下平台&nbsp;<code>(N-1, N-1)</code>？</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [[0,2],[1,3]]
<strong>输出:</strong> 3
<strong>解释:</strong>
时间为0时，你位于坐标方格的位置为 <code>(0, 0)。</code>
此时你不能游向任意方向，因为四个相邻方向平台的高度都大于当前时间为 0 时的水位。

等时间到达 3 时，你才可以游向平台 (1, 1). 因为此时的水位是 3，坐标方格中的平台没有比水位 3 更高的，所以你可以游向坐标方格中的任意位置
</pre>

<p><strong>示例2:</strong></p>

<pre><strong>输入:</strong> [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
<strong>输出:</strong> 16
<strong>解释:</strong>
<strong> 0  1  2  3  4</strong>
24 23 22 21  <strong>5</strong>
<strong>12 13 14 15 16</strong>
<strong>11</strong> 17 18 19 20
<strong>10  9  8  7  6</strong>

最终的路线用加粗进行了标记。
我们必须等到时间为 16，此时才能保证平台 (0, 0) 和 (4, 4) 是连通的
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ol>
	<li><code>2 &lt;= N &lt;= 50</code>.</li>
	<li><code>grid[i][j]</code> 是 <code>[0, ..., N*N - 1]</code> 的排列。</li>
</ol>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/swim-in-rising-water/solution/swim-in-rising-water-by-ikaruga-kmnw/)

### 答题
``` C++
struct DSU {
    DSU(int n) : data(n, -1), cnt(n) {}

    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (data[x] > data[y]) {
            swap(x, y);
        }
        data[x] += data[y];
        data[y] = x;
        cnt--;
        return true;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }

    vector<int> data;
    int cnt = 0;
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> seq(grid.size() * grid[0].size());
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                seq[grid[i][j]] = { i, j };
            }
        }

        DSU dsu(seq.size());
        for (int i = 0; i < seq.size(); i++) {
            int x = seq[i][0];
            int y = seq[i][1];
            
            int a = x * grid[0].size() + y;
            for (auto& d : dd) {
                int dx = x + d[0];
                int dy = y + d[1];
                if (dx < 0 || dx >= grid.size()) continue;
                if (dy < 0 || dy >= grid[0].size()) continue;
                if (grid[dx][dy] > i) continue;

                int b = dx * grid[0].size() + dy;
                dsu.unionSet(a, b);
            }
            if (dsu.same(0, seq.size() - 1)) return i;
        }
        return seq.size() - 1;
    }

private:
    vector<vector<int>> dd = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
};
```




