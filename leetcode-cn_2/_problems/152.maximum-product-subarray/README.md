# `（中等）`  [152.maximum-product-subarray 乘积最大子序列](https://leetcode-cn.com/problems/maximum-product-subarray/)

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
	if (nums.empty()) return 0;

	int ans = INT_MIN;
	int product_all = 1;
	int product_left = 1;
	int product_right = 0;
	size_t start = 0;
	bool bLeft = true;

	auto f = [&](size_t i)
	{
		if (start == i && i == nums.size()) return;
		if (start == i) product_all *= nums[i];
		else if (start != i - 1)
		{
			product_all = (product_all < 0) ? max(product_all / product_left, product_all / product_right) : product_all;
		}
		ans = max(ans, product_all);

		product_all = 1;
		product_left = 1;
		product_right = 0;
		start = i + 1;
		bLeft = true;
	};

	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
		{
			f(i);
			ans = max(ans, 0);
			continue;
		}
		if (nums[i] < 0)
		{
			product_left = bLeft ? product_left * nums[i] : product_left;
			bLeft = false;
			product_right = 1;
		}

		product_all *= nums[i];
		product_left = bLeft ? product_left * nums[i] : product_left;
		product_right *= nums[i];
	}
	f(nums.size());
	return ans;
}
```

### 其它
```C++
int maxProduct(vector<int>& nums) 
{
	int ans = INT_MIN;
	int maxTmp = 1;
	int minTmp = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] < 0)
		{
			swap(maxTmp, minTmp);
		}
		maxTmp = max(nums[i], maxTmp * nums[i]);
		minTmp = min(nums[i], minTmp * nums[i]);
		ans = max(ans, maxTmp);
	}
	return ans;
}
```

