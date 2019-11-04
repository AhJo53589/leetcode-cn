# `（中等）` [1248.count-number-of-nice-subarrays 统计「优美子数组」](https://leetcode-cn.com/problems/count-number-of-nice-subarrays/)

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

​            

---
### 思路
```

```

[发布的题解](https://leetcode-cn.com/problems/count-number-of-nice-subarrays/solution/1248-by-ikaruga/)



### 答题

``` C++
int numberOfSubarrays(vector<int>& nums, int k)
{
	vector<int> odd;
	odd.push_back(-1);

	int ans = 0;
	int i = 1;
	for (int j = 0; j <= nums.size(); j++)
	{
		if (j == nums.size() || (nums[j] & 1))
		{
			odd.push_back(j);
		}

		if (odd.size() - i > k)
		{
			int a = odd[i] - odd[i - 1];
			int b = j - odd[odd.size() - 2];
			ans += a * b;
			i++;
		}
	}
	return ans;
}
```



### 其它

前缀和

```C++
int numberOfSubarrays(vector<int>& nums, int k) 
{
	int n = nums.size();
	vector<int> arr;
	arr.push_back(0);
	for (auto x : nums)
	{
		arr.push_back(arr.back() + (x & 1));
	}

	unordered_map<int, int> h;
	int ans = 0;

	for (auto x : arr) 
	{
		ans += h[x - k];
		h[x] ++;
	}
	return ans;
}
```

