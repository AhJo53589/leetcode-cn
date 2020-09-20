# `（困难）` [5522.minimum-cost-to-connect-two-groups-of-points 连通两组点的最小成本](https://leetcode-cn.com/problems/minimum-cost-to-connect-two-groups-of-points/)

[contest](https://leetcode-cn.com/contest/weekly-contest-207/problems/minimum-cost-to-connect-two-groups-of-points/)

### 题目描述
<p>给你两组点，其中第一组中有 <code>size<sub>1</sub></code> 个点，第二组中有 <code>size<sub>2</sub></code> 个点，且 <code>size<sub>1</sub> >= size<sub>2</sub></code> 。</p>

<p>任意两点间的连接成本 <code>cost</code> 由大小为 <code>size<sub>1</sub> x size<sub>2</sub></code> 矩阵给出，其中 <code>cost[i][j]</code> 是第一组中的点 <code>i</code> 和第二组中的点 <code>j</code> 的连接成本。<strong>如果两个组中的每个点都与另一组中的一个或多个点连接，则称这两组点是连通的。</strong>换言之，第一组中的每个点必须至少与第二组中的一个点连接，且第二组中的每个点必须至少与第一组中的一个点连接。</p>

<p>返回连通两组点所需的最小成本。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 243px; width: 322px;" src="https://assets.leetcode.com/uploads/2020/09/03/ex1.jpg" alt=""></p>

<pre><strong>输入：</strong>cost = [[15, 96], [36, 2]]
<strong>输出：</strong>17
<strong>解释：</strong>连通两组点的最佳方法是：
1--A
2--B
总成本为 17 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="height: 403px; width: 322px;" src="https://assets.leetcode.com/uploads/2020/09/03/ex2.jpg" alt=""></p>

<pre><strong>输入：</strong>cost = [[1, 3, 5], [4, 1, 1], [1, 5, 3]]
<strong>输出：</strong>4
<strong>解释：</strong>连通两组点的最佳方法是：
1--A
2--B
2--C
3--A
最小成本为 4 。
请注意，虽然有多个点连接到第一组中的点 2 和第二组中的点 A ，但由于题目并不限制连接点的数目，所以只需要关心最低总成本。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>cost = [[2, 5, 1], [3, 4, 7], [8, 1, 2], [6, 2, 4], [3, 8, 8]]
<strong>输出：</strong>10
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>size<sub>1</sub> == cost.length</code></li>
	<li><code>size<sub>2</sub> == cost[i].length</code></li>
	<li><code>1 <= size<sub>1</sub>, size<sub>2</sub> <= 12</code></li>
	<li><code>size<sub>1</sub> >=&nbsp;size<sub>2</sub></code></li>
	<li><code>0 <= cost[i][j] <= 100</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {

    }
};
```




