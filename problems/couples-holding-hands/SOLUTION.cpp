
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        for (int i = 0; i < row.size(); i += 2) {
            int p = row[i] ^ 1;
            if (row[i + 1] == p) continue;

            for (int j = i + 2; j < row.size(); j++) {
                if (row[j] == p) {
                    swap(row[j], row[i + 1]);
                    break;
                }
            }
            ans++;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& row)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minSwapsCouples(row);
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
