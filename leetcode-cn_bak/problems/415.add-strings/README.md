# `（简单）`  [415.add-strings 字符串相加](https://leetcode-cn.com/problems/add-strings/)

### 题目描述
<p>给定两个字符串形式的非负整数&nbsp;<code>num1</code> 和<code>num2</code>&nbsp;，计算它们的和。</p>

<p><strong>注意：</strong></p>

<ol>
	<li><code>num1</code> 和<code>num2</code>&nbsp;的长度都小于 5100.</li>
	<li><code>num1</code> 和<code>num2</code> 都只包含数字&nbsp;<code>0-9</code>.</li>
	<li><code>num1</code> 和<code>num2</code> 都不包含任何前导零。</li>
	<li><strong>你不能使用任何內建 BigInteger 库，&nbsp;也不能直接将输入的字符串转换为整数形式。</strong></li>
</ol>


---
### 思路
```
基本上照抄 67.add-binary 二进制求和  
```

### 答题
``` C++
string addStrings(string num1, string num2) 
{
	while (num1.size() < num2.size()) num1.insert(num1.begin(), '0');
	while (num2.size() < num1.size()) num2.insert(num2.begin(), '0');

	string sum;
	int iCarry = 0;
	for (int i = num1.size() - 1; i >= 0; i--)
	{
		int val = (int)(num1[i] - '0') + (int)(num2[i] - '0') + iCarry;
		iCarry = val / 10;
		val %= 10;
		char c = (char)(val) + '0';
		sum.push_back(c);
	}
	if (iCarry != 0) sum.push_back((char)(iCarry)+'0');

	reverse(sum.begin(), sum.end());

	return sum;
}
```
