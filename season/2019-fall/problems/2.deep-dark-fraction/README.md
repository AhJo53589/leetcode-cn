# `（简单）`  [2.deep-dark-fraction 分式化简](https://leetcode-cn.com/contest/season/2019-fall/problems/deep-dark-fraction/)

### 题目描述

<p>有一个同学在学习分式。他需要将一个连分数化成最简分数，你能帮助他吗？</p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/09/fraction_example_1.jpg" style="height: 195px; width: 480px;"></p>

<p>连分数是形如上图的分式。在本题中，所有系数都是大于等于0的整数。</p>

<p>&nbsp;</p>

<p>输入的<code>cont</code>代表连分数的系数（<code>cont[0]</code>代表上图的<code>a<sub>0</sub></code>，以此类推）。返回一个长度为2的数组<code>[n, m]</code>，使得连分数的值等于<code>n / m</code>，且<code>n, m</code>最大公约数为1。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>cont = [3, 2, 0, 2]
<strong>输出：</strong>[13, 4]
<strong>解释：</strong>原连分数等价于3 + (1 / (2 + (1 / (0 + 1 / 2))))。注意[26, 8], [-13, -4]都不是正确答案。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>cont = [0, 0, 3]
<strong>输出：</strong>[3, 1]
<strong>解释：</strong>如果答案是整数，令分母为1即可。</pre>

<p><strong>限制：</strong></p>

<ol>
	<li><code>cont[i] &gt;= 0</code></li>
	<li><code>1 &lt;= cont的长度 &lt;= 10</code></li>
	<li><code>cont</code>最后一个元素不等于0</li>
	<li>答案的<code>n, m</code>的取值都能被32位int整型存下（即不超过<code>2 ^ 31 - 1</code>）。</li>
</ol>

            


---
### 思路
```
```

### 答题
``` C++
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

void fraction(vector<int>& cont, size_t last, vector<int>& val)
{
	if (last == cont.size() - 1)
	{
		last--;
		val[0] = cont[last + 1];
		val[1] = cont[last] * cont[last + 1] + 1;
		cout << "val[0] = " << val[0] << ", val[1] = " << val[1] << endl;
	}
	else if (last != 0)
	{
		last--;
		int temp = val[1];
		val[1] = cont[last] * val[1] + val[0];
		val[0] = temp;
		cout << "val[0] = " << val[0] << ", val[1] = " << val[1] << endl;
	}
	int g = gcd(val[0], val[1]);
	val[0] /= g;
	val[1] /= g;
	cout << "val[0] = " << val[0] << ", val[1] = " << val[1] << endl;
	if (last == 0)
	{
		swap(val[0], val[1]);
		return;
	}
	fraction(cont, last, val);
}

vector<int> fraction(vector<int>& cont)
{
	if (cont.size() == 1) return { cont[0], 1 };
	vector<int> val(2, 0);
	fraction(cont, cont.size() - 1, val);
	return val;
}
```

### 其它
``` C++
long long gcd(long long x,long long y)
{
	return y?gcd(y,x%y):x;
}
vector<int> fraction(vector<int>& cont) {
	long long x,y,n=cont.size(),i;
	x=cont[n-1];
	y=1;
	for(i=n-2;~i;i--)
	{
		swap(x,y);
		x+=cont[i]*y;
	}
	i=gcd(x,y);
	x/=i;
	y/=i;
	vector<int> ans;
	ans.push_back(x);
	ans.push_back(y);
	return ans;
}
```