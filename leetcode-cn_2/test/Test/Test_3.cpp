
//////////////////////////////////////////////////////////////////////////
//string removeDuplicates(string s, int k)
//{
//	string ans;
//	int cnt = 1;
//	for (size_t i = 1; i < s.size(); i++)
//	{
//		if (s[i] == s[i - 1])
//		{
//			cnt = (cnt + 1) % k;
//		}
//
//		if (s[i] != s[i - 1] || i == s.size() - 1)
//		{
//			while (cnt > 0)
//			{
//				cnt--;
//				ans.push_back(s[i - 1]);
//			}
//			cnt = 1;
//			if (s[i] != s[i - 1] && i == s.size() - 1)
//			{
//				ans.push_back(s[i]);
//			}
//		}
//	}
//
//	return (ans.size() == s.size()) ? ans : removeDuplicates(ans, k);
//}

//////////////////////////////////////////////////////////////////////////
//string removeDuplicates(string s, int k)
//{
//	vector<string> sub;
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		if (sub.empty() || s[i] != sub.back()[0])
//		{
//			sub.push_back({ s[i] });
//		}
//		else
//		{
//			sub.back() += s[i];
//			if (sub.back().size() == k)
//			{
//				sub.pop_back();
//			}
//		}
//	}
//	string ans;
//	for (auto &&s : sub)
//	{
//		ans.append(s);
//	}
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
string removeDuplicates(string s, int k)
{
	string sub;
	vector<int> cnt;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (sub.empty() || s[i] != sub.back())
		{
			sub.push_back(s[i]);
			cnt.push_back(1);
			continue;
		}
		if (++cnt.back() == k)
		{
			sub.pop_back();
			cnt.pop_back();
		}
	}
	string ans;
	for (size_t i = 0; i < sub.size(); i++)
	{
		while (cnt[i]-- > 0)
		{
			ans += sub[i];
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s, int k)
{
	return removeDuplicates(s, k);
}

#define USE_SOLUTION_CUSTOM
vector<int> _solution_custom(TestCases &tc)
{
	vector<int> nums(tc.get<vector<int>>());
	int target(tc.get<int>());
	return twoSum(nums, target);
}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "tests_1.txt";
}


