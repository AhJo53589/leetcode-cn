
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans = 0;
        
        vector<int> stone = { a, b, c };
        sort(stone.begin(), stone.end());
        
        if (stone[1] != stone[2]) {
            int dif = stone[2] - stone[1];
            dif = min(stone[0], dif);
            ans += dif;
            stone[0] -= dif;
            stone[2] -= dif;
        }
        
        if (stone[0] != 0) {
            int dif = stone[0] / 2;
            dif = min(stone[1], dif);
            ans += dif * 2;
            // stone[0] -= dif * 2;
            // stone[1] -= dif;
            stone[2] -= dif;
            return ans + stone[2];
        } 
        
        return ans + min(stone[1], stone[2]);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int a, int b, int c)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maximumScore(a, b, c);
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
