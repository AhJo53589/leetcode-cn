
//////////////////////////////////////////////////////////////////////////
bool check(vector<bool> &a, vector<bool> &b, string s)
{
	for (auto c : s)
	{
		if (a[c - 'a'] || b[c - 'a']) return false;
		b[c - 'a'] = true;
	}
	return true;
}

void add(vector<bool> &a, vector<bool> &b)
{
	for (auto i = 0; i < a.size(); i++)
	{
		if (b[i]) a[i] = true;
	}
}

int maxLength(vector<string>& arr)
{
	sort(arr.rbegin(), arr.rend(), [](const string &a, const string &b)
	{
		return a.size() < b.size();
	});

	int ans = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		vector<bool> f(26, false);
		int cnt = 0;

		for (auto c : f) cout << c; cout << endl;

		for (int j = i; j < arr.size(); j++)
		{
			vector<bool> temp(26, false);


			if (!check(f, temp, arr[j])) continue;

			cnt += arr[j].size();
			add(f, temp);
			for (auto c : temp) cout << c; cout << endl;
			ans = max(ans, cnt);
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& arr)
{
	return maxLength(arr);
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
	return "../../problems/maximum-length-of-a-concatenated-string-with-unique-characters/tests.txt";
}

