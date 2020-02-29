# `（中等）` [1109.corporate-flight-bookings 航班预订统计](https://leetcode-cn.com/problems/corporate-flight-bookings/)

### 题目描述
<p>这里有&nbsp;<code>n</code>&nbsp;个航班，它们分别从 <code>1</code> 到 <code>n</code> 进行编号。</p>

<p>我们这儿有一份航班预订表，表中第&nbsp;<code>i</code>&nbsp;条预订记录&nbsp;<code>bookings[i] = [i, j, k]</code>&nbsp;意味着我们在从&nbsp;<code>i</code>&nbsp;到&nbsp;<code>j</code>&nbsp;的每个航班上预订了 <code>k</code> 个座位。</p>

<p>请你返回一个长度为 <code>n</code> 的数组&nbsp;<code>answer</code>，按航班编号顺序返回每个航班上预订的座位数。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
<strong>输出：</strong>[10,55,45,25,25]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= bookings.length <= 20000</code></li>
	<li><code>1 <= bookings[i][0] <= bookings[i][1] <= n <= 20000</code></li>
	<li><code>1 <= bookings[i][2] <= 10000</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/zuma-game/solution/488-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
	{
		vector<int> ans(n + 1, 0);
		for (auto& b: bookings)
		{
			ans[b[0] - 1] += b[2];
			ans[b[1]] -= b[2];
		}
		for (int i = 1; i < n; i++)
		{
			ans[i] += ans[i - 1];
		}
		ans.pop_back();
		return ans;
    }
};
```




