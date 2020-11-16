
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        vector<vector<bool>> next(2, vector<bool>(A.size(), false));
        next[0].back() = true;
        next[1].back() = true;

        int ans = 1;
        map<int, int> mp;
        for (int i = A.size() - 1; i >= 0; i--) {
            auto it = mp.lower_bound(A[i]);
            if (it != mp.end() && next[0][it->second]) {
                next[1][i] = true;
                ans++;
            }
            it = mp.lower_bound(-A[i]);
            if (it != mp.end() && it->first <= 0 && next[1][it->second]) {
                next[0][i] = true;
            }

            mp[A[i]] = i;
            mp[-A[i]] = i;
        }

        return ans;
    }
};


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& A)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.oddEvenJumps(A);
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
