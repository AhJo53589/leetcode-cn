
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dic;
        for (auto& str : knowledge) {
            dic[str[0]] = str[1];
        }

        string ans = "";
        string k = "";
        bool isKey = false;
        for (auto c : s) {
            if (c == '(') {
                isKey = true;
            }
            else if (c == ')') {
                isKey = false;
                ans += (dic.find(k) != dic.end()) ? dic[k] : "?";
                k = "";
            }
            else if (!isKey) {
                ans += c;
            }
            else {
                k += c;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s, vector<vector<string>>& knowledge)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << s << endl;
    printVectorVectorT(knowledge);

    Solution sln;
    return sln.evaluate(s, knowledge);
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
