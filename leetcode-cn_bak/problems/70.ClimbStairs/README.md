# `（简单）`  [70.ClimbStairs 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)

### 题目描述
<p>假设你正在爬楼梯。需要 <em>n</em>&nbsp;阶你才能到达楼顶。</p>

<p>每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？</p>

<p><strong>注意：</strong>给定 <em>n</em> 是一个正整数。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong> 2
<strong>输出：</strong> 2
<strong>解释：</strong> 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong> 3
<strong>输出：</strong> 3
<strong>解释：</strong> 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
</pre>



---
### 思路
```
做到动态规划了，又跑去磕算法导论。  
虽然没完全看懂，但总算没白看。  
根据自己的理解做出来这道入门题了。  
```
> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/problems/70.ClimbStairs/Solution.jpg)


### 答题
``` C++
int climbStairs(int n)
{
	if (n <= 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	int s1 = 1;
	int s2 = 2;
	int ret = 0;
	for (int i = 3; i <= n; i++)
	{
		ret = s1 + s2;
		s1 = s2;
		s2 = ret;
	}
	return ret;
}
``` 