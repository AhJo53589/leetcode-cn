# `（中等）` [347.top-k-frequent-elements 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)

### 题目描述
<p>给定一个非空的整数数组，返回其中出现频率前&nbsp;<strong><em>k&nbsp;</em></strong>高的元素。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>nums = [1,1,1,2,2,3], k = 2
<strong>输出: </strong>[1,2]
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>nums = [1], k = 1
<strong>输出: </strong>[1]</pre>

<p><strong>说明：</strong></p>

<ul>
	<li>你可以假设给定的&nbsp;<em>k&nbsp;</em>总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。</li>
	<li>你的算法的时间复杂度<strong>必须</strong>优于 O(<em>n</em> log <em>n</em>) ,&nbsp;<em>n&nbsp;</em>是数组的大小。</li>
</ul>


---
### 思路
```
先使用unordered_map对频率进行统计。
然后需要对这个结果排序。
我是使用vector<pair<int, int>>，
但是发现别人使用multimap，再插入时使用multimap自己的算法排序效率更高。
```

### 答题
``` C++
vector<int> topKFrequent(vector<int>& nums, int k) 
{
	vector<int> res;
	unordered_map<int, int> m;
	for (auto n : nums) m[n]++;

	vector<pair<int, int>> freq;
	for (auto x : m) freq.push_back(x);
	sort(freq.begin(), freq.end(), [](auto a, auto b) { return a.second > b.second; });

	auto it = freq.begin();
	for (int i = 0; i < k; i++)
	{
		res.push_back(it->first);
		it++;
	}
	return res;
}
```

### 其它
``` C++
vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int,int> m;
	for(auto i:nums){
		m[i]++;
	}
	multimap<int,int,greater<int>> s;
	for(auto i:m){
		s.insert(make_pair(i.second,i.first));
	}
	vector<int> res;
	for(auto i:s){
		if(res.size()==k) break;
		res.push_back(i.second);
	}
	return res;
}
```

