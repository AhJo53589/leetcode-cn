# `（困难）` [1349.maximum-students-taking-exam 参加考试的最大学生数](https://leetcode-cn.com/problems/maximum-students-taking-exam/)

[contest](https://leetcode-cn.com/contest/weekly-contest-175/problems/maximum-students-taking-exam/)

### 题目描述
<p>给你一个&nbsp;<code>m&nbsp;* n</code>&nbsp;的矩阵 <code>seats</code>&nbsp;表示教室中的座位分布。如果座位是坏的（不可用），就用&nbsp;<code>'#'</code>&nbsp;表示；否则，用&nbsp;<code>'.'</code>&nbsp;表示。</p>
<p>学生可以看到左侧、右侧、左上、右上这四个方向上紧邻他的学生的答卷，但是看不到直接坐在他前面或者后面的学生的答卷。请你计算并返回该考场可以容纳的一起参加考试且无法作弊的最大学生人数。</p>
<p>学生必须坐在状况良好的座位上。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<p><img src="./image.png" style="height: 197px; width: 339px;"></p>
<pre><strong>输入：</strong>seats = [["#",".","#","#",".","#"],
&nbsp;             [".","#","#","#","#","."],
&nbsp;             ["#",".","#","#",".","#"]]
<strong>输出：</strong>4
<strong>解释：</strong>教师可以让 4 个学生坐在可用的座位上，这样他们就无法在考试中作弊。 
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>seats = [[".","#"],
&nbsp;             ["#","#"],
&nbsp;             ["#","."],
&nbsp;             ["#","#"],
&nbsp;             [".","#"]]
<strong>输出：</strong>3
<strong>解释：</strong>让所有学生坐在可用的座位上。
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>seats = [["#",".","<strong>.</strong>",".","#"],
&nbsp;             ["<strong>.</strong>","#","<strong>.</strong>","#","<strong>.</strong>"],
&nbsp;             ["<strong>.</strong>",".","#",".","<strong>.</strong>"],
&nbsp;             ["<strong>.</strong>","#","<strong>.</strong>","#","<strong>.</strong>"],
&nbsp;             ["#",".","<strong>.</strong>",".","#"]]
<strong>输出：</strong>10
<strong>解释：</strong>让学生坐在第 1、3 和 5 列的可用座位上。
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>seats</code>&nbsp;只包含字符&nbsp;<code>'.'&nbsp;和</code><code>'#'</code></li>
	<li><code>m ==&nbsp;seats.length</code></li>
	<li><code>n ==&nbsp;seats[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 8</code></li>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>

​            

---
### 思路
```

```

[发布的题解](https://leetcode-cn.com/problems/maximum-students-taking-exam/solution/5335-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
	int getCount(int n)
	{
		bitset<8> bs(n);
		return bs.count();
	}

	bool checkChair(vector<vector<char>>& seats, int row, int n)
	{
		bitset<8> bs(n);
		for (int i = 0; i < seats[row].size(); i++)
		{
			if (seats[row][i] == '#' && bs[i] == 1) return false;
		}
		return true;
	}

	bool checkValid(int n)
	{
		bitset<8> bs(n);
		for (int i = 1; i < 8; i++)
		{
			if (bs[i] == 1 && bs[i - 1] == 1) return false;
		}
		return true;
	}

	int maxStudents(vector<vector<char>>& seats)
	{
		int ans = 0;
		vector<vector<int>> dp(seats.size(), vector<int>(1 << seats[0].size(), 0));

		for (int i = 0; i < seats.size(); i++)
		{
			for (int j = 0; j < (1 << seats[0].size()); j++)
			{
				if (!checkChair(seats, i, j)) continue;
				if (!checkValid(j)) continue;
				int cnt = getCount(j);
				if (i == 0)
				{
					dp[i][j] = cnt;
				}
				else
				{
					for (int k = 0; k < (1 << seats[0].size()); k++)
					{
						if (!checkValid(j | k)) continue;
						dp[i][j] = max(dp[i][j], dp[i - 1][k] + cnt);
					}
				}
				ans = max(ans, dp[i][j]);
			}
		}
		return ans;
	}
};
```




