# `（中等）` [47.permutations-ii 全排列 II](https://leetcode-cn.com/problems/permutations-ii/)

### 题目描述
<p>给定一个可包含重复数字的序列，返回所有不重复的全排列。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [1,1,2]
<strong>输出:</strong>
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        perm = vector<int>(nums.size(), 0);
        vi = vector<bool>(nums.size(), false);
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int depth)
    {
        if (depth == nums.size())
        {
            ans.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (vi[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !vi[i - 1]) continue;

            vi[i] = true;
            perm[depth] = nums[i];
            dfs(nums, depth + 1);
            vi[i] = false;
        }
    }

private:
    vector<int> perm;
    vector<bool> vi;
    vector<vector<int>> ans;
};
```




