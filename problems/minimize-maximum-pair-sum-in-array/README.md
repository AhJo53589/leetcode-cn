# `（中等）` [1877.minimize-maximum-pair-sum-in-array 数组中最大数对和的最小值](https://leetcode-cn.com/problems/minimize-maximum-pair-sum-in-array/)

### 题目描述
<p>一个数对&nbsp;<code>(a,b)</code>&nbsp;的 <strong>数对和</strong>&nbsp;等于&nbsp;<code>a + b</code>&nbsp;。<strong>最大数对和</strong>&nbsp;是一个数对数组中最大的&nbsp;<strong>数对和</strong>&nbsp;。</p>

<ul>
	<li>比方说，如果我们有数对&nbsp;<code>(1,5)</code>&nbsp;，<code>(2,3)</code>&nbsp;和&nbsp;<code>(4,4)</code>，<strong>最大数对和</strong>&nbsp;为&nbsp;<code>max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8</code>&nbsp;。</li>
</ul>

<p>给你一个长度为 <strong>偶数</strong>&nbsp;<code>n</code>&nbsp;的数组&nbsp;<code>nums</code>&nbsp;，请你将 <code>nums</code>&nbsp;中的元素分成 <code>n / 2</code>&nbsp;个数对，使得：</p>

<ul>
	<li><code>nums</code>&nbsp;中每个元素&nbsp;<strong>恰好</strong>&nbsp;在 <strong>一个</strong>&nbsp;数对中，且</li>
	<li><strong>最大数对和</strong>&nbsp;的值 <strong>最小</strong>&nbsp;。</li>
</ul>

<p>请你在最优数对划分的方案下，返回最小的 <strong>最大数对和</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [3,5,2,3]
<b>输出：</b>7
<b>解释：</b>数组中的元素可以分为数对 (3,3) 和 (5,2) 。
最大数对和为 max(3+3, 5+2) = max(6, 7) = 7 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [3,5,4,2,4,6]
<b>输出：</b>8
<b>解释：</b>数组中的元素可以分为数对 (3,5)，(4,4) 和 (6,2) 。
最大数对和为 max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n</code>&nbsp;是 <strong>偶数</strong>&nbsp;。</li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size() / 2; i++) {
            ans = max(ans, nums[i] + nums[nums.size() - i - 1]);
        }
        return ans;
    }
};
```




