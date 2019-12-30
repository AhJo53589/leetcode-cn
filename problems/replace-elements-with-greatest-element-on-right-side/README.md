# `（简单）` [1299.replace-elements-with-greatest-element-on-right-side 将每个元素替换为右侧最大元素](https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-16/problems/replace-elements-with-greatest-element-on-right-side/)

### 题目描述
<p>给你一个数组&nbsp;<code>arr</code>&nbsp;，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用&nbsp;<code>-1</code> 替换。</p>

<p>完成所有替换操作后，请你返回这个数组。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>arr = [17,18,5,4,6,1]
<strong>输出：</strong>[18,6,6,6,1,-1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^4</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10^5</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
vector<int> replaceElements(vector<int>& arr)
{
	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		int t = INT_MIN;
		for (size_t j = i + 1; j < arr.size(); j++)
		{
			t = max(t, arr[j]);
		}
		arr[i] = t;
	}
	arr.back() = -1;
	return arr;
}
```




