class CustomFunction
{
public:
	CustomFunction(int fid) : func_id(fid) {}
	int f(int x, int y) { return func(func_id, x, y); }
	int func(int fid, int x, int y)
	{
		if (fid == 1) return x + y;
		if (fid == 2) return x * y;
		return 0;
	}

private:
	int func_id;
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> findSolution(CustomFunction& customfunction, int z)
{
	vector<vector<int>> ans;
	for (int a = 1; a <= z; a++)
	{
		for (int b = 1; b <= z; b++)
		{
			if (customfunction.f(a, b) == z)
			{
				ans.push_back({ a, b });
			}
			else if (customfunction.f(a, b) > z)
			{
				break;
			}
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(CustomFunction& customfunction, int z)
{
	return findSolution(customfunction, z);
}

#define USE_SOLUTION_CUSTOM
vector<vector<int>> _solution_custom(TestCases &tc)
{
	CustomFunction cf(tc.get<int>());
	int z(tc.get<int>());
	return findSolution(cf, z);
}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/find-positive-integer-solution-for-a-given-equation/tests.txt";
}

