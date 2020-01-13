# `（中等）` [1318.minimum-flips-to-make-a-or-b-equal-to-c 或运算的最小翻转次数](https://leetcode-cn.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/)

[contest](https://leetcode-cn.com/contest/weekly-contest-171/problems/minimum-flips-to-make-a-or-b-equal-to-c/)

### 题目描述
<p>给你三个正整数&nbsp;<code>a</code>、<code>b</code> 和 <code>c</code>。</p>
<p>你可以对 <code>a</code> 和 <code>b</code>&nbsp;的二进制表示进行位翻转操作，返回能够使按位或运算&nbsp; &nbsp;<code>a</code> OR <code>b</code> == <code>c</code>&nbsp;&nbsp;成立的最小翻转次数。</p>
<p>「位翻转操作」是指将一个数的二进制表示任何单个位上的 1 变成 0 或者 0 变成 1 。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<p><img style="height: 87px; width: 260px;" src="./sample_3_1676.png" alt=""></p>
<pre><strong>输入：</strong>a = 2, b = 6, c = 5
<strong>输出：</strong>3
<strong>解释：</strong>翻转后 a = 1 , b = 4 , c = 5 使得 <code>a</code> OR <code>b</code> == <code>c</code></pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>a = 4, b = 2, c = 7
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>a = 1, b = 2, c = 3
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>1 &lt;= a &lt;= 10^9</code></li>
	<li><code>1 &lt;= b&nbsp;&lt;= 10^9</code></li>
	<li><code>1 &lt;= c&nbsp;&lt;= 10^9</code></li>
</ul>

---
### 思路
```

```



### 答题
``` C++
int minFlips(int a, int b, int c) 
{
	int ans = 0;
	for (int i = 0; i < 32; i++)
	{
		int t = c & (1 << i);
		if (t == 0)
		{
			ans += ((a & (1 << i)) != 0);
			ans += ((b & (1 << i)) != 0);
		}
		else
		{
			ans += ((a & (1 << i)) == 0 && (b & (1 << i)) == 0);
		}
	}
	return ans;
}
```




