# `（简单）` [674.longest-continuous-increasing-subsequence 最长连续递增序列](https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/)

### 题目描述
<p>给定一个未经排序的整数数组，找到最长且<strong>连续</strong>的的递增序列。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [1,3,5,4,7]
<strong>输出:</strong> 3
<strong>解释:</strong> 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [2,2,2,2,2]
<strong>输出:</strong> 1
<strong>解释:</strong> 最长连续递增序列是 [2], 长度为1。
</pre>

<p><strong>注意：</strong>数组长度不会超过10000。</p>


---
### 思路
```
```

### 答题
``` C++
int findLengthOfLCIS(vector<int>& nums)
{
	if (nums.size() == 0) return 0;
	int ans = 1;
	int temp = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] > nums[i - 1])
		{
			temp++;
			ans = max(ans, temp);
		}
		else
		{
			temp = 1;
		}
	}
	return ans;
}
```

### 其它
``` C++
```

