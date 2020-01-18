


//////////////////////////////////////////////////////////////////////////
void printCodes(int sum, vector<int>& cur, vector<string>& codes)
{
	cout << sum << " \t";
	for (size_t i = 0; i < cur.size(); i++)
	{
		cout << codes[cur[i]];
	}
	cout << endl;
}

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

//////////////////////////////////////////////////////////////////////////
string _solution_run(int n, vector<vector<int>>& roads, vector<string>& codes)
{
	return happy(n,roads,codes);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
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
	return "../../problems/happy-new-year-lol/tests.txt";
}

