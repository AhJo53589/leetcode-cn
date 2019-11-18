# `（简单）` [747.largest-number-at-least-twice-of-others 至少是其他数字两倍的最大数](https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others/)

### 题目描述
<p>在一个给定的数组<code>nums</code>中，总是存在一个最大元素 。</p>

<p>查找数组中的最大元素是否至少是数组中每个其他数字的两倍。</p>

<p>如果是，则返回最大元素的索引，否则返回-1。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> nums = [3, 6, 1, 0]
<strong>输出:</strong> 1
<strong>解释:</strong> 6是最大的整数, 对于数组中的其他整数,
6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.
</pre>

<p>&nbsp;</p>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> nums = [1, 2, 3, 4]
<strong>输出:</strong> -1
<strong>解释:</strong> 4没有超过3的两倍大, 所以我们返回 -1.
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ol>
	<li><code>nums</code>&nbsp;的长度范围在<code>[1, 50]</code>.</li>
	<li>每个&nbsp;<code>nums[i]</code>&nbsp;的整数范围在&nbsp;<code>[0, 99]</code>.</li>
</ol>


---
### 思路
```
遍历一遍数组，找出最大的数和第二大的数。  
最后判断一下最大的是否是第二大的数的2倍。  
注意只有一个数的情况返回0，题目也不说清楚。  
```

### 答题
``` C++
int dominantIndex(vector<int>& nums) 
{
	if (nums.size() == 0) return -1;
	if (nums.size() == 1) return 0;
	int max = nums[0] < nums[1] ? 1 : 0;
	int second = nums[0] < nums[1] ? 0 : 1;
	for (int i = 2; i < nums.size(); i++)
	{
		if (nums[i] >= nums[max])
		{
			second = max;
			max = i;
		}
		else if (nums[i] >= nums[second])
		{
			second = i;
		}
	}
	if (nums[max] >= nums[second] * 2) return max;
	return -1;
}
```

