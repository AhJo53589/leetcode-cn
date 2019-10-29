# `（中等）` [300.longest-increasing-subsequence 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

### 题目描述
<p>给定一个无序的整数数组，找到其中最长上升子序列的长度。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> <code>[10,9,2,5,3,7,101,18]
</code><strong>输出: </strong>4 
<strong>解释: </strong>最长的上升子序列是&nbsp;<code>[2,3,7,101]，</code>它的长度是 <code>4</code>。</pre>

<p><strong>说明:</strong></p>

<ul>
	<li>可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。</li>
	<li>你算法的时间复杂度应该为&nbsp;O(<em>n<sup>2</sup></em>) 。</li>
</ul>

<p><strong>进阶:</strong> 你能将算法的时间复杂度降低到&nbsp;O(<em>n</em> log <em>n</em>) 吗?</p>


---
### 思路
```
使用一个数组记录数组中的数字比之前几个数字大，
通过与之前各个数字比较大小，
对大于的数字的记录数加一，
max所有情况就是这个数字的记录。

再使用一个值记录全局最大记录。
```

### 答题
``` C++
int lengthOfLIS(vector<int>& nums)
{
	if (nums.empty()) return 0;
	int res = 0;
	vector<int> dp(nums.size(), 0);
	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				res = max(res, dp[i]);
			}
		}
	}
	return res + 1;
}
```

### 其它
```
对数组中的数字依次拿出来重新进行摆放，
摆放的要求是：
如果比数组中已经排好的数字小，则替换比你大的那个数字，数组长度不增加。
如果比数组中所有数字都大，排在队尾，数组长度增加1。
这个数组的长度就是这个数列最长递增子序列。
因为数组中的数字都在不断替换成更优，但是不影响之前保存的最长长度。
而因为替换过更优，再后续到来的数字，能够以更优的数字来计算新的最长长度。


使用这个办法还有一个最好的地方，
可以使用二分查找法来优化寻找需要替换数字的索引位置，
将O(n2)降为O(nlogn)。
```
``` C++
int lengthOfLIS(vector<int>& nums)
{
	if (nums.size() == 0) return 0;
	vector<int> log(nums.size(), INT_MAX);
	int out = 0;
	for (int pos = 0; pos < nums.size(); pos++)
	{
		int pos1 = 0, pos2 = nums.size() - 1;
		while (pos2 > pos1)
		{
			int mid = (pos1 + pos2) / 2;
			if (log[mid] >= nums[pos]) pos2 = mid;
			else pos1 = mid + 1;
		}
		log[pos1] = nums[pos];
		out = max(out, pos1 + 1);
	}
	return out;
}
```

