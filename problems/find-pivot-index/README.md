# `（简单）` [724.find-pivot-index 寻找数组的中心索引](https://leetcode-cn.com/problems/find-pivot-index/)

### 题目描述
<p>给定一个整数类型的数组&nbsp;<code>nums</code>，请编写一个能够返回数组<strong>“中心索引”</strong>的方法。</p>

<p>我们是这样定义数组<strong>中心索引</strong>的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。</p>

<p>如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 
nums = [1, 7, 3, 6, 5, 6]
<strong>输出:</strong> 3
<strong>解释:</strong> 
索引3 (nums[3] = 6) 的左侧数之和(1 + 7 + 3 = 11)，与右侧数之和(5 + 6 = 11)相等。
同时, 3 也是第一个符合要求的中心索引。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 
nums = [1, 2, 3]
<strong>输出:</strong> -1
<strong>解释:</strong> 
数组中不存在满足此条件的中心索引。</pre>

<p><strong>说明:</strong></p>

<ul>
	<li><code>nums</code> 的长度范围为&nbsp;<code>[0, 10000]</code>。</li>
	<li>任何一个&nbsp;<code>nums[i]</code> 将会是一个范围在&nbsp;<code>[-1000, 1000]</code>的整数。</li>
</ul>


---
### 思路
```
记录左边和，右边和。  
遍历数组，根据索引的增加，对左边和加，对右边和减。  
注意一下处理的顺序。
```

### 答题
``` C++
int pivotIndex(vector<int>& nums) 
{
	if (nums.size() == 0) return -1;
	int sum_l = 0;
	int sum_r = 0;
	for (auto i : nums) sum_r += i;
	for (int i = 0; i < nums.size(); i++)
	{
		sum_r -= nums[i];
		if (sum_l == sum_r) return i;
		sum_l += nums[i];
	}
	return -1;
}
```
