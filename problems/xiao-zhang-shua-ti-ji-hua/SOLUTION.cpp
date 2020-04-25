
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minTime(vector<int>& time, int m) {
        if (time.size() <= m) return 0;

        int l = 0;
        int r = INT_MAX;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (canSplit(time, m, mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return r;
    }

    bool canSplit(vector<int>& time, int m, int split_sum) {
        int cnt = 0;
        int sum = 0;
        int maxT = 0;
        for (auto& t : time) {
            sum += t;
            maxT = max(maxT, t);
            if (sum - maxT > split_sum) {
                if (++cnt == m) return false;
                sum = t;
                maxT = t;
            }
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& time, int m)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(time);
    cout << "m = " << m << endl;
    Solution sln;
    return sln.minTime(time, m);
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
