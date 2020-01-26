


//////////////////////////////////////////////////////////////////////////
void dfs(vector<vector<int>>& city_dis, int cur, int threshold, unordered_map<int, int>& vi)
{
	for (int i = 0; i < city_dis[cur].size(); i++)
	{
		if (city_dis[cur][i] == -1) continue;
		if (vi.count(i) != 0 && vi[i] <= threshold) continue;
		if (threshold < city_dis[cur][i]) continue;
		vi[i] = threshold - city_dis[cur][i];
		dfs(city_dis, i, threshold - city_dis[cur][i], vi);
	}
}

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
{
	vector<vector<int>> city_dis(n, vector<int>(n, -1));
	for (auto& edge : edges)
	{
		city_dis[edge[0]][edge[1]] = edge[2];
		city_dis[edge[1]][edge[0]] = edge[2];
	}

	int ans = -1;
	int cnt = n;
	vector<vector<int>> citys(n, vector<int>());
	for (int i = 0; i < n; i++)
	{
		unordered_map<int, int> vi;
		vi[i] = distanceThreshold;
		dfs(city_dis, i, distanceThreshold, vi);
		if (cnt >= vi.size() - 1)
		{
			cnt = vi.size() - 1;
			ans = i;
		}
		cout << i << ": [vi] = " << vi.size() - 1 << "\t[cnt] = " << cnt << endl;
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

