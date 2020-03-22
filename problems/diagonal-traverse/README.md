# `（中等）` [498.diagonal-traverse 对角线遍历](https://leetcode-cn.com/problems/diagonal-traverse/)

### 题目描述
<p>给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。</p>
<p>&nbsp;</p>
<p><strong>示例:</strong></p>
<pre><strong>输入:</strong>
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

<strong>输出:</strong>  [1,2,4,7,5,3,6,8,9]

<strong>解释:</strong>
<img style="width: 220px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/diagonal_traverse.png">
</pre>

<p>&nbsp;</p>
<p><strong>说明:</strong></p>
<ol>
	<li>给定矩阵中的元素总数不会超过 100000 。</li>
</ol>

---
### 思路
```
根据题目描述，仔细找了找这道题的一些数字上的规律（可以结合题目给的图来看）。  
得知：  
1. 每一趟对角线中元素的坐标（x, y）相加的和是递增的。即第一趟 x + y == 0，第二趟 x + y == 1，第三趟 x + y == 2 ……
2. 每一趟都是 x 或 y 其中一个从大到小（每次-1），另一个从小到大（每次+1）。
3. 例如这一趟是 x 从大到小， x 尽量取最大，当初始值超过 x 的上限时，不足的部分加到 y 上面。
4. 例如这一趟是 x 从大到小，这一趟结束的判断是， x 减到 0 或者 y 加到上限。
5. 这一趟是 x 从大到小，那么下一趟是 y 从大到小，循环进行。  并且方向相反时，逻辑处理是一样的，除了x，y和他们各自的上限值是相反的。  
```
[发布的题解](https://leetcode-cn.com/problems/diagonal-traverse/solution/dui-jiao-xian-bian-li-fen-xi-ti-mu-zhao-zhun-gui-l/)


### 答题
``` C++
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        bool flag = true;
        for (int i = 0; i < m + n - 1; i++)
        {
            int pm = flag ? m : n;
            int pn = flag ? n : m;

            int px = (i < pm) ? i : pm - 1;
            int py = i - px;

            while (px >= 0 && py < pn)
            {
                ans.push_back(flag ? matrix[px][py] : matrix[py][px]);
                px--;
                py++;
            }

            flag = !flag;
        }
        return ans;
    }
};
```

### 其它

分享别人算法。  
``` C++
vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
{
	if (matrix.empty()) return vector<int>();
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<int> output;
	int i = 0, j = 0;
	output.push_back(matrix[i][j]);
	while (i != rows - 1 || j != cols - 1)
	{
		if (j + 1 < cols) j++;
		else if (i + 1 < rows) i++;
		output.push_back(matrix[i][j]);

		while (i + 1 < rows && j - 1 >= 0)
		{
			i++;
			j--;
			output.push_back(matrix[i][j]);
		}

		if (i + 1 < rows) i++;
		else if (j + 1 < cols) j++;
		else return output;
		output.push_back(matrix[i][j]);

		while (i - 1 >= 0 && j + 1 < cols)
		{
			i--;
			j++;
			output.push_back(matrix[i][j]);
		}
	}
	return output;
}
```

另一个
``` JAVA
class Solution 
{
	public int[] findDiagonalOrder(int[][] matrix)
	{
		if(matrix==null||matrix.length==0||matrix[0].length==0)
		{
			return new int[0]; 
		} 
		int m = matrix.length-1; 
		int n = matrix[0].length-1; 
		int[] newArray = new int[(m+1)*(n+1)]; 
		int row = 0, col = 0; 
		for(int i =0;i<newArray.length;i++)
		{ 
			newArray[i] = matrix[row][col];//初始化 
			if((row+col)%2==0)
			{
				//右上方向，为偶数时向右上方向， 
				if(col==n)
				{
					//边界就是当列到最右边时，即行向下 
					row++; 
				}
				else if(row==0)
				{ 
					col++; 
				}
				else
				{ 
					row--; 
					col++; 
				} 
			}
			else
			{
				//奇数时，向左下方向 
				if(row==m)
				{ 
					col++; 
				}
				else if(col==0)
				{ 
					row++; 
				}
				else
				{ 
					row++; 
					col--; 
				} 
			} 
		} 
		return newArray; 
	} 
}
```


