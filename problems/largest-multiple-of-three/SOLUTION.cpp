
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	bool deleteNum(vector<int>& cnt, int n)
	{
		for (int i = n; i <= 9; i += 3)
		{
			if (cnt[i] != 0)
			{
				cnt[i]--;
				return true;
			}
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

		if (cnt[0] == digits.size()) return "0";
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
