# `（困难）` [1569.number-of-ways-to-reorder-array-to-get-same-bst 将子数组重新排序得到同一个二叉查找树的方案数](https://leetcode-cn.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/)

[contest](https://leetcode-cn.com/contest/weekly-contest-204/problems/number-of-ways-to-reorder-array-to-get-same-bst/)

### 题目描述
<p>给你一个数组 <code>nums</code>&nbsp;表示 <code>1</code>&nbsp;到 <code>n</code>&nbsp;的一个排列。我们按照元素在 <code>nums</code>&nbsp;中的顺序依次插入一个初始为空的二叉查找树（BST）。请你统计将 <code>nums</code>&nbsp;重新排序后，统计满足如下条件的方案数：重排后得到的二叉查找树与 <code>nums</code>&nbsp;原本数字顺序得到的二叉查找树相同。</p>

<p>比方说，给你&nbsp;<code>nums = [2,1,3]</code>，我们得到一棵 2 为根，1 为左孩子，3 为右孩子的树。数组&nbsp;<code>[2,3,1]</code>&nbsp;也能得到相同的 BST，但&nbsp;<code>[3,2,1]</code>&nbsp;会得到一棵不同的&nbsp;BST 。</p>

<p>请你返回重排 <code>nums</code>&nbsp;后，与原数组 <code>nums</code>&nbsp;得到相同二叉查找树的方案数。</p>

<p>由于答案可能会很大，请将结果对<strong>&nbsp;</strong><code>10^9 + 7</code>&nbsp;取余数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 101px; width: 121px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/30/bb.png" alt=""></p>

<pre><strong>输入：</strong>nums = [2,1,3]
<strong>输出：</strong>1
<strong>解释：</strong>我们将 nums 重排， [2,3,1] 能得到相同的 BST 。没有其他得到相同 BST 的方案了。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img style="height: 161px; width: 241px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/30/ex1.png" alt=""></strong></p>

<pre><strong>输入：</strong>nums = [3,4,5,1,2]
<strong>输出：</strong>5
<strong>解释：</strong>下面 5 个数组会得到相同的 BST：
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img style="height: 161px; width: 121px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/30/ex4.png" alt=""></strong></p>

<pre><strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>0
<strong>解释：</strong>没有别的排列顺序能得到相同的 BST 。
</pre>

<p><strong>示例 4：</strong></p>

<p><strong><img style="height: 161px; width: 241px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/30/abc.png" alt=""></strong></p>

<pre><strong>输入：</strong>nums = [3,1,2,5,4,6]
<strong>输出：</strong>19
</pre>

<p><strong>示例&nbsp; 5：</strong></p>

<pre><strong>输入：</strong>nums = [9,4,2,1,3,6,5,7,8,14,11,10,12,13,16,15,17,18]
<strong>输出：</strong>216212978
<strong>解释：</strong>得到相同 BST 的方案数是 3216212999。将它对 10^9 + 7 取余后得到 216212978。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 1000</code></li>
	<li><code>1 <= nums[i] <= nums.length</code></li>
	<li><code>nums</code>&nbsp;中所有数 <strong>互不相同</strong>&nbsp;。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int numOfWays(vector<int>& nums) {

    }
};
```




