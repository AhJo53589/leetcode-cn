# `（中等）` [60.permutation-sequence 第k个排列](https://leetcode-cn.com/problems/permutation-sequence/)

### 题目描述
<p>给出集合&nbsp;<code>[1,2,3,…,<em>n</em>]</code>，其所有元素共有&nbsp;<em>n</em>! 种排列。</p>

<p>按大小顺序列出所有排列情况，并一一标记，当&nbsp;<em>n </em>= 3 时, 所有排列如下：</p>

<ol>
	<li><code>"123"</code></li>
	<li><code>"132"</code></li>
	<li><code>"213"</code></li>
	<li><code>"231"</code></li>
	<li><code>"312"</code></li>
	<li><code>"321"</code></li>
</ol>

<p>给定&nbsp;<em>n</em> 和&nbsp;<em>k</em>，返回第&nbsp;<em>k</em>&nbsp;个排列。</p>

<p><strong>说明：</strong></p>

<ul>
	<li>给定<em> n</em>&nbsp;的范围是 [1, 9]。</li>
	<li>给定 <em>k&nbsp;</em>的范围是[1, &nbsp;<em>n</em>!]。</li>
</ul>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> n = 3, k = 3
<strong>输出:</strong> "213"
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> n = 4, k = 9
<strong>输出:</strong> "2314"
</pre>


---
### 思路
```
根据k，计算每个位置上应该是哪个数字。
```

### 答题
``` C++
int factorial(unordered_map<int, int> &fac, int k)
{
	if (k < 2) return 1;
	if (fac.count(k)) return fac[k];
	int f = k * factorial(fac, k - 1);
	fac[k] = f;
	return f;
}

void getPermutation(vector<int> &nums, int len, unordered_map<int, int> &fac, int k)
{
	if (k == 0 || len == 0) return;

	int f = factorial(fac, len - 1);
	if (k < f)
	{
		getPermutation(nums, len - 1, fac, k);
	}
	else
	{
		int i = nums.size() - len;
		int j = k / f;
		k -= j * f;

		for (j = min(i + j, (int)nums.size() - 1); j > i; j--)
		{
			swap(nums[j], nums[j - 1]);
		}
		getPermutation(nums, len - 1, fac, k);
	}
}

string getPermutation(int n, int k)
{
	vector<int> nums;
	for (int i = 0; i < n; i++)
	{
		nums.push_back(i + 1);
	}

	unordered_map<int, int> fac;
	getPermutation(nums, nums.size(), fac, k - 1);

	string ans;
	for (auto &n : nums)
	{
		ans += to_string(n);
	}
	return ans;
}
```

### 其它
先写的暴力全排列输出。
``` C++
void getPermutation(vector<int> &nums)
{
	if (nums.empty()) return;

	vector<int> vec;
	for (size_t i = nums.size() - 1; i > 0;)
	{
		i--;
		vec.push_back(nums[i + 1]);
		if (nums[i] < nums[i + 1])
		{
			sort(vec.begin(), vec.end());
			auto it = lower_bound(vec.begin(), vec.end(), nums[i]);
			swap(nums[i], *it);
			for (size_t j = 0; j < vec.size(); j++)
			{
				nums[j + i + 1] = vec[j];
			}
			break;
		}
	}
}

string getPermutation(int n, int k)
{
	vector<int> nums;
	for (int i = 0; i < n; i++)
	{
		nums.push_back(i + 1);
	}
	while (--k > 0)
	{
		getPermutation(nums);
	}
	string ans;
	for (auto &n : nums)
	{
		ans += to_string(n);
	}
	return ans;
}
```

