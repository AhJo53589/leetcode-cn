# `（困难）` [1478.allocate-mailboxes 安排邮筒](https://leetcode-cn.com/problems/allocate-mailboxes/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-28/problems/allocate-mailboxes/)

### 题目描述
<p>给你一个房屋数组<code>houses</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，其中&nbsp;<code>houses[i]</code>&nbsp;是第 <code>i</code>&nbsp;栋房子在一条街上的位置，现需要在这条街上安排 <code>k</code>&nbsp;个邮筒。</p>

<p>请你返回每栋房子与离它最近的邮筒之间的距离的 <strong>最小 </strong>总和。</p>

<p>答案保证在 32 位有符号整数范围以内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 154px; width: 454px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/06/13/sample_11_1816.png" alt=""></p>

<pre><strong>输入：</strong>houses = [1,4,8,10,20], k = 3
<strong>输出：</strong>5
<strong>解释：</strong>将邮筒分别安放在位置 3， 9 和 20 处。
每个房子到最近邮筒的距离和为 |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img style="height: 154px; width: 433px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/06/13/sample_2_1816.png" alt=""></strong></p>

<pre><strong>输入：</strong>houses = [2,3,5,12,18], k = 2
<strong>输出：</strong>9
<strong>解释：</strong>将邮筒分别安放在位置 3 和 14 处。
每个房子到最近邮筒距离和为 |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>houses = [7,4,6,1], k = 1
<strong>输出：</strong>8
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>houses = [3,6,14,10], k = 4
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == houses.length</code></li>
	<li><code>1 <= n&nbsp;<= 100</code></li>
	<li><code>1 <= houses[i] <= 10^4</code></li>
	<li><code>1 <= k <= n</code></li>
	<li>数组&nbsp;<code>houses</code>&nbsp;中的整数互不相同。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {

    }
};
```




