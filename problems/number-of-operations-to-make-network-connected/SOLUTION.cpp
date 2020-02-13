


//////////////////////////////////////////////////////////////////////////
void dfs(vector<vector<int>>& conn, vector<bool>& visited, int n)
{
	if (visited[n]) return;
	visited[n] = true;
	for (auto& c : conn[n])
	{
		dfs(conn, visited, c);
	}
}

int makeConnected(int n, vector<vector<int>>& connections) 
{
	if (connections.size() < n - 1) return -1;

	vector<bool> visited(n, false);
	vector<vector<int>> conn(n, vector<int>());
	for (auto v : connections)
	{
		conn[v[0]].push_back(v[1]);
		conn[v[1]].push_back(v[0]);
	}

	int ans = -1;
	for (int i = 0; i < conn.size(); i++)
	{
		ans += (!visited[i]);
		dfs(conn, visited, i);
	}

	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& connections)
{
	return makeConnected(n,connections);
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

