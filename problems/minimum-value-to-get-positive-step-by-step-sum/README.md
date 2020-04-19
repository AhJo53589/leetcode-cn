# `（简单）` [5372.minimum-value-to-get-positive-step-by-step-sum 逐步求和得到正数的最小值](https://leetcode-cn.com/problems/minimum-value-to-get-positive-step-by-step-sum/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-24/problems/minimum-value-to-get-positive-step-by-step-sum/)

### 题目描述
<p>给你一个整数数组 <code>nums</code>&nbsp;。你可以选定任意的&nbsp;<strong>正数</strong> startValue 作为初始值。</p>
<p>你需要从左到右遍历 <code>nums</code>&nbsp;数组，并将 startValue 依次累加上&nbsp;<code>nums</code>&nbsp;数组中的值。</p>
<p>请你在确保累加和始终大于等于 1 的前提下，选出一个最小的&nbsp;<strong>正数</strong>&nbsp;作为 startValue 。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong>nums = [-3,2,-3,4,2]
<strong>输出：</strong>5
<strong>解释：</strong>如果你选择 startValue = 4，在第三次累加时，和小于 1 。
<strong>                累加求和
&nbsp;               startValue = 4 | startValue = 5 | nums
</strong>&nbsp;                 (4 <strong>-3</strong> ) = 1  | (5 <strong>-3</strong> ) = 2    |  -3
&nbsp;                 (1 <strong>+2</strong> ) = 3  | (2 <strong>+2</strong> ) = 4    |   2
&nbsp;                 (3 <strong>-3</strong> ) = 0  | (4 <strong>-3</strong> ) = 1    |  -3
&nbsp;                 (0 <strong>+4</strong> ) = 4  | (1 <strong>+4</strong> ) = 5    |   4
&nbsp;                 (4 <strong>+2</strong> ) = 6  | (5 <strong>+2</strong> ) = 7    |   2
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>nums = [1,2]
<strong>输出：</strong>1
<strong>解释：</strong>最小的 startValue 需要是正数。
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>nums = [1,-2,-3]
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-value-to-get-positive-step-by-step-sum/solution/minimum-value-to-get-positive-step-by-step-sum-by-/)

### 答题
``` C++
class Solution {
public:
    int minStartValue(vector<int>& nums) 
    {
        vector<int> a;
        partial_sum(nums.begin(), nums.end(), back_inserter(a));
        int ans = *min_element(a.begin(), a.end());
        return ans <= 0 ? 1 - ans : 1;
    }
};
```




