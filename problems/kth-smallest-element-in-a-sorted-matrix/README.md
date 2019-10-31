# `（中等）` [378.kth-smallest-element-in-a-sorted-matrix 有序矩阵中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/)

### 题目描述
<p>给定一个&nbsp;<em>n x n&nbsp;</em>矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。<br>
请注意，它是排序后的第k小元素，而不是第k个元素。</p>

<p><strong>示例:</strong></p>

<pre>matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
</pre>

<p><strong>说明: </strong><br>
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n<sup>2&nbsp;</sup>。</p>


---
### 思路
```
```



### 答题
``` C++
int lowerbound(vector<int>& row, int val)
{
	int low = 0;
	int high = row.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (row[mid] <= val)
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	return low;
}

int kthSmallest(vector<vector<int>>& matrix, int k)
{
	size_t m = matrix.size();
	if (m == 0) return 0;

	int low = matrix[0][0];
	int high = matrix.back().back();

	while (low < high)
	{
		int mid = low + (high - low) / 2;
		int count = 0;
		for (auto &row : matrix)
		{
			count += lowerbound(row, mid);
			if (count > k) break;
		}
		if (count < k)
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	return low;
}
```




