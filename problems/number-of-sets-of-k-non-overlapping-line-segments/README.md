# `（中等）` [1621.number-of-sets-of-k-non-overlapping-line-segments 大小为 K 的不重叠线段的数目](https://leetcode-cn.com/problems/number-of-sets-of-k-non-overlapping-line-segments/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-37/problems/number-of-sets-of-k-non-overlapping-line-segments/)

### 题目描述
<p>给你一维空间的&nbsp;<code>n</code>&nbsp;个点，其中第&nbsp;<code>i</code>&nbsp;个点（编号从&nbsp;<code>0</code> 到&nbsp;<code>n-1</code>）位于&nbsp;<code>x = i</code>&nbsp;处，请你找到&nbsp;<strong>恰好</strong>&nbsp;<code>k</code>&nbsp;<strong>个不重叠</strong>&nbsp;线段且每个线段至少覆盖两个点的方案数。线段的两个端点必须都是&nbsp;<strong>整数坐标</strong>&nbsp;。这&nbsp;<code>k</code>&nbsp;个线段不需要全部覆盖全部&nbsp;<code>n</code>&nbsp;个点，且它们的端点&nbsp;<strong>可以&nbsp;</strong>重合。</p>

<p>请你返回 <code>k</code>&nbsp;个不重叠线段的方案数。由于答案可能很大，请将结果对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong> 后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 179px; height: 222px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/17/ex1.png" alt="">
<pre><b>输入：</b>n = 4, k = 2
<b>输出：</b>5
<strong>解释：
</strong>如图所示，两个线段分别用红色和蓝色标出。
上图展示了 5 种不同的方案 {(0,2),(2,3)}，{(0,1),(1,3)}，{(0,1),(2,3)}，{(1,2),(2,3)}，{(0,1),(1,2)} 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 3, k = 1
<b>输出：</b>3
<strong>解释：</strong>总共有 3 种不同的方案 {(0,1)}, {(0,2)}, {(1,2)} 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>n = 30, k = 7
<b>输出：</b>796297179
<strong>解释：</strong>画 7 条线段的总方案数为 3796297200 种。将这个数对 10<sup>9</sup> + 7 取余得到 796297179 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>n = 5, k = 3
<b>输出：</b>7
</pre>

<p><strong>示例 5：</strong></p>

<pre><b>输入：</b>n = 3, k = 2
<b>输出：</b>1</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= n-1</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int numberOfSets(int n, int k) {

    }
};
```




