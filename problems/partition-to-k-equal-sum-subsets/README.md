# `（中等）` [698.partition-to-k-equal-sum-subsets 划分为k个相等的子集](https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/)

### 题目描述
<p>给定一个整数数组&nbsp;&nbsp;<code>nums</code> 和一个正整数 <code>k</code>，找出是否有可能把这个数组分成 <code>k</code> 个非空子集，其总和都相等。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong> nums = [4, 3, 2, 3, 5, 2, 1], k = 4
<strong>输出：</strong> True
<strong>说明：</strong> 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= len(nums) &lt;= 16</code></li>
	<li><code>0 &lt; nums[i] &lt; 10000</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/solution/partition-to-k-equal-sum-subsets-by-ikar-f207/)

### 答题
``` C++
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int avg = sum / k;

        vector<int> vi(nums.size(), 0);
        return dfs(nums, vi, avg, 0, k);
    }

    bool dfs(vector<int>& nums, vector<int>& vi, int target, int sum, int k) {
        if (k == 0) return true;

        int firstIdx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (vi[i] == 1) continue;
            firstIdx = (firstIdx == -1) ? i : firstIdx;
            if (sum == 0 && i != firstIdx) return false;

            int temp = sum + nums[i];
            if (temp > target) continue;

            int nextK = (temp == target) ? k - 1 : k;
            int nextSum = (temp == target) ? 0 : temp;

            vi[i] = 1;
            if (dfs(nums, vi, target, nextSum, nextK)) return true;
            vi[i] = 0;
        }
        return false;
    }
};
```




