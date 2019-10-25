# `（中等）` [16.3sum-closest 最接近的三数之和](https://leetcode-cn.com/problems/3sum-closest/)

### 题目描述
<p>给定一个包括&nbsp;<em>n</em> 个整数的数组&nbsp;<code>nums</code><em>&nbsp;</em>和 一个目标值&nbsp;<code>target</code>。找出&nbsp;<code>nums</code><em>&nbsp;</em>中的三个整数，使得它们的和与&nbsp;<code>target</code>&nbsp;最接近。返回这三个数的和。假定每组输入只存在唯一答案。</p>

<pre>例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
</pre>


---
### 思路
```
照着 15.3sum 三数之和 改了改，几乎一样。
```

### 答题
``` C++
int threeSumClosest(vector<int>& nums, int target)
{
	int ret = INT_MAX;
	sort(nums.begin(), nums.end());
	int len = nums.size();
	if (len < 3) return 0;
	for (int i = 0; i < len; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重
		int L = i + 1;
		int R = len - 1;
		while (L < R)
		{
			int sum = nums[i] + nums[L] + nums[R];
			int temp = sum - target;
			ret = (abs(temp) < abs(ret)) ? temp : ret;
			if (sum == target) return target;
			if (sum < target) L++;
			else if (sum > target) R--;
		}
	}
	return target + ret;
}
```
