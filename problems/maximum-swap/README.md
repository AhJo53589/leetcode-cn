# `（中等）` [670.maximum-swap 最大交换](https://leetcode-cn.com/problems/maximum-swap/)

### 题目描述
<p>给定一个非负整数，你<strong>至多</strong>可以交换一次数字中的任意两位。返回你能得到的最大值。</p>

<p><strong>示例 1 :</strong></p>

<pre><strong>输入:</strong> 2736
<strong>输出:</strong> 7236
<strong>解释:</strong> 交换数字2和数字7。
</pre>

<p><strong>示例 2 :</strong></p>

<pre><strong>输入:</strong> 9973
<strong>输出:</strong> 9973
<strong>解释:</strong> 不需要交换。
</pre>

<p><strong>注意:</strong></p>

<ol>
	<li>给定数字的范围是&nbsp;[0, 10<sup>8</sup>]</li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-swap/solution/670-by-ikaruga/)

### 答题
``` C++
int maximumSwap(int num) 
{
	string ss = to_string(num);
	vector<int> cnts(10, 0);
	for (auto c : ss)
	{
		cnts[c - '0']++;
	}

	size_t i = cnts.size() - 1;
	size_t j = 0;
	while (true)
	{
		if (cnts[i] == 0)
		{
			i--;
			if (i >= cnts.size())
			{
				return num;
			}
			continue;
		}
		if (j < ss.size() && ss[j] - '0' != i) break;
		cnts[i]--;
		j++;
	}

	size_t k = ss.size() - 1;
	while (k < ss.size())
	{
		if (ss[k] - '0' == i) break;
		k--;
	}

	swap(ss[j], ss[k]);
	return stoi(ss);
}
```




