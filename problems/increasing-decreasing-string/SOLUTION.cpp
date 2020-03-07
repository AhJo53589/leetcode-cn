
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string sortString(string s) 
	{
		string ans = "";
		vector<int> count(26, 0);
		for (auto& c : s)
		{
			count[c - 'a']++;
		}

		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int i = 0; i < count.size(); i++)
			{
				if (count[i] == 0) continue;
                ans.push_back('a' + i);
				count[i]--;
                flag = true;
			}

            for (int i = count.size() - 1; i >= 0; i--)
            {
                if (count[i] == 0) continue;
                ans.push_back('a' + i);
                count[i]--;
                flag = true;
            }
		}
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.sortString(s);
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
