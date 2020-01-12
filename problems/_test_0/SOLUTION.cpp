


//////////////////////////////////////////////////////////////////////////
bool addVisited(vector<bool>& visited, int n)
{
	if (visited[n]) return false;
	visited[n] = true;
	for (auto b : visited)
	{
		if (!b) return false;
	}
	return true;
}

int getNext(vector<vector<int>>& conn)
{
	for (int i = 0; i < conn.size(); i++)
	{
		if (!conn[i].empty())
		{
			return i;
		}
	}
	return -1;
}

int makeConnected(int n, vector<vector<int>>& connections) 
{
	if (connections.size() < n - 1) return -1;

	vector<bool> visited(n, false);
	bool fin = false;
	vector<vector<int>> conn(n, vector<int>());
	for (auto v : connections)
	{
		conn[v[0]].push_back(v[1]);
	}

	int ans = -1;
	while (true)
	{
		int start = getNext(conn);
		if (start == -1) break;
		ans++;
		queue<int> que;
		que.push(start);

		while (!que.empty())
		{
			auto q = que.front();
			que.pop();
			fin = addVisited(visited, q);
			for (auto n : conn[q])
			{
				if (!visited[n])
				{
					que.push(n);
				}
			}
			conn[q].clear();
			if (fin) break;
		}
		if (fin) break;
	}

	if (fin) return ans;

	for (auto b : visited)
	{
		ans += (!b);
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
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/_test_0/tests.txt";
}

