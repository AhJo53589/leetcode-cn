# `（困难）` [1649.create-sorted-array-through-instructions 通过指令创建有序数组](https://leetcode-cn.com/problems/create-sorted-array-through-instructions/)

[contest](https://leetcode-cn.com/contest/weekly-contest-214/problems/create-sorted-array-through-instructions/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>instructions</code>&nbsp;，你需要根据&nbsp;<code>instructions</code>&nbsp;中的元素创建一个有序数组。一开始你有一个空的数组&nbsp;<code>nums</code>&nbsp;，你需要&nbsp;<strong>从左到右</strong>&nbsp;遍历&nbsp;<code>instructions</code>&nbsp;中的元素，将它们依次插入&nbsp;<code>nums</code>&nbsp;数组中。每一次插入操作的&nbsp;<strong>代价</strong>&nbsp;是以下两者的 <strong>较小值</strong>&nbsp;：</p>

<ul>
	<li><code>nums</code>&nbsp;中 <strong>严格小于&nbsp;</strong>&nbsp;<code>instructions[i]</code>&nbsp;的数字数目。</li>
	<li><code>nums</code>&nbsp;中 <strong>严格大于&nbsp;</strong>&nbsp;<code>instructions[i]</code>&nbsp;的数字数目。</li>
</ul>

<p>比方说，如果要将&nbsp;<code>3</code> 插入到&nbsp;<code>nums = [1,2,3,5]</code>&nbsp;，那么插入操作的&nbsp;<strong>代价</strong>&nbsp;为&nbsp;<code>min(2, 1)</code> (元素&nbsp;<code>1</code>&nbsp;和&nbsp;&nbsp;<code>2</code>&nbsp;小于&nbsp;<code>3</code>&nbsp;，元素&nbsp;<code>5</code>&nbsp;大于&nbsp;<code>3</code>&nbsp;），插入后&nbsp;<code>nums</code> 变成&nbsp;<code>[1,2,3,3,5]</code>&nbsp;。</p>

<p>请你返回将&nbsp;<code>instructions</code>&nbsp;中所有元素依次插入&nbsp;<code>nums</code>&nbsp;后的 <strong>总最小代价&nbsp;</strong>。由于答案会很大，请将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<b>取余</b>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>instructions = [1,5,6,2]
<b>输出：</b>1
<b>解释：</b>一开始 nums = [] 。
插入 1 ，代价为 min(0, 0) = 0 ，现在 nums = [1] 。
插入 5 ，代价为 min(1, 0) = 0 ，现在 nums = [1,5] 。
插入 6 ，代价为 min(2, 0) = 0 ，现在 nums = [1,5,6] 。
插入 2 ，代价为 min(1, 2) = 1 ，现在 nums = [1,2,5,6] 。
总代价为 0 + 0 + 0 + 1 = 1 。</pre>

<p><strong>示例 2:</strong></p>

<pre><b>输入：</b>instructions = [1,2,3,6,5,4]
<b>输出：</b>3
<b>解释：</b>一开始 nums = [] 。
插入 1 ，代价为 min(0, 0) = 0 ，现在 nums = [1] 。
插入 2 ，代价为 min(1, 0) = 0 ，现在 nums = [1,2] 。
插入 3 ，代价为 min(2, 0) = 0 ，现在 nums = [1,2,3] 。
插入 6 ，代价为 min(3, 0) = 0 ，现在 nums = [1,2,3,6] 。
插入 5 ，代价为 min(3, 1) = 1 ，现在 nums = [1,2,3,5,6] 。
插入 4 ，代价为 min(3, 2) = 2 ，现在 nums = [1,2,3,4,5,6] 。
总代价为 0 + 0 + 0 + 0 + 1 + 2 = 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>instructions = [1,3,3,3,2,4,2,1,2]
<b>输出：</b>4
<b>解释：</b>一开始 nums = [] 。
插入 1 ，代价为 min(0, 0) = 0 ，现在 nums = [1] 。
插入 3 ，代价为 min(1, 0) = 0 ，现在 nums = [1,3] 。
插入 3 ，代价为 min(1, 0) = 0 ，现在 nums = [1,3,3] 。
插入 3 ，代价为 min(1, 0) = 0 ，现在 nums = [1,3,3,3] 。
插入 2 ，代价为 min(1, 3) = 1 ，现在 nums = [1,2,3,3,3] 。
插入 4 ，代价为 min(5, 0) = 0 ，现在 nums = [1,2,3,3,3,4] 。
​​​​​插入 2 ，代价为 min(1, 4) = 1 ，现在 nums = [1,2,2,3,3,3,4] 。
插入 1 ，代价为 min(0, 6) = 0 ，现在 nums = [1,1,2,2,3,3,3,4] 。
插入 2 ，代价为 min(2, 4) = 2 ，现在 nums = [1,1,2,2,2,3,3,3,4] 。
总代价为 0 + 0 + 0 + 0 + 1 + 0 + 1 + 0 + 2 = 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= instructions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= instructions[i] &lt;= 10<sup>5</sup></code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {

    }
};
```




