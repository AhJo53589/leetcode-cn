
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) 
	{
		vector<int> ans(num_people, 0);
		size_t i = 0;
		int j = 1;
		while (candies != 0)
		{
			j = min(j, candies);
			candies -= j;
			ans[i] += j;
			i = (i + 1) % ans.size();
            j++;
		}
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int candies, int num_people)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.distributeCandies(candies, num_people);
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
