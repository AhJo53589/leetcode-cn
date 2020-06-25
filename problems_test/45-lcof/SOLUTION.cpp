
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
            long long n_a = 10;
            while (a / n_a) n_a *= 10;

            long long n_b = 10;
            while (b / n_b) n_b *= 10;

            long long r_a = (long long)a * n_b + (long long)b;
            long long r_b = (long long)b * n_a + (long long)a;

            return r_a < r_b;
        });

        string ans = "";
        for (auto n : nums) {
            ans += to_string(n);
        }
        return ans;
    }
};
//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minNumber(nums);
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
