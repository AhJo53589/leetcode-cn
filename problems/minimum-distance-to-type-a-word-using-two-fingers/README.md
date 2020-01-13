# `（困难）` [1320.minimum-distance-to-type-a-word-using-two-fingers 二指输入的的最小距离](https://leetcode-cn.com/problems/minimum-distance-to-type-a-word-using-two-fingers/)

[contest](https://leetcode-cn.com/contest/weekly-contest-171/problems/minimum-distance-to-type-a-word-using-two-fingers/)

### 题目描述
<p><img style="height: 250px; width: 417px;" src="./leetcode_keyboard.png" alt=""></p>
<p>二指输入法定制键盘在 XY 平面上的布局如上图所示，其中每个大写英文字母都位于某个坐标处，例如字母&nbsp;<strong>A</strong>&nbsp;位于坐标&nbsp;<strong>(0,0)</strong>，字母&nbsp;<strong>B</strong>&nbsp;位于坐标&nbsp;<strong>(0,1)</strong>，字母&nbsp;<strong>P</strong>&nbsp;位于坐标&nbsp;<strong>(2,3)</strong>&nbsp;且字母 <strong>Z</strong>&nbsp;位于坐标&nbsp;<strong>(4,1)</strong>。</p>
<p>给你一个待输入字符串&nbsp;<code>word</code>，请你计算并返回在仅使用两根手指的情况下，键入该字符串需要的最小移动总距离。坐标&nbsp;<strong>(x<sub>1</sub>,y<sub>1</sub>)</strong> 和 <strong>(x<sub>2</sub>,y<sub>2</sub>)</strong> 之间的距离是&nbsp;<strong>|x<sub>1</sub> - x<sub>2</sub>| + |y<sub>1</sub> - y<sub>2</sub>|</strong>。&nbsp;</p>
<p>注意，两根手指的起始位置是零代价的，不计入移动总距离。你的两根手指的起始位置也不必从首字母或者前两个字母开始。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong>word = "CAKE"
<strong>输出：</strong>3
<strong>解释： 
</strong>使用两根手指输入 "CAKE" 的最佳方案之一是： 
手指 1 在字母 'C' 上 -&gt; 移动距离 = 0 
手指 1 在字母 'A' 上 -&gt; 移动距离 = 从字母 'C' 到字母 'A' 的距离 = 2 
手指 2 在字母 'K' 上 -&gt; 移动距离 = 0 
手指 2 在字母 'E' 上 -&gt; 移动距离 = 从字母 'K' 到字母 'E' 的距离  = 1 
总距离 = 3
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>word = "HAPPY"
<strong>输出：</strong>6
<strong>解释： </strong>
使用两根手指输入 "HAPPY" 的最佳方案之一是：
手指 1 在字母 'H' 上 -&gt; 移动距离 = 0
手指 1 在字母 'A' 上 -&gt; 移动距离 = 从字母 'H' 到字母 'A' 的距离 = 2
手指 2 在字母 'P' 上 -&gt; 移动距离 = 0
手指 2 在字母 'P' 上 -&gt; 移动距离 = 从字母 'P' 到字母 'P' 的距离 = 0
手指 1 在字母 'Y' 上 -&gt; 移动距离 = 从字母 'A' 到字母 'Y' 的距离 = 4
总距离 = 6
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>word = "NEW"
<strong>输出：</strong>3
</pre>

<p><strong>示例 4：</strong></p>
<pre><strong>输入：</strong>word = "YEAR"
<strong>输出：</strong>7
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>2 &lt;= word.length &lt;= 300</code></li>
	<li>每个 <code>word[i]</code>&nbsp;都是一个大写英文字母。</li>
</ul>

---
### 思路
```

```



### 答题
``` C++
int M[26][2] = 
{
	{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5},
	{1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5},
	{2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5},
	{3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5},
	{4, 0}, {4, 1}
};

int dist(int i, int j)
{
	return abs(M[i][0] - M[j][0]) + abs(M[i][1] - M[j][1]);
}

int minimumDistance(string word) 
{
	int N = word.size();
	if (N < 2) return 0;

	vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(26, vector<int>(26, INT_MAX - 10)));
	int step = 0;
	for (int i = 0; i < 26; ++i) 
	{
		for (int j = 0; j < 26; ++j) 
		{
			dp[0][i][j] = 0;
		}
	}

	for (int i = 1; i <= N; ++i) 
	{
		int curr = word[i - 1] - 'A';
		for (int j = 0; j < 26; ++j) 
		{
			for (int k = 0; k < 26; ++k) 
			{
				dp[i][curr][j] = min(dp[i][curr][j], dp[i - 1][k][j] + dist(curr, k));
				dp[i][curr][j] = min(dp[i][curr][j], dp[i - 1][curr][k] + dist(k, j));

				dp[i][j][curr] = min(dp[i][j][curr], dp[i - 1][j][k] + dist(curr, k));
				dp[i][j][curr] = min(dp[i][j][curr], dp[i - 1][k][curr] + dist(k, j));
			}
		}
	}

	int ans = INT_MAX;
	int ind = word[N - 1] - 'A';
	for (int i = 0; i < 26; ++i) 
	{
		ans = min(ans, dp[N][ind][i]);
		ans = min(ans, dp[N][i][ind]);
	}
	return ans;
}
```




