# `（简单）` [5709.maximum-ascending-subarray-sum 最大升序子数组和](https://leetcode-cn.com/problems/maximum-ascending-subarray-sum/)

[contest](https://leetcode-cn.com/contest/weekly-contest-233/problems/maximum-ascending-subarray-sum/)

### 题目描述
<p>给你一个正整数组成的数组 <code>nums</code> ，返回 <code>nums</code> 中一个 <strong>升序 </strong>子数组的最大可能元素和。</p>

<p>子数组是数组中的一个连续数字序列。</p>

<p>已知子数组 <code>[nums<sub>l</sub>, nums<sub>l+1</sub>, ..., nums<sub>r-1</sub>, nums<sub>r</sub>]</code> ，若对所有 <code>i</code>（<code>l &lt;= i &lt; r</code>），<code>nums<sub>i </sub> &lt; nums<sub>i+1</sub></code> 都成立，则称这一子数组为 <strong>升序</strong> 子数组。注意，大小为 <code>1</code> 的子数组也视作 <strong>升序</strong> 子数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [10,20,30,5,10,50]
<strong>输出：</strong>65
<strong>解释：</strong>[5,10,50] 是元素和最大的升序子数组，最大元素和为 65 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [10,20,30,40,50]
<strong>输出：</strong>150
<strong>解释：</strong>[10,20,30,40,50] 是元素和最大的升序子数组，最大元素和为 150 。 
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [12,17,15,13,10,11,12]
<strong>输出：</strong>33
<strong>解释：</strong>[10,11,12] 是元素和最大的升序子数组，最大元素和为 33 。 
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [100,10,1]
<strong>输出：</strong>100
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-ascending-subarray-sum/solution/maximum-ascending-by-ikaruga-1lf5/)

### 答题
``` C++
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = (i != 0 && nums[i] > nums[i - 1]) ? sum + nums[i] : nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};
```




