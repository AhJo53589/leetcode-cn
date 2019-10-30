# `（中等）` [324.wiggle-sort-ii 摆动排序 II](https://leetcode-cn.com/problems/wiggle-sort-ii/)

### 题目描述
<p>给定一个无序的数组&nbsp;<code>nums</code>，将它重新排列成&nbsp;<code>nums[0] &lt; nums[1] &gt; nums[2] &lt; nums[3]...</code>&nbsp;的顺序。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入: </strong><code>nums = [1, 5, 1, 1, 6, 4]</code>
<strong>输出: </strong>一个可能的答案是 <code>[1, 4, 1, 5, 1, 6]</code></pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong><code>nums = [1, 3, 2, 2, 3, 1]</code>
<strong>输出:</strong> 一个可能的答案是 <code>[2, 3, 1, 3, 1, 2]</code></pre>

<p><strong>说明:</strong><br>
你可以假设所有输入都会得到有效的结果。</p>

<p><strong>进阶:</strong><br>
你能用&nbsp;O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？</p>


---
### 思路
```
```

### 答题
``` C++
void wiggleSort(vector<int>& nums) {
	vector<int> tmp(nums.begin(), nums.end());
	int len = nums.size();
	int k = (len + 1) >> 1;
	int j = len;
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < len; ++i) {
		nums[i] = i & 1 ? tmp[--j] : tmp[--k];
	}
}
```

### 其它
``` C++
void wiggleSort(vector<int>& nums) {
	if (2 > nums.size()) {
		return;
	}

	int nums_size = nums.size();
	auto midptr = nums.begin() + nums_size / 2;
	nth_element(nums.begin(), midptr, nums.end());
	int mid = *midptr;
#define A(i) nums[(1+2*(i)) % (nums_size|1)]
	int i = 0, j = 0, k = nums_size - 1;
	while (j <= k) {
		if (A(j) > mid)
			swap(A(i++), A(j++));
		else if (A(j) < mid)
			swap(A(j), A(k--));
		else
			j++;
	}
}
```

