
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> pos(26, 0);
        for (int i = 0; i < S.size(); i++) {
            pos[S[i] - 'a'] = i;
        }

        vector<int> ans;
        int k = 0;
        int cut = -1;
        for (int i = 0; i < S.size(); i++) {
            k = max(k, pos[S[i] - 'a']);
            if (i == k) {
                ans.push_back(i - cut);
                cut = i;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(string S)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.partitionLabels(S);
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
