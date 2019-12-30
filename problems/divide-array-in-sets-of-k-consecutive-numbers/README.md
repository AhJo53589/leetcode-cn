# `（中等）` [1296.divide-array-in-sets-of-k-consecutive-numbers 划分数组为连续数字的集合](https://leetcode-cn.com/problems/divide-array-in-sets-of-k-consecutive-numbers/)

[contest](https://leetcode-cn.com/contest/weekly-contest-168/problems/divide-array-in-sets-of-k-consecutive-numbers/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个正整数&nbsp;<code>k</code>，请你判断是否可以把这个数组划分成一些由&nbsp;<code>k</code>&nbsp;个连续数字组成的集合。<br>
如果可以，请返回&nbsp;<code>True</code>；否则，返回&nbsp;<code>False</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,3,4,4,5,6], k = 4
<strong>输出：</strong>true
<strong>解释：</strong>数组可以分成 [1,2,3,4] 和 [3,4,5,6]。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
<strong>输出：</strong>true
<strong>解释：</strong>数组可以分成 [1,2,3] , [2,3,4] , [3,4,5] 和 [9,10,11]。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,3,2,2,1,1], k = 3
<strong>输出：</strong>true
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4], k = 3
<strong>输出：</strong>false
<strong>解释：</strong>数组不能分成几个大小为 3 的子数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^9</code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
bool isPossibleDivide(vector<int>& nums, int k) 
{
	map<int, int> cnts;
	for (auto n : nums) cnts[n]++;

	for (auto it = cnts.begin(); it != cnts.end(); it++)
	{
		while (it->second != 0)
		{
			int _first = it->first;
			it->second--;
			for (int i = 1; i < k; i++)
			{
				int t = _first + i;
				if (cnts.count(t) == 0) return false;
				if (cnts[t]-- == 0) return false;
			}
		}
	}
	return true;
}
```




