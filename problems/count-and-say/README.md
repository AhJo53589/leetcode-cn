# `（简单）` [38.count-and-say 报数](https://leetcode-cn.com/problems/count-and-say/)

### 题目描述
<p>报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：</p>

<pre>1.     1
2.     11
3.     21
4.     1211
5.     111221
</pre>

<p><code>1</code>&nbsp;被读作&nbsp;&nbsp;<code>"one 1"</code>&nbsp;&nbsp;(<code>"一个一"</code>) , 即&nbsp;<code>11</code>。<br>
<code>11</code> 被读作&nbsp;<code>"two 1s"</code>&nbsp;(<code>"两个一"</code>）, 即&nbsp;<code>21</code>。<br>
<code>21</code> 被读作&nbsp;<code>"one 2"</code>, &nbsp;"<code>one 1"</code>&nbsp;（<code>"一个二"</code>&nbsp;,&nbsp;&nbsp;<code>"一个一"</code>)&nbsp;, 即&nbsp;<code>1211</code>。</p>

<p>给定一个正整数 <em>n</em>（1 ≤&nbsp;<em>n</em>&nbsp;≤ 30），输出报数序列的第 <em>n</em> 项。</p>

<p>注意：整数顺序将表示为一个字符串。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> 1
<strong>输出:</strong> "1"
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 4
<strong>输出:</strong> "1211"
</pre>




---
### 思路
```
```


### 答题
``` C++
string countAndSay(int n) 
{
	if (n <= 0 || n > 30) return "";

	if (n == 1) return "1";

	string str = countAndSay(n - 1);
	string strCount;
	size_t i = 0;
	while (i < str.size())
	{
		size_t j = 1;
		while (str[i] == str[i + j])
		{
			j++;
		}
		strCount += to_string(j);
		strCount += str[i];
		i += j;
	}
	return strCount;
}
``` 

### 其它
纠结了半天的居然是怎么int转string。
