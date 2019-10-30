# `（中等）` [36.valid-sudoku 有效的数独](https://leetcode-cn.com/problems/valid-sudoku/)

### 题目描述
<p>判断一个&nbsp;9x9 的数独是否有效。只需要<strong>根据以下规则</strong>，验证已经填入的数字是否有效即可。</p>

<ol>
	<li>数字&nbsp;<code>1-9</code>&nbsp;在每一行只能出现一次。</li>
	<li>数字&nbsp;<code>1-9</code>&nbsp;在每一列只能出现一次。</li>
	<li>数字&nbsp;<code>1-9</code>&nbsp;在每一个以粗实线分隔的&nbsp;<code>3x3</code>&nbsp;宫内只能出现一次。</li>
</ol>

<p><img style="height: 250px; width: 250px;" src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png"></p>

<p><small>上图是一个部分填充的有效的数独。</small></p>

<p>数独部分空格内已填入了数字，空白格用&nbsp;<code>'.'</code>&nbsp;表示。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong>
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
<strong>输出:</strong> true
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong>
[
&nbsp; ["8","3",".",".","7",".",".",".","."],
&nbsp; ["6",".",".","1","9","5",".",".","."],
&nbsp; [".","9","8",".",".",".",".","6","."],
&nbsp; ["8",".",".",".","6",".",".",".","3"],
&nbsp; ["4",".",".","8",".","3",".",".","1"],
&nbsp; ["7",".",".",".","2",".",".",".","6"],
&nbsp; [".","6",".",".",".",".","2","8","."],
&nbsp; [".",".",".","4","1","9",".",".","5"],
&nbsp; [".",".",".",".","8",".",".","7","9"]
]
<strong>输出:</strong> false
<strong>解释:</strong> 除了第一行的第一个数字从<strong> 5</strong> 改为 <strong>8 </strong>以外，空格内其他数字均与 示例1 相同。
     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。</pre>

<p><strong>说明:</strong></p>

<ul>
	<li>一个有效的数独（部分已被填充）不一定是可解的。</li>
	<li>只需要根据以上规则，验证已经填入的数字是否有效即可。</li>
	<li>给定数独序列只包含数字&nbsp;<code>1-9</code>&nbsp;和字符&nbsp;<code>'.'</code>&nbsp;。</li>
	<li>给定数独永远是&nbsp;<code>9x9</code>&nbsp;形式的。</li>
</ul>




---
### 思路
```

```


### 答题
``` C++
bool isValidSudoku(vector<vector<char>>& board)
{
	for (int i = 0; i < 9; i++)
	{
		if (checkDuplicate(board[i])) return false;
	}

	vector<char> grid[9];
	for (int i = 0; i < 9; i++)
	{
		vector<char> line;
		for (int j = 0; j < 9; j++)
		{
			line.push_back(board[j][i]);

			// 把81宫格合并成9宫格
			int k = i / 3 + j / 3 * 3;
			grid[k].push_back(board[i][j]);
		}
		if (checkDuplicate(line)) return false;
	}

	for (int i = 0; i < 9; i++)
	{
		if (checkDuplicate(grid[i])) return false;
	}

	return true;
}
``` 

