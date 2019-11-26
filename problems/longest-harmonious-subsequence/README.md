# `（简单）` [594.longest-harmonious-subsequence 最长和谐子序列](https://leetcode-cn.com/problems/longest-harmonious-subsequence/)

### 题目描述
<p>和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。</p>

<p>现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [1,3,2,2,5,2,3,7]
<strong>输出:</strong> 5
<strong>原因:</strong> 最长的和谐数组是：[3,2,2,2,3].
</pre>

<p><strong>说明:</strong> 输入的数组长度最大不超过20,000.</p>


---
### 思路
```
```



### 答题
``` C++
int findLHS(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int l = 0, ans = 0;
	for (int r = 1; r < nums.size(); ++r)
	{
		while (nums[r] - nums[l] > 1)
		{
			++l;
		}
		if (nums[r] - nums[l] == 1)
		{
			ans = max(ans, r - l + 1);
		}
	}
	return ans;
}
```




