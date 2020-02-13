


//////////////////////////////////////////////////////////////////////////
vector<int> getHaveBoxes(vector<int>& haveStatus)
{
	vector<int> ret;
	for (auto i = 0; i < haveStatus.size(); i++)
	{
		if (haveStatus[i] == 1)
		{
			ret.push_back(i);
		}
	}
	return ret;
}

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
{
	vector<int> haveStatus(status.size(), 0);
	for (auto n : initialBoxes) haveStatus[n] = 1;
	vector<int> keyStatus(status.size(), 0);

	int ans = 0;

	bool flag = true;
	while (flag)
	{
		flag = false;

		auto have = getHaveBoxes(haveStatus);
		if (have.empty()) break;

		for (auto i : have)
		{
			if (status[i] == 1 || keyStatus[i] == 1)
			{
				flag = true;
				haveStatus[i] = 2;

				ans += candies[i];
				for (auto k : keys[i])
				{
					keyStatus[k] = 1;
				}
				for (auto c : containedBoxes[i])
				{
					haveStatus[c] = 1;
				}
			}
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes)
{
	return maxCandies(status,candies,keys,containedBoxes,initialBoxes);
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

