
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        for (auto n : arr) {
            cnt[n]++;
        }

        map<int, int> r_cnt;
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            r_cnt[it->second]++;
        }

        int ans = 0;
        for (auto it = r_cnt.begin(); it != r_cnt.end(); it++) {
            if (k != 0) {
                if (k < it->first) {
                    k = 0;
                }
                else {
                    int t = k / (it->first);
                    t = min(t, it->second);
                    it->second -= t;
                    k -= t * (it->first);
                }
            }
            if (it->second == 0) continue;

            ans += it->second;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(arr);
    cout << k << endl;
    Solution sln;
    return sln.findLeastNumOfUniqueInts(arr, k);
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
