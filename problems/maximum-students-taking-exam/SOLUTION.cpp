

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	int getCount(int n)
	{
		bitset<8> bs(n);
		return bs.count();
	}

	bool checkChair(vector<vector<char>>& seats, int row, int n)
	{
		bitset<8> bs(n);
		for (int i = 0; i < seats[row].size(); i++)
		{
			if (seats[row][i] == '#' && bs[i] == 1) return false;
		}
		return true;
	}

	bool checkValid(int n)
	{
		bitset<8> bs(n);
		for (int i = 1; i < 8; i++)
		{
			if (bs[i] == 1 && bs[i - 1] == 1) return false;
		}
		return true;
	}

	int maxStudents(vector<vector<char>>& seats)
	{
		int ans = 0;
		vector<vector<int>> dp(seats.size(), vector<int>(1 << seats[0].size(), 0));

		for (int i = 0; i < seats.size(); i++)
		{
			for (int j = 0; j < (1 << seats[0].size()); j++)
			{
				if (!checkChair(seats, i, j)) continue;
				if (!checkValid(j)) continue;
				int cnt = getCount(j);
				if (i == 0)
				{
					dp[i][j] = cnt;
				}
				else
				{
					for (int k = 0; k < (1 << seats[0].size()); k++)
					{
						if (!checkValid(j | k)) continue;
						dp[i][j] = max(dp[i][j], dp[i - 1][k] + cnt);
					}
				}
				ans = max(ans, dp[i][j]);
			}
		}
		return ans;
	}
};


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<char>>& seats)
{
	//int caseNo = 0;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

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
