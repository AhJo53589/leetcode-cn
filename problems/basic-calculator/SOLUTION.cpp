//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int calculate(string s) {
        s += '#';

        int ans = 0;
        int op = 1;
        int real = 1;
        int cur = 0;
        stack<int> st;

        for (auto c : s) {
            if (c == ' ') continue;
            if (isdigit(c)) {
                cur = cur * 10 + (c - '0');
                continue;
            }

            ans += real * op * cur;
            cur = 0;

            if (c == '+' || c == '-') {
                op = (c == '+') ? 1 : -1;
            }
            else if (c == '(') {
                st.push(op);
                real *= op;
                op = 1;
            }
            else if (c == ')') {
                real *= st.top();
                st.pop();
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
//class Solution {
//public:
//    int calculate(string s) {
//        s += '+';
//        stack<int> num;
//        stack<int> op;
//        string cur;
//        num.push(0);
//        for (auto c : s) {
//            if (c == ' ') continue;
//            if (isdigit(c)) {
//                cur += c;
//                continue;
//            }
//
//            calc(num, op, cur);
//            if (c == '+' || c == '-') {
//                int p = (c == '+') ? 1 : -1;
//                op.push(p);
//            }
//            else if (c == '(') {
//                op.push(0);
//            }
//            else if (c == ')') {
//                op.pop();
//                handle(num, op);
//            }
//        }
//        return num.top();
//    }
//
//    void calc(stack<int>& num, stack<int>& op, string& cur) {
//        if (cur == "") return;
//        if (!op.empty() && op.top() != 0) {
//            num.top() = num.top() + op.top() * stoi(cur);
//            op.pop();
//        }
//        else {
//            num.push(stoi(cur));
//        }
//        cur = "";
//    }
//
//    void handle(stack<int>& num, stack<int>& op) {
//        if (!op.empty() && op.top() != 0) {
//            int x = num.top();
//            num.pop();
//            num.top() = num.top() + op.top() * x;
//            op.pop();
//        }
//    }
//};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    cout << s << endl;
    Solution sln;
    return sln.calculate(s);
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
