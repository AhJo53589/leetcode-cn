# `（中等）` [1288.remove-covered-intervals 删除被覆盖区间](https://leetcode-cn.com/problems/remove-covered-intervals/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-15/problems/remove-covered-intervals/)

### 题目描述
<p>给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。</p>

<p>只有当&nbsp;<code>c &lt;= a</code>&nbsp;且&nbsp;<code>b &lt;= d</code>&nbsp;时，我们才认为区间&nbsp;<code>[a,b)</code> 被区间&nbsp;<code>[c,d)</code> 覆盖。</p>

<p>在完成所有删除操作后，请你返回列表中剩余区间的数目。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>intervals = [[1,4],[3,6],[2,8]]
<strong>输出：</strong>2
<strong>解释：</strong>区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong>​​​​​​</p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 1000</code></li>
	<li><code>0 &lt;= intervals[i][0] &lt;&nbsp;intervals[i][1] &lt;= 10^5</code></li>
	<li>对于所有的&nbsp;<code>i != j</code>：<code>intervals[i] != intervals[j]</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
int removeCoveredIntervals(vector<vector<int>>& intervals) 
{
	sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
		{
			if (a[0] == b[0])
			{
				return b[1] < a[1];
			}
			return (a[0] < b[0]);
		});

	for (auto v : intervals)
	{
		cout << v[0] << "," << v[1] << endl;
	}
	int cnt = 0;
	for (size_t i = 1; i < intervals.size(); i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (intervals[i][0] >= intervals[j][0]
				&& intervals[i][1] <= intervals[j][1])
			{
				cnt++;
				break;
			}
		}
	}
	return intervals.size() - cnt;
}
```




