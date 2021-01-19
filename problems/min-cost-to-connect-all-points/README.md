# `（中等）` [1584.min-cost-to-connect-all-points 连接所有点的最小费用](https://leetcode-cn.com/problems/min-cost-to-connect-all-points/)

[contest](https://leetcode-cn.com/contest/weekly-contest-206/problems/min-cost-to-connect-all-points/)

### 题目描述
<p>给你一个<code>points</code>&nbsp;数组，表示 2D 平面上的一些点，其中&nbsp;<code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;。</p>

<p>连接点&nbsp;<code>[x<sub>i</sub>, y<sub>i</sub>]</code> 和点&nbsp;<code>[x<sub>j</sub>, y<sub>j</sub>]</code>&nbsp;的费用为它们之间的 <strong>曼哈顿距离</strong>&nbsp;：<code>|x<sub>i</sub> - x<sub>j</sub>| + |y<sub>i</sub> - y<sub>j</sub>|</code>&nbsp;，其中&nbsp;<code>|val|</code>&nbsp;表示&nbsp;<code>val</code>&nbsp;的绝对值。</p>

<p>请你返回将所有点连接的最小总费用。只有任意两点之间 <strong>有且仅有</strong>&nbsp;一条简单路径时，才认为所有点都已连接。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height:268px; width:214px" src="https://assets.leetcode.com/uploads/2020/08/26/d.png" alt=""></p>

<pre><strong>输入：</strong>points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
<strong>输出：</strong>20
<strong>解释：
</strong><img style="height:268px; width:214px" src="https://assets.leetcode.com/uploads/2020/08/26/c.png" alt="">
我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
注意到任意两个点之间只有唯一一条路径互相到达。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>points = [[3,12],[-2,5],[-4,1]]
<strong>输出：</strong>18
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>points = [[0,0],[1,1],[1,0],[-1,1]]
<strong>输出：</strong>4
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>points = [[-1000000,-1000000],[1000000,1000000]]
<strong>输出：</strong>4000000
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>points = [[0,0]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 1000</code></li>
	<li><code>-10<sup>6</sup>&nbsp;&lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li>所有点&nbsp;<code>(x<sub>i</sub>, y<sub>i</sub>)</code>&nbsp;两两不同。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/min-cost-to-connect-all-points/solution/min-cost-to-connect-by-ikaruga-t7my/)

### 答题
``` C++
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;    
        vector<bool> vi(points.size(), false);
        int n = points.size();
        int ans = 0;
        
        pq.push({0, 0});
        while (!pq.empty() && n > 0) {
            auto [d, p1] = pq.top();
            pq.pop();
            if (vi[p1]) continue;
            
            ans += d;
            vi[p1] = true;
            n--;
            
            for (int p2 = 0; p2 < points.size(); p2++) {
                if (vi[p2]) continue;
                int dis = abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
                pq.push({dis, p2});
            }
        }
        return ans;
    }
};
```




