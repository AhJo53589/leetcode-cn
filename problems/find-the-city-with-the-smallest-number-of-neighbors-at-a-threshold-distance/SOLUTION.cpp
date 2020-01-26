


//////////////////////////////////////////////////////////////////////////
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
{
	vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
	for (auto& edge : edges)
	{
		int u = edge[0];
		int v = edge[1];
		dis[u][v] = min(edge[2], dis[u][v]);
		dis[v][u] = min(edge[2], dis[v][u]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int u = 0; u < n; u++)
		{
			if (i == u) continue;
			for (int v = 0; v < n; v++)
			{
				if (v == u || v == i) continue;
				if (dis[u][i] == INT_MAX || dis[i][v] == INT_MAX) continue;
				dis[u][v] = min(dis[u][v], dis[u][i] + dis[i][v]);
				dis[v][u] = min(dis[u][v], dis[v][u]);
			}
		}
	}

	int minn = INT_MAX;
	int ans = -1;
	for (int i = n - 1; i >= 0; i--)
	{
		int cnt = 0;
		for (int nex = 0; nex < n; nex++)
		{
			cnt += (i != nex && dis[i][nex] <= distanceThreshold);
		}
		if (cnt < minn)
		{
			minn = cnt;
			ans = i;
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& edges, int distanceThreshold)
{
	return findTheCity(n,edges,distanceThreshold);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/tests.txt";
}

