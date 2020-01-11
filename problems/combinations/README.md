# `（中等）` [77.combinations 组合](https://leetcode-cn.com/problems/combinations/)

### 题目描述
<p>给定两个整数 <em>n</em> 和 <em>k</em>，返回 1 ... <em>n </em>中所有可能的 <em>k</em> 个数的组合。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>&nbsp;n = 4, k = 2
<strong>输出:</strong>
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/combinations/solution/77-by-ikaruga/)

### 答题
``` C++
bool getNext(vector<int>& a, int n)
{
	int _max = n;
	for (size_t i = a.size() - 1; i < a.size(); i--)
	{
		if (a[i] < _max)
		{
			a[i]++;
			for (size_t j = i + 1; j < a.size(); j++)
			{
				a[j] = a[j - 1] + 1;
			}
			return true;
		}
		_max--;
	}
	return false;
}

vector<vector<int>> combine(int n, int k) 
{
	vector<int> a;
	for (size_t i = 0; i < k; i++) a.push_back(1 + i);

	vector<vector<int>> ans;
	do
	{
		ans.push_back(a);
	} while (getNext(a, n));

	return ans;
}
```




