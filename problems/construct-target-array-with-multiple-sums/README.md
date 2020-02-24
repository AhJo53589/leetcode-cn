# `（困难）` [1354.construct-target-array-with-multiple-sums 多次求和构造目标数组](https://leetcode-cn.com/problems/construct-target-array-with-multiple-sums/)

[contest](https://leetcode-cn.com/contest/weekly-contest-176/problems/construct-target-array-with-multiple-sums/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>target</code> 。一开始，你有一个数组&nbsp;<code>A</code> ，它的所有元素均为 1 ，你可以执行以下操作：</p>

<ul>
	<li>令&nbsp;<code>x</code>&nbsp;为你数组里所有元素的和</li>
	<li>选择满足&nbsp;<code>0 &lt;= i &lt; target.size</code>&nbsp;的任意下标&nbsp;<code>i</code>&nbsp;，并让&nbsp;<code>A</code>&nbsp;数组里下标为&nbsp;<code>i</code>&nbsp;处的值为&nbsp;<code>x</code>&nbsp;。</li>
	<li>你可以重复该过程任意次</li>
</ul>

<p>如果能从&nbsp;<code>A</code>&nbsp;开始构造出目标数组&nbsp;<code>target</code>&nbsp;，请你返回 True ，否则返回 False 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>target = [9,3,5]
<strong>输出：</strong>true
<strong>解释：</strong>从 [1, 1, 1] 开始
[1, 1, 1], 和为 3 ，选择下标 1
[1, 3, 1], 和为 5， 选择下标 2
[1, 3, 5], 和为 9， 选择下标 0
[9, 3, 5] 完成
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>target = [1,1,1,2]
<strong>输出：</strong>false
<strong>解释：</strong>不可能从 [1,1,1,1] 出发构造目标数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>target = [8,5]
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>N == target.length</code></li>
	<li><code>1 &lt;= target.length&nbsp;&lt;= 5 * 10^4</code></li>
	<li><code>1 &lt;= target[i] &lt;= 10^9</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
	bool isPossible(vector<int>& target)
	{
		return isPossible(target, 0);
	}

	bool isPossible(vector<int>& target, long long sum) 
	{
		if (all_of(target.begin(), target.end(), [](auto num) { return num == 1; })) return true;

		sum = (sum != 0) ? sum : accumulate(target.begin(), target.end(), sum);
		for (auto& num : target) 
		{
			auto temp = num * 2 - sum;
			if (temp < 1) continue;
			num = temp;
			return isPossible(target, (num + sum) / 2);
		}
		return false;
	}
};
```




