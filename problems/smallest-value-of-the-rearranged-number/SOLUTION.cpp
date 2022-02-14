
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;

        int flag = num / abs(num);
        num *= flag;
        vector<int> dd(10, 0);
        while (num != 0) {
            dd[num % 10]++;
            num /= 10;
        }

        long long ans = 0;
        if (flag < 0) {
            for (int i = 9; i >= 0; i--) {
                addNum(ans, i, dd[i]);
            }
        }
        else {
            int first = getFirstNotZero(dd);
            ans += first;
            for (int i = 0; i < 10; i++) {
                addNum(ans, i, dd[i]);
            }
        }
        return 1LL * flag * ans;
    }

    void addNum(long long &ans, int n, int c) {
        for (int j = 0; j < c; j++) {
            ans *= 10;
            ans += n;
        }
    }

    int getFirstNotZero(vector<int>& dd) {
        for (int i = 1; i < 10; i++) {
            if (dd[i] == 0) continue;
            dd[i]--;
            return i;
        }
        return 0;
    }
};

//////////////////////////////////////////////////////////////////////////
long _solution_run(long long num)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.smallestNumber(num);
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
