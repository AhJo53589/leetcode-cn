# `（中等）` [227.basic-calculator-ii 基本计算器 II](https://leetcode-cn.com/problems/basic-calculator-ii/)

### 题目描述
<p>实现一个基本的计算器来计算一个简单的字符串表达式的值。</p>
<p>字符串表达式仅包含非负整数，<code>+</code>， <code>-</code> ，<code>*</code>，<code>/</code> 四种运算符和空格&nbsp;<code>&nbsp;</code>。 整数除法仅保留整数部分。</p>
<p><strong>示例&nbsp;1:</strong></p>
<pre><strong>输入: </strong>"3+2*2"
<strong>输出:</strong> 7
</pre>

<p><strong>示例 2:</strong></p>
<pre><strong>输入:</strong> " 3/2 "
<strong>输出:</strong> 1</pre>

<p><strong>示例 3:</strong></p>
<pre><strong>输入:</strong> " 3+5 / 2 "
<strong>输出:</strong> 5
</pre>

<p><strong>说明：</strong></p>
<ul>
	<li>你可以假设所给定的表达式都是有效的。</li>
	<li>请<strong>不要</strong>使用内置的库函数 <code>eval</code>。</li>
</ul>

---
### 思路
```

```

[发布的题解](https://leetcode-cn.com/problems/basic-calculator-ii/solution/227-by-ikaruga/)

### 答题
``` C++
int calculate(string s)
{
	s.append("+");
	stack<int> nums;
	stack<char> op;

	int num = 0;
	for (auto c : s)
	{
		if (isspace(c)) continue;
		if (isdigit(c))	// 取得数字
		{
			num = num * 10 + c - '0';
			continue;
		}

		if (!op.empty() && (op.top() == '*' || op.top() == '/'))
		{
			// 先解决上一次的 */ 
			num = (op.top() == '*') ? nums.top() * num : nums.top() / num;
			nums.pop();
			op.pop();
		}

		// 这里不是 else if ，解决完上次的 */ 之后，可以继续处理这次的计算
		if (op.empty() || c == '*' || c == '/')
		{
			nums.push(num);
			op.push(c);
		}
		else
		{
			// 如果本次不是 */ ，可以把上一次的 +- 处理了
			nums.top() += (op.top() == '+') ? num : -num;
			op.top() = c;
		}
		num = 0;
	}
	return nums.top();
}
```
