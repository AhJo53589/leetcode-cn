
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        while (i < name.size() && j < typed.size()) {
            if (name[i] == typed[j]) {
                i++;
                j++;
                continue;
            }
            if (i != 0 && name[i - 1] == typed[j]) {
                j++;
                continue;
            }
            return false;
        }
        if (i != name.size()) return false;
        while (j < typed.size()) {
            if (typed[j] != name[i - 1]) return false;
            j++;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string name, string typed)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.isLongPressedName(name, typed);
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
