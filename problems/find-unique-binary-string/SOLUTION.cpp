
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<int> x;
        for (int i = 0; i < nums.size(); i++) {
            x.insert(str2int(nums[i]));
        }

        auto it = x.begin();
        int n = nums[0].size();
        for (int i = 0; i < (1 << n); i++, it++) {
            if (it == x.end()) return int2str(i, n);
            if (*it != i) return int2str(i, n);
        }
        return "";
    }

    int str2int(string s) {
        int x = 0;
        for (auto c : s) {
            x *= 2;
            x += (c - '0');
        }
        return x;
    }

    string int2str(int x, int n) {
        string s(n, '0');
        for (int i = n - 1; ~i; i--) {
            s[i] = (x % 2 == 1) ? '1' : '0';
            x /= 2;
        }
        return s;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<string>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(nums);
    Solution sln;
    return sln.findDifferentBinaryString(nums);
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
