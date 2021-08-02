# `（中等）` [743.network-delay-time 网络延迟时间](https://leetcode-cn.com/problems/network-delay-time/)

### 题目描述
<p>有 <code>n</code> 个网络节点，标记为&nbsp;<code>1</code>&nbsp;到 <code>n</code>。</p>

<p>给你一个列表&nbsp;<code>times</code>，表示信号经过 <strong>有向</strong> 边的传递时间。&nbsp;<code>times[i] = (u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>)</code>，其中&nbsp;<code>u<sub>i</sub></code>&nbsp;是源节点，<code>v<sub>i</sub></code>&nbsp;是目标节点， <code>w<sub>i</sub></code>&nbsp;是一个信号从源节点传递到目标节点的时间。</p>

<p>现在，从某个节点&nbsp;<code>K</code>&nbsp;发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回&nbsp;<code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 220px; width: 200px;" src="https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png" alt=""></p>

<pre><strong>输入：</strong>times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>times = [[1,2,1]], n = 2, k = 1
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>times = [[1,2,1]], n = 2, k = 2
<strong>输出：</strong>-1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= times.length &lt;= 6000</code></li>
	<li><code>times[i].length == 3</code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>0 &lt;= w<sub>i</sub> &lt;= 100</code></li>
	<li>所有 <code>(u<sub>i</sub>, v<sub>i</sub>)</code> 对都 <strong>互不相同</strong>（即，不含重复边）</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> paths(n, vector<int>(n, -1));
        vector<int> vi(n, INT_MAX);

        for (auto &t : times) {
            paths[t[0] - 1][t[1] - 1] = t[2];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k - 1});
        vi[k - 1] = 0;

        while (!pq.empty()) {
            auto [t, n] = pq.top();
            pq.pop();

            for (int i = 0; i < paths[n].size(); i++) {
                if (paths[n][i] == -1) continue;
                int time = t + paths[n][i];
                if (time >= vi[i]) continue;
                pq.push({time, i});
                vi[i] = time;
            }
        }

        bool fin = true;
        int ans = 0;
        for (auto v : vi) {
            if (v == INT_MAX) {
                fin = false;
                break;
            }
            ans = max(ans, v);
        }
        return fin ? ans : -1;
    }
};
```




