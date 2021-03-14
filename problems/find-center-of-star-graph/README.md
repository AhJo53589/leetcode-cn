# `（中等）` [5702.find-center-of-star-graph 找出星型图的中心节点](https://leetcode-cn.com/problems/find-center-of-star-graph/)

[contest](https://leetcode-cn.com/contest/weekly-contest-232/problems/find-center-of-star-graph/)

### 题目描述
<div class="notranslate"><p>有一个无向的 <strong>星型</strong> 图，由 <code>n</code> 个编号从 <code>1</code> 到 <code>n</code> 的节点组成。星型图有一个 <strong>中心</strong> 节点，并且恰有 <code>n - 1</code> 条边将中心节点与其他每个节点连接起来。</p>

<p>给你一个二维整数数组 <code>edges</code> ，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示在节点 <code>u<sub>i</sub></code> 和 <code>v<sub>i</sub></code> 之间存在一条边。请你找出并返回&nbsp;<code>edges</code> 所表示星型图的中心节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 331px; height: 321px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/03/14/star_graph.png" alt="">
<pre><strong>输入：</strong>edges = [[1,2],[2,3],[4,2]]
<strong>输出：</strong>2
<strong>解释：</strong>如上图所示，节点 2 与其他每个节点都相连，所以节点 2 是中心节点。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>edges = [[1,2],[5,1],[1,3],[1,4]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 &lt;= u<sub>i,</sub> v<sub>i</sub> &lt;= n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li>题目数据给出的 <code>edges</code> 表示一个有效的星型图</li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) ? edges[0][0] : edges[0][1];
    }
};
```




