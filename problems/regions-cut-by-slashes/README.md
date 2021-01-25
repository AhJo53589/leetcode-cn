# `（中等）` [959.regions-cut-by-slashes 由斜杠划分区域](https://leetcode-cn.com/problems/regions-cut-by-slashes/)

### 题目描述
<p>在由 1 x 1 方格组成的 N x N 网格&nbsp;<code>grid</code> 中，每个 1 x 1&nbsp;方块由 <code>/</code>、<code>\</code> 或空格构成。这些字符会将方块划分为一些共边的区域。</p>

<p>（请注意，反斜杠字符是转义的，因此 <code>\</code> 用 <code>"\\"</code>&nbsp;表示。）。</p>

<p>返回区域的数目。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：
</strong>[
&nbsp; " /",
&nbsp; "/ "
]
<strong>输出：</strong>2
<strong>解释：</strong>2x2 网格如下：
<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/15/1.png" alt=""></pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：
</strong>[
&nbsp; " /",
&nbsp; "  "
]
<strong>输出：</strong>1
<strong>解释：</strong>2x2 网格如下：
<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/15/2.png" alt=""></pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：
</strong>[
&nbsp; "\\/",
&nbsp; "/\\"
]
<strong>输出：</strong>4
<strong>解释：</strong>（回想一下，因为 \ 字符是转义的，所以 "\\/" 表示 \/，而 "/\\" 表示 /\。）
2x2 网格如下：
<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/15/3.png" alt=""></pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：
</strong>[
&nbsp; "/\\",
&nbsp; "\\/"
]
<strong>输出：</strong>5
<strong>解释：</strong>（回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。）
2x2 网格如下：
<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/15/4.png" alt=""></pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：
</strong>[
&nbsp; "//",
&nbsp; "/ "
]
<strong>输出：</strong>3
<strong>解释：</strong>2x2 网格如下：
<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/15/5.png" alt="">
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= grid.length == grid[0].length &lt;= 30</code></li>
	<li><code>grid[i][j]</code> 是&nbsp;<code>'/'</code>、<code>'\'</code>、或&nbsp;<code>' '</code>。</li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/regions-cut-by-slashes/solution/regions-cut-by-slashes-by-ikaruga-rjs9/)

### 答题
``` C++
struct DSU {
    DSU(int n) : data(n, -1) {}

    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;

        if (data[y] < data[x]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    bool same(int x, int y) { return root(x) == root(y); }

    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }

    int size(int x) { return -data[root(x)]; }

    std::vector<int> data;
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int ans = grid.size() * grid[0].size() * 4;
        DSU dsu(ans);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int a = (i * grid[i].size() + j) * 4;
                if (grid[i][j] != '\\') {
                    ans -= dsu.unionSet(a + 0, a + 3);
                    ans -= dsu.unionSet(a + 1, a + 2);
                }
                if (grid[i][j] != '/') {
                    ans -= dsu.unionSet(a + 0, a + 1);
                    ans -= dsu.unionSet(a + 2, a + 3);
                }

                if (i != 0) {
                    int b = ((i - 1) * grid[0].size() + j) * 4;
                    ans -= dsu.unionSet(a + 0, b + 2);
                }
                if (j != 0) {
                    int b = (i * grid[0].size() + (j - 1)) * 4;
                    ans -= dsu.unionSet(a + 3, b + 1);
                }
            }
        }
        return ans;
    }
};
```




