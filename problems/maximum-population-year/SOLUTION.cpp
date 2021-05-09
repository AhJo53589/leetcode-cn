
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> birth(logs.size());
        vector<int> death(logs.size());
        for (int i = 0; i < logs.size(); i++) {
            birth[i] = logs[i][0];
            death[i] = logs[i][1];
        }
        sort(birth.begin(), birth.end());
        sort(death.begin(), death.end());

        int maxP = 0;
        int ans = 0;
        int p = 0;
        for (int i = 0, j = 0; i < birth.size(); i++) {
            p++;
            while (death[j] <= birth[i]) {
                p--;
                j++;
            }

            if (p > maxP) {
                maxP = p;
                ans = birth[i];
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& logs)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maximumPopulation(logs);
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
