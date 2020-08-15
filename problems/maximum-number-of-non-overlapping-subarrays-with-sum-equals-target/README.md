# `（中等）` [1546.maximum-number-of-non-overlapping-subarrays-with-sum-equals-target 和为目标值的最大数目不重叠非空子数组数目](https://leetcode-cn.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/)

[contest](https://leetcode-cn.com/contest/weekly-contest-201/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/)

### 题目描述
<p>给你一个数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>target</code>&nbsp;。</p>

<p>请你返回&nbsp;<strong>非空不重叠</strong>&nbsp;子数组的最大数目，且每个子数组中数字和都为 <code>target</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,1,1,1], target = 2
<strong>输出：</strong>2
<strong>解释：</strong>总共有 2 个不重叠子数组（加粗数字表示） [<strong>1,1</strong>,1,<strong>1,1</strong>] ，它们的和为目标值 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [-1,3,5,1,4,2,-9], target = 6
<strong>输出：</strong>2
<strong>解释：</strong>总共有 3 个子数组和为 6 。
([5,1], [4,2], [3,5,1,4,2,-9]) 但只有前 2 个是不重叠的。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [-2,6,6,3,5,4,1,2,8], target = 10
<strong>输出：</strong>3
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [0,0,0], target = 0
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <=&nbsp;10^5</code></li>
	<li><code>-10^4 <= nums[i] <=&nbsp;10^4</code></li>
	<li><code>0 <= target <= 10^6</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0, end = -1;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mp.find(sum - target) != mp.end()) {
                if (mp[sum - target] + 1 > end) {
                    ret++;
                    end = i;
                }
            }
            mp[sum] = i;
        }
        return ret;
    }
};
```




