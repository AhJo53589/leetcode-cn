# `（简单）`  [447.number-of-boomerangs 回旋镖的数量](https://leetcode-cn.com/problems/number-of-boomerangs/)

### 题目描述
<p>给定平面上<em>&nbsp;n </em>对不同的点，“回旋镖” 是由点表示的元组&nbsp;<code>(i, j, k)</code>&nbsp;，其中&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code>&nbsp;之间的距离和&nbsp;<code>i</code>&nbsp;和&nbsp;<code>k</code>&nbsp;之间的距离相等（<strong>需要考虑元组的顺序</strong>）。</p>

<p>找到所有回旋镖的数量。你可以假设<em>&nbsp;n </em>最大为 <strong>500</strong>，所有点的坐标在闭区间<strong> [-10000, 10000] </strong>中。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>
[[0,0],[1,0],[2,0]]

<strong>输出:</strong>
2

<strong>解释:</strong>
两个回旋镖为 <strong>[[1,0],[0,0],[2,0]]</strong> 和 <strong>[[1,0],[2,0],[0,0]]</strong>
</pre>


---
### 思路
```
```

### 答题
``` C++
int numberOfBoomerangs(vector<vector<int>>& points) 
{
	int res = 0;
	if (points.empty()) return res;
	for (int i = 0; i < points.size(); i++)
	{
		unordered_map<double, int> _map;
		for (int j = 0; j < points.size(); j++)
		{
			if (i == j) continue;
			double dis = pow(((double)points[i][0] - (double)points[j][0]), 2) + pow(((double)points[i][1] - (double)points[j][1]), 2);
			//if (_map.count(dis))	// 可以用排列组合公式
			//{
			//	res += _map[dis] * 2;
			//}
			_map[dis]++;
		}
		for (auto p : _map) res += p.second * (p.second - 1);	//计算排列组合公式 n * (n - 1)
	}
	return res;
}
```

### 其它
``` C++
int dis(vector<int>&p1, vector<int>&p2)
{
	return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
}
int numberOfBoomerangs(vector<vector<int>>& points) {
	int count = 0;
	int n = points.size();
	int data[n][n] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			data[i][j] = dis(points[i], points[j]);
			data[j][i] = data[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		int cn = 1;
		sort(data[i], data[i] + n);
		for (int j = 0; j < n - 1; j++)
		{
			if (data[i][j] == data[i][j + 1])
				cn++;
			else
			{
				count += cn * (cn - 1);
				cn = 1;
			}
		}
		count += cn * (cn - 1);
	}
	return count;
}
```

