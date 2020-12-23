# `（困难）` [1617.count-subtrees-with-max-distance-between-cities 统计子树中城市之间最大距离](https://leetcode-cn.com/problems/count-subtrees-with-max-distance-between-cities/)

[contest](https://leetcode-cn.com/contest/weekly-contest-210/problems/count-subtrees-with-max-distance-between-cities/)

### 题目描述
<p>给你&nbsp;<code>n</code>&nbsp;个城市，编号为从&nbsp;<code>1</code> 到&nbsp;<code>n</code>&nbsp;。同时给你一个大小为&nbsp;<code>n-1</code>&nbsp;的数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code>&nbsp;表示城市&nbsp;<code>u<sub>i</sub></code>&nbsp;和&nbsp;<code>v<sub>i</sub></code><sub>&nbsp;</sub>之间有一条双向边。题目保证任意城市之间只有唯一的一条路径。换句话说，所有城市形成了一棵&nbsp;<strong>树</strong>&nbsp;。</p>

<p>一棵&nbsp;<strong>子树</strong>&nbsp;是城市的一个子集，且子集中任意城市之间可以通过子集中的其他城市和边到达。两个子树被认为不一样的条件是至少有一个城市在其中一棵子树中存在，但在另一棵子树中不存在。</p>

<p>对于&nbsp;<code>d</code>&nbsp;从&nbsp;<code>1</code> 到&nbsp;<code>n-1</code>&nbsp;，请你找到城市间&nbsp;<strong>最大距离</strong>&nbsp;恰好为 <code>d</code>&nbsp;的所有子树数目。</p>

<p>请你返回一个大小为&nbsp;<code>n-1</code>&nbsp;的数组，其中第<em>&nbsp;</em><code>d</code><em>&nbsp;</em>个元素（<strong>下标从 1 开始</strong>）是城市间 <strong>最大距离</strong> 恰好等于&nbsp;<code>d</code>&nbsp;的子树数目。</p>

<p><strong>请注意</strong>，两个城市间距离定义为它们之间需要经过的边的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="width: 161px; height: 181px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/11/p1.png" alt=""></strong></p>

<pre><b>输入：</b>n = 4, edges = [[1,2],[2,3],[2,4]]
<b>输出：</b>[3,4,0]
<strong>解释：
</strong>子树 {1,2}, {2,3} 和 {2,4} 最大距离都是 1 。
子树 {1,2,3}, {1,2,4}, {2,3,4} 和 {1,2,3,4} 最大距离都为 2 。
不存在城市间最大距离为 3 的子树。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 2, edges = [[1,2]]
<b>输出：</b>[1]
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>n = 3, edges = [[1,2],[2,3]]
<b>输出：</b>[2,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 15</code></li>
	<li><code>edges.length == n-1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 <= u<sub>i</sub>, v<sub>i</sub> <= n</code></li>
	<li>题目保证&nbsp;<code>(u<sub>i</sub>, v<sub>i</sub>)</code>&nbsp;所表示的边互不相同。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {

    }
};
```




