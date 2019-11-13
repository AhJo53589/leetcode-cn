# `（中等）` [54.spiral-matrix 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/)

### 题目描述
<p>给定一个包含&nbsp;<em>m</em> x <em>n</em>&nbsp;个元素的矩阵（<em>m</em> 行, <em>n</em> 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong>
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
<strong>输出:</strong> [1,2,3,6,9,8,7,4,5]
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong>
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
<strong>输出:</strong> [1,2,3,4,8,12,11,10,9,5,6,7]
</pre>


---
### 思路
```
过于依赖合并逻辑这种手法了，感觉有点走歪了。    
分享的别人代码是用for循环控制就搞定了。  
```

### 答题
``` C++
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> nums;
	int m = matrix.size();
	if (m == 0) return nums;
	int n = matrix[0].size();
	if (n == 0) return nums;

	// 0 == →, 1 == ↓, 2 == ←, 3 == ↑
	int iDirection = 0;
	int iSize = m * n;
	int x = 0;
	int y = -1;

	while (nums.size() < iSize)
	{
		int iCount = 1;
		int iMaxCount = (iDirection % 2 == 0) ? n : m;
		int iStepX = (iDirection % 2 == 0) ? 0 : (iDirection / 2 == 0) ? 1 : -1;
		int iStepY = (iDirection % 2 == 1) ? 0 : (iDirection / 2 == 0) ? 1 : -1;

		while (iCount <= iMaxCount)
		{
			x = x + iStepX;
			y = y + iStepY;
			nums.push_back(matrix[x][y]);
			iCount++;
		}
		if (iDirection % 2 == 0) m--;
		else n--;

		iDirection = (iDirection + 1) % 4;
	}

	return nums;
}
```

### 其它
``` C++
vector<int> spiralOrder(vector<vector<int> > &matrix) {
	if (matrix.empty() || matrix[0].empty()) return {};
	int m = matrix.size(), n = matrix[0].size();
	vector<int> res;
	int c = m > n ? (n + 1) / 2 : (m + 1) / 2;
	int p = m, q = n;
	for (int i = 0; i < c; ++i, p -= 2, q -= 2) {
		for (int col = i; col < i + q; ++col)
			res.push_back(matrix[i][col]);
		for (int row = i + 1; row < i + p; ++row)
			res.push_back(matrix[row][i + q - 1]);
		if (p == 1 || q == 1) break;
		for (int col = i + q - 2; col >= i; --col)
			res.push_back(matrix[i + p - 1][col]);
		for (int row = i + p - 2; row > i; --row)
			res.push_back(matrix[row][i]);
	}
	return res;
}
```

