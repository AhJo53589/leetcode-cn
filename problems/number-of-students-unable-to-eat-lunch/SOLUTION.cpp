
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> que;
        for (auto n : students) {
            que.push(n);
        }
        int idx = 0;
        int len = 0;
        while (!que.empty()) {
            if (len == que.size()) break;
            len = que.size();
            for (int i = 0; i < len && idx != sandwiches.size(); i++) {
                auto q = que.front();
                que.pop();
                if (sandwiches[idx] != q) {
                    que.push(q);
                }
                else {
                    idx++;
                }
            }
        }
        return que.size();
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& students, vector<int>& sandwiches)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countStudents(students, sandwiches);
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
