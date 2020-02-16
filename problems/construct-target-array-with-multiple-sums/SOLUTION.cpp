
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	bool isPossible(vector<int>& target)
	{
		return isPossible(target, 0);
	}

	bool isPossible(vector<int>& target, long long sum) 
	{
		if (all_of(target.begin(), target.end(), [](auto num) { return num == 1; })) return true;

		sum = (sum != 0) ? sum : accumulate(target.begin(), target.end(), sum);
		for (auto& num : target) 
		{
			auto temp = num * 2 - sum;
			if (temp < 1) continue;
			num = temp;
			return isPossible(target, (num + sum) / 2);
		}
		return false;
	}
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& target)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.isPossible(target);
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
