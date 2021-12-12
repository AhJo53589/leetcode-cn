
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int ans = 0;
        int curA = capacityA;
        int curB = capacityB;
        for (int i = 0, j = plants.size() - 1; i <= j; i++, j--) {
            if (i == j) {
                ans += max(curA, curB) < plants[i];
                break;
            }

            if (curA < plants[i]) {
                curA = capacityA;
                ans++;
            }
            curA -= plants[i];
            if (curB < plants[j]) {
                curB = capacityB;
                ans++;
            }
            curB -= plants[j];
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& plants, int capacityA, int capacityB)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minimumRefill(plants, capacityA, capacityB);
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
