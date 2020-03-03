
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string intToRoman(int num) 
	{
		vector<vector<string>> romans = {
		{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
		{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
		{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
		{"", "M", "MM", "MMM"}
		};

		string ans = "";
		int i = 0;
		while (num != 0)
		{
			ans.insert(0, romans[i][num % 10]);
			num /= 10;
			i++;
		}
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(int num)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.intToRoman(num);
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
