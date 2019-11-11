# `（简单）` [48.rotate-image 旋转图像](https://leetcode-cn.com/problems/rotate-image/)

### 题目描述
<p>给定一个 <em>n&nbsp;</em>×&nbsp;<em>n</em> 的二维矩阵表示一个图像。</p>

<p>将图像顺时针旋转 90 度。</p>

<p><strong>说明：</strong></p>

<p>你必须在<strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95">原地</a></strong>旋转图像，这意味着你需要直接修改输入的二维矩阵。<strong>请不要</strong>使用另一个矩阵来旋转图像。</p>

<p><strong>示例 1:</strong></p>

<pre>给定 <strong>matrix</strong> = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

<strong>原地</strong>旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
</pre>

<p><strong>示例 2:</strong></p>

<pre>给定 <strong>matrix</strong> =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

<strong>原地</strong>旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
</pre>




---
### 思路
```

```


### 答题
``` C++
//firstly exchange elements by diagonal, then exchange elements by mid-line.
void rotate(vector<vector<int>>& matrix)
{
	int temp;
	int end = matrix.size() - 1;
	float mid_line = end / 2;
	for (int i = 0; i <= end; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}
	for (int i = 0; i <= end; i++)
	{
		for (int j = 0; j <= mid_line; j++)
		{
			swap(matrix[i][j], matrix[i][end - j]);
		}
	}
}
``` 


### 其它
这道题一看就感觉没思路，学习了别人写的，这个方法比较好理解。  
先沿着对角线翻转一次，  
再按中线翻转一次。  

想了想还是应该调用旋转公式的，  
回头补习一下。  

