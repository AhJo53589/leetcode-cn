# `（简单）`  [5230.check-if-it-is-a-straight-line 缀点成线](https://leetcode-cn.com/contest/weekly-contest-159/problems/check-if-it-is-a-straight-line/)

### 题目描述
<p>在一个&nbsp;XY 坐标系中有一些点，我们用数组&nbsp;<code>coordinates</code>&nbsp;来分别记录它们的坐标，其中&nbsp;<code>coordinates[i] = [x, y]</code>&nbsp;表示横坐标为 <code>x</code>、纵坐标为 <code>y</code>&nbsp;的点。</p>

<p>请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 &lt;font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"&gt;<span style="">true</span>&lt;/font&gt;，否则请返回 &lt;font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"&gt;<span style="">false</span>&lt;/font&gt;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/19/untitled-diagram-2.jpg" style="height: 336px; width: 336px;"></p>

<pre><strong>输入：</strong>coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/19/untitled-diagram-1.jpg" style="height: 336px; width: 348px;"></strong></p>

<pre><strong>输入：</strong>coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;=&nbsp;coordinates.length &lt;= 1000</code></li>
	<li><code>coordinates[i].length == 2</code></li>
	<li><code>-10^4 &lt;=&nbsp;coordinates[i][0],&nbsp;coordinates[i][1] &lt;= 10^4</code></li>
	<li><code>coordinates</code>&nbsp;中不含重复的点</li>
</ul>

            

---
### 思路
```
```

### 答题
``` C++
bool isLine(vector<int>& a, vector<int>& b, vector<int>& c)
{
	long long t1 = ((long long)a[0] - b[0]) * ((long long)a[1] - c[1]);
	long long t2 = ((long long)a[0] - c[0]) * ((long long)a[1] - b[1]);
	return t1 == t2;
}

bool checkStraightLine(vector<vector<int>>& coordinates) 
{
	vector<vector<int>>& c = coordinates;
	if (c.size() < 3) return true;
	for (size_t i = 0; i < c.size() - 2; i++)
	{
		if (!isLine(c[i], c[i + 1], c[i + 2]))
			return false;
	}
	return true;
}
```

