
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        for (auto& a : asteroids) {
            if (m < a) return false;
            m += 1LL * a;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(int mass, vector<int>& asteroids)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.asteroidsDestroyed(mass, asteroids);
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
