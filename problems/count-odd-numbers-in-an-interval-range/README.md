# `（简单）` [1523.count-odd-numbers-in-an-interval-range 在区间范围内统计奇数数目](https://leetcode-cn.com/problems/count-odd-numbers-in-an-interval-range/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-31/problems/count-odd-numbers-in-an-interval-range/)

### 题目描述
<p>给你两个非负整数&nbsp;<code>low</code> 和&nbsp;<code>high</code>&nbsp;。请你返回<em>&nbsp;</em><code>low</code><em> </em>和<em>&nbsp;</em><code>high</code><em>&nbsp;</em>之间（包括二者）奇数的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>low = 3, high = 7
<strong>输出：</strong>3
<strong>解释：</strong>3 到 7 之间奇数数字为 [3,5,7] 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>low = 8, high = 10
<strong>输出：</strong>1
<strong>解释：</strong>8 到 10 之间奇数数字为 [9] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= low &lt;= high&nbsp;&lt;= 10^9</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int countOdds(int low, int high) {
		int ans = 0;
		ans += (low % 2);
		low += (low % 2);
		high += (high % 2);
		ans += (high - low) / 2;
		return ans;
    }
};
```




