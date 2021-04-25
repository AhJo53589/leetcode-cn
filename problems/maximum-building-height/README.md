# `（困难）` [5741.maximum-building-height 最高建筑高度](https://leetcode-cn.com/problems/maximum-building-height/)

[contest](https://leetcode-cn.com/contest/weekly-contest-238/problems/maximum-building-height/)

### 题目描述
<p>在一座城市里，你需要建&nbsp;<code>n</code>&nbsp;栋新的建筑。这些新的建筑会从 <code>1</code>&nbsp;到 <code>n</code>&nbsp;编号排成一列。</p>

<p>这座城市对这些新建筑有一些规定：</p>

<ul>
	<li>每栋建筑的高度必须是一个非负整数。</li>
	<li>第一栋建筑的高度 <strong>必须</strong>&nbsp;是&nbsp;<code>0</code>&nbsp;。</li>
	<li>任意两栋相邻建筑的高度差 <strong>不能超过</strong>&nbsp;&nbsp;<code>1</code>&nbsp;。</li>
</ul>

<p>除此以外，某些建筑还有额外的最高高度限制。这些限制会以二维整数数组&nbsp;<code>restrictions</code>&nbsp;的形式给出，其中&nbsp;<code>restrictions[i] = [id<sub>i</sub>, maxHeight<sub>i</sub>]</code>&nbsp;，表示建筑&nbsp;<code>id<sub>i</sub></code>&nbsp;的高度 <strong>不能超过</strong>&nbsp;<code>maxHeight<sub>i</sub></code>&nbsp;。</p>

<p>题目保证每栋建筑在 <code>restrictions</code>&nbsp;中<strong>&nbsp;至多出现一次</strong>&nbsp;，同时建筑 <code>1</code>&nbsp;<strong>不会</strong>&nbsp;出现在&nbsp;<code>restrictions</code>&nbsp;中。</p>

<p>请你返回 <strong>最高</strong>&nbsp;建筑能达到的 <strong>最高高度</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 400px; height: 253px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/04/25/ic236-q4-ex1-1.png" alt="">
<pre><b>输入：</b>n = 5, restrictions = [[2,1],[4,1]]
<b>输出：</b>2
<b>解释：</b>上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,1,2] ，最高建筑的高度为 2 。</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 500px; height: 269px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/04/25/ic236-q4-ex2.png" alt="">
<pre><b>输入：</b>n = 6, restrictions = []
<b>输出：</b>5
<b>解释：</b>上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,3,4,5] ，最高建筑的高度为 5 。
</pre>

<p><strong>示例 3：</strong></p>
<img style="width: 500px; height: 187px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/04/25/ic236-q4-ex3.png" alt="">
<pre><b>输入：</b>n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
<b>输出：</b>5
<b>解释：</b>上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,3,3,4,4,5,4,3] ，最高建筑的高度为 5 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= restrictions.length &lt;= min(n - 1, 10<sup>5</sup>)</code></li>
	<li><code>2 &lt;= id<sub>i</sub> &lt;= n</code></li>
	<li><code>id<sub>i</sub></code>&nbsp;是 <strong>唯一的</strong>&nbsp;。</li>
	<li><code>0 &lt;= maxHeight<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

    }
};
```




