# `（简单）`  [349.intersection-of-two-arrays 两个数组的交集](https://leetcode-cn.com/problems/intersection-of-two-arrays/)

### 题目描述
<p>给定两个数组，编写一个函数来计算它们的交集。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>nums1 = [1,2,2,1], nums2 = [2,2]
<strong>输出: </strong>[2]
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>输出: </strong>[9,4]</pre>

<p><strong>说明:</strong></p>

<ul>
	<li>输出结果中的每个元素一定是唯一的。</li>
	<li>我们可以不考虑输出结果的顺序。</li>
</ul>


---
### 思路
```
先确定数组中的值是唯一的，  
然后找出相同的。  
这里有点草率了，先排序再按顺序找效率能高一点。  
```

### 答题
``` C++
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
	unordered_set<int> set1;
	unordered_set<int> set2;
	for (auto n : nums1) set1.insert(n);
	for (auto n : nums2) set2.insert(n);
	vector<int> rst;
	for (auto n1 : set1)
	{
		for (auto n2 : set2)
		{
			if (n1 == n2) rst.push_back(n1);
		}
	}
	return rst;
}
```

### 其它
``` C++
```

