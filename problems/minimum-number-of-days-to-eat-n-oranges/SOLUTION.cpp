
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minDays(int n) {
        unordered_set<int> s;
        int ans = 0;
        queue<int> que;
        que.push(n);

        while (!que.empty()) {
            for (int i = que.size() - 1; i >= 0; i--) {
                auto q = que.front();
                que.pop();

                if (q == 0) return ans;

                if (q % 3 == 0 && s.count(q / 3) == 0) {
                    que.push(q / 3);
                    s.insert(q / 3);
                }
                if (q % 2 == 0 && s.count(q / 2) == 0) {
                    que.push(q / 2);
                    s.insert(q / 2);
                }
                if (s.count(q - 1) == 0) {
                    que.push(q - 1);
                    s.insert(q - 1);
                }
            }
            ans++;
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	cout << n << endl;
	Solution sln;
	return sln.minDays(n);
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
