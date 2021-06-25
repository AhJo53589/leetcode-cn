//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        map<string, bool> mapDeadends;
        for (string s : deadends) {
            mapDeadends[s] = true;
        }

        string strInit("0000");
        if (target == strInit) return 0;
        if (mapDeadends[strInit]) return -1;

        queue<string> qLockNum;
        qLockNum.push(strInit);
        mapDeadends[strInit] = true;
        qLockNum.push("----");

        int num = 1;

        while (!qLockNum.empty()) {
            string strCurrent = qLockNum.front();
            qLockNum.pop();

            if (strCurrent == "----") {
                if (qLockNum.empty() || qLockNum.front() == "----") {
                    break;
                }
                else {
                    num++;
                    qLockNum.push("----");
                    continue;
                }
            }

            vector<string> strNext = changeKey(strCurrent);
            for (string s : strNext) {
                if (!mapDeadends[s]) {
                    if (s == target) return num;
                    mapDeadends[s] = true;
                    qLockNum.push(s);
                }
            }
        }
        return -1;
    }

        vector<string> changeKey(string strCurrent) {
        vector<string> vStr;
        for (int i = 0; i < 4; i++) {
            string strTemp = strCurrent;
            int iCurrent = strCurrent[i] - '0';

            strTemp[i] = ((iCurrent + 1) % 10) + '0';
            vStr.push_back(strTemp);
            strTemp[i] = ((iCurrent + 10 - 1) % 10) + '0';
            vStr.push_back(strTemp);
        }
        return vStr;
    }
};


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& deadends, string target)
{
	Solution sln;
	return sln.openLock(deadends,target);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

