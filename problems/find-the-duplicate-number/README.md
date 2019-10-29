# `（中等）` [287.find-the-duplicate-number 寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/)

### 题目描述
<p>给定一个包含&nbsp;<em>n</em> + 1 个整数的数组&nbsp;<em>nums</em>，其数字都在 1 到 <em>n&nbsp;</em>之间（包括 1 和 <em>n</em>），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <code>[1,3,4,2,2]</code>
<strong>输出:</strong> 2
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [3,1,3,4,2]
<strong>输出:</strong> 3
</pre>

<p><strong>说明：</strong></p>

<ol>
	<li><strong>不能</strong>更改原数组（假设数组是只读的）。</li>
	<li>只能使用额外的 <em>O</em>(1) 的空间。</li>
	<li>时间复杂度小于 <em>O</em>(<em>n</em><sup>2</sup>) 。</li>
	<li>数组中只有一个重复的数字，但它可能不止重复出现一次。</li>
</ol>


---
### 思路
```
查看官方题解方法三。
弗洛伊德的乌龟和兔子（循环检测）。
其实也就是链表里常用的快慢指针检测循环。
```

[官方题解](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode/)

### 答题
``` C++
int findDuplicate(vector<int>& nums) {
	int low = nums[0];
	int fast = nums[nums[0]];
	while (low != fast)
	{
		low = nums[low];
		fast = nums[nums[fast]];
	}
	low = 0;
	while (low != fast)
	{
		low = nums[low];
		fast = nums[fast];
	}
	return fast;
}
```

### 其它
不符合这条，“只能使用额外的 O(1) 的空间。”  
``` C++
int findDuplicate(vector<int>& nums)
{
	unordered_set<int> s;
	for (auto i : nums)
	{
		if (s.count(i)) return i;
		s.insert(i);
	}
	return nums[0];
}
```

