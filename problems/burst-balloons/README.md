# `（困难）` [312.burst-balloons 戳气球](https://leetcode-cn.com/problems/burst-balloons/)

### 题目描述
<p>有 <code>n</code> 个气球，编号为<code>0</code> 到 <code>n-1</code>，每个气球上都标有一个数字，这些数字存在数组&nbsp;<code>nums</code>&nbsp;中。</p>

<p>现在要求你戳破所有的气球。每当你戳破一个气球 <code>i</code> 时，你可以获得&nbsp;<code>nums[left] * nums[i] * nums[right]</code>&nbsp;个硬币。&nbsp;这里的&nbsp;<code>left</code>&nbsp;和&nbsp;<code>right</code>&nbsp;代表和&nbsp;<code>i</code>&nbsp;相邻的两个气球的序号。注意当你戳破了气球 <code>i</code> 后，气球&nbsp;<code>left</code>&nbsp;和气球&nbsp;<code>right</code>&nbsp;就变成了相邻的气球。</p>

<p>求所能获得硬币的最大数量。</p>

<p><strong>说明:</strong></p>

<ul>
	<li>你可以假设&nbsp;<code>nums[-1] = nums[n] = 1</code>，但注意它们不是真实存在的所以并不能被戳破。</li>
	<li>0 ≤ <code>n</code> ≤ 500, 0 ≤ <code>nums[i]</code> ≤ 100</li>
</ul>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> <code>[3,1,5,8]</code>
<strong>输出:</strong> <code>167 
<strong>解释: </strong></code>nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
&nbsp;    coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int maxCoins(vector<int>& nums) 
	{
		cache = vector<vector<int>>(nums.size(), vector<int>(nums.size(), 0));
		int ans = getMaxCoins(nums, 0, nums.size() - 1);
		return ans;
    }

	int getMaxCoins(vector<int>& nums, int start, int end)
	{
		if (start > end) return 0;
		if (cache[start][end] != 0) return cache[start][end];

		for (int i = start; i <= end; i++)
		{
			int a = (start == 0) ? 1 : nums[start - 1];
			int b = (end == nums.size() - 1) ? 1 : nums[end + 1];
			int temp = a * nums[i] * b + getMaxCoins(nums, start, i - 1) + getMaxCoins(nums, i + 1, end);
			cache[start][end] = max(cache[start][end], temp);
		}
		return cache[start][end];
	}

private:
	vector<vector<int>> cache;
};
```




