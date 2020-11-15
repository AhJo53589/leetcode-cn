
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        while (k-- > 0) {
            for (int i = 0; i < num.size(); i++) {
                if (i != num.size() - 1 && num[i] <= num[i + 1]) continue;
                num.erase(num.begin() + i);
                break;
            }
        }
        while (num.size() > 1 && num.front() == '0') {
            num.erase(num.begin());
        }
        return num;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string num, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << "num = " << num << " k = " << k << endl;
    Solution sln;
    return sln.removeKdigits(num, k);
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
