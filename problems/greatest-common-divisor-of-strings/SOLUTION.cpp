
//////////////////////////////////////////////////////////////////////////
//class Solution {
//public:
//    string gcdOfStrings(string str1, string str2) {
//        if (str1 + str2 != str2 + str1) return "";
//        return str1.substr(0, __gcd((int)str1.length(), (int)str2.length())); // __gcd() 为c++自带的求最大公约数的函数
//    }
//};
class Solution {
public:
    int gcd(int a, int b)
    {
        return (b == 0) ? a : gcd(b, a % b);
    }

    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd((int)str1.size(), (int)str2.size()));
    }
};


//////////////////////////////////////////////////////////////////////////
string _solution_run(string str1, string str2)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.gcdOfStrings(str1, str2);
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
