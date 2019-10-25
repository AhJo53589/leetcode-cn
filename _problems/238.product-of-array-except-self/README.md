# `（中等）`  [238.product-of-array-except-self 除自身以外数组的乘积](https://leetcode-cn.com/problems/product-of-array-except-self/)

### 题目描述
<p>给定长度为&nbsp;<em>n</em>&nbsp;的整数数组&nbsp;<code>nums</code>，其中&nbsp;<em>n</em> &gt; 1，返回输出数组&nbsp;<code>output</code>&nbsp;，其中 <code>output[i]</code>&nbsp;等于&nbsp;<code>nums</code>&nbsp;中除&nbsp;<code>nums[i]</code>&nbsp;之外其余各元素的乘积。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> <code>[1,2,3,4]</code>
<strong>输出:</strong> <code>[24,12,8,6]</code></pre>

<p><strong>说明: </strong>请<strong>不要使用除法，</strong>且在&nbsp;O(<em>n</em>) 时间复杂度内完成此题。</p>

<p><strong>进阶：</strong><br>
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组<strong>不被视为</strong>额外空间。）</p>


---
### 思路
```
```

[别人的题解](https://leetcode-cn.com/problems/product-of-array-except-self/solution/cheng-ji-dang-qian-shu-zuo-bian-de-cheng-ji-dang-q/)  


### 答题
``` C++
vector<int> productExceptSelf(vector<int>& nums) 
{
	auto calc = [](int i, int &k, vector<int> &ret, vector<int> &nums) { ret[i] *= k; k *= nums[i]; };
	vector<int> ret(nums.size(), 1);
	int k = 1;
	for (int i = 0; i < nums.size(); i++) calc(i, k, ret, nums);
	k = 1;
	for (int i = nums.size() - 1; i >= 0; i--) calc(i, k, ret, nums);
	return ret;
}
```

