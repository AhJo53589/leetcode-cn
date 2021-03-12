
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> st;
        st.push(0);

        stringstream ss(preorder);
        string temp;
        while (!st.empty() && getline(ss, temp, ',')) {
            st.top() += 1;
            if (temp != "#") {
                st.push(0);
            }
            while (!st.empty() && st.top() == 2) {
                st.pop();
            }
        }
        return st.size() == 1;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string preorder)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.isValidSerialization(preorder);
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
