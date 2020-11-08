
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> que;
        que.push(s);
        set<string> us;
        us.insert(s);
        
        while (!que.empty()) {
            auto q = que.front();
            while (true) {
                for (int i = 1; i < s.size(); i += 2) {
                    int x = q[i] - '0';
                    x = (x + a) % 10;
                    q[i] = '0' + x;
                }
                // cout << q << endl;
                if (us.find(q) != us.end()) break;
                que.push(q);
                us.insert(q);
            }
            
            q = que.front();
            while (true) {
                string t = q.substr(b, s.size()) + q.substr(0, b);
                // cout << t << endl;
                if (us.find(t) != us.end()) break;
                que.push(t);
                us.insert(t);
                q = t;
            }
            
            que.pop();
        }
        return *us.begin();
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s, int a, int b)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findLexSmallestString(s, a, b);
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
