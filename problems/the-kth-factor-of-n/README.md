# `（中等）` [1492.the-kth-factor-of-n n 的第 k 个因子](https://leetcode-cn.com/problems/the-kth-factor-of-n/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-29/problems/the-kth-factor-of-n/)

### 题目描述
<p>给你两个正整数&nbsp;<code>n</code> 和&nbsp;<code>k</code>&nbsp;。</p>

<p>如果正整数 <code>i</code> 满足 <code>n % i == 0</code> ，那么我们就说正整数 <code>i</code> 是整数 <code>n</code>&nbsp;的因子。</p>

<p>考虑整数 <code>n</code>&nbsp;的所有因子，将它们 <strong>升序排列</strong>&nbsp;。请你返回第 <code>k</code>&nbsp;个因子。如果 <code>n</code>&nbsp;的因子数少于 <code>k</code>&nbsp;，请你返回 <strong>-1</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 12, k = 3
<strong>输出：</strong>3
<strong>解释：</strong>因子列表包括 [1, 2, 3, 4, 6, 12]，第 3 个因子是 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 7, k = 2
<strong>输出：</strong>7
<strong>解释：</strong>因子列表包括 [1, 7] ，第 2 个因子是 7 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 4, k = 4
<strong>输出：</strong>-1
<strong>解释：</strong>因子列表包括 [1, 2, 4] ，只有 3 个因子，所以我们应该返回 -1 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 1, k = 1
<strong>输出：</strong>1
<strong>解释：</strong>因子列表包括 [1] ，第 1 个因子为 1 。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>n = 1000, k = 3
<strong>输出：</strong>4
<strong>解释：</strong>因子列表包括 [1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500, 1000] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 1000</code></li>
</ul>



---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int kthFactor(int n, int k) {
		for (int i = 1; i <= n; i++) {
			k -= (n % i == 0);
			if (k == 0) return i;
		}
		return -1;
    }
};
```




