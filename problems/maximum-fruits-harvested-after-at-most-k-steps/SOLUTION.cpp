
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = 0;
        int start = 0;
        vector<int> leftFruits(k + 1, 0);
        vector<int> rightFruits(k + 1, 0);
        for (auto& f : fruits) {
            if (f[0] < startPos && f[0] >= startPos - k) {
                leftFruits[startPos - f[0]] = f[1];
            }
            else if (f[0] > startPos&& f[0] <= startPos + k) {
                rightFruits[f[0] - startPos] = f[1];
            }
            else if (f[0] == startPos) {
                start = f[1];
            }
        }

        map<int, long long> left;
        map<int, long long> right;
        long long leftSum = 0;
        long long rightSum = 0;
        for (int i = 0; i <= k; i++) {
            if (leftFruits[i] != 0) {
                leftSum += leftFruits[i];
                left[i] = leftSum;
            }
            if (rightFruits[i] != 0) {
                rightSum += rightFruits[i];
                right[i] = rightSum;
            }
        }

        check(left, right, k, ans);
        check(right, left, k, ans);
        return ans + start;
    }

    void check(map<int, long long>& a, map<int, long long>& b, int k, int& ans) {
        for (auto it : a) {
            int step = it.first;
            int sum = it.second;
            
            int cur = k - step * 2;
            if (cur >= 0 && !b.empty()) {
                //for (auto [k, v] : b) {
                //    cout << "[k, v] = " << k << ", " << v << endl;
                //}
                auto it2 = b.upper_bound(cur);
                //if (it2 != b.end()) {
                //    cout << "it2 = " << it2->first << ", " << it2->second << endl;
                //}
                it2--;
                //if (it2 == b.end()) {
                //    cout << "## it2--; it2 = end" << endl;
                //}
                //else {
                //    cout << "## it2-- it2 = " << it2->first << ", " << it2->second << endl;
                //}
                if (it2 != b.end() && it2->first <= cur) {
                    sum += it2->second;
                }
            }
            ans = max(ans, sum);
        }
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& fruits, int startPos, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxTotalFruits(fruits, startPos, k);
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
