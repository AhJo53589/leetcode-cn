
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int hi = accumulate(weights.begin(), weights.end(), 0);
        int lo = *min_element(weights.begin(), weights.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(weights, D, mid)) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        return lo;
    }

    bool check(vector<int>& weights, int D, int w) {
        int j = 0;
        for (int i = 0; i < D; i++) {
            int sum = 0;
            while (j < weights.size() && sum + weights[j] <= w) {
                sum += weights[j++];
            }
            if (j == weights.size()) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int hi = accumulate(weights.begin(), weights.end(), 0);
        int lo = *min_element(weights.begin(), weights.end());

        vector<int> pre = { 0 };
        partial_sum(weights.begin(), weights.end(), back_inserter(pre));

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (!check(pre, D, mid)) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        return lo;
    }

    bool check(vector<int>& pre, int D, int w) {
        int s = 0;
        auto it = pre.begin();
        auto itpre = pre.begin();
        for (int i = 0; i < D; i++) {
            it = upper_bound(it, pre.end(), s + w);
            if (it == pre.end()) return true;
            it--;
            s = *it;
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& weights, int D)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    printVectorT(weights);
    cout << D << endl;

    Solution sln;
    return sln.shipWithinDays(weights, D);
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
