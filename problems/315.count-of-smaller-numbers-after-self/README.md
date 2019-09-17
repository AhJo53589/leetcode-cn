# `（困难）`  [315.count-of-smaller-numbers-after-self 计算右侧小于当前元素的个数](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/)

### 题目描述
<p>给定一个整数数组 <em>nums</em>，按要求返回一个新数组&nbsp;<em>counts</em>。数组 <em>counts</em> 有该性质： <code>counts[i]</code> 的值是&nbsp; <code>nums[i]</code> 右侧小于&nbsp;<code>nums[i]</code> 的元素的数量。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [5,2,6,1]
<strong>输出:</strong> <code>[2,1,1,0] 
<strong>解释:</strong></code>
5 的右侧有 <strong>2 </strong>个更小的元素 (2 和 1).
2 的右侧仅有 <strong>1 </strong>个更小的元素 (1).
6 的右侧有 <strong>1 </strong>个更小的元素 (1).
1 的右侧有 <strong>0 </strong>个更小的元素.
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/solution/315-by-ikaruga/)

### 答题
``` C++
vector<int> countSmaller(vector<int>& nums) 
{
	if (nums.empty()) return {};
	if (nums.size() == 1) return { 0 };

	vector<int> counts(nums.size(), 0);
	vector<int> sort_nums;

	sort_nums.push_back(nums[nums.size() - 1]);
	size_t i = nums.size() - 2;
	do
	{
		auto it = lower_bound(sort_nums.begin(), sort_nums.end(), nums[i]);
		counts[i] = it - sort_nums.begin();
		sort_nums.insert(it, nums[i]);
	} while (i-- != 0);
	
	return counts;
}
```

### 其它
``` C++
```

