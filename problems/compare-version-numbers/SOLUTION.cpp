
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1 = getVer(version1, '.');
        vector<int> ver2 = getVer(version2, '.');

        int i = -1;
        while (true) {
            i++;
            if (i < ver1.size() && i < ver2.size()) {
                if (ver1[i] == ver2[i]) continue;
                return ver1[i] < ver2[i] ? -1 : 1;
            }
            if (i < ver1.size()) {
                if (ver1[i] == 0) continue;
                return 1;
            }
            if (i < ver2.size()) {
                if (ver2[i] == 0) continue;
                return -1;
            }
            break;
        }
        return 0;
    }

    vector<int> getVer(string& version, char c) {
        vector<int> ver;
        stringstream ss(version);
        string n;
        while (getline(ss, n, '.')) {
            ver.push_back(stoi(n));
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
