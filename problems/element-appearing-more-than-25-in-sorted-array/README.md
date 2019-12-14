# `（简单）` [5126.element-appearing-more-than-25-in-sorted-array 有序数组中出现次数超过25%的元素](https://leetcode-cn.com/problems/element-appearing-more-than-25-in-sorted-array/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-15/problems/element-appearing-more-than-25-in-sorted-array/)

### 题目描述
<p>给你一个非递减的&nbsp;<strong>有序&nbsp;</strong>整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。</p>

<p>请你找到并返回这个整数</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,2,6,6,6,6,7,10]
<strong>输出：</strong>6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^4</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10^5</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
int findSpecialInteger(vector<int>& arr) 
{
	int cnt = 0;
	int pre = INT_MAX;
	for (auto n : arr)
	{
		if (pre != n)
		{
			if (cnt > arr.size() / 4)
			{
				return pre;
			}
			cnt = 1;
		}
		else
		{
			cnt++;
		}
		pre = n;
	}
	return pre;
}
```




