
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        for (int state = 0; state < (1 << requests.size()); state++) {
            ans = max(ans, tryRequest(n, requests, state));
        }
        return ans;
    }

    int tryRequest(int n, const vector<vector<int>>& requests, int state) {
        vector<int> in(n, 0);
        vector<int> out(n, 0);
        int index = 0;
        int ans = 0;

        while (state) {
            if (state & 1) {
                out[requests[index][0]] ++;
                in[requests[index][1]] ++;
                ans++;
            }

            state >>= 1;
            index++;
        }

        for (int i = 0; i < n; i++) {
            if (in[i] != out[i]) return -1;
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& requests)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maximumRequests(n, requests);
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
