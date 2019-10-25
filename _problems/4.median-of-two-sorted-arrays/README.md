# `（困难）`  [4.median-of-two-sorted-arrays 寻找两个有序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

### 题目描述
<p>给定两个大小为 m 和 n 的有序数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>。</p>

<p>请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为&nbsp;O(log(m + n))。</p>

<p>你可以假设&nbsp;<code>nums1</code>&nbsp;和&nbsp;<code>nums2</code>&nbsp;不会同时为空。</p>

<p><strong>示例 1:</strong></p>

<pre>nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
</pre>

<p><strong>示例 2:</strong></p>

<pre>nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
</pre>


---
### 思路
```
没能达成时间复杂度为 O(log(m + n))。
先尝试把题做出来。
```


### 答题
``` C++
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size();
	int n = nums2.size();
	if (m > n) return findMedianSortedArrays(nums2, nums1);
	if (m + n == 1) return nums2[0];

	bool odd = (m + n) % 2 == 1;
	int i1 = 0;
	int i2 = 0;
	int iPrev2 = 0;
	int iPrev = 0;

	while (i1 + i2 < (m + n) / 2 + 1)
	{
		iPrev2 = iPrev;
		if (odd && i1 == m) return nums2[n - (m + n) / 2 - 1];
		else if (odd && i2 == n) return nums1[m - (m + n) / 2 - 1];
		else if (!odd && i1 == m) iPrev = nums2[i2++];
		else if (!odd && i2 == n) iPrev = nums1[i1++];
		else iPrev = (nums1[i1] < nums2[i2]) ? nums1[i1++] : nums2[i2++];
	}
	return odd ? iPrev : (double)(iPrev + iPrev2) / 2;
}
```

### 其它

[别人的题解](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/)
