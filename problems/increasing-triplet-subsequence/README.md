# `（中等）` [334.increasing-triplet-subsequence 递增的三元子序列](https://leetcode-cn.com/problems/increasing-triplet-subsequence/)

### 题目描述
<p>给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。</p>

<p>数学表达式如下:</p>

<blockquote>如果存在这样的&nbsp;<em>i, j, k,&nbsp;</em>&nbsp;且满足&nbsp;0 ≤ <em>i</em> &lt; <em>j</em> &lt; <em>k</em> ≤ <em>n</em>-1，<br>
使得&nbsp;<em>arr[i]</em> &lt; <em>arr[j]</em> &lt; <em>arr[k] </em>，返回 true ;&nbsp;否则返回 false 。</blockquote>

<p><strong>说明:</strong> 要求算法的时间复杂度为 O(<em>n</em>)，空间复杂度为 O(<em>1</em>) 。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>[1,2,3,4,5]
<strong>输出: </strong>true
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>[5,4,3,2,1]
<strong>输出: </strong>false</pre>


---
### 思路
```
使用l记录最小值，m记录中间值。  
使用l2记录新的最小值，当时机合适的时候，将l更新成l2，m更新成当前值，用来整体替换递增子数组。
```

### 答题
``` C++
bool increasingTriplet(vector<int>& nums)
{
	if (nums.size() < 3) return false;
	int l = 0;
	int l2 = 0;
	int m = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (m == l)
		{
			if (nums[l] < nums[i]) m = i;
			else
			{
				l = i;
				l2 = i;
				m = i;
			}
		}
		else
		{
			if (nums[m] < nums[i]) return true;
			if (nums[i] < nums[l2]) l2 = i;
			else if (nums[l2] < nums[i] && nums[i] < nums[m])
			{
				l = l2;
				m = i;
			}
		}
	}
	return false;
}
```

### 其它
因为不用在意最小值是否被修改，最终结果是和中间值做判断。   
所以可以直接写成下面这样。
``` C++
bool increasingTriplet(vector<int>& nums) 
{
	int a = INT_MAX;
	int b = INT_MAX;

	for (auto e : nums) 
	{
		if (e <= a) a = e;
		else if (e <= b) b = e;
		else return true;
	}
	return false;
}
```

