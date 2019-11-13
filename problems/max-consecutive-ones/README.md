# `（简单）` [485.max-consecutive-ones 最大连续1的个数](https://leetcode-cn.com/problems/max-consecutive-ones/)

### 题目描述
<p>给定一个二进制数组， 计算其中最大连续1的个数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [1,1,0,1,1,1]
<strong>输出:</strong> 3
<strong>解释:</strong> 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
</pre>

<p><strong>注意：</strong></p>

<ul>
	<li>输入的数组只包含&nbsp;<code>0</code> 和<code>1</code>。</li>
	<li>输入数组的长度是正整数，且不超过 10,000。</li>
</ul>


---
### 思路
```
```

### 答题
``` C++
int findMaxConsecutiveOnes(vector<int>& nums)
{
	int len = 0;
	int k = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
		{
			len = max(len, k);
			k = 0;
			continue;
		}
		k++;
	}
	return max(len, k);
}
```
