# `（中等）` [74.search-a-2d-matrix 搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)

### 题目描述
<p>编写一个高效的算法来判断&nbsp;<em>m</em> x <em>n</em>&nbsp;矩阵中，是否存在一个目标值。该矩阵具有如下特性：</p>

<ul>
	<li>每行中的整数从左到右按升序排列。</li>
	<li>每行的第一个整数大于前一行的最后一个整数。</li>
</ul>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong>
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
<strong>输出:</strong> true
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong>
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
<strong>输出:</strong> false</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
	{
		int x = -1;
		int y = -1;
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[i].empty()) break;
			if (matrix[i][0] > target) break;
			x = i;
		}
		if (x == -1) return false;
		for (int j = 0; j < matrix[x].size(); j++)
		{
			if (matrix[x][j] > target) break;
			if (matrix[x][j] == target) return true;
		}
		return false;
    }
};
```




