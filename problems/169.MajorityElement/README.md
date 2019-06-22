# `（简单）`  [169.MajorityElement 求众数](https://leetcode-cn.com/problems/majority-element/)

### 题目描述
<p>给定一个大小为 <em>n </em>的数组，找到其中的众数。众数是指在数组中出现次数<strong>大于</strong>&nbsp;<code>⌊ n/2 ⌋</code>&nbsp;的元素。</p>

<p>你可以假设数组是非空的，并且给定的数组总是存在众数。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> [3,2,3]
<strong>输出:</strong> 3</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> [2,2,1,1,1,2,2]
<strong>输出:</strong> 2
</pre>


---
### 思路
```

```


### 答题
``` C++
int majorityElement(vector<int>& nums)
{
	int res = 0, cnt = 0;
	for (int num : nums) 
	{
		if (cnt == 0) 
		{ 
			res = num;
			++cnt; 
		}
		else
		{
			(num == res) ? ++cnt : --cnt;
		}
	}
	return res;
}
``` 