# `（困难）` [5619.minimum-incompatibility 最小不兼容性](https://leetcode-cn.com/problems/minimum-incompatibility/)

[contest](https://leetcode-cn.com/contest/weekly-contest-218/problems/minimum-incompatibility/)

### 题目描述
<div class="notranslate"><p>给你一个整数数组&nbsp;<code>nums</code>​​​ 和一个整数&nbsp;<code>k</code>&nbsp;。你需要将这个数组划分到&nbsp;<code>k</code>&nbsp;个相同大小的子集中，使得同一个子集里面没有两个相同的元素。</p>

<p>一个子集的 <strong>不兼容性</strong>&nbsp;是该子集里面最大值和最小值的差。</p>

<p>请你返回将数组分成 <code>k</code>&nbsp;个子集后，各子集 <strong>不兼容性 </strong>的<strong> 和</strong>&nbsp;的 <strong>最小值</strong>&nbsp;，如果无法分成分成 <code>k</code>&nbsp;个子集，返回 <code>-1</code>&nbsp;。</p>

<p>子集的定义是数组中一些数字的集合，对数字顺序没有要求。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,2,1,4], k = 2
<b>输出：</b>4
<b>解释：</b>最优的分配是 [1,2] 和 [1,4] 。
不兼容性和为 (2-1) + (4-1) = 4 。
注意到 [1,1] 和 [2,4] 可以得到更小的和，但是第一个集合有 2 个相同的元素，所以不可行。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [6,3,8,1,3,1,2,2], k = 4
<b>输出：</b>6
<b>解释：</b>最优的子集分配为 [1,2]，[2,3]，[6,8] 和 [1,3] 。
不兼容性和为 (2-1) + (3-2) + (8-6) + (3-1) = 6 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [5,3,3,6,3,3], k = 3
<b>输出：</b>-1
<b>解释：</b>没办法将这些数字分配到 3 个子集且满足每个子集里没有相同数字。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 16</code></li>
	<li><code>nums.length</code> 能被&nbsp;<code>k</code> 整除。</li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
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
    int minimumIncompatibility(vector<int>& nums, int k) {

    }
};
```




