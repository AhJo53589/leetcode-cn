
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (popped.size() > pushed.size()) return false;

        stack<int> st;
        int i = 0;
        int j = 0;
        while (i < pushed.size() && j < popped.size()) {
            while (pushed[i] != popped[j]) {
                st.push(pushed[i]);
                i++;
                if (i == pushed.size()) return false;
            }
            if (pushed[i] == popped[j]) {
                i++;
                j++;
                if (j == popped.size()) return true;
                while (!st.empty() && popped[j] == st.top()) {
                    j++;
                    st.pop();
                }
            }
        }
        return j == popped.size();
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& pushed, vector<int>& popped)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.validateStackSequences(pushed, popped);
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
