
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int>> rec;
        
        for (int i = 0; i < keyName.size(); i++) {
            rec[keyName[i]].push_back(getTime(keyTime[i]));
        }
        
        vector<string> ans;
        for (auto [n, s] : rec) {
            if (!check(s)) continue;
            ans.push_back(n);
        }
        return ans;
    }
    
    int getTime(string strTime) {
        int h = (strTime[0] - '0') * 10 + (strTime[1] - '0');
        int m = (strTime[3] - '0') * 10 + (strTime[4] - '0');
        return h * 60 + m;
    }
    
    bool check(vector<int>& s) {
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size() - 2; i++) {
            if (s[i + 2] - s[i] <= 60) return true;
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(vector<string>& keyName, vector<string>& keyTime)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.alertNames(keyName, keyTime);
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
