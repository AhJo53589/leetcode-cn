# `（简单）` [219.contains-duplicate-ii 存在重复元素 II](https://leetcode-cn.com/problems/contains-duplicate-ii/)

### 题目描述
<p>给定一个整数数组和一个整数&nbsp;<em>k</em>，判断数组中是否存在两个不同的索引<em>&nbsp;i</em>&nbsp;和<em>&nbsp;j</em>，使得&nbsp;<strong>nums [i] = nums [j]</strong>，并且 <em>i</em> 和 <em>j</em>&nbsp;的差的绝对值最大为 <em>k</em>。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> nums = [1,2,3,1], k<em> </em>= 3
<strong>输出:</strong> true</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>nums = [1,0,1,1], k<em> </em>=<em> </em>1
<strong>输出:</strong> true</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入: </strong>nums = [1,2,3,1,2,3], k<em> </em>=<em> </em>2
<strong>输出:</strong> false</pre>


---
### 思路
```
这题考的阅读理解吧  
实际上求的是：数组里至少有一个数字有多个，并且这个数字的所有索引中差值最小的值，不大于k。  
而不是，求这个数字，所有索引的差值全都不大于k。
```

### 答题
``` C++
bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
	if (nums.empty()) return false;
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
	{
		if (!m.count(nums[i])) m[nums[i]] = i;
		else if (i - m[nums[i]] <= k) return true;
		else m[nums[i]] = i;
	}
	return false;
}
```


