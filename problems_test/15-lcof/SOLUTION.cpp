
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n != 0) {
            n &= (n - 1);
            sum++;
        }
        return sum;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string str)
{
    cout << str << endl;
    uint32_t n = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        n <<= 1;
        n |= (str[i] - '0');
    }

    cout << n << endl;
	Solution sln;
	return sln.hammingWeight(n);
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
