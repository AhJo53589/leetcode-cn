# `（简单）` [788.rotated-digits 旋转数字](https://leetcode-cn.com/problems/rotated-digits/)

### 题目描述
<p>我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。</p>

<p>如果一个数的每位数字被旋转以后仍然还是一个数字，&nbsp;则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方；6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。</p>

<p>现在我们有一个正整数&nbsp;<code>N</code>, 计算从&nbsp;<code>1</code> 到&nbsp;<code>N</code> 中有多少个数&nbsp;X 是好数？</p>

<pre><strong>示例:</strong>
<strong>输入:</strong> 10
<strong>输出:</strong> 4
<strong>解释:</strong> 
在[1, 10]中有四个好数： 2, 5, 6, 9。
注意 1 和 10 不是好数, 因为他们在旋转之后不变。
</pre>

<p><strong>注意:</strong></p>

<ul>
	<li>N&nbsp;的取值范围是&nbsp;<code>[1, 10000]</code>。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
const vector<vector<int>> cnt = { { 0,0,1,1,1,2,3,3,3,4 }, { 1,2,3,3,3,4,5,5,6,7 } };
const set<int> s1 = { 3,4,7 };
const set<int> s2 = { 2,5,6,9 };

int calcGood(int n, int d, int f, vector<map<vector<int>, int>> &m)
{
	if (d == 0)
	{
		return cnt[f][n - 1];
	}
	int ans = 0;
	if (m[f].count({ n, d }) == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (s1.count(i) != 0) continue;
			int tempf = (f || s2.count(i) != 0);
			ans += calcGood(10, d - 1, tempf, m);
		}
		m[f][{n, d}] = ans;
	}
	else
	{
		ans = m[f][{n, d}];
	}
	return ans;
}

int rotatedDigits(int N)
{
	vector<map<vector<int>, int>> m(2, map<vector<int>, int>());

	vector<int> a;
	while (N > 0)
	{
		a.push_back(N % 10);
		N /= 10;
	}

	int ans = 0;
	int f = 0;
	for (size_t i = a.size() - 1; i < a.size(); i--)
	{
		if (i != 0)
		{
			ans += calcGood(a[i], i, f, m);
			if (s1.count(a[i]) != 0) break;
			f = (f || s2.count(a[i]) != 0);
		}
		else
		{
			ans += calcGood(a[i] + 1, i, f, m);
		}
	}
	return ans;
}
```


### 其它
``` C++
vector<int> dir = { 8,1,0,2,5,6,9 };
void dfs(int e, int &re, int N, int x) {
	if (x > N) return;
	for (int i = 0; i < e; i++) {
		if (x == 0 && dir[i] == 0) continue;
		int tx = x * 10 + dir[i];
		if (tx <= N) re++;
		dfs(e, re, N, tx);
	}
}
int rotatedDigits(int N) {
	int ans1 = 0;
	dfs(3, ans1, N, 0);
	int ans2 = 0;
	dfs(7, ans2, N, 0);
	return ans2 - ans1;
}
```


