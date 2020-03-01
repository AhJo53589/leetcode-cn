# `（简单）` [5344.how-many-numbers-are-smaller-than-the-current-number 有多少小于当前数字的数字](https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number/)

[contest](https://leetcode-cn.com/contest/weekly-contest-178/problems/how-many-numbers-are-smaller-than-the-current-number/)

### 题目描述
<p>给你一个数组&nbsp;<code>nums</code>，对于其中每个元素&nbsp;<code>nums[i]</code>，请你统计数组中比它小的所有数字的数目。</p>

<p>换而言之，对于每个&nbsp;<code>nums[i]</code>&nbsp;你必须计算出有效的&nbsp;<code>j</code>&nbsp;的数量，其中 <code>j</code> 满足&nbsp;<code>j != i</code> <strong>且</strong> <code>nums[j] &lt; nums[i]</code>&nbsp;。</p>

<p>以数组形式返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [8,1,2,2,3]
<strong>输出：</strong>[4,0,1,1,3]
<strong>解释：</strong> 
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。 
对于 nums[3]=2 存在一个比它小的数字：（1）。 
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [6,5,4,8]
<strong>输出：</strong>[2,1,0,3]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [7,7,7,7]
<strong>输出：</strong>[0,0,0,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 500</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
	{
		map<int, int> count;
		for (auto& n : nums)
		{
			count[n]++;
		}
		int t = 0;
		for (auto& p : count)
		{
			int temp = p.second;
			p.second = t;
			t += temp;
		}
		for (auto& n : nums)
		{
			n = count[n];
		}
		return nums;
    }
};
```




