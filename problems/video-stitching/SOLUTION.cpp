
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        int ans = 1;

        int end = 0;
        int next = 0;
        for (auto c : clips) {
            if (c[0] > end) {
                if (next >= T) break;
                ans++;
                end = next;
                if (c[0] > end) return -1;
            }
            next = max(next, c[1]);
        }
        return (next < T) ? -1 : ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& clips, int T)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorVectorT(clips);
    cout << T << endl;
	Solution sln;
	return sln.videoStitching(clips, T);
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
