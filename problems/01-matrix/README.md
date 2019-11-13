# `（中等）` [542.01-matrix 01](https://leetcode-cn.com/problems/01-matrix/)

### 题目描述
<p>给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。</p>

<p>两个相邻元素间的距离为 1 。</p>

<p><strong>示例 1: </strong><br>
输入:</p>

<pre>0 0 0
0 1 0
0 0 0
</pre>

<p>输出:</p>

<pre>0 0 0
0 1 0
0 0 0
</pre>

<p><strong>示例 2: </strong><br>
输入:</p>

<pre>0 0 0
0 1 0
1 1 1
</pre>

<p>输出:</p>

<pre>0 0 0
0 1 0
1 2 1
</pre>

<p><strong>注意:</strong></p>

<ol>
	<li>给定矩阵的元素个数不超过 10000。</li>
	<li>给定矩阵中至少有一个元素是 0。</li>
	<li>矩阵中的元素只在四个方向上相邻: 上、下、左、右。</li>
</ol>


---
### 思路
```
首先循环一遍，将0，排除掉。  
把与0相接距离为1的1，排除掉。并且把周边4格存到队列中。  
除此之外的数字全部改变为INT_MAX。  


接下来循环队列。  
计算队列中的元素的距离，并把他周围的格子继续添加到队列中。  
注意剪枝。  
```

### 答题
``` C++
int getMin(vector<vector<int>>& matrix, int x, int y, int x_Size, int y_Size)
{
	if (matrix[x][y] == 0) return 0;
	int iMin = INT_MAX;
	if (x + 1 < x_Size) iMin = min(iMin, matrix[x + 1][y]);
	if (x - 1 >= 0) iMin = min(iMin, matrix[x - 1][y]);
	if (y + 1 < y_Size) iMin = min(iMin, matrix[x][y + 1]);
	if (y - 1 >= 0) iMin = min(iMin, matrix[x][y - 1]);
	return iMin;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
{
	int x_Size = matrix.size();
	if (x_Size == 0) return matrix;
	int y_Size = matrix[0].size();
	if (y_Size == 0) return matrix;

	queue<pair<int, int>> q;
	for (int x = 0; x < x_Size; x++)
	{
		for (int y = 0; y < y_Size; y++)
		{
			if (getMin(matrix, x, y, x_Size, y_Size) == 0)
			{
				if (matrix[x][y] == 1)
				{
					if (x + 1 < x_Size) q.push(make_pair(x + 1, y));
					if (x - 1 >= 0) q.push(make_pair(x - 1, y));
					if (y + 1 < y_Size) q.push(make_pair(x, y + 1));
					if (y - 1 >= 0) q.push(make_pair(x, y - 1));
				}
				continue;
			}
			matrix[x][y] = INT_MAX;
		}
	}

	int iMin = 0;
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();

		int x = p.first;
		int y = p.second;
		if (matrix[x][y] != INT_MAX) continue;
		if (matrix[x][y] <= iMin) continue;
		iMin = getMin(matrix, p.first, p.second, x_Size, y_Size);
		matrix[x][y] = iMin + 1;

		if (x + 1 < x_Size) q.push(make_pair(x + 1, y));
		if (x - 1 >= 0) q.push(make_pair(x - 1, y));
		if (y + 1 < y_Size) q.push(make_pair(x, y + 1));
		if (y - 1 >= 0) q.push(make_pair(x, y - 1));
	}
	return matrix;
}
```

### 其它

这个方法效率很高。  
先从左上角往右下角计算新值。  
然后再从右下角往左上角计算新值。  
两遍之后就ok了，干干净净。  
``` C++
vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
	int rows = matrix.size();
	if (rows == 0)
		return matrix;
	int cols = matrix[0].size();
	vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX - 100000));

	//First pass: check for left and top
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] == 0)
				dist[i][j] = 0;
			else {
				if (i > 0)
					dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
				if (j > 0)
					dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
			}
		}
	}

	//Second pass: check for bottom and right
	for (int i = rows - 1; i >= 0; i--) {
		for (int j = cols - 1; j >= 0; j--) {
			if (i < rows - 1)
				dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
			if (j < cols - 1)
				dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
		}
	}

	return dist;
}
```

