
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 1;
        int high = INT_MAX;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (check(position, m, mid)) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low - 1;
    }

    bool check(vector<int>& position, int m, int f) {
        int idx = 0;
        int cnt = 1;
        for (int j = idx + 1; j < position.size(); j++) {
            if (position[j] - position[idx] < f) continue;
            cnt++;
            idx = j;
            if (cnt == m) return true;
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& position, int m)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxDistance(position, m);
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
