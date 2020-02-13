


//////////////////////////////////////////////////////////////////////////
int minPushBox(vector<vector<char>>& grid) 
{
	// pq��[0]��ǰ״̬��С�����Ӵ��� [1]�˵�����x [2]�˵�����y [3]���ӵ�����x [4]���ӵ�����y
	priority_queue<vector<size_t>, vector<vector<size_t>>, greater<vector<size_t>>> pq;
	size_t m = grid.size();
	size_t n = grid[0].size();

	vector<size_t> a(5, 0);
	for (size_t x = 0; x < m; x++)
	{
		for (size_t y = 0; y < n; y++)
		{
			if (grid[x][y] == 'S')
			{
				a[1] = x;
				a[2] = y;
				grid[x][y] = '.';
			}
			else if (grid[x][y] == 'B')
			{
				a[3] = x;
				a[4] = y;
				grid[x][y] = '.';
			}
		}
	}
	pq.push(a);

	map<vector<size_t>, size_t> dist;
	dist[{ a[1], a[2], a[3], a[4] }] = 0;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	while (!pq.empty())
	{
		auto v = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			vector<size_t> next_s = { v[1] + dx[i], v[2] + dy[i] };
			if (next_s[0] >= m || next_s[1] >= n || grid[next_s[0]][next_s[1]] == '#')
			{
				continue;
			}
			vector<size_t> next_b = { v[3], v[4] };
			size_t d = v[0];
			if (next_s == next_b)
			{
				next_b[0] += dx[i];
				next_b[1] += dy[i];
				if (next_b[0] >= m || next_b[1] >= n || grid[next_b[0]][next_b[1]] == '#')
				{
					continue;
				}
				d++;
			}
			if (grid[next_b[0]][next_b[1]] == 'T')
			{
				return (int)d;
			}

			if (dist.find({next_s[0], next_s[1], next_b[0], next_b[1]}) != dist.end())
			{
				continue;
			}
			dist[{next_s[0], next_s[1], next_b[0], next_b[1]}] = d;
			pq.push({ d, next_s[0], next_s[1], next_b[0], next_b[1] });
		}
	}
	return -1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<char>>& grid)
{
	return minPushBox(grid);
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

