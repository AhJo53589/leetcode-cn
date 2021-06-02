# `（困难）` [1703.minimum-adjacent-swaps-for-k-consecutive-ones 得到连续 K 个 1 的最少相邻交换次数](https://leetcode-cn.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-42/problems/minimum-adjacent-swaps-for-k-consecutive-ones/)

### 题目描述
<div class="notranslate"><p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。&nbsp;<code>nums</code> 仅包含&nbsp;<code>0</code>&nbsp;和&nbsp;<code>1</code>&nbsp;。每一次移动，你可以选择 <strong>相邻</strong>&nbsp;两个数字并将它们交换。</p>

<p>请你返回使&nbsp;<code>nums</code>&nbsp;中包含&nbsp;<code>k</code>&nbsp;个 <strong>连续&nbsp;</strong><code>1</code>&nbsp;的 <strong>最少</strong>&nbsp;交换次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,0,0,1,0,1], k = 2
<b>输出：</b>1
<b>解释：</b>在第一次操作时，nums 可以变成 [1,0,0,0,<strong>1</strong>,<strong>1</strong>] 得到连续两个 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,0,0,0,0,0,1,1], k = 3
<b>输出：</b>5
<b>解释：</b>通过 5 次操作，最左边的 1 可以移到右边直到 nums 变为 [0,0,0,0,0,<strong>1</strong>,<strong>1</strong>,<strong>1</strong>] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [1,1,0,1], k = 2
<b>输出：</b>0
<b>解释：</b>nums 已经有连续 2 个 1 了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> 要么是&nbsp;<code>0</code>&nbsp;，要么是&nbsp;<code>1</code>&nbsp;。</li>
	<li><code>1 &lt;= k &lt;= sum(nums)</code></li>
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
    int minMoves(vector<int>& nums, int k) {

    }
};
```




