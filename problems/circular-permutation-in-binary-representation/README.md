# `（中等）` [5239.circular-permutation-in-binary-representation 循环码排列](https://leetcode-cn.com/problems/circular-permutation-in-binary-representation/)

[contest](https://leetcode-cn.com/contest/weekly-contest-160/problems/circular-permutation-in-binary-representation/)

### 题目描述

              <p>给你两个整数&nbsp;<code>n</code> 和 <code>start</code>。你的任务是返回任意 <code>(0,1,2,,...,2^n-1)</code> 的排列 <code>p</code>，并且满足：</p>

<ul>
	<li><code>p[0] = start</code></li>
	<li><code>p[i]</code> 和 <code>p[i+1]</code>&nbsp;的二进制表示形式只有一位不同</li>
	<li><code>p[0]</code> 和 <code>p[2^n -1]</code>&nbsp;的二进制表示形式也只有一位不同</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2, start = 3
<strong>输出：</strong>[3,2,0,1]
<strong>解释：</strong>这个排列的二进制表示是 (11,10,00,01)
     所有的相邻元素都有一位是不同的，另一个有效的排列是 [3,1,0,2]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输出：</strong>n = 3, start = 2
<strong>输出：</strong>[2,6,7,5,4,0,1,3]
<strong>解释：</strong>这个排列的二进制表示是 (010,110,111,101,100,000,001,011)
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 16</code></li>
	<li><code>0 &lt;= start&nbsp;&lt;&nbsp;2^n</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
vector<int> grayCode(int n) 
{
	vector<int> res;
	for (int i = 0; i < (1 << n); ++i)
		res.push_back(i ^ (i >> 1));
	return res;
}

vector<int> circularPermutation(int n, int start) 
{
	vector<int> ans = grayCode(n);
	auto k = ans.begin();
	while (k != ans.end() && *k != start) k++;
	rotate(ans.begin(), k, ans.end());
	return ans;
}
```




