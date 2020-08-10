# `（困难）` [1499.max-value-of-equation 满足不等式的最大值](https://leetcode-cn.com/problems/max-value-of-equation/)

[contest](https://leetcode-cn.com/contest/weekly-contest-195/problems/max-value-of-equation/)

### 题目描述
<p>给你一个数组 <code>points</code> 和一个整数 <code>k</code> 。数组中每个元素都表示二维平面上的点的坐标，并按照横坐标 x 的值从小到大排序。也就是说 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> ，并且在 <code>1 <= i < j <= points.length</code> 的前提下， <code>x<sub>i</sub> < x<sub>j</sub></code> 总成立。</p>

<p>请你找出<em> </em><code>y<sub>i</sub>&nbsp;+ y<sub>j</sub>&nbsp;+ |x<sub>i</sub>&nbsp;- x<sub>j</sub>|</code> 的 <strong>最大值</strong>，其中 <code>|x<sub>i</sub>&nbsp;- x<sub>j</sub>|&nbsp;<= k</code> 且 <code>1 <= i < j <= points.length</code>。</p>

<p>题目测试数据保证至少存在一对能够满足 <code>|x<sub>i</sub>&nbsp;- x<sub>j</sub>|&nbsp;<= k</code> 的点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
<strong>输出：</strong>4
<strong>解释：</strong>前两个点满足 |x<sub>i</sub>&nbsp;- x<sub>j</sub>| <= 1 ，带入方程计算，则得到值 3 + 0 + |1 - 2| = 4 。第三个和第四个点也满足条件，得到值 10 + -10 + |5 - 6| = 1 。
没有其他满足条件的点，所以返回 4 和 1 中最大的那个。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>points = [[0,0],[3,0],[9,2]], k = 3
<strong>输出：</strong>3
<strong>解释：</strong>只有前两个点满足 |x<sub>i</sub>&nbsp;- x<sub>j</sub>| <= 3 ，带入方程后得到值 0 + 0 + |0 - 3| = 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= points.length <= 10^5</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10^8&nbsp;<= points[i][0], points[i][1] <= 10^8</code></li>
	<li><code>0 <= k <= 2 * 10^8</code></li>
	<li>对于所有的<code>1 <= i < j <= points.length</code> ，<code>points[i][0] < points[j][0]</code> 都成立。也就是说，<code>x<sub>i</sub></code> 是严格递增的。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {

    }
};
```




