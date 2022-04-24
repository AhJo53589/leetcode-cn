# `（中等）` [LCP 56.6UEx57 信物传送](https://leetcode-cn.com/problems/6UEx57/)

### 题目描述
<p>欢迎各位勇者来到力扣城，本次试炼主题为「信物传送」。</p>
<p>本次试炼场地设有若干传送带，<code>matrix[i][j]</code> 表示第 <code>i</code> 行 <code>j</code> 列的传送带运作方向，<code>"^","v","&lt;","&gt;"</code> 这四种符号分别表示 <strong>上、下、左、右</strong> 四个方向。信物会随传送带的方向移动。勇者<strong>每一次</strong>施法操作，可<strong>临时</strong>变更一处传送带的方向，在物品经过后传送带恢复原方向。<br>
<img src="https://pic.leetcode-cn.com/1649835246-vfupSL-lcp%20(2).gif" alt="lcp (2).gif" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " width="300px"></p>
<p>通关信物初始位于坐标 <code>start</code>处，勇者需要将其移动到坐标 <code>end</code> 处，请返回勇者施法操作的最少次数。</p>
<p><strong>注意：</strong></p>
<ul>
<li><code>start</code> 和 <code>end</code> 的格式均为 <code>[i,j]</code></li>
</ul>
<p><strong>示例 1:</strong></p>
<blockquote>
<p>输入：<code>matrix = ["&gt;&gt;v","v^&lt;","&lt;&gt;&lt;"], start = [0,1], end = [2,0]</code></p>
<p>输出：<code>1</code></p>
<p>解释：<br>
如上图所示<br>
当信物移动到 <code>[1,1]</code> 时，勇者施法一次将 <code>[1,1]</code> 的传送方向 <code>^</code> 从变更为 <code>&lt;</code><br>
从而信物移动到 <code>[1,0]</code>，后续到达 <code>end</code> 位置<br>
因此勇者最少需要施法操作 1 次</p>
</blockquote>
<p><strong>示例 2:</strong></p>
<blockquote>
<p>输入：<code>matrix = ["&gt;&gt;v","&gt;&gt;v","^&lt;&lt;"], start = [0,0], end = [1,1]</code></p>
<p>输出：<code>0</code></p>
<p>解释：勇者无需施法，信物将自动传送至 <code>end</code> 位置</p>
</blockquote>
<p><strong>示例 3:</strong></p>
<blockquote>
<p>输入：<code>matrix = ["&gt;^^&gt;","&lt;^v&gt;","^v^&lt;"], start = [0,0], end = [1,3]</code></p>
<p>输出：<code>3</code></p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>matrix</code> 中仅包含 <code>'^'、'v'、'&lt;'、'&gt;'</code></li>
<li><code>0 &lt; matrix.length &lt;= 100</code></li>
<li><code>0 &lt; matrix[i].length &lt;= 100</code></li>
<li><code>0 &lt;= start[0],end[0] &lt; matrix.length</code></li>
<li><code>0 &lt;= start[1],end[1] &lt; matrix[i].length</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {
        unordered_map<char, int> cc = { {'>', 0}, {'v', 1}, {'<', 2}, {'^', 3} };
        vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

        vector<vector<int>> vi(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({ 0, start[0], start[1] });
        vi[start[0]][start[1]] = 0;

        while (!pq.empty()) {
            auto q = pq.top();
            pq.pop();

            int x = q[1];
            int y = q[2];
            int to = cc[matrix[x][y]];
            for (int i = 0; i < dd.size(); i++) {
                int dx = x + dd[i][0];
                int dy = y + dd[i][1];
                if (dx < 0 || dx >= vi.size() || dy < 0 || dy >= vi[0].size()) continue;
                int change = q[0] + (to != i);
                if (vi[dx][dy] > change) {
                    vi[dx][dy] = change;
                    pq.push({ change, dx, dy });
                }
            }
        }

        return vi[end[0]][end[1]];
    }
};
```




