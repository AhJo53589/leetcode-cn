
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for (auto n : nums) {
            auto [f, s] = calc(n);
            a += f;
            b = max(b, s);
        }
        return a + b;
    }

    pair<int, int> calc(int n) {
        if (n == 0) return { 0, 0 };
        int a = 0;
        int b = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                a++;
                n--;
            }
            else {
                b++;
                n /= 2;
            }
        }
        return { a, b };
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minOperations(nums);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
