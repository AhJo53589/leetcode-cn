class Solution2 {
	vector<int> a[3], b;
	string ans;
public:
	string largestMultipleOfThree(vector<int>& digits) {
		int s = 0, i;
		for (i = 0; i < 3; i++)a[i].clear();
		b.clear();
		for (auto c : digits)
		{
			s += c;
			a[c % 3].push_back(c);
		}
		for (i = 0; i < 3; i++)sort(a[i].begin(), a[i].end(), greater<int>());
		if (s % 3)if (!a[s % 3].empty())a[s % 3].pop_back();
		else for (i = 0; i < 2; i++)a[s % 3 ^ 3].pop_back();
		for (i = 0; i < 3; i++)for (auto c : a[i])b.push_back(c);
		sort(b.begin(), b.end(), greater<int>());
		ans = "";
		if (b.empty() || b.front())for (auto c : b)ans += c ^ '0';
		else ans = "0";
		return ans;
	}
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	bool deleteNum(vector<int>& cnt, int n)
	{
		for (int i = n; i <= 9; i += 3)
		{
			if (cnt[i] == 0) continue;
			cnt[i]--;
			return true;
		}
		return false;
	}

	string largestMultipleOfThree(vector<int>& digits)
	{
		vector<int> cnt(10, 0);
		int sum = 0;
		for (auto& d : digits)
		{
			sum += d;
			cnt[d]++;
		}

		if (sum % 3 != 0)
		{
			int a = sum % 3;
			int b = 3 - a;
			if (!deleteNum(cnt, a))
			{
				deleteNum(cnt, b);
				deleteNum(cnt, b);
			}
		}
		if (cnt[0] != 0 && all_of(cnt.begin() + 1, cnt.end(), [](const int& a) { return a == 0; })) return "0";

		string ans;
		for (int i = cnt.size() - 1; i < cnt.size(); i--)
		{
			while (cnt[i]-- != 0)
			{
				ans += to_string(i);
			}
		}
		return ans;
	}
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<int>& digits)
{
	//int caseNo = 4;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.largestMultipleOfThree(digits);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
