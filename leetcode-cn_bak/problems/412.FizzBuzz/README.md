# `（简单）`  [412.FizzBuzz Fizz Buzz](https://leetcode-cn.com/problems/fizz-buzz/)

### 题目描述
<p>写一个程序，输出从 1 到 <em>n</em> 数字的字符串表示。</p>

<p>1. 如果&nbsp;<em>n&nbsp;</em>是3的倍数，输出“Fizz”；</p>

<p>2. 如果&nbsp;<em>n&nbsp;</em>是5的倍数，输出“Buzz”；</p>

<p>3.如果&nbsp;<em>n&nbsp;</em>同时是3和5的倍数，输出 “FizzBuzz”。</p>

<p><strong>示例：</strong></p>

<pre>n = 15,

返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
</pre>



---
### 思路
``` 
```


### 答题
``` C++
vector<string> fizzBuzz(int n)
{
	vector<string> str;
	for (int i = 1; i <= n; i++)
	{
		if (i % 15 == 0)
		{
			str.push_back("FizzBuzz");
		}
		else if (i % 5 == 0)
		{
			str.push_back("Buzz");
		}
		else if (i % 3 == 0)
		{
			str.push_back("Fizz");
		}
		else
		{
			str.push_back(to_string(i));
		}
	}
	return str;
}
``` 