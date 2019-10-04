# `（中等）`  [89.gray-code 格雷编码](https://leetcode-cn.com/problems/gray-code/)

### 题目描述
<p>格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。</p>

<p>给定一个代表编码总位数的非负整数<em> n</em>，打印其格雷编码序列。格雷编码序列必须以 0 开头。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong>&nbsp;2
<strong>输出:</strong>&nbsp;<code>[0,1,3,2]</code>
<strong>解释:</strong>
00 - 0
01 - 1
11 - 3
10 - 2

对于给定的&nbsp;<em>n</em>，其格雷编码序列并不唯一。
例如，<code>[0,2,3,1]</code>&nbsp;也是一个有效的格雷编码序列。

00 - 0
10 - 2
11 - 3
01 - 1</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong>&nbsp;0
<strong>输出:</strong>&nbsp;<code>[0]
<strong>解释:</strong> 我们定义</code>格雷编码序列必须以 0 开头。<code>
&nbsp;    给定</code>编码总位数为<code> <em>n</em> 的格雷编码序列，其长度为 2<sup>n</sup></code>。<code>当 <em>n</em> = 0 时，长度为 2<sup>0</sup> = 1。
&nbsp;    因此，当 <em>n</em> = 0 时，其格雷编码序列为 [0]。</code>
</pre>


---
### 思路
```
```
[别人的题解](https://leetcode-cn.com/problems/gray-code/solution/gray-code-jing-xiang-fan-she-fa-by-jyd/)
[别人的题解](https://leetcode-cn.com/problems/gray-code/solution/gen-ju-ge-lei-ma-de-xing-zhi-by-powcai/)


### 答题
``` C++
vector<int> grayCode(int n)
{
	if (n == 0) return { 0 };
	if (n == 1) return { 0, 1 };

	vector<int> prev = grayCode(n - 1);
	vector<int> res;
	bool bFlag = true;
	for (int i = 0; i < prev.size(); i += 2)
	{
		int add1 = prev[i] & 1;
		int add2 = (add1 == 1) ? 0 : 1;
		if (!bFlag) swap(add1, add2);
		res.push_back((prev[i] << 1) + add1);
		res.push_back((prev[i] << 1) + add2);

		add1 = prev[i + 1] & 1;
		add2 = (add1 == 1) ? 0 : 1;
		if (!bFlag) swap(add1, add2);
		res.push_back((prev[i + 1] << 1) + add1);
		res.push_back((prev[i + 1] << 1) + add2);

		bFlag = !bFlag;
	}
	return res;
}
```

### 其它
现阶段看懂了也不知道怎样才能想出来。
``` C++
vector<int> grayCode(int n) {
	vector<int> res;
	for (int i = 0; i < (1 << n); ++i)
		res.push_back(i ^ (i >> 1));
	return res;
}
```

