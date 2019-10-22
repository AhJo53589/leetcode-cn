# `（简单）`  [217.ContainsDuplicate 存在重复元素](https://leetcode-cn.com/problems/contains-duplicate/)

### 题目描述
<p>给定一个整数数组，判断是否存在重复元素。</p>

<p>如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [1,2,3,1]
<strong>输出:</strong> true</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>[1,2,3,4]
<strong>输出:</strong> false</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre><strong>输入: </strong>[1,1,1,3,3,4,3,2,4,2]
<strong>输出:</strong> true</pre>




---
### 思路
```

```


### 答题
``` C++
bool containsDuplicate(vector<int>& nums)
{
	sort(nums.begin(), nums.end());

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i - 1] == nums[i]) return true;
	}

	return false;
}
``` 

### 其它
这道题前两天面试官现场问我的，  
当时我说先排序，再判断相邻两个数字是否相同。  
面试官还问可不可以不排序，  
我就又说用map记录一下。  
结果测试速度最快的就是先排序那个方法。  