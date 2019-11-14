# `（简单）` [66.plus-one 加一](https://leetcode-cn.com/problems/plus-one/)

### 题目描述
<p>给定一个由<strong>整数</strong>组成的<strong>非空</strong>数组所表示的非负整数，在该数的基础上加一。</p>

<p>最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。</p>

<p>你可以假设除了整数 0 之外，这个整数不会以零开头。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> [1,2,3]
<strong>输出:</strong> [1,2,4]
<strong>解释:</strong> 输入数组表示数字 123。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> [4,3,2,1]
<strong>输出:</strong> [4,3,2,2]
<strong>解释:</strong> 输入数组表示数字 4321。
</pre>




---
### 思路
```

```


### 答题
``` C++
vector<int> plusOne(vector<int>& digits)
{
	if (digits.size() == 0) return digits;

	int i = digits.size() - 1;
	int bUpFlag = 1;
	while (i >= 0 && bUpFlag > 0)
	{
		digits[i] += bUpFlag;
		bUpFlag--;
		if (digits[i] > 9)
		{
			bUpFlag += digits[i] / 10;
			digits[i] %= 10;
		}
		i--;
	}
	if (bUpFlag > 0)
	{
		digits.insert(digits.begin(), bUpFlag);
	}
	return digits;
}
``` 
