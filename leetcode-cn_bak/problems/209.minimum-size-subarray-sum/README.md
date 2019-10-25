# `（简单）`  [209.minimum-size-subarray-sum 长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)

### 题目描述
<p>给定一个含有&nbsp;<strong>n&nbsp;</strong>个正整数的数组和一个正整数&nbsp;<strong>s ，</strong>找出该数组中满足其和<strong> ≥ s </strong>的长度最小的连续子数组<strong>。</strong>如果不存在符合条件的连续子数组，返回 0。</p>

<p><strong>示例:&nbsp;</strong></p>

<pre><strong>输入:</strong> <code>s = 7, nums = [2,3,1,2,4,3]</code>
<strong>输出:</strong> 2
<strong>解释: </strong>子数组&nbsp;<code>[4,3]</code>&nbsp;是该条件下的长度最小的连续子数组。
</pre>

<p><strong>进阶:</strong></p>

<p>如果你已经完成了<em>O</em>(<em>n</em>) 时间复杂度的解法, 请尝试&nbsp;<em>O</em>(<em>n</em> log <em>n</em>) 时间复杂度的解法。</p>


---
### 思路
```
使用双指针。  
记录low-high之间的和sum。  
当sum >= s时，说明找到符合条件的子串，记录长度，  
然后移动low，并调整sum。
当sum < s时，移动high，继续寻找。  
```

### 答题
``` C++
int minSubArrayLen(int s, vector<int>& nums)
{
	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return nums[0] >= s ? 1 : 0;

	int iLen_min = INT_MAX;
	int low = 0;
	int high = 1;
	int sum = nums[low] + nums[high];
	while (low < nums.size() - 1)
	{
		if (nums[low] >= s) return 1;
		if (sum >= s)
		{
			iLen_min = min(iLen_min, high - low + 1);
			sum -= nums[low];
			low++;
		}
		else
		{
			high++;
			if (high == nums.size()) break;
			sum += nums[high];
		}
	}
	return iLen_min == INT_MAX ? 0 : iLen_min;
}

```

