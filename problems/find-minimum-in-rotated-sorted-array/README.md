# `（中等）` [153.find-minimum-in-rotated-sorted-array 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

### 题目描述
<p>假设按照升序排序的数组在预先未知的某个点上进行了旋转。</p>

<p>( 例如，数组&nbsp;<code>[0,1,2,4,5,6,7]</code> <strong> </strong>可能变为&nbsp;<code>[4,5,6,7,0,1,2]</code>&nbsp;)。</p>

<p>请找出其中最小的元素。</p>

<p>你可以假设数组中不存在重复元素。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [3,4,5,1,2]
<strong>输出:</strong> 1</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [4,5,6,7,0,1,2]
<strong>输出:</strong> 0</pre>


---
### 思路
```
```

### 答题
``` C++
int findMin(vector<int>& nums) 
{
	if (nums.empty()) return -1;
	if (nums.size() == 1) return nums[0];
	int low = 0;
	int high = nums.size();
	if (low == 0 && nums[low] < nums[nums.size() - 1]) return nums[low];
	if (high - 2 != 0 && high - 1 != 0 && nums[high - 1] < nums[high - 2]) return nums[high - 1];
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (low != 0 && nums[low] < nums[low - 1]) return nums[low];
		if (mid != 0 && nums[mid] < nums[mid - 1]) return nums[mid];
		if (nums[low] <= nums[mid]) low = mid + 1;
		//else if (nums[mid] <= nums[high - 1]) high = mid;
		else high = mid;
	}
	return (low < nums.size()) ? nums[low] : -1;
}
```

### 其它
``` C++
int findMin(vector<int>& nums) {
	int lens = nums.size();
	int i = 0;
	int j = lens - 1;
	while (i < j)
	{
		int mid = i + (j - i) / 2;
		if (nums[mid] > nums[j])
		{
			i = mid + 1;
		}
		else
		{
			j = mid;
		}
	}
	return nums[i];
}
```

