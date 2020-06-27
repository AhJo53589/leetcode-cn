
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    double average(vector<int>& salary) {
		int salary_min = INT_MAX;
		int salary_max = 0;
		double sum = 0;
		for (auto s : salary) {
			salary_min = min(salary_min, s);
			salary_max = max(salary_max, s);
			sum += s;
		}
		double avg = (double)(sum - salary_min - salary_max) / (salary.size() - 2);
		return avg;
    }
};

//////////////////////////////////////////////////////////////////////////
double _solution_run(vector<int>& salary)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.average(salary);
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
