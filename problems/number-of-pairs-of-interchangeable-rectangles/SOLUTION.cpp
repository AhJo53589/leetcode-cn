
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans = 0;

        unordered_map<string, long long> cnt;
        for (auto& rect : rectangles) {
            int g = gcd(rect[0], rect[1]);
            string t = to_string(rect[0] / g) + "/" + to_string(rect[1] / g);
            ans += cnt[t];
            cnt[t]++;
        }

        return ans;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

//////////////////////////////////////////////////////////////////////////
long _solution_run(vector<vector<int>>& rectangles)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.interchangeableRectangles(rectangles);
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
