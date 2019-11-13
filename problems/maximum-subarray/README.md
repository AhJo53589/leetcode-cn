# `（简单）` [53.maximum-subarray 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)

### 题目描述
<p>给定一个整数数组 <code>nums</code>&nbsp;，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [-2,1,-3,4,-1,2,1,-5,4],
<strong>输出:</strong> 6
<strong>解释:</strong>&nbsp;连续子数组&nbsp;[4,-1,2,1] 的和最大，为&nbsp;6。
</pre>

<p><strong>进阶:</strong></p>

<p>如果你已经实现复杂度为 O(<em>n</em>) 的解法，尝试使用更为精妙的分治法求解。</p>



---
### 思路
```
就是昨天终于认定这个题要用分治法了，  
照着书上伪代码写完，发现  
别人的代码好简单。  
```


### 答题
``` C++
int maxSubArrayCross(vector<int> &nums, int low, int mid, int high)
{
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int sum = 0;
	for (int i = mid; i >= 0; i--)
	{
		sum += nums[i];
		left_sum = max(left_sum, sum);
	}
	sum = 0;
	for (int i = mid + 1; i <= high; i++)
	{
		sum += nums[i];
		right_sum = max(right_sum, sum);
	}
	return left_sum + right_sum;
}

int maxSubArraySide(vector<int>& nums, int low, int high)
{
	if (low == high) return nums[low];

	int _Mid = low + (high - low) / 2;
	int left_sum = maxSubArraySide(nums, low, _Mid);
	int right_sum = maxSubArraySide(nums, _Mid + 1, high);
	int cross_sum = maxSubArrayCross(nums, low, _Mid, high);

	return max(left_sum, max(right_sum, cross_sum));
}

int maxSubArray(vector<int>& nums)
{
	// 分治法
	int low = 0;
	int high = nums.size() - 1;
	return maxSubArraySide(nums, low, high);
}
``` 


### 其它
``` C++
int maxSubArray(vector<int>& nums)
{
	//法1：复杂度为O(n)的解法
	int res = INT_MIN, sum = 0;
	for (int n : nums) {
		sum = max(n, sum + n);
		res = max(sum, res);
	}
	return res;
}
``` 
