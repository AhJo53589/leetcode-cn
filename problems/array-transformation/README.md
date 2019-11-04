# `（简单）` [1243.array-transformation 数组变换](https://leetcode-cn.com/problems/array-transformation/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-12/problems/array-transformation/)

### 题目描述
<p>首先，给你一个初始数组 <code>arr</code>。然后，每天你都要根据前一天的数组生成一个新的数组。</p>

<p>第&nbsp;<code>i</code>&nbsp;天所生成的数组，是由你对第&nbsp;<code>i-1</code>&nbsp;天的数组进行如下操作所得的：</p>

<ol>
	<li>假如一个元素小于它的左右邻居，那么该元素自增 <code>1</code>。</li>
	<li>假如一个元素大于它的左右邻居，那么该元素自减 <code>1</code>。</li>
	<li>首、尾元素 <strong>永不</strong>&nbsp;改变。</li>
</ol>

<p>过些时日，你会发现数组将会不再发生变化，请返回最终所得到的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[6,2,3,4]
<strong>输出：</strong>[6,3,3,4]
<strong>解释：</strong>
第一天，数组从 [6,2,3,4] 变为 [6,3,3,4]。
无法再对该数组进行更多操作。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[1,6,3,4,3,5]
<strong>输出：</strong>[1,4,4,4,4,5]
<strong>解释：</strong>
第一天，数组从 [1,6,3,4,3,5] 变为 [1,5,4,3,4,5]。
第二天，数组从 [1,5,4,3,4,5] 变为 [1,4,4,4,4,5]。
无法再对该数组进行更多操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= arr.length &lt;= 100</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 100</code></li>
</ol>

            

---
### 思路
```
```



### 答题
``` C++
vector<int> transformArray(vector<int>& arr) 
{
	vector<int> arr2(arr.size());
	bool bChange = true;
	while (bChange)
	{
		bChange = false;
		arr2[0] = arr[0];
		arr2[arr.size() - 1] = arr[arr.size() - 1];
		for (size_t i = 1; i < arr.size() - 1; i++)
		{
			arr2[i] = arr[i];
			if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
			{
				arr2[i]++;
				bChange = true;
			}
			else if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
			{
				arr2[i]--;
				bChange = true;
			}
		}
		swap(arr, arr2);
	}
	return arr;
}
```




