# `（中等）`  [454.4sum-ii 四数相加 II](https://leetcode-cn.com/problems/4sum-ii/)

### 题目描述
<p>给定四个包含整数的数组列表&nbsp;A , B , C , D ,计算有多少个元组 <code>(i, j, k, l)</code>&nbsp;，使得&nbsp;<code>A[i] + B[j] + C[k] + D[l] = 0</code>。</p>

<p>为了使问题简单化，所有的 A, B, C, D 具有相同的长度&nbsp;N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2<sup>28</sup> 到 2<sup>28</sup> - 1 之间，最终结果不会超过&nbsp;2<sup>31</sup> - 1 。</p>

<p><strong>例如:</strong></p>

<pre><strong>输入:</strong>
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

<strong>输出:</strong>
2

<strong>解释:</strong>
两个元组如下:
1. (0, 0, 0, 1) -&gt; A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -&gt; A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
</pre>


---
### 思路
```
```

### 答题
``` C++
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
{
	unordered_map<int, int> rec;
	int res = 0;
	for (int i = 0; i < C.size(); i++)
		for (int j = 0; j < D.size(); j++)
			rec[C[i] + D[j]]++;

	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++) {
			if (rec.find(-A[i] - B[j]) != rec.end())
				res += rec[-A[i] - B[j]];
		}
	return res;
}
```
