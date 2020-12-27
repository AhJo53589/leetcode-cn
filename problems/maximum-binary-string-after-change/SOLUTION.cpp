
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string maximumBinaryString(string binary) {
        int left = 0;
        int right = 0;
        bool flag = true;
        for (auto c : binary) {
            flag = (flag && c == '1');
            left += (flag && c == '1');
            right += (!flag && c == '1');
        }

        if (left + right == 0 || right != 0) {
            int k = binary.size() - right - 1;
            for (int i = 0; i < binary.size(); i++) {
                binary[i] = (i == k) ? '0' : '1';
            }
        }
        return binary;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string binary)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    cout << binary << endl;
    Solution sln;
    return sln.maximumBinaryString(binary);
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
