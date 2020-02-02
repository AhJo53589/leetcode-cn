


//////////////////////////////////////////////////////////////////////////
void maxJumps(vector<int>& arr, int d, int cur, vector<int>& steps, int& ans)
{
	int l = max(0, cur - d);
	int r = min(arr.size() - 1, cur + d);

	int step = 0;
	for (int dirction = -1; dirction <= 1; dirction += 2)
	{
		int h = arr[cur];
		for (int i = cur; i <= r && i >= l; i += dirction)
		{
			if (i == cur) continue;
			if (h <= arr[i]) break;

			if (steps[i] == -1)
			{
				maxJumps(arr, d, i, steps, ans);
			}
			step = max(step, steps[i]);
		}
	}
	steps[cur] = step + 1;
	ans = max(ans, steps[cur]);
}

int maxJumps(vector<int>& arr, int d) 
{
	vector<int> steps(arr.size(), -1);
	int ans = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		maxJumps(arr, d, i, steps, ans);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr, int d)
{
	return maxJumps(arr,d);
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
	return "../../problems/jump-game-v/tests.txt";
}

