
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = getVer(version1);
        auto v2 = getVer(version2);
        return (v1 == v2) ? 0 : (v1 < v2) ? -1 : 1;
    }

    vector<int> getVer(string& version) {
        vector<int> ver(500, 0);
        stringstream ss(version);
        string n;
        int idx = 0;
        while (getline(ss, n, '.')) {
            ver[idx++] = stoi(n);
        }
        return ver;
    }    
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string version1, string version2)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.compareVersion(version1, version2);
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
