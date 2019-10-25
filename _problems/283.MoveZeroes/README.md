# `（简单）`  [283.MoveZeroes 移动零](https://leetcode-cn.com/problems/move-zeroes/)

### 题目描述
<p>给定一个数组 <code>nums</code>，编写一个函数将所有 <code>0</code> 移动到数组的末尾，同时保持非零元素的相对顺序。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> <code>[0,1,0,3,12]</code>
<strong>输出:</strong> <code>[1,3,12,0,0]</code></pre>

<p><strong>说明</strong>:</p>

<ol>
	<li>必须在原数组上操作，不能拷贝额外的数组。</li>
	<li>尽量减少操作次数。</li>
</ol>



---
### 思路
```

```


### 答题
``` C++
void moveZeroes(vector<int>& nums) 
{
	int iLen = nums.size();
	int j = 0;
	for (int i = 0; i < iLen; ++i)
	{
		if (nums[i] != 0)
		{
			if (i != j)
			{
				swap(nums[i], nums[j]);
			}
			++j;
		}
	}
}
``` 