# `（中等）` [63.unique-paths-ii 不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/)

### 题目描述
<p>一个机器人位于一个 <em>m x n </em>网格的左上角 （起始点在下图中标记为“Start” ）。</p>

<p>机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。</p>

<p>现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？</p>

<p><img style="height: 183px; width: 400px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/robot_maze.png"></p>

<p>网格中的障碍物和空位置分别用 <code>1</code> 和 <code>0</code> 来表示。</p>

<p><strong>说明：</strong><em>m</em>&nbsp;和 <em>n </em>的值均不超过 100。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:
</strong>[
&nbsp; [0,0,0],
&nbsp; [0,1,0],
&nbsp; [0,0,0]
]
<strong>输出:</strong> 2
<strong>解释:</strong>
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 <code>2</code> 条不同的路径：
1. 向右 -&gt; 向右 -&gt; 向下 -&gt; 向下
2. 向下 -&gt; 向下 -&gt; 向右 -&gt; 向右
</pre>


---
### 思路
```
```



### 答题
``` C++
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
	vector<vector<double>> dp(obstacleGrid.size(), vector<double>(obstacleGrid[0].size(), 0));

	for (size_t i = 0; i < obstacleGrid.size(); i++)
	{
		for (size_t j = 0; j < obstacleGrid[0].size(); j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = (obstacleGrid[i][j] == 0);
				if (i != 0 && dp[i - 1][j] == 0)
				{
					dp[i][j] = 0;
				}
				if (j != 0 && dp[i][j - 1] == 0)
				{
					dp[i][j] = 0;
				}
			}
			else
			{
				if (obstacleGrid[i][j] == 1)
				{
					dp[i][j] = 0;
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
}
```




