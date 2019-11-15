# `（简单）` [67.add-binary 二进制求和](https://leetcode-cn.com/problems/add-binary/)

### 题目描述
<p>给定两个二进制字符串，返回他们的和（用二进制表示）。</p>

<p>输入为<strong>非空</strong>字符串且只包含数字&nbsp;<code>1</code>&nbsp;和&nbsp;<code>0</code>。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> a = "11", b = "1"
<strong>输出:</strong> "100"</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> a = "1010", b = "1011"
<strong>输出:</strong> "10101"</pre>


---
### 思路
```
先用指针找到长度比较长的字符串。  
然后循环处理完相同长度之后，再循环处理更长的部分。  
```

### 答题
``` C++
string addBinary(string a, string b) 
{
	string *pA = (a.size() < b.size()) ? &a : &b;
	string *pB = (a.size() >= b.size()) ? &a : &b;
	string c;

	int iCarry = 0;
	int iDiff = pB->size() - pA->size();
	for (int i = pA->size() - 1; i >= 0; i--)
	{
		int a = (*pA)[i] == '1';
		int b = (*pB)[i + iDiff] == '1';
		char sum = (a + b + iCarry == 0 || a + b + iCarry == 2) ? '0' : '1';
		c.insert(c.begin(), sum);
		iCarry = (a + b + iCarry > 1) ? 1 : 0;
	}
	for (int i = iDiff - 1; i >= 0; i--)
	{
		if (iCarry == 0)
		{
			c.insert(c.begin(), (*pB)[i]);
		}
		else
		{
			char sum = ((*pB)[i] == '0') ? '1' : '0';
			c.insert(c.begin(), sum);
			iCarry = (sum == '0') ? 1 : 0;
		}
	}
	if (iCarry == 1) c.insert(c.begin(), '1');

	return c;
}

```

### 其它
跟这个代码比简直每一步都能学到新技巧。  
首先长度不同，补零比选长的更适合统一操作，而且补零代码还比较简洁。  
相加的时候，进位和求余明明可以像10进制时的思路一样处理的，还写了特例代码，真是蠢。  
``` C++
string addBinary(string a, string b)
{
	/* 1.补0 */
	while (a.size() < b.size())
		a.insert(a.begin(), '0');
	while (b.size() < a.size())
		b.insert(b.begin(), '0');

	/* 2.相加 */
	string res;
	int add = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		int val = (int)(a[i] - '0') + (int)(b[i] - '0') + add;
		add = val / 2;
		val %= 2;
		char c = (char)(val)+'0';
		res.push_back(c);
	}
	if (add != 0) res.push_back((char)(add)+'0');

	reverse(res.begin(), res.end());

	return res;
}
```

