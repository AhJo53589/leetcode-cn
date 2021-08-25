# `（中等）` [787.cheapest-flights-within-k-stops K 站中转内最便宜的航班](https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/)

### 题目描述
<p>有 <code>n</code> 个城市通过一些航班连接。给你一个数组&nbsp;<code>flights</code> ，其中&nbsp;<code>flights[i] = [from<sub>i</sub>, to<sub>i</sub>, price<sub>i</sub>]</code> ，表示该航班都从城市 <code>from<sub>i</sub></code> 开始，以价格 <code>to<sub>i</sub></code> 抵达 <code>price<sub>i</sub></code>。</p>

<p>现在给定所有的城市和航班，以及出发城市 <code>src</code> 和目的地 <code>dst</code>，你的任务是找到出一条最多经过 <code>k</code>&nbsp;站中转的路线，使得从 <code>src</code> 到 <code>dst</code> 的 <strong>价格最便宜</strong> ，并返回该价格。 如果不存在这样的路线，则输出 <code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
<strong>输出:</strong> 200
<strong>解释:</strong> 
城市航班图如下
<img style="height: 180px; width: 246px;" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png" alt="">

从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200，如图中红色所示。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
<strong>输出:</strong> 500
<strong>解释:</strong> 
城市航班图如下
<img style="height: 180px; width: 246px;" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png" alt="">

从城市 0 到城市 2 在 0 站中转以内的最便宜价格是 500，如图中蓝色所示。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= flights.length &lt;= (n * (n - 1) / 2)</code></li>
	<li><code>flights[i].length == 3</code></li>
	<li><code>0 &lt;= from<sub>i</sub>, to<sub>i</sub> &lt; n</code></li>
	<li><code>from<sub>i</sub> != to<sub>i</sub></code></li>
	<li><code>1 &lt;= price<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>航班没有重复，且不存在自环</li>
	<li><code>0 &lt;= src, dst, k &lt; n</code></li>
	<li><code>src != dst</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/solution/cheapest-flights-within-k-stops-by-ikaru-128w/)

### 答题
``` C++
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, int> vi;
        vi[src] = 0;

        unordered_map<int, vector<pair<int, int>>> fdic;
        for (auto& f : flights) {
            fdic[f[0]].emplace_back(f[1], f[2]);
        }

        queue<pair<int, int>> que;
        que.push({src, 0});
        while (k-- >= 0) {
            for (int len = (int)que.size(); len > 0; len--) {
                auto [pos, price] = que.front();
                que.pop();

                for (auto [d, p] : fdic[pos]) {
                    if (vi.find(d) != vi.end() && vi[d] <= price + p) continue;
                    vi[d] = price + p;
                    que.push({d, price + p});
                }
            }
        }

        return vi.find(dst) == vi.end() ? -1 : vi[dst];
    }
};
```




