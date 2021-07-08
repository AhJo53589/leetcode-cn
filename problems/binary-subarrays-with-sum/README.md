# `（中等）` [930.binary-subarrays-with-sum 和相同的二元子数组](https://leetcode-cn.com/problems/binary-subarrays-with-sum/)

### 题目描述
<p>给你一个二元数组 <code>nums</code> ，和一个整数 <code>goal</code> ，请你统计并返回有多少个和为 <code>goal</code> 的<strong> 非空</strong> 子数组。</p>

<p><strong>子数组</strong> 是数组的一段连续部分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,0,1,0,1], goal = 2
<strong>输出：</strong>4
<strong>解释：</strong>
如下面黑体所示，有 4 个满足题目要求的子数组：
[<strong>1,0,1</strong>,0,1]
[<strong>1,0,1,0</strong>,1]
[1,<strong>0,1,0,1</strong>]
[1,0,<strong>1,0,1</strong>]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [0,0,0,0,0], goal = 0
<strong>输出：</strong>15
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>nums[i]</code> 不是 <code>0</code> 就是 <code>1</code></li>
	<li><code>0 &lt;= goal &lt;= nums.length</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        unordered_map<int, int> cnt;
        int ans = 0;
        for (auto& num : nums) {
            cnt[sum]++;
            sum += num;
            ans += cnt[sum - goal];
        }
        return ans;
    }
};
```




