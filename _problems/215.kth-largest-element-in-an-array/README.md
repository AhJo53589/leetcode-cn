# `（中等）`  [215.kth-largest-element-in-an-array 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

### 题目描述
<p>在未排序的数组中找到第 <strong>k</strong> 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <code>[3,2,1,5,6,4] 和</code> k = 2
<strong>输出:</strong> 5
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> <code>[3,2,3,1,2,4,5,5,6] 和</code> k = 4
<strong>输出:</strong> 4</pre>

<p><strong>说明: </strong></p>

<p>你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。</p>


---
### 思路
```
```

### 答题
``` C++
int findKthLargest(vector<int>& nums, int k)
{
	int len = nums.size();
	bool bOrder = k <= len / 2;
	int t = bOrder ? k : len - k + 1;
	for (int j = 0; j < len - 1; j++)
	{
		for (int i = 0; i < len - 1 - j; i++)
		{
			if ([bOrder](int a, int b) { return bOrder ? a > b : b > a; }(nums[i], nums[i + 1]))
			{
				swap(nums[i], nums[i + 1]);
			}
		}
		if (t-- == 0) break;
	}
	return bOrder ? nums[len - k] : nums[k - 1];
}
```
