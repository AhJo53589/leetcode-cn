
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        for (int i = 1; i < arr.size(); i++) {
            arr[i] = arr[i - 1] ^ arr[i];
        }
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                for (int k = j; k < arr.size(); k++) {
                    int a = (i == 0) ? arr[j - 1] : arr[j - 1] ^ arr[i - 1];
                    int b = arr[k] ^ arr[j - 1];
                    ans += (a == b);
                }
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    printVectorT(arr);
    //cout << "[] " << i << " " << j << " " << k << endl;
    //cout << a << " " << b << endl;

    Solution sln;
    return sln.countTriplets(arr);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
