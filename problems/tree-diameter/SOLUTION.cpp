
//////////////////////////////////////////////////////////////////////////
// bfs
pair<int, int> bfs(unordered_map<int, vector<int>> &r, int start)
{
	vector<int> visited(r.size(), - 1);

	queue<int> q;
	q.push(start);
	visited[start] = 0;

	pair<int, int> ret;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		ret.first = x;
		ret.second = visited[x];

		for (auto &y : r[x])
		{
			if (visited[y] == -1)
			{
				visited[y] = visited[x] + 1;
				q.push(y);
			}
		}
	}
	return ret;
}

int treeDiameter(vector<vector<int>>& edges)
{
	sort(edges.begin(), edges.end());
	unordered_map<int, vector<int>> route;
	for (auto n : edges)
	{
		route[n[0]].push_back(n[1]);
		route[n[1]].push_back(n[0]);
	}

	auto ans = bfs(route, 0);
	ans = bfs(route, ans.first);
	return ans.second;
}

//////////////////////////////////////////////////////////////////////////
// dfs ��ʱ
//void dfs(unordered_map<int, vector<int>> &r, unordered_set<int> v, int i, int val, int &ans)
//{
//	if (v.count(i) == 1 || r.count(i) == 0)
//	{
//		ans = max(ans, val);
//		return;
//	}
//	v.insert(i);
//	val++;
//	for (auto n : r[i])
//	{
//		dfs(r, v, n, val, ans);
//	}
//}
//
//int treeDiameter(vector<vector<int>>& edges)
//{
//	sort(edges.begin(), edges.end());
//	unordered_map<int, vector<int>> route;
//	for (auto n : edges)
//	{
//		route[n[0]].push_back(n[1]);
//		route[n[1]].push_back(n[0]);
//	}
//
//	int ans = 0;
//	unordered_set<int> visited;
//	for (auto &r : route)
//	{
//		dfs(route, visited, r.first, 0, ans);
//	}
//	return ans - 1;
//}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& edges)
{
	return treeDiameter(edges);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

