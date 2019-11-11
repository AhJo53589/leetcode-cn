# `（中等）` [46.permutations 全排列](https://leetcode-cn.com/problems/permutations/)

### 题目描述
<p>给定一个<strong>没有重复</strong>数字的序列，返回其所有可能的全排列。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [1,2,3]
<strong>输出:</strong>
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]</pre>


---
### 思路
```
```

### 答题
``` C++
void backtrack(vector<int> &nums, vector<vector<int>> &res, int i)
{
	if (i == nums.size()) res.push_back(nums);

	for (int j = i; j < nums.size(); j++)
	{
		swap(nums[i], nums[j]);
		backtrack(nums, res, i + 1);
		swap(nums[i], nums[j]);
	}
}

vector<vector<int>> permute(vector<int>& nums) 
{
	vector<vector<int>> res;
	backtrack(nums, res, 0);
	return res;
}
```


