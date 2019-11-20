# `（中等）` [912.sort-an-array 排序数组](https://leetcode-cn.com/problems/sort-an-array/)

### 题目描述
<p>给定一个整数数组&nbsp;<code>nums</code>，将该数组升序排列。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[5,2,3,1]
<strong>输出：</strong>[1,2,3,5]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[5,1,1,2,0,0]
<strong>输出：</strong>[0,0,1,1,2,5]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 10000</code></li>
	<li><code>-50000 &lt;= A[i] &lt;= 50000</code></li>
</ol>


---
### 思路
```
```

### 答题
``` C++
size_t partition(vector<int>& nums, size_t left, size_t right)
{
	size_t mid = left;
	for (auto i = left; i < right; i++)
	{
		if (nums[i] < nums[right - 1])
		{
			swap(nums[i], nums[mid++]);
		}
	}
	swap(nums[mid], nums[right - 1]);
	return mid;
}

void quickSort(vector<int>& nums, size_t left, size_t right)
{
	if (left >= right) return;
	size_t mid = partition(nums, left, right);
	quickSort(nums, left, mid);
	quickSort(nums, mid + 1, right);
}

vector<int> sortArray(vector<int>& nums) 
{
	quickSort(nums, 0, nums.size());
	return nums;
}
```

### 其它
``` C++
```

