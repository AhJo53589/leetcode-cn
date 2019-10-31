
//////////////////////////////////////////////////////////////////////////
//int numberOfBoomerangs(vector<vector<int>>& points)
//{
//	int res = 0;
//	if (points.empty()) return res;
//	for (int i = 0; i < points.size(); i++)
//	{
//		unordered_map<double, int> _map;
//		for (int j = 0; j < points.size(); j++)
//		{
//			if (i == j) continue;
//			double dis = pow(((double)points[i][0] - (double)points[j][0]), 2) + pow(((double)points[i][1] - (double)points[j][1]), 2);
//			//if (_map.count(dis))	// 可以用排列组合公式
//			//{
//			//	res += _map[dis] * 2;
//			//}
//			_map[dis]++;
//		}
//		for (auto p : _map) res += p.second * (p.second - 1);	//计算排列组合公式 n * (n - 1)
//	}
//	return res;
//}

int dis(vector<int>&p1, vector<int>&p2)
{
	return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
}


//////////////////////////////////////////////////////////////////////////
int numberOfBoomerangs(vector<vector<int>>& points) {
	int count = 0;
	int n = points.size();
	//int data[n][n] = { 0 };
	vector<vector<int>> data(n, vector<int>());
	for (int i = 0; i < n; i++) data[i].resize(n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			data[i][j] = dis(points[i], points[j]);
			data[j][i] = data[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		sort(data[i].begin(), data[i].end());
		for (int j = 0; j < n - 1; j++)
		{
			if (data[i][j] == data[i][j + 1]) cnt++;
			else
			{
				count += cnt * (cnt - 1);
				cnt = 1;
			}
		}
		count += cnt * (cnt - 1);
	}
	return count;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& points)
{
	return numberOfBoomerangs(points);
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
	return "../../problems/number-of-boomerangs/tests.txt";
}

