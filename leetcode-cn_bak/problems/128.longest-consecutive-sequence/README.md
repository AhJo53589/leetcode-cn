# `（困难）`  [128.longest-consecutive-sequence 最长连续序列](https://leetcode-cn.com/problems/longest-consecutive-sequence/)

### 题目描述
<p>给定一个未排序的整数数组，找出最长连续序列的长度。</p>

<p>要求算法的时间复杂度为&nbsp;<em>O(n)</em>。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>&nbsp;[100, 4, 200, 1, 3, 2]
<strong>输出:</strong> 4
<strong>解释:</strong> 最长连续序列是 <code>[1, 2, 3, 4]。它的长度为 4。</code></pre>


---
### 思路
```
```

### 答题
``` C++
int longestConsecutive(vector<int>& nums) 
{
	if (nums.size() == 0) return 0;
	sort(nums.begin(), nums.end());

	int ans = 1;
	int temp = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] == nums[i - 1]) continue;
		temp = (nums[i] == nums[i - 1] + 1) ? temp + 1 : 1;
		ans = max(ans, temp);
	}

	return ans;
}
```

### 其它
``` C++
```

