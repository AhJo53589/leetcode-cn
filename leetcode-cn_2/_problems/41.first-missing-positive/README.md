# `（困难）`  [41.first-missing-positive 缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/)

### 题目描述
<p>给定一个未排序的整数数组，找出其中没有出现的最小的正整数。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>输入: [1,2,0]
输出: 3
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>输入: [3,4,-1,1]
输出: 2
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre>输入: [7,8,9,11,12]
输出: 1
</pre>

<p><strong>说明:</strong></p>

<p>你的算法的时间复杂度应为O(<em>n</em>)，并且只能使用常数级别的空间。</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/first-missing-positive/solution/41-by-ikaruga/)

### 答题
``` C++
int firstMissingPositive(vector<int>& nums) 
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] >= 1 && nums[i] < nums.size())
		{
			int t = nums[i] - 1;
			if (nums[i] != nums[t])
			{
				swap(nums[i], nums[t]);
				i -= (t > i);
			}
		}
	}
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] != i + 1) return i + 1;
	}
	return nums.size() + 1;
}
```

### 其它
``` C++
```

