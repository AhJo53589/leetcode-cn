# `（中等）` [918.maximum-sum-circular-subarray 环形子数组的最大和](https://leetcode-cn.com/problems/maximum-sum-circular-subarray/)

### 题目描述
<p>给定一个由整数数组 <code>A</code>&nbsp;表示的<strong>环形数组 <code>C</code></strong>，求 <code><strong>C</strong></code>&nbsp;的非空子数组的最大可能和。</p>

<p>在此处，<em>环形数组</em>意味着数组的末端将会与开头相连呈环状。（形式上，当<code>0 &lt;= i &lt; A.length</code>&nbsp;时&nbsp;<code>C[i] = A[i]</code>，而当&nbsp;<code>i &gt;= 0</code>&nbsp;时&nbsp;<code>C[i+A.length] = C[i]</code>）</p>

<p>此外，子数组最多只能包含固定缓冲区 <code>A</code>&nbsp;中的每个元素一次。（形式上，对于子数组&nbsp;<code>C[i], C[i+1], ..., C[j]</code>，不存在&nbsp;<code>i &lt;= k1, k2 &lt;= j</code>&nbsp;其中&nbsp;<code>k1 % A.length&nbsp;= k2 % A.length</code>）</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[1,-2,3,-2]
<strong>输出：</strong>3
<strong>解释：</strong>从子数组 [3] 得到最大和 3
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[5,-3,5]
<strong>输出：</strong>10
<strong>解释：</strong>从子数组 [5,5] 得到最大和 5 + 5 = 10
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>[3,-1,2,-1]
<strong>输出：</strong>4
<strong>解释：</strong>从子数组 [2,-1,3] 得到最大和 2 + (-1) + 3 = 4
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>[3,-2,2,-3]
<strong>输出：</strong>3
<strong>解释：</strong>从子数组 [3] 和 [3,-2,2] 都可以得到最大和 3
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>[-2,-3,-1]
<strong>输出：</strong>-1
<strong>解释：</strong>从子数组 [-1] 得到最大和 -1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>-30000 &lt;= A[i] &lt;= 30000</code></li>
	<li><code>1 &lt;= A.length &lt;= 30000</code></li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-sum-circular-subarray/solution/918-by-ikaruga/)

### 答题
``` C++
int maxSubarraySumCircular(vector<int>& A) 
{
	int sum = 0;
	int smax = INT_MIN;
	bool flag = true;
	int s1 = 0;
	int s2 = 0;
	int ans1 = 0;
	int ans2 = 0;
	for (auto n : A)
	{
		sum += n;
		smax = max(smax, n);
		if (n > 0) flag = false;
		s1 = (s1 > 0) ? s1 + n : n;
		ans1 = max(ans1, s1);
		s2 = (s2 < 0) ? s2 + n : n;
		ans2 = min(ans2, s2);
	}
	if (flag && sum == ans2) return smax;
	return max(ans1, sum - ans2);
}
```




