


//////////////////////////////////////////////////////////////////////////
bool getNext(vector<int>& a, int n)
{
	int _max = n;
	for (size_t i = a.size() - 1; i < a.size(); i--)
	{
		if (a[i] < _max)
		{
			a[i]++;
			for (size_t j = i + 1; j < a.size(); j++)
			{
				a[j] = a[j - 1] + 1;
			}
			return true;
		}
		_max--;
	}
	return false;
}

vector<vector<int>> combine(int n, int k) 
{
	vector<int> a;
	for (size_t i = 0; i < k; i++) a.push_back(1 + i);

	vector<vector<int>> ans;
	do
	{
		ans.push_back(a);
	} while (getNext(a, n));

	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(int n, int k)
{
	return combine(n,k);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
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
	return "../../problems/combinations/tests.txt";
}

