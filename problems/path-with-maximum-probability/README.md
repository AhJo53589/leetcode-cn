# `（中等）` [5211.path-with-maximum-probability 概率最大的路径](https://leetcode-cn.com/problems/path-with-maximum-probability/)

[contest](https://leetcode-cn.com/contest/weekly-contest-197/problems/path-with-maximum-probability/)

### 题目描述
<p>给你一个由 <code>n</code> 个节点（下标从 0 开始）组成的无向加权图，该图由一个描述边的列表组成，其中 <code>edges[i] = [a, b]</code> 表示连接节点 a 和 b 的一条无向边，且该边遍历成功的概率为 <code>succProb[i]</code> 。</p>

<p>指定两个节点分别作为起点 <code>start</code> 和终点 <code>end</code> ，请你找出从起点到终点成功概率最大的路径，并返回其成功概率。</p>

<p>如果不存在从 <code>start</code> 到 <code>end</code> 的路径，请 <strong>返回 0</strong> 。只要答案与标准答案的误差不超过 <strong>1e-5 </strong>，就会被视作正确答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="height: 186px; width: 187px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/12/1558_ex1.png" alt=""></strong></p>

<pre><strong>输入：</strong>n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
<strong>输出：</strong>0.25000
<strong>解释：</strong>从起点到终点有两条路径，其中一条的成功概率为 0.2 ，而另一条为 0.5 * 0.5 = 0.25
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img style="height: 186px; width: 189px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/12/1558_ex2.png" alt=""></strong></p>

<pre><strong>输入：</strong>n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
<strong>输出：</strong>0.30000
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img style="height: 191px; width: 215px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/12/1558_ex3.png" alt=""></strong></p>

<pre><strong>输入：</strong>n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
<strong>输出：</strong>0.00000
<strong>解释：</strong>节点 0 和 节点 2 之间不存在路径
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 10^4</code></li>
	<li><code>0 <= start, end < n</code></li>
	<li><code>start != end</code></li>
	<li><code>0 <= a, b < n</code></li>
	<li><code>a != b</code></li>
	<li><code>0 <= succProb.length == edges.length <= 2*10^4</code></li>
	<li><code>0 <= succProb[i] <= 1</code></li>
	<li>每两个节点之间最多有一条边</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/path-with-maximum-probability/solution/path-with-maximum-probability-by-ikaruga/)

### 答题
``` C++
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<bool> vi(n, false);

        vector<vector<pair<double, int>>> path(n, vector<pair<double, int>>());
        for (int i = 0; i < edges.size(); i++) {
            auto& e = edges[i];
            path[e[0]].push_back({ succProb[i], e[1] });
            path[e[1]].push_back({ succProb[i], e[0] });
        }

        priority_queue<pair<double, int>> pq;
        pq.push({ 1, start });

        while (!pq.empty()) {
            auto [curProb, cur] = pq.top();
            pq.pop();

            if (vi[cur]) continue;
            vi[cur] = true;

            if (cur == end) return curProb;

            for (auto [nextProb, next] : path[cur]) {
                if (vi[next]) continue;
                pq.push({ curProb * nextProb, next });
            }
        }

        return 0;
    }
```




