
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    const int mod = 1e9 + 7;

    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);

        long long maxh = horizontalCuts[0];
        long long  maxv = verticalCuts[0];
        for (int i = 0; i < horizontalCuts.size() - 1; i++) {
            maxh = max((int)maxh, horizontalCuts[i + 1] - horizontalCuts[i]);
        }
        for (int i = 0; i < verticalCuts.size() - 1; i++) {
            maxv = max((int)maxv, verticalCuts[i + 1] - verticalCuts[i]);
        }

        return (int)((maxh * maxv) % mod);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << h << endl;
    cout << w << endl;
    printVectorT(horizontalCuts);
    printVectorT(verticalCuts);
    Solution sln;
    return sln.maxArea(h, w, horizontalCuts, verticalCuts);
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
