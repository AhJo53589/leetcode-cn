
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> a(k, 0);
        for (auto n : arr) {
            if (n < 0) {
                n *= -1;
                n %= k;
                n = k - n;
            }
            a[n % k]++;
        }

        if (a[0] % 2 != 0) return false;
        int i = 1;
        int j = a.size() - 1;
        while (i < j) {
            if (a[i] != a[j]) return false;
            i++;
            j--;
        }
        if (i == j && a[i] % 2 != 0) return false;
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& arr, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.canArrange(arr, k);
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
