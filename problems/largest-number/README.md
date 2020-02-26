# `（中等）` [179.largest-number 最大数](https://leetcode-cn.com/problems/largest-number/)

### 题目描述
<p>给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。</p>
<p><strong>示例 1:</strong></p>
<pre><strong>输入:</strong> <code>[10,2]</code>
<strong>输出:</strong> <code>210</code></pre>

<p><strong>示例&nbsp;2:</strong></p>
<pre><strong>输入:</strong> <code>[3,30,34,5,9]</code>
<strong>输出:</strong> <code>9534330</code></pre>

<p><strong>说明: </strong>输出结果可能非常大，所以你需要返回一个字符串而不是整数。</p>

---
### 思路
```
写一个排序算法。
使用数字比较。
```

[发布的题解](https://leetcode-cn.com/problems/largest-number/solution/179-by-ikaruga/)

### 答题
``` C++
string largestNumber(vector<int>& nums) 
{
	auto f_sort = [](const int &a, const int &b)
	{
		long long n_a = 10;
		while (a / n_a) n_a *= 10;
		long long n_b = 10;
		while (b / n_b) n_b *= 10;
		long long r_a = (long long)a * n_b + (long long)b;
		long long r_b = (long long)b * n_a + (long long)a;
		return r_a < r_b;
	};

	sort(nums.rbegin(), nums.rend(), f_sort);

	string ans;
	bool bZeroFlag = true;
	for (auto &n : nums)
	{
		if (bZeroFlag)
		{
			if (n == 0) continue;
			bZeroFlag = false;
		}
		ans.append(to_string(n));
	}
	return ans.empty() ? "0" : ans;
}
```

### 其它
使用字符串比较。
``` C++
string largestNumber(vector<int>& nums)
{
	if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) return string("0");

	vector<string> strNums(nums.size());
	std::transform(nums.begin(), nums.end(), strNums.begin(), [](int x) { return std::to_string(x);	});

	std::sort(strNums.rbegin(), strNums.rend(), [](const string& a, const string& b) { return a + b < b + a; });

	return std::accumulate(strNums.begin(), strNums.end(), string());
}
```

