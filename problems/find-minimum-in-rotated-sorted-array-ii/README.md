# `（困难）` [154.find-minimum-in-rotated-sorted-array-ii 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)

### 题目描述
<p>假设按照升序排序的数组在预先未知的某个点上进行了旋转。</p>

<p>( 例如，数组&nbsp;<code>[0,1,2,4,5,6,7]</code> <strong> </strong>可能变为&nbsp;<code>[4,5,6,7,0,1,2]</code>&nbsp;)。</p>

<p>请找出其中最小的元素。</p>

<p>注意数组中可能存在重复的元素。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> [1,3,5]
<strong>输出:</strong> 1</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre><strong>输入:</strong> [2,2,2,0,1]
<strong>输出:</strong> 0</pre>

<p><strong>说明：</strong></p>

<ul>
	<li>这道题是&nbsp;<a href="https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/">寻找旋转排序数组中的最小值</a>&nbsp;的延伸题目。</li>
	<li>允许重复会影响算法的时间复杂度吗？会如何影响，为什么？</li>
</ul>


---
### 思路
```
```

### 答题
``` C++
int findMin(vector<int>& nums)
{
	int low = 0;
	int high = nums.size() - 1;
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] == nums[high]) high--;
		else if (nums[mid] > nums[high]) low = mid + 1;
		//else if (nums[mid] < nums[0]) high = mid;
		else high = mid;
	}
	return (low < nums.size()) ? nums[low] : nums[0];
}
```

