
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) 
	{
		vector<vector<int>> dd = { {0, -1}, {0, 1}, {-1, -1}, {-1, 1} };
		int M = seats.size();
		int N = seats[0].size();
		vector<vector<int>> valid;
		vector<vector<vector<vector<int>>>> op(M, vector<vector<vector<int>>>(N, vector<vector<int>>()));
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (seats[i][j] == '#') continue;
				valid.push_back({ i, j });
				for (auto d : dd)
				{
					int dx = i + d[0];
					int dy = j + d[1];
					if (dx < 0 || dx >= M) continue;
					if (dy < 0 || dy >= N) continue;
					if (seats[dx][dy] == '#') continue;
					op[i][j].push_back({ dx, dy });
				}
			}
		}

		int ans = 0;
		for (int cur = 0; cur < (1 << valid.size()); cur++)
		{
			int cnt = 0;
			set <vector<int>> vi;
			for (int i = 0; i < valid.size(); i++)
			{
				if (((1 << i) & cur) == 0) continue;
				if (vi.count(valid[i]) != 0)
				{
					cnt = 0;
					break;
				}
				for (auto &p : op[valid[i][0]][valid[i][1]])
				{
					vi.insert(p);
				}
				cnt++;
			}
			ans = max(ans, cnt);
		}
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<char>>& seats)
{
	int caseNo = 3;
	static int caseCnt = 0;
	if (caseNo != -1 && caseCnt++ != caseNo) return {};

	printVectorVectorT(seats);
	Solution sln;
	return sln.maxStudents(seats);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
