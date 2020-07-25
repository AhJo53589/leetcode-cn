
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
		target.push_back(0);

		int ans = 0;
		stack<int> st;
		st.push(0);

		for (int i = 0; i < target.size(); i++) {
            while (st.top() > target[i]) {
				int t = st.top();
				st.pop();
				ans += t - max(st.top(), target[i]);
            }
            if (st.top() == target[i]) continue;

			if (st.top() < target[i]) {
				st.push(target[i]);
			}
		}
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& target)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minNumberOperations(target);
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
