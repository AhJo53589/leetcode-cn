
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string originalDigits(string s) {
        vector<int> nums(10, 0);

        vector<string> strNums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        vector<vector<int>> chNums(10, vector<int>(26, 0));
        for (int i = 0; i < strNums.size(); i++) {
            for (auto& c : strNums[i]) {
                chNums[i][c - 'a']++;
            }
        }

        vector<int> chOrg(26, 0);
        for (auto& c : s) {
            chOrg[c - 'a']++;
        }

        vector<vector<int>> steps = {{0, 2, 4, 6, 8}, {1, 3, 5, 7}, {9}};
        vector<char> key = {'z', 'o', 'w', 't', 'u', 'f', 'x', 's', 'g', 'n'};
        for (auto& st : steps) {
            for (auto& t : st) {
                while (chOrg[key[t] - 'a'] > 0) {
                    nums[t]++;
                    sub(chOrg, chNums[t]);
                }
            }
        }

        string ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.insert(ans.end(), nums[i], '0' + i);
        }
        return ans;
    }

    void sub(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size(); i++) {
            a[i] -= b[i];
        }
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.originalDigits(s);
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
