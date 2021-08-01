
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long apples = 0;
        for (int x = 0; x < INT_MAX; x++) {
            apples += calc(x);
            if (apples >= neededApples) {
                return x * 2 * 4;
            }
        }
        return 0;
    }

    long long calc(int x) {
        long long a = x + 1;
        long long b = 2 * x - 1;
        long long side = (a <= b) ? (a + b) * (b - a + 1) / 2 : 0;
        return 4LL * x + 4LL * 2 * x + side * 8;
    }
};

//////////////////////////////////////////////////////////////////////////
long _solution_run(long long neededApples)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << neededApples << endl;
    Solution sln;
    return sln.minimumPerimeter(neededApples);
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
