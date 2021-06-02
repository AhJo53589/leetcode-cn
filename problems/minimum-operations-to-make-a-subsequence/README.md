# `（困难）` [1713.minimum-operations-to-make-a-subsequence 得到子序列的最少操作次数](https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/)

[contest](https://leetcode-cn.com/contest/weekly-contest-222/problems/minimum-operations-to-make-a-subsequence/)

### 题目描述
<div class="notranslate"><p>给你一个数组&nbsp;<code>target</code>&nbsp;，包含若干 <strong>互不相同</strong>&nbsp;的整数，以及另一个整数数组&nbsp;<code>arr</code>&nbsp;，<code>arr</code>&nbsp;<strong>可能</strong> 包含重复元素。</p>

<p>每一次操作中，你可以在 <code>arr</code>&nbsp;的任意位置插入任一整数。比方说，如果&nbsp;<code>arr = [1,4,1,2]</code>&nbsp;，那么你可以在中间添加 <code>3</code>&nbsp;得到&nbsp;<code>[1,4,<strong>3</strong>,1,2]</code>&nbsp;。你可以在数组最开始或最后面添加整数。</p>

<p>请你返回 <strong>最少</strong>&nbsp;操作次数，使得<em>&nbsp;</em><code>target</code><em>&nbsp;</em>成为&nbsp;<code>arr</code>&nbsp;的一个子序列。</p>

<p>一个数组的 <strong>子序列</strong>&nbsp;指的是删除原数组的某些元素（可能一个元素都不删除），同时不改变其余元素的相对顺序得到的数组。比方说，<code>[2,7,4]</code>&nbsp;是&nbsp;<code>[4,<strong>2</strong>,3,<strong>7</strong>,2,1,<strong>4</strong>]</code>&nbsp;的子序列（加粗元素），但&nbsp;<code>[2,4,2]</code>&nbsp;不是子序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>target = [5,1,3], <code>arr</code> = [9,4,2,3,4]
<b>输出：</b>2
<b>解释：</b>你可以添加 5 和 1 ，使得 arr 变为 [<strong>5</strong>,9,4,<strong>1</strong>,2,3,4] ，target 为 arr 的子序列。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>target = [6,4,8,1,3,2], <code>arr</code> = [4,7,6,2,3,8,6,1]
<b>输出：</b>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target.length, arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= target[i], arr[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>target</code>&nbsp;不包含任何重复元素。</li>
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
    int minOperations(vector<int>& target, vector<int>& arr) {

    }
};
```




