# `（中等）`  [56.merge-intervals 合并区间](https://leetcode-cn.com/problems/merge-intervals/)

### 题目描述
<p>给出一个区间的集合，请合并所有重叠的区间。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [[1,3],[2,6],[8,10],[15,18]]
<strong>输出:</strong> [[1,6],[8,10],[15,18]]
<strong>解释:</strong> 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> [[1,4],[4,5]]
<strong>输出:</strong> [[1,5]]
<strong>解释:</strong> 区间 [1,4] 和 [4,5] 可被视为重叠区间。</pre>


---
### 思路
```
```

### 答题
``` C++
vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	auto vector_earse = [](vector<vector<int>> &a, int n)
	{
		for (int i = n; i < a.size() - 1; i++) a[i] = a[i + 1];
		if (a.size() > 0 && a.size() > n) a.pop_back();
	};

	vector<vector<int>> ans;
	for (int i = 0; i < intervals.size(); i++)
	{
		auto n = intervals[i];
		ans.push_back(n);
		if (ans.size() == 1) continue;
		int repeat = ans.size() - 1;
		for (int j = ans.size() - 2; j >= 0; j--)
		{
			auto &m = ans[j];
			if (n[0] <= m[1] && n[1] >= m[0])
			{
				m[0] = min(n[0], m[0]);
				m[1] = max(n[1], m[1]);
				vector_earse(ans, repeat);
				repeat = j;
				n = m;
			}
		}
	}

	return ans;
}
```

### 其它
``` C++
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	auto f = [](const vector<int> &vec1, const vector<int> &vec2)
	{
		return vec1[0] < vec2[0];
	};

	sort(intervals.begin(), intervals.end(), f);

	int i = 0;
	for (int j = 0; j < intervals.size(); ++i)
	{
		if (i != j)
		{
			intervals[i] = intervals[j];
		}

		++j;
		for (; j < intervals.size(); ++j)
		{
			if (intervals[i][1] >= intervals[j][0])
			{
				intervals[i][1] = max(intervals[i][1], intervals[j][1]);
			}
			else
			{
				break;
			}
		}

	}

	intervals.resize(i);
	return intervals;
}
```

