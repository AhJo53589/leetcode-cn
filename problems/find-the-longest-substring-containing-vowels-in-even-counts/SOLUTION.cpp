
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findTheLongestSubstring(string s) 
	{
		unordered_map<char, int> vowel = { {'a', 1}, {'e', 2}, {'i', 3}, {'o', 4}, {'u', 5} };
        vector<int> pos((1 << 5), -1);
		int ans = 0;
		int now = 0;
		pos[now] = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int t = vowel[s[i]] - 1;
			if (t != -1)
			{
				now ^= (1 << t);
			}
			if (pos[now] == -1)
			{
				pos[now] = i + 1;
			}
			else
			{
				ans = max(ans, i + 1 - pos[now]);
			}
		}

		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findTheLongestSubstring(s);
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
