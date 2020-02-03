# `（中等）` [152.maximum-product-subarray 乘积最大子序列](https://leetcode-cn.com/problems/maximum-product-subarray/)

### 题目描述
<p>给定一个整数数组 <code>nums</code>&nbsp;，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。</p>
<p><strong>示例 1:</strong></p>
<pre><strong>输入:</strong> [2,3,-2,4]
<strong>输出:</strong> <code>6</code>
<strong>解释:</strong>&nbsp;子数组 [2,3] 有最大乘积 6。
</pre>

<p><strong>示例 2:</strong></p>
<pre><strong>输入:</strong> [-2,0,-1]
<strong>输出:</strong> 0
<strong>解释:</strong>&nbsp;结果不能为 2, 因为 [-2,-1] 不是子数组。</pre>

---
### 思路
```

```

### 答题
``` C++
int maxProduct(vector<int>& nums)
{
	int ans = INT_MIN;
	int maxP = 1;
	int minP = 1;
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] < 0)
		{
			swap(maxP, minP);
		}
		maxP = max(maxP * nums[i], nums[i]);
		minP = min(minP * nums[i], nums[i]);
		ans = max(ans, maxP);
	}
	return ans;
}
```

### 其它
```C++

```

