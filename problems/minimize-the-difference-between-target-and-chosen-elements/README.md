# `（中等）` [5852.minimize-the-difference-between-target-and-chosen-elements 最小化目标值与所选元素的差](https://leetcode-cn.com/problems/minimize-the-difference-between-target-and-chosen-elements/)

[contest](https://leetcode-cn.com/contest/weekly-contest-255/problems/minimize-the-difference-between-target-and-chosen-elements/)

### 题目描述
<div class="notranslate"><p>给你一个大小为 <code>m x n</code> 的整数矩阵 <code>mat</code> 和一个整数 <code>target</code> 。</p>

<p>从矩阵的 <strong>每一行</strong> 中选择一个整数，你的目标是&nbsp;<strong>最小化</strong>&nbsp;所有选中元素之&nbsp;<strong>和</strong>&nbsp;与目标值 <code>target</code> 的 <strong>绝对差</strong> 。</p>

<p>返回 <strong>最小的绝对差</strong> 。</p>

<p><code>a</code> 和 <code>b</code> 两数字的 <strong>绝对差</strong> 是 <code>a - b</code> 的绝对值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="width: 181px; height: 181px;" src="https://assets.leetcode.com/uploads/2021/08/03/matrix1.png" alt=""></p>

<pre><strong>输入：</strong>mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
<strong>输出：</strong>0
<strong>解释：</strong>一种可能的最优选择方案是：
- 第一行选出 1
- 第二行选出 5
- 第三行选出 7
所选元素的和是 13 ，等于目标值，所以绝对差是 0 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="width: 61px; height: 181px;" src="https://assets.leetcode.com/uploads/2021/08/03/matrix1-1.png" alt=""></p>

<pre><strong>输入：</strong>mat = [[1],[2],[3]], target = 100
<strong>输出：</strong>94
<strong>解释：</strong>唯一一种选择方案是：
- 第一行选出 1
- 第二行选出 2
- 第三行选出 3
所选元素的和是 6 ，绝对差是 94 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img style="width: 301px; height: 61px;" src="https://assets.leetcode.com/uploads/2021/08/03/matrix1-3.png" alt=""></p>

<pre><strong>输入：</strong>mat = [[1,2,9,8,7]], target = 6
<strong>输出：</strong>1
<strong>解释：</strong>最优的选择方案是选出第一行的 7 。
绝对差是 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 70</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 70</code></li>
	<li><code>1 &lt;= target &lt;= 800</code></li>
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
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {

    }
};
```




