# `（中等）` [1262.greatest-sum-divisible-by-three 可被三整除的最大和](https://leetcode-cn.com/problems/greatest-sum-divisible-by-three/)

[contest](https://leetcode-cn.com/contest/weekly-contest-163/problems/greatest-sum-divisible-by-three/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>nums</code>，请你找出并返回能被三整除的元素最大和。</p>

<ol>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [3,6,5,1,8]
<strong>输出：</strong>18
<strong>解释：</strong>选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [4]
<strong>输出：</strong>0
<strong>解释：</strong>4 不能被 3 整除，所以无法选出数字，返回 0。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,4]
<strong>输出：</strong>12
<strong>解释：</strong>选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 4 * 10^4</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^4</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
int maxSumDivThree(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());

	vector<vector<int>> a(2, vector<int>());
    int ans = 0;
    for (auto n : nums)
    {
		ans += n;
		if ((n % 3) == 0 || a[(n % 3) - 1].size() == 2) continue;
		a[(n % 3) - 1].push_back(n);
	}

	if (ans % 3 != 0)
	{
		int k1 = (ans % 3) - 1;
		int k2 = (k1 == 0) ? 1 : 0;
		int t1 = a[k1].empty() ? INT_MAX : a[k1][0];
		int t2 = a[k2].size() < 2 ? INT_MAX : a[k2][0] + a[k2][1];
		ans -= min(t1, t2);
	}
	return ans;
}
```




