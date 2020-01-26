


//////////////////////////////////////////////////////////////////////////
void dfs(vector<vector<int>>& saving, int cur, int overJobs, int saved, int& maxSaved)
{
	if (overJobs == 0)
	{
		maxSaved = max(saved, maxSaved);
		return;
	}
	for (size_t j = 0; j < overJobs + 1; j++)
	{
		int k = cur + j;
		if (k >= saving[j].size()) break;
		dfs(saving, k + 1, overJobs - j, saved + saving[j][cur], maxSaved);
	}
}

int minDifficulty(vector<int>& jobDifficulty, int d) 
{
	int n = jobDifficulty.size();
	if (d == 1) return *max_element(jobDifficulty.begin(), jobDifficulty.end());
	int ans = accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
	int overJobs = jobDifficulty.size() - d;
	if (overJobs < 0) return -1;
	if (overJobs == 0) return ans;

	vector<vector<int>> jobs(jobDifficulty.size() + 1, vector<int>(d + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= min(d, i); j++)
		{
			jobs[i][j] = INT_MAX;
			int mx = 0;
			for (int k = i - 1; k >= j - 1; k--)
			{
				if (jobs[k][j - 1] == INT_MAX) continue;
				mx = max(mx, jobDifficulty[k]);
				jobs[i][j] = min(jobs[i][j], jobs[k][j - 1] + mx);
			}
		}
	}
	return jobs[n][d];
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& jobDifficulty, int d)
{
	return minDifficulty(jobDifficulty,d);
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
	return "../../problems/minimum-difficulty-of-a-job-schedule/tests.txt";
}

