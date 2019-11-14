# `（中等）` [658.find-k-closest-elements 找到](https://leetcode-cn.com/problems/find-k-closest-elements/)

### 题目描述
<p>给定一个排序好的数组，两个整数 <code>k</code> 和 <code>x</code>，从数组中找到最靠近 <code>x</code>（两数之差最小）的 <code>k</code> 个数。返回的结果必须要是按升序排好的。如果有两个数与 <code>x</code> 的差值一样，优先选择数值较小的那个数。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> [1,2,3,4,5], k=4, x=3
<strong>输出:</strong> [1,2,3,4]
</pre>

<p>&nbsp;</p>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [1,2,3,4,5], k=4, x=-1
<strong>输出:</strong> [1,2,3,4]
</pre>

<p>&nbsp;</p>

<p><strong>说明:</strong></p>

<ol>
	<li>k 的值为正数，且总是小于给定排序数组的长度。</li>
	<li>数组不为空，且长度不超过 10<sup>4</sup></li>
	<li>数组里的每个元素与&nbsp;x 的绝对值不超过 10<sup>4</sup></li>
</ol>

<p>&nbsp;</p>

<p><strong>更新(2017/9/19):</strong><br>
这个参数 <em>arr</em> 已经被改变为一个<strong>整数数组</strong>（而不是整数列表）。<strong><em>&nbsp;请重新加载代码定义以获取最新更改。</em></strong></p>


---
### 思路
```
```

### 答题
``` C++
vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
	int low = 0;
	int high = arr.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] < x) low = mid + 1;
		else high = mid;
	}
	int mid = low;
	while (high - low < k)
	{
		if (k > arr.size()) return {};
		if (low == 0)
		{
			high = high + 1;
			continue;
		}
		else if (high == arr.size())
		{
			low = low - 1;
			continue;
		}

		if (x - arr[low - 1] <= arr[high] - x) low = low - 1;
		else high = high + 1;
	}
	vector<int> res;
	res.assign(&arr[low], &arr[high]);
	return res;
}
```

### 其它
``` C++
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
	int left = 0, right = arr.size() - k;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
		else right = mid;
	}
	return vector<int>(arr.begin() + left, arr.begin() + left + k);
}
```

``` C++
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
	int size = arr.size(), n = size - k;
	int left = 0, right = size - 1;
	while (n) {

		if (x - arr[left] <= arr[right] - x)
			right--;
		else
			left++;
		n--;
	}
	vector<int> a;
	a.assign(arr.begin() + left, arr.begin() + right + 1);
	return a;
}
```

