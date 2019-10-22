# `（中等）`  [33.search-in-rotated-sorted-array 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

### 题目描述
<p>假设按照升序排序的数组在预先未知的某个点上进行了旋转。</p>

<p>( 例如，数组&nbsp;<code>[0,1,2,4,5,6,7]</code>&nbsp;可能变为&nbsp;<code>[4,5,6,7,0,1,2]</code>&nbsp;)。</p>

<p>搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>你可以假设数组中不存在重复的元素。</p>

<p>你的算法时间复杂度必须是&nbsp;<em>O</em>(log&nbsp;<em>n</em>) 级别。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> nums = [<code>4,5,6,7,0,1,2]</code>, target = 0
<strong>输出:</strong> 4
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> nums = [<code>4,5,6,7,0,1,2]</code>, target = 3
<strong>输出:</strong> -1</pre>


---
### 思路
```
这题真是if else地狱！

思路还是二分查找，
难点在于怎么处理旋转后的数组。
解决方案为，
先判断正常顺序的是low - mid（左侧）还是mid - high（右侧）。
然后只对正常顺序的那一侧判断target是否在范围内，
那么如果不在肯定就再另一侧。
```
[发布的题解](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-by-ikaruga/)

### 答题
``` C++
int lowerBound(vector<int> &nums, int target, int low, int high)
{
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] == target) return mid;
		if (nums[low] <= nums[mid])
		{
			if (nums[low] <= target && target <= nums[mid])
			{
				high = mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		else if (nums[mid] <= nums[high - 1])
		{
			if (nums[mid] <= target && target <= nums[high - 1])
			{
				low = mid + 1;
			}
			else
			{
				high = mid;
			}
		}
	}
	return low;
}

int search(vector<int>& nums, int target) 
{
	int i = lowerBound(nums, target, 0, nums.size());
	if (i == nums.size()) return -1;
	return (nums[i] == target) ? i : -1;
}
```
