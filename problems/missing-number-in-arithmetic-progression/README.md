# `（简单）` [1228.missing-number-in-arithmetic-progression 等差数列中缺失的数字](https://leetcode-cn.com/problems/missing-number-in-arithmetic-progression/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-11/problems/missing-number-in-arithmetic-progression/)

### 题目描述
<p>有一个数组，其中的值符合等差数列的数值规律，也就是说：</p>
<ul>
	<li>在&nbsp;<code>0 &lt;= i &lt; arr.length - 1</code>&nbsp;的前提下，<code>arr[i+1] - arr[i]</code>&nbsp;的值都相等。</li>
</ul>

<p>我们会从该数组中删除一个 <strong>既不是第一个 </strong>也<strong>&nbsp;不是最后一个的值</strong>，得到一个新的数组&nbsp;&nbsp;<code>arr</code>。</p>
<p>给你这个缺值的数组&nbsp;<code>arr</code>，请你帮忙找出被删除的那个数。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong>arr = [5,7,11,13]
<strong>输出：</strong>9
<strong>解释：</strong>原来的数组是 [5,7,<strong>9</strong>,11,13]。
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>arr = [15,13,12]
<strong>输出：</strong>14
<strong>解释：</strong>原来的数组是 [15,<strong>14</strong>,13,12]。</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>3 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10^5</code></li>
</ul>

---
### 思路
```
先通过逆序来解决递增递减问题，
先确定初始的公差，
随着遍历，如果公差不同，
根据新的公差更大还是更小就能分成两个情况，
如果新公差更大，说明这里漏掉数字了，
反之就是初始的公差是错误的。
```



### 答题
``` C++
int missingNumber(vector<int>& arr)
{
	if (arr.back() < arr.front())
	{
		reverse(arr.begin(), arr.end());
	}
	int k = arr[1] - arr[0];
	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i + 1] - arr[i] == k) continue;
		if (arr[i + 1] - arr[i] > k) return arr[i] + k;
		break;
	}
	return arr[0] + k / 2;
}
```


### 其它
``` C++
int missingNumber(vector<int>& arr) 
{
	// 数组求和
	int sum = accumulate(arr.begin(), arr.end(), 0);
	// 公式求和 - 数组求和
	return (arr.size() + 1) * (arr.front() + arr.back()) / 2 - sum;
}
```


