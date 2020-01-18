# `（简单）` [100272.happy-new-year-lol 🐭年快乐](https://leetcode-cn.com/problems/happy-new-year-lol/)

[contest](https://leetcode-cn.com/contest/sf-2020/problems/happy-new-year-lol/)

### 题目描述
<p>🐭年快要到了，出于不知名的原因，jp 的老爸给了他一个谜题，jp 首先需要从 11 号城市去到 0 号城市，jp 所在的国家一共有 <code>n</code> 个城市，每个城市的编号都小于 <code>n</code> 并且唯一，他可以通过双向公路从一个城市走到另一个城市，jp 的老爸告诉他，他需要走最短路径才能揭开谜底。</p>

<p>&nbsp;</p>

<p>除编号外，这个国家的每个城市都有一个代号，由一个可打印的字符组成，每个城市的代号并不唯一。</p>

<p>由于 jp 太懒了，他只想划水并不想做什么谜题，所以他决定把这个谜题交给你做。</p>

<p>&nbsp;</p>

<p>题目只有一套测试数据，给出城市数量 <code>n</code>，所有公路 <code>roads</code>，其中每个元素 <code>r</code> 是一个数组，<code>r[0]</code> 和 <code>r[1]</code> 是公路连接的两个城市的编号（而不是代号），<code>r[2]</code> 代表公路的长度，还有每个城市的代号 <code>codes</code>，<code>codes[i]</code> 代表 <code>i</code> 号城市的代号。</p>

<p>&nbsp;</p>

<p>你的程序需要返回谜底，一个字符串。</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>题目保证最短路径存在并唯一</li>
	<li>公路长度为正整数，且总和不会溢出 32 位整数</li>
	<li>两个城市之间可能存在多条公路，一条公路可能连接同一个城市</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
string happy(int n, vector<vector<int>>& roads, vector<string>& codes)
{
	vector<unordered_map<int, int>> _roads(n, unordered_map<int, int>());
	for (auto& r : roads)
	{
		if (_roads[r[0]].count(r[1]) == 0)
		{
			_roads[r[0]][r[1]] = r[2];
		}
		else
		{
			_roads[r[0]][r[1]] = min(r[2], _roads[r[0]][r[1]]);
		}
		if (_roads[r[1]].count(r[0]) == 0)
		{
			_roads[r[1]][r[0]] = r[2];
		}
		else
		{
			_roads[r[1]][r[0]] = min(r[2], _roads[r[1]][r[0]]);
		}
	}

	priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;

	int minPath = INT_MAX;
	vector<int> ans;
	pq.push({ 0, {11} });
	while (!pq.empty())
	{
		auto p = pq.top();
		pq.pop();

		int sum = p.first;
		if (sum >= minPath) break;

		vector<int>& cur = p.second;
		int city = cur.back();
		vector<int> vi(n, 0);
		for (size_t i = 0; i < cur.size(); i++)
		{
			vi[cur[i]] = 1;
		}
		for (auto& r : _roads[city])
		{
			if (vi[r.first] == 1) continue;
			int ps = sum + r.second;
			cur.push_back(r.first);
			pq.push({ ps, cur });
			if (r.first == 0)
			{
				if (ps < minPath)
				{
					minPath = ps;
					ans = cur;
				}
			}
			cur.pop_back();
		}
	}

	string str;
	for (size_t i = 0; i < ans.size(); i++)
	{
		str += codes[ans[i]];
	}
	return str;
}
```




