# `（中等）` [5304.xor-queries-of-a-subarray 子数组异或查询](https://leetcode-cn.com/problems/xor-queries-of-a-subarray/)

[contest](https://leetcode-cn.com/contest/weekly-contest-170/problems/xor-queries-of-a-subarray/)

### 题目描述
<p>有一个正整数数组&nbsp;<code>arr</code>，现给你一个对应的查询数组&nbsp;<code>queries</code>，其中&nbsp;<code>queries[i] = [L<sub>i,&nbsp;</sub>R<sub>i</sub>]</code>。</p>

<p>对于每个查询&nbsp;<code>i</code>，请你计算从&nbsp;<code>L<sub>i</sub></code>&nbsp;到&nbsp;<code>R<sub>i</sub></code>&nbsp;的&nbsp;<strong>XOR</strong>&nbsp;值（即&nbsp;<code>arr[L<sub>i</sub>] <strong>xor</strong> arr[L<sub>i+1</sub>] <strong>xor</strong> ... <strong>xor</strong> arr[R<sub>i</sub>]</code>）作为本次查询的结果。</p>

<p>并返回一个包含给定查询&nbsp;<code>queries</code>&nbsp;所有结果的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
<strong>输出：</strong>[2,7,14,8] 
<strong>解释：</strong>
数组中元素的二进制表示形式是：
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
查询的 XOR 值为：
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
<strong>输出：</strong>[8,0,4,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 3 *&nbsp;10^4</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10^9</code></li>
	<li><code>1 &lt;= queries.length &lt;= 3 * 10^4</code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= queries[i][0] &lt;= queries[i][1] &lt; arr.length</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
{
	vector<int> res(arr.size(), 0);

	res[0] = arr[0];
	for (size_t i = 1; i < arr.size(); i++)
	{
		res[i] = res[i - 1] ^ arr[i];
	}

	vector<int> ans;
	for (size_t i = 0; i < queries.size(); i++)
	{
		auto& qu = queries[i];
		int left = (qu[0] == 0) ? 0 : res[qu[0] - 1];
		int r = (left == 0) ? res[qu[1]] : res[qu[1]] ^ left;
		ans.push_back(r);
	}
	return ans;
}
```




