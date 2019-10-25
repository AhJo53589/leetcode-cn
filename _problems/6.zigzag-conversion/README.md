# `（中等）`  [6.zigzag-conversion Z 字形变换](https://leetcode-cn.com/problems/zigzag-conversion/)

### 题目描述
<p>将一个给定字符串根据给定的行数，以从上往下、从左到右进行&nbsp;Z 字形排列。</p>
<p>比如输入字符串为 <code>"LEETCODEISHIRING"</code>&nbsp;行数为 3 时，排列如下：</p>
<pre>L   C   I   R
E T O E S I I G
E   D   H   N
</pre>

<p>之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如：<code>"LCIRETOESIIGEDHN"</code>。</p>
<p>请你实现这个将字符串进行指定行数变换的函数：</p>
<pre>string convert(string s, int numRows);</pre>
<p><strong>示例&nbsp;1:</strong></p>
<pre><strong>输入:</strong> s = "LEETCODEISHIRING", numRows = 3
<strong>输出:</strong> "LCIRETOESIIGEDHN"
</pre>

<p><strong>示例&nbsp;2:</strong></p>
<pre><strong>输入:</strong> s = "LEETCODEISHIRING", numRows =&nbsp;4
<strong>输出:</strong>&nbsp;"LDREOEIIECIHNTSG"
<strong>解释:</strong>

L     D     R
E   O E   I I
E C   I H   N
T     S     G</pre>

---
### 思路
```
根据索引的数学规律，每行依次添加。
```

### 答题
``` C++
string convert(string s, int numRows) 
{
	if (numRows == 1) return s;
	string ans;
	size_t iStep = numRows * 2 - 2;
	for (size_t i = 0; i < numRows; i++)
	{
		size_t iOffset = (i == 0) ? 0 : (numRows - i - 1) * 2;
		size_t t = i;
		while (t < s.size())
		{
			ans.push_back(s[t]);
			if (iOffset != 0 && t + iOffset < s.size())
			{
				ans.push_back(s[t + iOffset]);
			}
			t += iStep;
		}
	}
	return ans;
}
```

