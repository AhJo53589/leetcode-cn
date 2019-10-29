# `（中等）` [220.contains-duplicate-iii 存在重复元素 III](https://leetcode-cn.com/problems/contains-duplicate-iii/)

### 题目描述
<p>给定一个整数数组，判断数组中是否有两个不同的索引 <em>i</em> 和 <em>j</em>，使得&nbsp;<strong>nums [i]</strong> 和&nbsp;<strong>nums [j]</strong>&nbsp;的差的绝对值最大为 <em>t</em>，并且 <em>i</em> 和 <em>j</em> 之间的差的绝对值最大为 <em>ķ</em>。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> nums = [1,2,3,1], k<em> </em>= 3, t = 0
<strong>输出:</strong> true</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>nums = [1,0,1,1], k<em> </em>=<em> </em>1, t = 2
<strong>输出:</strong> true</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入: </strong>nums = [1,5,9,1,5,9], k = 2, t = 3
<strong>输出:</strong> false</pre>


---
### 思路
```
学习了set的原理和lower_bound的应用。
```

[发布的题解](https://leetcode-cn.com/problems/contains-duplicate-iii/solution/220-by-ikaruga/)

### 答题
``` C++
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
{
	set<double> _set;
	for (int i = 0; i < nums.size(); ++i) 
	{
		auto s = _set.lower_bound((double)nums[i] - (double)t);
		if (s != _set.end() && *s <= (double)nums[i] + (double)t) return true;

		_set.insert(nums[i]);
		if (_set.size() > k) _set.erase(nums[i - k]);
	}
	return false;
}
```
