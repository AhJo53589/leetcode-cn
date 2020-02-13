
//////////////////////////////////////////////////////////////////////////
//bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
//	int a = 0, b = 0, u = 0, v = 0;
//	for (auto i : command)if (i == 'R')a++;
//	else b++;
//	bool c = 0;
//	for (auto i : command)
//	{
//		for (auto j : obstacles)if (j[0] <= x && j[1] <= y && (j[0] - u) % a == 0 && (j[1] - v) % b == 0 && (j[0] - u) / a == (j[1] - v) / b)return 0;
//		if ((x - u) % a == 0 && (y - v) % b == 0 && (x - u) / a == (y - v) / b)c = 1;
//		if (i == 'R')u++;
//		else v++;
//	}
//	return c;
//}

//////////////////////////////////////////////////////////////////////////
//bool robot(string command, vector<vector<int>>& obstacles, int x, int y) 
//{
//	int a = 0, b = 0, u = 0, v = 0;
//	for (auto i : command)
//	{
//		if (i == 'R')
//			a++;
//		else 
//			b++;
//	}
//
//	bool c = false;
//	for (auto i : command)
//	{
//		for (auto j : obstacles)
//		{
//			if (j[0] <= x && j[1] <= y
//				&& (j[0] - u) % a == 0
//				&& (j[1] - v) % b == 0
//				&& (j[0] - u) / a == (j[1] - v) / b)
//			{
//				return false;
//			}
//		}
//		if ((x - u) % a == 0
//			&& (y - v) % b == 0
//			&& (x - u) / a == (y - v) / b)
//		{
//			c = true;
//		}
//
//		if (i == 'R')
//		{
//			u++;
//		}
//		else
//		{
//			v++;
//		}
//	}
//	return c;
//}


//////////////////////////////////////////////////////////////////////////
bool robot(string command, vector<vector<int>>& obstacles, int x, int y)
{
	vector<vector<int>> ob2(obstacles.begin(), obstacles.end());
	sort(obstacles.begin(), obstacles.end(), [](const vector<int>& a, const vector<int>& b)
	{
		return a[0] < b[0];
	});
	sort(ob2.begin(), ob2.end(), [](const vector<int>& a, const vector<int>& b)
	{
		return a[1] < b[1];
	});

	size_t i_x = 0;
	size_t i_y = 0;

	vector<int> pos(2, 0);
	while (true)
	{
		for (auto &c : command)
		{
			if (pos[0] == x && pos[1] == y) return true;
			if (pos[0] > x || pos[1] > y) return false;

			if (c == 'R')
			{
				pos[0]++;
				if (obstacles.size() == 0) continue;
				while (i_x < obstacles.size() && obstacles[i_x][0] < pos[0]) i_x++;
				while (i_x < obstacles.size() && obstacles[i_x][0] == pos[0])
				{
					if (obstacles[i_x][1] == pos[1]) return false;
					i_x++;
				}
			}
			else if (c == 'U')
			{
				pos[1]++;
				if (ob2.size() == 0) continue;
				while (i_y < ob2.size() && ob2[i_y][1] < pos[1]) i_y++;
				while (i_y < ob2.size() && ob2[i_y][1] == pos[1])
				{
					if (ob2[i_y][0] == pos[0]) return false;
					i_y++;
				}
			}
		}
	}
	return false;
}


//////////////////////////////////////////////////////////////////////////
bool _solution_run(string command, vector<vector<int>>& obstacles, int x, int y)
{
	return robot(command,obstacles,x,y);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

