# `（困难）`  [149.max-points-on-a-line 直线上最多的点数](https://leetcode-cn.com/problems/max-points-on-a-line/)

### 题目描述
<p>给定一个二维平面，平面上有&nbsp;<em>n&nbsp;</em>个点，求最多有多少个点在同一条直线上。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [[1,1],[2,2],[3,3]]
<strong>输出:</strong> 3
<strong>解释:</strong>
^
|
| &nbsp; &nbsp; &nbsp; &nbsp;o
| &nbsp; &nbsp; o
| &nbsp;o &nbsp;
+-------------&gt;
0 &nbsp;1 &nbsp;2 &nbsp;3  4
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
<strong>输出:</strong> 4
<strong>解释:</strong>
^
|
|  o
| &nbsp;&nbsp;&nbsp;&nbsp;o&nbsp;&nbsp;      o
| &nbsp;&nbsp;&nbsp;&nbsp;   o
| &nbsp;o &nbsp;      o
+-------------------&gt;
0 &nbsp;1 &nbsp;2 &nbsp;3 &nbsp;4 &nbsp;5 &nbsp;6</pre>


---
### 思路
```
不排序的话，判定重复的计数非常困难。
加了调试代码才发现哪里有问题。

另外虽然省了排序的时间，但是查找的时候效率差了太多。
所以还是应该先排序。
```


另外，一开始考虑用斜率做键值，然后踩到了unordered_map<pair<int, int>, int>的坑。  
[使用unordered_set的pair](https://blog.csdn.net/zhaohaibo_/article/details/90340120)


### 答题
``` C++
bool isLine(vector<int>& a, vector<int>& b, vector<int>& c)
{
	long long tmp1 = ((long long)a[0] - b[0]) * ((long long)a[1] - c[1]);
	long long tmp2 = ((long long)a[0] - c[0]) * ((long long)a[1] - b[1]);
	if (tmp1 == tmp2) return true;
	return false;
}

int maxPoints(vector<vector<int>>& points)
{
	if (points.size() < 3) return points.size();
	int res = 0;
	for (int i = 0; i < points.size(); i++)
	{
		int cnt1 = 1;
		for (int j = i + 1; j < points.size(); j++)
		{
			if (points[i] == points[j])
			{
				cnt1++;
				res = max(res, cnt1);
				continue;
			}
			int cnt2 = 1;
			for (int k = j + 1; k < points.size(); k++)
			{
				if (points[i] == points[k] || points[j] == points[k]) cnt2++;
				else if (isLine(points[i], points[j], points[k])) cnt2++;
			}
			res = max(res, cnt1 + cnt2);
		}
	}
	return res;
}
```

### 其它
``` C++
bool cmp(vector<int>& a, vector<int>& b)
{
	if (a[0] != b[0]) return a[0] < b[0];
	else return a[1] < b[1];
}

bool isLine(vector<int>& a, vector<int>& b, vector<int>& c)
{
	long long tmp1 = ((long long)a[0] - b[0]) * ((long long)a[1] - c[1]);
	long long tmp2 = ((long long)a[0] - c[0]) * ((long long)a[1] - b[1]);
	if (tmp1 == tmp2) return true;
	return false;
}

int maxPoints(vector<vector<int>>& points) 
{
	if (points.size() < 3) return points.size();
	sort(points.begin(), points.end(), cmp);

	int ans = 2, count1 = 1, count2 = 1;
	for (int i = 0; i < points.size() - 2; i++) 
	{
		count1 = 1;
		while (i < points.size() - 3 && points[i + 1][0] == points[i][0] && points[i + 1][1] == points[i][1]) 
		{
			count1++;
			i++;
		}
		for (int j = i + 1; j < points.size() - 1; j++) 
		{
			count2 = 1;
			while (j < points.size() - 2 && points[j + 1][0] == points[j][0] && points[j + 1][1] == points[j][1]) 
			{
				count2++;
				j++;
			}
			int tmp = count1 + count2;
			for (int k = j + 1; k < points.size(); k++) {
				if (isLine(points[i], points[j], points[k])) tmp++;
			}
			ans = ans > tmp ? ans : tmp;
		}
	}
	return ans;
}
```

