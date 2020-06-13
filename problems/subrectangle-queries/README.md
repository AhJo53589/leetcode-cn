# `（中等）` [5422.subrectangle-queries 子矩形查询](https://leetcode-cn.com/problems/subrectangle-queries/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-28/problems/subrectangle-queries/)

### 题目描述
<p>请你实现一个类&nbsp;<code>SubrectangleQueries</code>&nbsp;，它的构造函数的参数是一个 <code>rows x cols</code>&nbsp;的矩形（这里用整数矩阵表示），并支持以下两种操作：</p>

<p>1.<code>&nbsp;updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)</code></p>

<ul>
	<li>用&nbsp;<code>newValue</code>&nbsp;更新以&nbsp;<code>(row1,col1)</code>&nbsp;为左上角且以&nbsp;<code>(row2,col2)</code>&nbsp;为右下角的子矩形。</li>
</ul>

<p>2.<code>&nbsp;getValue(int row, int col)</code></p>

<ul>
	<li>返回矩形中坐标 <code>(row,col)</code> 的当前值。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
["SubrectangleQueries","getValue","updateSubrectangle","getValue","getValue","updateSubrectangle","getValue","getValue"]
[[[[1,2,1],[4,3,4],[3,2,1],[1,1,1]]],[0,2],[0,0,3,2,5],[0,2],[3,1],[3,0,3,2,10],[3,1],[0,2]]
<strong>输出：</strong>
[null,1,null,5,5,null,10,5]
<strong>解释：</strong>
SubrectangleQueries subrectangleQueries = new SubrectangleQueries([[1,2,1],[4,3,4],[3,2,1],[1,1,1]]);  
// 初始的 (4x3) 矩形如下：
// 1 2 1
// 4 3 4
// 3 2 1
// 1 1 1
subrectangleQueries.getValue(0, 2); // 返回 1
subrectangleQueries.updateSubrectangle(0, 0, 3, 2, 5);
// 此次更新后矩形变为：
// 5 5 5
// 5 5 5
// 5 5 5
// 5 5 5 
subrectangleQueries.getValue(0, 2); // 返回 5
subrectangleQueries.getValue(3, 1); // 返回 5
subrectangleQueries.updateSubrectangle(3, 0, 3, 2, 10);
// 此次更新后矩形变为：
// 5   5   5
// 5   5   5
// 5   5   5
// 10  10  10 
subrectangleQueries.getValue(3, 1); // 返回 10
subrectangleQueries.getValue(0, 2); // 返回 5
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>
["SubrectangleQueries","getValue","updateSubrectangle","getValue","getValue","updateSubrectangle","getValue"]
[[[[1,1,1],[2,2,2],[3,3,3]]],[0,0],[0,0,2,2,100],[0,0],[2,2],[1,1,2,2,20],[2,2]]
<strong>输出：</strong>
[null,1,null,100,100,null,20]
<strong>解释：</strong>
SubrectangleQueries subrectangleQueries = new SubrectangleQueries([[1,1,1],[2,2,2],[3,3,3]]);
subrectangleQueries.getValue(0, 0); // 返回 1
subrectangleQueries.updateSubrectangle(0, 0, 2, 2, 100);
subrectangleQueries.getValue(0, 0); // 返回 100
subrectangleQueries.getValue(2, 2); // 返回 100
subrectangleQueries.updateSubrectangle(1, 1, 2, 2, 20);
subrectangleQueries.getValue(2, 2); // 返回 20
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>最多有&nbsp;<code>500</code>&nbsp;次<code>updateSubrectangle</code> 和&nbsp;<code>getValue</code>&nbsp;操作。</li>
	<li><code>1 <= rows, cols <= 100</code></li>
	<li><code>rows ==&nbsp;rectangle.length</code></li>
	<li><code>cols == rectangle[i].length</code></li>
	<li><code>0 <= row1 <= row2 < rows</code></li>
	<li><code>0 <= col1 <= col2 < cols</code></li>
	<li><code>1 <= newValue, rectangle[i][j] <= 10^9</code></li>
	<li><code>0 <= row < rows</code></li>
	<li><code>0 <= col < cols</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class SubrectangleQueries {
public:
	SubrectangleQueries(vector<vector<int>>& rectangle) : rect(rectangle) {

	}

	void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        if (row1 < 0 || row1 >= rect.size()) return;
        if (col1 < 0 || col1 >= rect[0].size()) return;
        if (row2 < 0 || row2 >= rect.size()) return;
        if (col2 < 0 || col2 >= rect[0].size()) return;
		for (int i = row1; i <= row2; i++) {
			for (int j = col1; j <= col2; j++) {
				rect[i][j] = newValue;
			}
		}
	}

	int getValue(int row, int col) {
		if (row < 0 || row >= rect.size()) return -1; 
		if (col < 0 || col >= rect[0].size()) return -1;
		return rect[row][col];
	}

private:
	vector<vector<int>> rect;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
```




