# `（中等）` [34.find-first-and-last-position-of-element-in-sorted-array 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

### 题目描述
<p>给定一个按照升序排列的整数数组 <code>nums</code>，和一个目标值 <code>target</code>。找出给定目标值在数组中的开始位置和结束位置。</p>

<p>你的算法时间复杂度必须是&nbsp;<em>O</em>(log <em>n</em>) 级别。</p>

<p>如果数组中不存在目标值，返回&nbsp;<code>[-1, -1]</code>。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> nums = [<code>5,7,7,8,8,10]</code>, target = 8
<strong>输出:</strong> [3,4]</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> nums = [<code>5,7,7,8,8,10]</code>, target = 6
<strong>输出:</strong> [-1,-1]</pre>


---
### 思路
```
```

### 答题
``` C++
int lowerBound(vector<int> &nums, int target, int low, int high)
{
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] < target) low = mid + 1;
		else high = mid;
	}
	return low;
}

vector<int> searchRange(vector<int>& nums, int target) 
{
	int l = lowerBound(nums, target, 0, nums.size());
	if (l < nums.size() && nums[l] == target)
	{
		int r = lowerBound(nums, target + 1, l, nums.size());
		return { l, r - 1 };
	}
	return { -1,-1 };
}
```
