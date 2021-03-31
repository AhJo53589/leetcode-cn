# `（中等）` [90.subsets-ii 子集 II](https://leetcode-cn.com/problems/subsets-ii/)

### 题目描述
<p>给你一个整数数组 <code>nums</code> ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。</p>

<p>解集 <strong>不能</strong> 包含重复的子集。返回的解集中，子集可以按 <strong>任意顺序</strong> 排列。</p>

<div class="original__bRMd">
<div>
<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,2]
<strong>输出：</strong>[[],[1],[1,2],[1,2,2],[2],[2,2]]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [0]
<strong>输出：</strong>[[],[0]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
</ul>
</div>
</div>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int index) {
        ans.push_back(temp);

        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            dfs(nums, i + 1);
            temp.pop_back();
        }
    }

private:
    vector<vector<int>> ans;
    vector<int> temp;
};
```




