
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
	{
		size_t validEnd = 0;
		vector<vector<string>> dp(s.size() + 1, vector<string>());

		for (size_t i = 0; i < s.size(); i++)
		{
			if (i == validEnd + 1) return {"a"};
			if (i != 0 && dp[i].empty()) continue;
			for (auto& word : wordDict)
			{
				size_t newEnd = i + word.size();
				if (newEnd > s.size()) continue;
				if (memcmp(&s[i], &word[0], word.size()) != 0) continue;
				validEnd = max(validEnd, newEnd);
				if (i == 0)
				{
					dp[newEnd].push_back(word);
					continue;
				}
				for (auto& d : dp[i])
				{
					dp[newEnd].push_back(d + " " + word);
				}
			}
		}

		return dp.back();
    }
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(string s, vector<string>& wordDict)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.wordBreak(s, wordDict);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

#define USE_CHECKANSWER_CUSTOM
void _checkAnswer_custom(vector<string>& ans, TestCases& tc)
{
	vector<string> answer = tc.get<vector<string>>();
	sort(ans.begin(), ans.end());
	sort(answer.begin(), answer.end());
	cout << checkAnswer<decltype(ans)>(ans, answer) << endl;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
