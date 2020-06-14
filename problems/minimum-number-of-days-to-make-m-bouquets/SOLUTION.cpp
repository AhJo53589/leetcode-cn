
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 0;
        int high = INT_MAX;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (check(bloomDay, m, k, mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        
        return low == INT_MAX ? -1 : low;
    }

    bool check(vector<int>& bloomDay, int m, int k, int day) {
        int cnt = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] > day) {
                cnt = 0;
                continue;
            }

            if (++cnt == k) {
                cnt = 0;
                if (--m == 0) return true;
            }
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& bloomDay, int m, int k)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(bloomDay);
    cout << m << ", " << k << endl;
    Solution sln;
    return sln.minDays(bloomDay, m, k);
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
