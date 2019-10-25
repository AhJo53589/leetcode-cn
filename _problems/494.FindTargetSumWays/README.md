# `（中等）`  [494.FindTargetSumWays 目标和](https://leetcode-cn.com/problems/target-sum/)

### 题目描述
<p>给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号&nbsp;<code>+</code>&nbsp;和&nbsp;<code>-</code>。对于数组中的任意一个整数，你都可以从&nbsp;<code>+</code>&nbsp;或&nbsp;<code>-</code>中选择一个符号添加在前面。</p>

<p>返回可以使最终数组和为目标数 S 的所有添加符号的方法数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> nums: [1, 1, 1, 1, 1], S: 3
<strong>输出:</strong> 5
<strong>解释:</strong> 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
</pre>

<p><strong>注意:</strong></p>

<ol>
	<li>数组的长度不会超过20，并且数组中的值全为正数。</li>
	<li>初始的数组的和不会超过1000。</li>
	<li>保证返回的最终结果为32位整数。</li>
</ol>



---
### 思路
``` 
这道题本来看着没思路，但是因为是堆栈里的题目，  
我就仔细想了想堆栈的特点，和DFS的作用。  
终于愉快的想到了思路写出了代码。  
思路就是对每个数的正负值入栈求和。  
虽然效率不高，但是比较符合DFS思路。  
```


### 答题
``` C++
int findTargetSumWays(vector<int>& nums, int S, int iIndex, int iSum)
{
	if (iIndex == nums.size() - 1)
	{
		if (nums[iIndex] == 0 && iSum == S) return 2;
		if (iSum + nums[iIndex] == S) return 1;
		if (iSum - nums[iIndex] == S) return 1;
		return 0;
	}

	int iRst = 0;
	iRst += findTargetSumWays(nums, S, iIndex + 1, iSum + nums[iIndex]);
	iRst += findTargetSumWays(nums, S, iIndex + 1, iSum - nums[iIndex]);
	return iRst;
}

int findTargetSumWays(vector<int>& nums, int S) 
{
	return findTargetSumWays(nums, S, 0, 0);
}
``` 


### 其它
查看别人的代码之后，发现自己的动态规划学的还不行啊。  

``` C++
int findTargetSumWays(vector<int>& nums, int S) {
	int sum=0;
	for(int n : nums) sum+=n;
	if(sum<S || (S+sum)%2!=0) return 0;
	int right = (S+sum)>>1;
	vector<int> dp(right+1, 0);
	dp[0]=1;
	for(int d : nums){
		for(int i=right; i>=d; i--) dp[i]+=dp[i-d];
	}
	return dp[right];
}
``` 