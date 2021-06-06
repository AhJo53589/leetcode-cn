# `（困难）` [5779.minimum-space-wasted-from-packaging 装包裹的最小浪费空间](https://leetcode-cn.com/problems/minimum-space-wasted-from-packaging/)

[contest](https://leetcode-cn.com/contest/weekly-contest-244/problems/minimum-space-wasted-from-packaging/)

### 题目描述
<div class="notranslate"><p>给你&nbsp;<code>n</code>&nbsp;个包裹，你需要把它们装在箱子里，<strong>每个箱子装一个包裹</strong>。总共有&nbsp;<code>m</code>&nbsp;个供应商提供 <strong>不同尺寸</strong>&nbsp;的箱子（每个规格都有无数个箱子）。如果一个包裹的尺寸 <strong>小于等于</strong>&nbsp;一个箱子的尺寸，那么这个包裹就可以放入这个箱子之中。</p>

<p>包裹的尺寸用一个整数数组&nbsp;<code>packages</code>&nbsp;表示，其中&nbsp;<code>packages[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个包裹的尺寸。供应商用二维数组&nbsp;<code>boxes</code>&nbsp;表示，其中&nbsp;<code>boxes[j]</code>&nbsp;是第 <code>j</code>&nbsp;个供应商提供的所有箱子尺寸的数组。</p>

<p>你想要选择 <strong>一个供应商</strong>&nbsp;并只使用该供应商提供的箱子，使得 <strong>总浪费空间最小</strong>&nbsp;。对于每个装了包裹的箱子，我们定义 <strong>浪费的</strong>&nbsp;空间等于 <code>箱子的尺寸 - 包裹的尺寸</code>&nbsp;。<strong>总浪费空间</strong>&nbsp;为&nbsp;<strong>所有</strong>&nbsp;箱子中浪费空间的总和。</p>

<ul>
	<li>比方说，如果你想要用尺寸数组为&nbsp;<code>[4,8]</code>&nbsp;的箱子装下尺寸为&nbsp;<code>[2,3,5]</code>&nbsp;的包裹，你可以将尺寸为 <code>2</code>&nbsp;和 <code>3</code>&nbsp;的两个包裹装入两个尺寸为 <code>4</code>&nbsp;的箱子中，同时把尺寸为 <code>5</code>&nbsp;的包裹装入尺寸为 <code>8</code>&nbsp;的箱子中。总浪费空间为&nbsp;<code>(4-2) + (4-3) + (8-5) = 6</code>&nbsp;。</li>
</ul>

<p>请你选择 <strong>最优</strong>&nbsp;箱子供应商，使得 <strong>总浪费空间最小</strong>&nbsp;。如果 <strong>无法</strong> 将所有包裹放入箱子中，请你返回 <code>-1</code>&nbsp;。由于答案可能会 <strong>很大</strong>&nbsp;，请返回它对<strong>&nbsp;</strong><code>10<sup>9</sup> + 7</code>&nbsp;<b>取余</b>&nbsp;的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>packages = [2,3,5], boxes = [[4,8],[2,8]]
<b>输出：</b>6
<b>解释：</b>选择第一个供应商最优，用两个尺寸为 4 的箱子和一个尺寸为 8 的箱子。
总浪费空间为 (4-2) + (4-3) + (8-5) = 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>packages = [2,3,5], boxes = [[1,4],[2,3],[3,4]]
<b>输出：</b>-1
<b>解释：</b>没有箱子能装下尺寸为 5 的包裹。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>packages = [3,5,8,10,11,12], boxes = [[12],[11,9],[10,5,14]]
<b>输出：</b>9
<b>解释：</b>选择第三个供应商最优，用两个尺寸为 5 的箱子，两个尺寸为 10 的箱子和两个尺寸为 14 的箱子。
总浪费空间为 (5-3) + (5-5) + (10-8) + (10-10) + (14-11) + (14-12) = 9 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == packages.length</code></li>
	<li><code>m == boxes.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= packages[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= boxes[j].length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= boxes[j][k] &lt;= 10<sup>5</sup></code></li>
	<li><code>sum(boxes[j].length) &lt;= 10<sup>5</sup></code></li>
	<li><code>boxes[j]</code>&nbsp;中的元素 <strong>互不相同</strong>&nbsp;。</li>
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
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {

    }
};
```




