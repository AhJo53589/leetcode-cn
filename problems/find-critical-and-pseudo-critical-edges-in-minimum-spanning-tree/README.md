# `（困难）` [1489.find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree 找到最小生成树里的关键边和伪关键边](https://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/)

[contest](https://leetcode-cn.com/contest/weekly-contest-194/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/)

### 题目描述

              <p>给你一个 <code>n</code>&nbsp;个点的带权无向连通图，节点编号为 <code>0</code>&nbsp;到 <code>n-1</code>&nbsp;，同时还有一个数组 <code>edges</code>&nbsp;，其中 <code>edges[i] = [from</code><code><sub>i</sub>, to<sub>i</sub>, weight<sub>i</sub>]</code>&nbsp;表示在&nbsp;<code>from<sub>i</sub></code>&nbsp;和&nbsp;<code>to<sub>i</sub></code>&nbsp;节点之间有一条带权无向边。最小生成树&nbsp;(MST) 是给定图中边的一个子集，它连接了所有节点且没有环，而且这些边的权值和最小。</p>

<p>请你找到给定图中最小生成树的所有关键边和伪关键边。如果最小生成树中删去某条边，会导致最小生成树的权值和增加，那么我们就说它是一条关键边。伪关键边则是可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。</p>

<p>请注意，你可以分别以任意顺序返回关键边的下标和伪关键边的下标。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/06/21/ex1.png" style="height: 262px; width: 259px;"></p>

<pre><strong>输入：</strong>n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
<strong>输出：</strong>[[0,1],[2,3,4,5]]
<strong>解释：</strong>上图描述了给定图。
下图是所有的最小生成树。
<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/06/21/msts.png" style="height: 553px; width: 540px;">
注意到第 0 条边和第 1 条边出现在了所有最小生成树中，所以它们是关键边，我们将这两个下标作为输出的第一个列表。
边 2，3，4 和 5 是所有 MST 的剩余边，所以它们是伪关键边。我们将它们作为输出的第二个列表。
</pre>

<p><strong>示例 2 ：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/06/21/ex2.png" style="height: 253px; width: 247px;"></p>

<pre><strong>输入：</strong>n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
<strong>输出：</strong>[[],[0,1,2,3]]
<strong>解释：</strong>可以观察到 4 条边都有相同的权值，任选它们中的 3 条可以形成一棵 MST 。所以 4 条边都是伪关键边。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= edges.length &lt;= min(200, n * (n - 1) / 2)</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= from<sub>i</sub> &lt; to<sub>i</sub> &lt; n</code></li>
	<li><code>1 &lt;= weight<sub>i</sub>&nbsp;&lt;= 1000</code></li>
	<li>所有 <code>(from<sub>i</sub>, to<sub>i</sub>)</code>&nbsp;数对都是互不相同的。</li>
</ul>



---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

    }
};
```




