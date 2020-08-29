# `（中等）` [491.increasing-subsequences 递增子序列](https://leetcode-cn.com/problems/increasing-subsequences/)

### 题目描述
<p>给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [4, 6, 7, 7]
<strong>输出:</strong> [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]</pre>

<p><strong>说明:</strong></p>

<ol>
	<li>给定数组的长度不会超过15。</li>
	<li>数组中的整数范围是&nbsp;[-100,100]。</li>
	<li>给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0, INT_MIN);
        return ans;
    }

    void dfs(vector<int>& nums, int idx, int maxVal) {
        if (idx == nums.size()) {
            if (temp.size() > 1) {
                ans.push_back(temp);
            }
            return;
        }

        if (nums[idx] >= maxVal) {
            temp.push_back(nums[idx]);
            dfs(nums, idx + 1, nums[idx]);
            temp.pop_back();
        }

        if (nums[idx] != maxVal) {
            dfs(nums, idx + 1, maxVal);
        }
    }

private:
    vector<vector<int>> ans;
    vector<int> temp;
};
```




