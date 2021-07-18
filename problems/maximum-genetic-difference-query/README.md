# `（困难）` [5816.maximum-genetic-difference-query 查询最大基因差](https://leetcode-cn.com/problems/maximum-genetic-difference-query/)

[contest](https://leetcode-cn.com/contest/weekly-contest-250/problems/maximum-genetic-difference-query/)

### 题目描述
<div class="notranslate"><p>给你一棵 <code>n</code>&nbsp;个节点的有根树，节点编号从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。每个节点的编号表示这个节点的 <strong>独一无二的基因值</strong>&nbsp;（也就是说节点 <code>x</code>&nbsp;的基因值为 <code>x</code>）。两个基因值的 <strong>基因差</strong>&nbsp;是两者的 <strong>异或和</strong>&nbsp;。给你整数数组&nbsp;<code>parents</code>&nbsp;，其中&nbsp;<code>parents[i]</code>&nbsp;是节点 <code>i</code>&nbsp;的父节点。如果节点 <code>x</code>&nbsp;是树的 <strong>根</strong>&nbsp;，那么&nbsp;<code>parents[x] == -1</code>&nbsp;。</p>

<p>给你查询数组&nbsp;<code>queries</code>&nbsp;，其中&nbsp;<code>queries[i] = [node<sub>i</sub>, val<sub>i</sub>]</code>&nbsp;。对于查询&nbsp;<code>i</code>&nbsp;，请你找到 <code>val<sub>i</sub></code>&nbsp;和 <code>p<sub>i</sub></code>&nbsp;的 <strong>最大基因差</strong>&nbsp;，其中&nbsp;<code>p<sub>i</sub></code>&nbsp;是节点 <code>node<sub>i</sub></code>&nbsp;到根之间的任意节点（包含 <code>node<sub>i</sub></code>&nbsp;和根节点）。更正式的，你想要最大化&nbsp;<code>val<sub>i</sub> XOR p<sub>i</sub></code><sub>&nbsp;</sub>。</p>

<p>请你返回数组<em>&nbsp;</em><code>ans</code>&nbsp;，其中&nbsp;<code>ans[i]</code>&nbsp;是第 <code>i</code>&nbsp;个查询的答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 118px; height: 163px;" src="https://assets.leetcode.com/uploads/2021/06/29/c1.png" alt="">
<pre><b>输入：</b>parents = [-1,0,1,1], queries = [[0,2],[3,2],[2,5]]
<b>输出：</b>[2,3,7]
<strong>解释：</strong>查询数组处理如下：
- [0,2]：最大基因差的对应节点为 0 ，基因差为 2 XOR 0 = 2 。
- [3,2]：最大基因差的对应节点为 1 ，基因差为 2 XOR 1 = 3 。
- [2,5]：最大基因差的对应节点为 2 ，基因差为 5 XOR 2 = 7 。
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 256px; height: 221px;" src="https://assets.leetcode.com/uploads/2021/06/29/c2.png" alt="">
<pre><b>输入：</b>parents = [3,7,-1,2,0,7,0,2], queries = [[4,6],[1,15],[0,5]]
<b>输出：</b>[6,14,7]
<strong>解释：</strong>查询数组处理如下：
- [4,6]：最大基因差的对应节点为 0 ，基因差为 6 XOR 0 = 6 。
- [1,15]：最大基因差的对应节点为 1 ，基因差为 15 XOR 1 = 14 。
- [0,5]：最大基因差的对应节点为 2 ，基因差为 5 XOR 2 = 7 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= parents.length &lt;= 10<sup>5</sup></code></li>
	<li>对于每个&nbsp;<strong>不是</strong>&nbsp;根节点的&nbsp;<code>i</code>&nbsp;，有&nbsp;<code>0 &lt;= parents[i] &lt;= parents.length - 1</code>&nbsp;。</li>
	<li><code>parents[root] == -1</code></li>
	<li><code>1 &lt;= queries.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= node<sub>i</sub> &lt;= parents.length - 1</code></li>
	<li><code>0 &lt;= val<sub>i</sub> &lt;= 2 * 10<sup>5</sup></code></li>
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
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {

    }
};
```




