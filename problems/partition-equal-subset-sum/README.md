# `（中等）` [416.partition-equal-subset-sum 分割等和子集](https://leetcode-cn.com/problems/partition-equal-subset-sum/)

### 题目描述
<p>给定一个<strong>只包含正整数</strong>的<strong>非空</strong>数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。</p>

<p><strong>注意:</strong></p>

<ol>
	<li>每个数组中的元素不会超过 100</li>
	<li>数组的大小不会超过 200</li>
</ol>

<p><strong>示例 1:</strong></p>

<pre>输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
</pre>

<p>&nbsp;</p>

<p><strong>示例&nbsp;2:</strong></p>

<pre>输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.
</pre>

<p>&nbsp;</p>


---
### 思路
```
```

### 答题
``` C++
bool DFS(const vector<int>& nums, int start, int curSum, int C)
{
	curSum += nums[start];
	if (curSum == C) return true;

	for (int i = start - 1; i >= 0; --i)
	{
		if (curSum + nums[i] > C) continue;
		return DFS(nums, i, curSum, C);
	}
	return false;
}

bool canPartition(vector<int>& nums)
{
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
	}
	if (sum % 2 != 0) return false;

	sort(nums.begin(), nums.end());
	int C = sum / 2;
	if (nums.back() > C) return false;

	for (int i = nums.size() - 1; i >= 0; --i)
	{
		if (DFS(nums, i, 0, C)) return true;
	}
	return false;
}
```

### 其它
01背包
``` C++
bool canPartition(vector<int>& nums) 
{
	int sum = 0;
	for (auto n : nums) 
	{
		sum += n;
	}
	if (sum % 2 != 0) return false;

	int target = sum / 2;
	vector<int> dp = vector<int>(target + 1, INT_MIN);
	dp[0] = 0;
	for (int i = 0; i < nums.size(); i++) 
	{
		int n = nums[i];
		for (int j = target; j >= n; j--) 
		{
			dp[j] = max(dp[j], dp[j - n] + n); //使用了滚动数组
			if (dp[j] < 0) 
			{
				dp[j] = INT_MIN;
			}
		}
	}
	return dp.back() == target;
}
```

