# `（中等）` [162.find-peak-element 寻找峰值](https://leetcode-cn.com/problems/find-peak-element/)

### 题目描述
<p>峰值元素是指其值大于左右相邻值的元素。</p>

<p>给定一个输入数组&nbsp;<code>nums</code>，其中 <code>nums[i] ≠ nums[i+1]</code>，找到峰值元素并返回其索引。</p>

<p>数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。</p>

<p>你可以假设&nbsp;<code>nums[-1] = nums[n] = -∞</code>。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <strong>nums</strong> = <code>[1,2,3,1]</code>
<strong>输出:</strong> 2
<strong>解释: </strong>3 是峰值元素，你的函数应该返回其索引 2。</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> <strong>nums</strong> = <code>[</code>1,2,1,3,5,6,4]
<strong>输出:</strong> 1 或 5 
<strong>解释:</strong> 你的函数可以返回索引 1，其峰值元素为 2；
&nbsp;    或者返回索引 5， 其峰值元素为 6。
</pre>

<p><strong>说明:</strong></p>

<p>你的解法应该是&nbsp;<em>O</em>(<em>logN</em>)<em>&nbsp;</em>时间复杂度的。</p>


---
### 思路
```
```

### 答题
``` C++
int findPeakElement(vector<int>& nums) 
{
	int low = 0;
	int high = nums.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		bool l = (mid == 0 || nums[mid - 1] < nums[mid]);
		bool r = (mid == nums.size() - 1 || nums[mid + 1] < nums[mid]);
		if (l && r) return mid;
		else if (l) low = mid + 1;
		else high = mid;
	}
	return (low < nums.size()) ? low : -1;
}
```
