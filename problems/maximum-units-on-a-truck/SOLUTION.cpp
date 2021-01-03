
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.rbegin(), boxTypes.rend(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int ans = 0;
        for (auto& box : boxTypes) {
            int t = min(truckSize, box[0]);
            ans += t * box[1];
            truckSize -= t;
            if (truckSize == 0) break;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& boxTypes, int truckSize)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    printVectorVectorT(boxTypes);
    cout << truckSize << endl;

    Solution sln;
    return sln.maximumUnits(boxTypes, truckSize);
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
