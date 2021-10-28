
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for (int i = 0; i < expression.size(); i++) {
            auto c = expression[i];
            if (c != '+' && c != '-' && c != '*') continue;

            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));
            for (auto& l : left) {
                for (auto& r : right) {
                    if (c == '+') {
                        ans.push_back(l + r);
                    }
                    else if (c == '-') {
                        ans.push_back(l - r);
                    }
                    else {
                        ans.push_back(l * r);
                    }
                }
            }
        }

        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(string expression)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.diffWaysToCompute(expression);
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
