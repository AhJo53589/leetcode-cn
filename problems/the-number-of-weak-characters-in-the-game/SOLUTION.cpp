
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        vector<int> st;
        sort(properties.begin(), properties.end(), [](const auto& a, const auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        for (int i = 0; i < properties.size(); i++) {
            while (!st.empty() && properties[st.back()][1] < properties[i][1]) {
                st.pop_back();
            }
            st.push_back(i);
        }
        return properties.size() - st.size();
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& properties)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.numberOfWeakCharacters(properties);
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
