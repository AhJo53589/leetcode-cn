//////////////////////////////////////////////////////////////////////////
//void calc(vector<int> &king, vector<int> &queen, vector<vector<int>> &ans)
//{
//	int kx = king[0];
//	int ky = king[1];
//	int qx = queen[0];
//	int qy = queen[1];
//
//	int i = 0;
//	if (kx == qx)
//	{
//		if (ky < qy) i = 0;
//		else i = 4;
//		if (ans[i].empty())
//		{
//			ans[i].push_back(qx);
//			ans[i].push_back(qy);
//		}
//		else if (abs(qy - ky) < abs(ans[i][1] - ky))
//		{
//			ans[i][1] = qy;
//		}
//	}
//	else if (ky == qy)
//	{
//		i = (kx < qx) ? 2 : 6;
//		if (ans[i].empty())
//		{
//			ans[i].push_back(qx);
//			ans[i].push_back(qy);
//		}
//		else if (abs(qx - kx) < abs(ans[i][0] - kx))
//		{
//			ans[i][0] = qx;
//		}
//	}
//	else if (abs(qy - ky) == abs(qx - kx))
//	{
//		if (qy - ky == qx - kx)
//		{
//			i = (ky < qy) ? 1 : 5;
//		}
//		else
//		{
//			i = (kx < qx) ? 3 : 7;
//		}
//		if (ans[i].empty())
//		{
//			ans[i].push_back(qx);
//			ans[i].push_back(qy);
//		}
//		else if (abs(qx - kx) < abs(ans[i][0] - kx))
//		{
//			ans[i][0] = qx;
//			ans[i][1] = qy;
//		}
//	}
//}
//vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king)
//{
//	vector<vector<int>> temp(8, vector<int>());
//	for (auto v : queens)
//	{
//		calc(king, v, temp);
//	}
//	vector<vector<int>> ans;
//	for (auto v : temp)
//	{
//		if (v.empty()) continue;
//		ans.push_back(v);
//	}
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
//void calc(vector<int> &king, vector<int> &queen, vector<int> &distance)
//{
//	int kx = king[0];
//	int ky = king[1];
//	int qx = queen[0];
//	int qy = queen[1];
//
//	int i = 0;
//	if (kx == qx)
//	{
//		i = (ky < qy) ? 0 : 4;
//		distance[i] = min(distance[i], abs(qy - ky));
//	}
//	else if (ky == qy)
//	{
//		i = (kx < qx) ? 2 : 6;
//		distance[i] = min(distance[i], abs(qx - kx));
//	}
//	else if (qy - ky == qx - kx)
//	{
//		i = (ky < qy) ? 1 : 5;
//		distance[i] = min(distance[i], abs(qy - ky));
//	}
//	else if (qy - ky == -(qx - kx))
//	{
//		i = (kx < qx) ? 3 : 7;
//		distance[i] = min(distance[i], abs(qy - ky));
//	}
//}
//
//vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king)
//{
//	// test for map_fun
//	unordered_map<size_t, std::function<vector<int>(int)>> map_fun;
//	map_fun[0] = [&king](int dis) -> vector<int> { return { king[0], king[1] + dis }; };
//	map_fun[1] = [&king](int dis) -> vector<int> { return { king[0] + dis, king[1] + dis }; };
//	map_fun[2] = [&king](int dis) -> vector<int> { return { king[0] + dis, king[1] }; };
//	map_fun[3] = [&king](int dis) -> vector<int> { return { king[0] + dis, king[1] - dis }; };
//	map_fun[4] = [&king](int dis) -> vector<int> { return { king[0], king[1] - dis }; };
//	map_fun[5] = [&king](int dis) -> vector<int> { return { king[0] - dis, king[1] - dis }; };
//	map_fun[6] = [&king](int dis) -> vector<int> { return { king[0] - dis, king[1]}; };
//	map_fun[7] = [&king](int dis) -> vector<int> { return { king[0] - dis, king[1] + dis }; };
//
//
//	vector<int> distance(8, INT_MAX);
//	for (auto v : queens)
//	{
//		calc(king, v, distance);
//	}
//	vector<vector<int>> ans;
//	for (auto i = 0; i < distance.size(); i++)
//	{
//		if (distance[i] == INT_MAX) continue;
//		// test for map_fun
//		ans.push_back(map_fun[i](distance[i]));
//	}
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king)
{
	//vector<vector<bool>> board(8, vector<bool>());
	//for (auto &b : board)
	//{
	//	b.resize(8);
	//}
	bool board[8][8];
	memset(board, 0, sizeof(board));
	for (const auto &q : queens)
	{
		board[q[0]][q[1]] = true;
	}

	vector<int> dx = { 1, 1, 1, 0,-1,-1,-1, 0 };
	vector<int> dy = { 1, 0,-1,-1,-1, 0, 1, 1 };

	vector<vector<int>> distance;
	for (size_t i = 0; i != dx.size(); i++)
	{
		int x = king[0];
		int y = king[1];
		while (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			if (board[x][y])
			{
				distance.push_back({ x,y });
				break;
			}
			x += dx[i];
			y += dy[i];
		}
	}
	return distance;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& queens, vector<int>& king)
{
	return queensAttacktheKing(queens, king);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
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
	return "../../problems/queens-that-can-attack-the-king/tests.txt";
}


