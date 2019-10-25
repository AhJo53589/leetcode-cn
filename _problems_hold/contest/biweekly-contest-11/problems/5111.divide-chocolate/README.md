# `（困难）`  [5111.divide-chocolate 分享巧克力](https://leetcode-cn.com/contest/biweekly-contest-11/problems/divide-chocolate/)

### 题目描述
<p>你有一大块巧克力，它由一些甜度不完全相同的小块组成。我们用数组&nbsp;<code>sweetness</code>&nbsp;来表示每一小块的甜度。</p>

<p>你打算和&nbsp;<code>K</code>&nbsp;名朋友一起分享这块巧克力，所以你需要将切割&nbsp;<code>K</code>&nbsp;次才能得到 <code>K+1</code>&nbsp;块，每一块都由一些 <strong>连续&nbsp;</strong>的小块组成。</p>

<p>为了表现出你的慷慨，你将会吃掉&nbsp;<strong>总甜度最小</strong> 的一块，并将其余几块分给你的朋友们。</p>

<p>请找出一个最佳的切割策略，使得你所分得的巧克力&nbsp;<strong>总甜度最大</strong>，并返回这个 <strong>最大总甜度</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>sweetness = [1,2,3,4,5,6,7,8,9], K = 5
<strong>输出：</strong>6
<strong>解释：</strong>你可以把巧克力分成 [1,2,3], [4,5], [6], [7], [8], [9]。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>sweetness = [5,6,7,8,9,1,2,3,4], K = 8
<strong>输出：</strong>1
<strong>解释：</strong>只有一种办法可以把巧克力分成 9 块。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>sweetness = [1,2,2,1,2,2,1,2,2], K = 2
<strong>输出：</strong>5
<strong>解释：</strong>你可以把巧克力分成 [1,2,2], [1,2,2], [1,2,2]。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= K &lt;&nbsp;sweetness.length &lt;= 10^4</code></li>
	<li><code>1 &lt;= sweetness[i] &lt;= 10^5</code></li>
</ul>

            

---
### 思路
```
和410题一样。
使用二分查找来确定答案。
```

### 答题
``` C++
bool calc(vector<int> &vec, int k, int d)
{
	int val = 0;
	int cnt = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		val += vec[i];
		if (val >= d && cnt < k)
		{
			val = 0;
			cnt++;
		}
	}
	return val >= d;
}

int maximizeSweetness(vector<int>& sweetness, int K) 
{
	int lb = 0, ub = 1e10;
	while (ub - lb > 1)
	{
		int mid = lb + (ub - lb) / 2;
		if (calc(sweetness, K, mid)) lb = mid;
		else ub = mid;
	}
	return lb;
}
```
