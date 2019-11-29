# `（中等）` [698.partition-to-k-equal-sum-subsets 划分为k个相等的子集](https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/)

### 题目描述
<p>给定一个整数数组&nbsp;&nbsp;<code>nums</code> 和一个正整数 <code>k</code>，找出是否有可能把这个数组分成 <code>k</code> 个非空子集，其总和都相等。</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong> nums = [4, 3, 2, 3, 5, 2, 1], k = 4
<strong>输出：</strong> True
<strong>说明：</strong> 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。</pre>

<p>&nbsp;</p>
<p><strong>注意:</strong></p>
<ul>
	<li><code>1 &lt;= k &lt;= len(nums) &lt;= 16</code></li>
	<li><code>0 &lt; nums[i] &lt; 10000</code></li>
</ul>

---
### 思路
```
回溯。
记录每个数字被使用情况，回溯失败还原。
找到一组等于平均值的数字后，把组数减1，继续寻找。
```



### 答题
``` C++
bool dfs(vector<int>& nums, vector<int>& visited, int sum, int k, int target)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (visited[i] == 1) continue;
		if (sum + nums[i] > target) continue;
		if (sum + nums[i] == target)
		{
			if (--k == 0) return true;
			visited[i] = 1;
			if (dfs(nums, visited, 0, k, target))
			{
				return true;
			}
			visited[i] = 0;
			k++;
		}
		else
		{
			visited[i] = 1;
			if (dfs(nums, visited, sum + nums[i], k, target))
			{
				return true;
			}
			visited[i] = 0;
		}
	}
	return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k)
{
	sort(nums.rbegin(), nums.rend());
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % k != 0) return false;
	int avg = sum / k;
	if (nums.front() > avg) return false;

	vector<int> visited(nums.size(), 0);
	return dfs(nums, visited, 0, k, avg);
}
```


