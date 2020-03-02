# `（中等）` [556.next-greater-element-iii 下一个更大元素 III](https://leetcode-cn.com/problems/next-greater-element-iii/)

### 题目描述
<p>给定一个<strong>32位</strong>正整数&nbsp;<strong>n</strong>，你需要找到最小的<strong>32位</strong>整数，其与&nbsp;<strong>n&nbsp;</strong>中存在的位数完全相同，并且其值大于n。如果不存在这样的<strong>32位</strong>整数，则返回-1。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 12
<strong>输出:</strong> 21
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 21
<strong>输出:</strong> -1
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/reverse-linked-list/solution/206-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int nextGreaterElement(int n) 
	{
		vector<int> dg;
		while (n != 0)
		{
			dg.push_back(n % 10);
			n /= 10;
		}
		reverse(dg.begin(), dg.end());
		if (!next_permutation(dg.begin(), dg.end())) return -1;
		
		long long ans = 0;
		for (auto& i : dg)
		{
			ans *= 10;
			ans += i;
		}
		return (ans > INT_MAX) ? -1 : ans;
    }
};
```




