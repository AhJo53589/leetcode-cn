# `（简单）` [1271.hexspeak 十六进制魔术数字](https://leetcode-cn.com/problems/hexspeak/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-14/problems/hexspeak/)

### 题目描述
<p>你有一个十进制数字，请按照此规则将它变成「十六进制魔术数字」：首先将它变成字母大写的十六进制字符串，然后将所有的数字&nbsp;<code>0</code> 变成字母&nbsp;<code>O</code> ，将数字&nbsp;<code>1</code> &nbsp;变成字母&nbsp;<code>I</code> 。</p>

<p>如果一个数字在转换后只包含&nbsp;<code>{"A", "B", "C", "D", "E", "F", "I", "O"}</code>&nbsp;，那么我们就认为这个转换是有效的。</p>

<p>给你一个字符串&nbsp;<code>num</code> ，它表示一个十进制数 <code>N</code>，如果它的十六进制魔术数字是有效的，请返回转换后的结果，否则返回&nbsp;<code>"ERROR"</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = "257"
<strong>输出：</strong>"IOI"
<strong>解释：</strong>257 的十六进制表示是 101 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = "3"
<strong>输出：</strong>"ERROR"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= N &lt;= 10^12</code></li>
	<li>给定字符串不会有前导 0 。</li>
	<li>结果中的所有字母都应该是大写字母。</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
char getCh(char c) 
{
	if (c == 0) return 'O';
	if (c == 1) return 'I';
	if (c < 10) return -1;
	return c - 10 + 'A';
}

string toHexspeak(string num) 
{
	long long n = stoll(num);
	string s;
	while (n) 
	{
		char c = getCh(n % 16);
		if (c == -1) return "ERROR";
		s.push_back(c);
		n /= 16;
	}
	reverse(s.begin(), s.end());
	return s;
}
```




