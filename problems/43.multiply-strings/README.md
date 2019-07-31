# `（中等）`  [43.multiply-strings 字符串相乘](https://leetcode-cn.com/problems/multiply-strings/)

### 题目描述
<p>给定两个以字符串形式表示的非负整数&nbsp;<code>num1</code>&nbsp;和&nbsp;<code>num2</code>，返回&nbsp;<code>num1</code>&nbsp;和&nbsp;<code>num2</code>&nbsp;的乘积，它们的乘积也表示为字符串形式。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> num1 = "2", num2 = "3"
<strong>输出:</strong> "6"</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> num1 = "123", num2 = "456"
<strong>输出:</strong> "56088"</pre>

<p><strong>说明：</strong></p>

<ol>
	<li><code>num1</code>&nbsp;和&nbsp;<code>num2</code>&nbsp;的长度小于110。</li>
	<li><code>num1</code> 和&nbsp;<code>num2</code> 只包含数字&nbsp;<code>0-9</code>。</li>
	<li><code>num1</code> 和&nbsp;<code>num2</code>&nbsp;均不以零开头，除非是数字 0 本身。</li>
	<li><strong>不能使用任何标准库的大数类型（比如 BigInteger）</strong>或<strong>直接将输入转换为整数来处理</strong>。</li>
</ol>


---
### 思路
```
```
[别人的题解](https://leetcode-cn.com/problems/multiply-strings/solution/ping-xing-cheng-fa-yu-shu-shi-cheng-fa-by-simple-2/)

### 答题
``` C++
string multiply(string num1, string num2)
{
	string ret(num1.size() + num2.size(), '0');
	for (int i = num1.size() - 1; i >= 0; i--)
	{
		int val1 = num1[i] - '0';
		for (int j = num2.size() - 1; j >= 0; j--)
		{
			int val2 = num2[j] - '0';
			int sum = (ret[i + j + 1] - '0') + val1 * val2;
			ret[i + j + 1] = (char)(sum % 10 + '0');
			ret[i + j] += sum / 10;
		}
	}

	for (int i = 0; i < ret.size(); i++)
	{
		if (ret[i] != '0' || i == ret.size() - 1) return ret.substr(i, ret.size() - i);
	}
	return "0";
}
```

### 其它
贪图省事，模式化调用。
拿415的现成加法代码凑活用。
结果超时了。
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
	if (iCarry != 0) sum.push_back((char)(iCarry) + '0');

	reverse(sum.begin(), sum.end());

	return sum;
}

string multiply(string num1, string num2)
{
	if (num1 == "0" || num2 == "0") return "0";

	string sum;
	int len1 = num1.size();
	int len2 = num2.size();
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			int val = (int)(num1[i] - '0') * (int)(num2[j] - '0');
			int zero = (len1 - i - 1) + (len2 - j - 1);
			string t = to_string(val);
			while (zero-- > 0) t += "0";
			sum = addStrings(sum, t);
		}
	}
	return sum;
}
```

