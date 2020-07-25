
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int> pre(arr.size(), 0);
        pre[0] = arr[0];
        int odd = 0;
        int even = 1;
        int ans = 0;
        if (pre[0] % 2 == 1) {
            ans = 1;
            odd = 1;
        }
        else {
            even++;
        }

        for (int i = 1; i < arr.size(); i++) {
            pre[i] = pre[i - 1] + arr[i];
            if (pre[i] % 2 == 1) {
                ans += even;
                odd++;
            }
            else {
                ans += odd;
                even++;
            }
            ans %= mod;
        }
        return ans;
    }
private:
    const int mod = 1e9 + 7;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(arr);

	Solution sln;
	return sln.numOfSubarrays(arr);
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
