# `（中等）` [451.sort-characters-by-frequency 根据字符出现频率排序](https://leetcode-cn.com/problems/sort-characters-by-frequency/)

### 题目描述
<p>给定一个字符串，请将字符串里的字符按照出现的频率降序排列。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong>
"tree"

<strong>输出:</strong>
"eert"

<strong>解释:
</strong>'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong>
"cccaaa"

<strong>输出:</strong>
"cccaaa"

<strong>解释:
</strong>'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong>
"Aabb"

<strong>输出:</strong>
"bbAa"

<strong>解释:
</strong>此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。
</pre>


---
### 思路
```
```

### 答题
``` C++
string frequencySort(string s)
{
	auto f_cmp = [](const pair<char, int> &a, const pair<char, int> &b) { return a.second > b.second; };
	auto f_sort = [f_cmp](map<char, int> &_m, vector<pair<char, int>> &_v)
	{
		for (auto i : _m) _v.push_back(i);
		sort(_v.begin(), _v.end(), f_cmp);
	};

	map<char, int> m;
	for (auto &c : s)m[c]++;
	vector<pair<char, int>> v;
	f_sort(m, v);
	string res;
	for (auto p : v) for (int i = 0; i < p.second; i++) res += p.first;
	return res;
}
```
