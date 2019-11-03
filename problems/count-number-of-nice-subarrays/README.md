# `（中等）` [5248.count-number-of-nice-subarrays 统计「优美子数组」](https://leetcode-cn.com/problems/count-number-of-nice-subarrays/)

[contest](https://leetcode-cn.com/contest/weekly-contest-161/problems/count-number-of-nice-subarrays/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>nums</code> 和一个整数 <code>k</code>。</p>

<p>如果某个子数组中恰好有 <code>k</code> 个奇数数字，我们就认为这个子数组是「<strong>优美子数组</strong>」。</p>

<p>请返回这个数组中「优美子数组」的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,2,1,1], k = 3
<strong>输出：</strong>2
<strong>解释：</strong>包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [2,4,6], k = 1
<strong>输出：</strong>0
<strong>解释：</strong>数列中不包含任何奇数，所以不存在优美子数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [2,2,2,1,2,2,1,2,2,2], k = 2
<strong>输出：</strong>16
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^5</code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
int numberOfSubarrays(vector<int>& nums, int k)
{
	int ans = 0;
	int cnt = 0;
	int a = 1;
	int b = 1;

	int i = 0;
	for (int j = i; j < nums.size(); j++)
	{
		if (nums[j] & 1)
		{
			cnt++;
		}
		else if (cnt == k)
		{
			b++;
		}

		if (cnt > k)
		{
			while (!(nums[i++] & 1)) a++;
			cnt--;
			ans += a * b;
			a = 1;
			b = 1;
		}
	}

	if (cnt < k) return 0;

	while (!(nums[i++] & 1)) a++;
	ans += a * b;
	return ans;
}
```




