# `（困难）` [5683.count-pairs-of-nodes 统计点对的数目](https://leetcode-cn.com/problems/count-pairs-of-nodes/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-47/problems/count-pairs-of-nodes/)

### 题目描述
<div class="notranslate"><p>给你一个无向图，无向图由整数&nbsp;<code>n</code>&nbsp;&nbsp;，表示图中节点的数目，和&nbsp;<code>edges</code>&nbsp;组成，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code>&nbsp;表示&nbsp;<code>u<sub>i</sub></code> 和&nbsp;<code>v<sub>i</sub></code><sub>&nbsp;</sub>之间有一条无向边。同时给你一个代表查询的整数数组&nbsp;<code>queries</code>&nbsp;。</p>

<p>第 <code>j</code> 个查询的答案是满足如下条件的点对 <code>(a, b)</code> 的数目：</p>

<ul>
	<li><code>a &lt; b</code></li>
	<li><code>cnt</code>&nbsp;是与 <code>a</code>&nbsp;<strong>或者&nbsp;</strong><code>b</code>&nbsp;相连的边的数目，且 <code>cnt</code>&nbsp;<strong>严格大于&nbsp;</strong><code>queries[j]</code>&nbsp;。</li>
</ul>

<p>请你返回一个数组&nbsp;<code>answers</code>&nbsp;，其中&nbsp;<code>answers.length == queries.length</code> 且&nbsp;<code>answers[j]</code>&nbsp;是第 <code>j</code>&nbsp;个查询的答案。</p>

<p>请注意，图中可能会有 <strong>重复边</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 310px; height: 278px;" src="https://pic.leetcode-cn.com/1614828447-GMnLVg-image.png" alt="">
<pre><b>输入：</b>n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
<b>输出：</b>[6,5]
<b>解释：</b>每个点对中，与至少一个点相连的边的数目如上图所示。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],[2,3],[2,5]], queries = [1,2,3,4,5]
<b>输出：</b>[10,10,9,8,6]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= edges.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li><code>u<sub>i </sub>!= v<sub>i</sub></code></li>
	<li><code>1 &lt;= queries.length &lt;= 20</code></li>
	<li><code>0 &lt;= queries[j] &lt; edges.length</code></li>
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
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {

    }
};
```




