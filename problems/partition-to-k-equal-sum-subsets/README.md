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
```



### 答题
``` C++
bool dfs(vector<int>& nums, vector<bool> visted, vector<bool> group, int gsum, size_t pos, int k, int sum)
{
	if (k == 0) return true;
	if (pos >= nums.size()) return false;
	if (visted[pos])
	{
		return dfs(nums, visted, group, gsum, pos - 1, k, sum);
	}

	for (size_t i = pos; i < nums.size(); i--)
	{
		if (visted[i]) continue;
		if (group[i]) continue;
		if (gsum + nums[i] > sum) continue;
		if (gsum + nums[i] == sum)
		{
			group[i] = true;
			for (auto g = 0; g < group.size(); g++)
			{
				visted[g] = (group[g]) ? true : visted[g];
			}
			k--;
			if (dfs(nums, visted, vector<bool>(nums.size(), false), 0, pos - 1, k, sum))
			{
				return true;
			}
			for (auto g = 0; g < group.size(); g++)
			{
				visted[g] = (group[g]) ? false : visted[g];
			}
			k++;
		}
		else
		{
			group[i] = true;
			gsum += nums[i];
			if (dfs(nums, visted, group, gsum, pos, k, sum))
			{
				return true;
			}
			group[i] = false;
			gsum -= nums[i];
		}
	}
	return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) 
{
	sort(nums.begin(), nums.end());
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if ((sum % k) != 0) return false;
	int avg = sum / k;
	if (nums.back() > avg) return false;

	return dfs(nums, vector<bool>(nums.size(), false), vector<bool>(nums.size(), false), 0, nums.size() - 1, k, avg);
}
```


### 其它
``` C++
bool dfs(vector<int>& nums, vector<int>& record, int target, int k, int start, int curSum)
{
	if (k == 1) {
		return true;
	}
	if (curSum == target) {
		return dfs(nums, record, target, --k, 0, 0);
	}
	if (curSum < target) {
		for (int i = start; i < nums.size(); ++i) {
			if (record[i] == 0) {
				continue;
			}
			record[i] = 0;
			if (dfs(nums, record, target, k, i + 1, curSum + nums[i])) {
				return true;
			}
			record[i] = 1;
		}
	}
	return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if ((sum % k) != 0) {
		return false;
	}
	int target = sum / k;
	int N = nums.size();
	vector<int> record(N, 1);
	vector<int> paths;
	return dfs(nums, record, target, k, 0, 0);
}
```


