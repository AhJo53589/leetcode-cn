
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> cnts;
        for (auto n : hand) cnts[n]++;

        for (auto it = cnts.begin(); it != cnts.end(); it++) {
            while (it->second != 0) {
                int _first = it->first;
                it->second--;
                for (int i = 1; i < groupSize; i++) {
                    int t = _first + i;
                    if (cnts.count(t) == 0) return false;
                    if (cnts[t]-- == 0) return false;
                }
            }
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& hand, int groupSize)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.isNStraightHand(hand, groupSize);
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
