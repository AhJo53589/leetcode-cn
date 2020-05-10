# `（中等）` [5406.minimum-time-to-collect-all-apples-in-a-tree 收集树上所有苹果的最少时间](https://leetcode-cn.com/problems/minimum-time-to-collect-all-apples-in-a-tree/)

[contest](https://leetcode-cn.com/contest/weekly-contest-188/problems/minimum-time-to-collect-all-apples-in-a-tree/)

### 题目描述
<p>给你一棵有&nbsp;<code>n</code>&nbsp;个节点的无向树，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n-1</code>&nbsp;，它们中有一些节点有苹果。通过树上的一条边，需要花费 1 秒钟。你从&nbsp;<strong>节点 0&nbsp;</strong>出发，请你返回最少需要多少秒，可以收集到所有苹果，并回到节点 0 。</p>

<p>无向树的边由&nbsp;<code>edges</code>&nbsp;给出，其中&nbsp;<code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>]</code>&nbsp;，表示有一条边连接&nbsp;<code>from</code>&nbsp;和&nbsp;<code>to<sub>i</sub></code> 。除此以外，还有一个布尔数组&nbsp;<code>hasApple</code> ，其中&nbsp;<code>hasApple[i] = true</code>&nbsp;代表节点&nbsp;<code>i</code>&nbsp;有一个苹果，否则，节点&nbsp;<code>i</code>&nbsp;没有苹果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="height: 212px; width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/10/min_time_collect_apple_1.png" alt=""></strong></p>

<pre><strong>输入：</strong>n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
<strong>输出：</strong>8 
<strong>解释：</strong>上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img style="height: 212px; width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/10/min_time_collect_apple_2.png" alt=""></strong></p>

<pre><strong>输入：</strong>n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
<strong>输出：</strong>6
<strong>解释：</strong>上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 10^5</code></li>
	<li><code>edges.length == n-1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 <= from<sub>i</sub>, to<sub>i</sub> <= n-1</code></li>
	<li><code>from<sub>i</sub>&nbsp;< to<sub>i</sub></code></li>
	<li><code>hasApple.length == n</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-time-to-collect-all-apples-in-a-tree/solution/minimum-time-to-collect-all-apples-in-a-tree-by-ik/)

### 答题
``` C++
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> ft(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            ft[edges[i][0]].push_back(edges[i][1]);
        }

        int ans = 0;
        minTime(0, ft, hasApple, ans);
        return ans;
    }

    bool minTime(int from, vector<vector<int>>& ft, vector<bool>& hasApple, int& ans) {
        bool ha = hasApple[from];
        for (auto& to : ft[from]) {
            if (minTime(to, ft, hasApple, ans)) {
                ha = true;
            }
        }
        ans += (ha && from != 0) ? 2 : 0;
        return ha;
    }
};
```




