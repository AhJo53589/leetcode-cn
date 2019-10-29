# `（简单）` [268.missing-number 缺失数字](https://leetcode-cn.com/problems/missing-number/)

### 题目描述
<p>给定一个包含 <code>0, 1, 2, ..., n</code>&nbsp;中&nbsp;<em>n</em>&nbsp;个数的序列，找出 0 .. <em>n</em>&nbsp;中没有出现在序列中的那个数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [3,0,1]
<strong>输出:</strong> 2
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> [9,6,4,2,3,5,7,0,1]
<strong>输出:</strong> 8
</pre>

<p><strong>说明:</strong><br>
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?</p>


---
### 思路
```
等差数列和 = (首项 + 末项) * 项数 / 2
```

### 答题
``` C++
int missingNumber(vector<int>& nums)
{
	//int sum = (0 + nums.size() - 1 + 1) * (nums.size() + 1) / 2;
	int sum = nums.size() * (nums.size() + 1) / 2;
	for (auto i : nums) sum -= i;
	return sum;
}
```

### 其它
位运算方法。  
``` C++
int missingNumber(vector<int>& nums)
{
	int missing = nums.size(); 
	for (int i = 0; i < nums.size(); i++)
	{ 
		missing ^= i ^ nums[i]; 
	} 
	return missing;
}```
