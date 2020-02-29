
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    bool hasGroupsSizeX(vector<int>& deck) 
	{
		if (deck.size() < 2) return false;
		unordered_map<int, int> um;
		for (auto& n : deck)
		{
			um[n]++;
		}
		int cnt = 0;
		for (auto& p : um)
		{
			cnt = (cnt == 0) ? p.second : cnt;
			cnt = gcd(p.second, cnt);
			if ((p.second % cnt) != 0 || cnt < 2) return false;
		}
		return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& deck)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.hasGroupsSizeX(deck);
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
