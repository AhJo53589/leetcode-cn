# `（中等）`  [59.spiral-matrix-ii 螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/)

### 题目描述
<p>给定一个正整数&nbsp;<em>n</em>，生成一个包含 1 到&nbsp;<em>n</em><sup>2</sup>&nbsp;所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 3
<strong>输出:</strong>
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]</pre>


---
### 思路
```
```

### 答题
``` C++
vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> ret(n, vector<int>(n));

	int i = 0;
	int j = 0;
	int val = 1;
	int direction = 0;
	while (val <= n * n)
	{
		ret[i][j] = val++;

		if (direction == 0 && (j == n - 1 || ret[i][j + 1] != 0)) direction = 1;
		else if (direction == 1 && (i == n - 1 || ret[i + 1][j] != 0)) direction = 2;
		else if (direction == 2 && (j == 0 || ret[i][j - 1] != 0)) direction = 3;
		else if (direction == 3 && (i == 0 || ret[i - 1][j] != 0)) direction = 0;

		if (direction == 0) j++;
		else if (direction == 1) i++;
		else if (direction == 2) j--;
		else if (direction == 3) i--;
	}
	return ret;
}
```

### 其它
``` C++
vector<vector<int>> generateMatrix(int n) {
	if (n == 0)
		return {};

	vector<vector<int>> matrix(n, vector<int>(n, 0));
	int count = 1;
	int up = 0, down = n - 1, left = 0, right = n - 1;

	while (count <= n * n) {
		for (int i = left; i <= right; i++) {
			matrix[up][i] = count;
			++count;
		}
		++up;
		for (int i = up; i <= down; i++) {
			matrix[i][right] = count;
			++count;
		}
		--right;
		for (int i = right; i >= left; i--) {
			matrix[down][i] = count;
			++count;
		}
		--down;
		for (int i = down; i >= up; i--) {
			matrix[i][left] = count;
			++count;
		}
		++left;
	}
	return matrix;
}
```

