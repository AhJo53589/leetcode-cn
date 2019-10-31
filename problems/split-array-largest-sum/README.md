# `（困难）` [410.split-array-largest-sum 分割数组的最大值](https://leetcode-cn.com/problems/split-array-largest-sum/)

### 题目描述
<p>给定一个非负整数数组和一个整数&nbsp;<em>m</em>，你需要将这个数组分成&nbsp;<em>m&nbsp;</em>个非空的连续子数组。设计一个算法使得这&nbsp;<em>m&nbsp;</em>个子数组各自和的最大值最小。</p>

<p><strong>注意:</strong><br>
数组长度&nbsp;<em>n&nbsp;</em>满足以下条件:</p>

<ul>
	<li>1 ≤ <em>n</em> ≤ 1000</li>
	<li>1 ≤ <em>m</em> ≤ min(50, <em>n</em>)</li>
</ul>

<p><strong>示例: </strong></p>

<pre>输入:
<strong>nums</strong> = [7,2,5,10,8]
<strong>m</strong> = 2

输出:
18

解释:
一共有四种方法将<strong>nums</strong>分割为2个子数组。
其中最好的方式是将其分为<strong>[7,2,5]</strong> 和 <strong>[10,8]</strong>，
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/split-array-largest-sum/solution/410-by-ikaruga/)

### 答题
``` C++
int splitArray(vector<int>& nums, int m, int split_sum)
{
	long long sum = 0;
	long long nextsum = 0;
	int cnt = 1;
	for (int &n : nums) 
	{
		if (sum + n > split_sum)
		{
			nextsum = (nextsum == 0) ? sum + n : min(nextsum, sum + n);

			sum = n;
			++cnt;
			if (cnt > m) return splitArray(nums, m, nextsum);
		}
		else sum += n;
	}
	return split_sum;
}

int splitArray(vector<int>& nums, int m)
{
	int num_max = 0;
	long long sum = 0;
	for (auto &n : nums)
	{
		num_max = max(num_max, n);
		sum += n;
	}
	return splitArray(nums, m, max((int)(sum / m), num_max));
}
```

### 其它
``` C++
// 二分查找 4ms
bool canSplit(vector<int>& nums, int m, int split_sum) 
{
	long long sum = 0;
	int cnt = 1;
	for (auto &n : nums) 
	{
		if (sum + n > split_sum) 
		{
			sum = n;
			++cnt;
			if (cnt > m) return false;
		}
		else sum += n;
	}
	return true;
}

int splitArray(vector<int>& nums, int m) 
{
	long long l = 0;
	long long r = 0;
	for (auto &n : nums) 
	{
		r += n;
		l = max(l, (long long)n);
	}

	while (l < r)
	{
		int mid = l + (r - l) / 2;
		if (canSplit(nums, m, mid)) r = mid;
		else l = mid + 1;
	}
	return r;
}
```

