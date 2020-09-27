
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashmap;
        
        for (auto u : strings) {
            string temp = u;
            for (int i = 0; i < u.size(); i++) {
                u[i] = (u[i] - temp[0] + 26) % 26 + 'a';
            }
            hashmap[u].push_back(temp);
        } 

        for (auto u : hashmap) {
            ans.push_back(u.second);
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<string>> _solution_run(vector<string>& strings)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.groupStrings(strings);
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
