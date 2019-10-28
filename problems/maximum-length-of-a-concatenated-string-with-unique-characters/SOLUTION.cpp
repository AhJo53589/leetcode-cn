
//////////////////////////////////////////////////////////////////////////
//bool check(bool* a, bool* b, string s)
//{
//	for (auto c : s)
//	{
//		if (a[c - 'a'] || b[c - 'a']) return false;
//		b[c - 'a'] = true;
//	}
//	return true;
//}
//
//void add(bool* a, bool* b)
//{
//	for (auto i = 0; i < 26; i++)
//	{
//		if (b[i]) a[i] = true;
//	}
//}
//
//int maxLength(vector<string>& arr)
//{
//	sort(arr.rbegin(), arr.rend(), [](const string &a, const string &b)
//	{
//		return a.size() < b.size();
//	});
//
//	int ans = 0;
//	for (int i = 0; i < arr.size(); i++)
//	{
//		bool f[26];
//		memset(f, 0, sizeof(f));
//		int cnt = 0;
//
//		for (int j = i; j < arr.size(); j++)
//		{
//			bool temp[26];
//			memset(temp, 0, sizeof(temp));
//			if (!check(f, temp, arr[j])) continue;
//			add(f, temp);
//			cnt += arr[j].size();
//			ans = max(ans, cnt);
//		}
//	}
//	return ans;
//}


//////////////////////////////////////////////////////////////////////////
bool check(int &a, int &b, string s)
{
	for (auto c : s)
	{
		if (a & (1 << (c - 'a')) || b & (1 << (c - 'a'))) return false;
		b |= 1 << (c - 'a');
	}
	return true;
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
		int bit_all = 0;
		int cnt = 0;

		for (int j = i; j < arr.size(); j++)
		{
			int temp = 0;
			if (!check(bit_all, temp, arr[j])) continue;
			bit_all |= temp;
			cnt += arr[j].size();
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

