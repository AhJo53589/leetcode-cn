
#include <numeric>		// std::accumulate
#include <functional>	// std::bit_xor

//////////////////////////////////////////////////////////////////////////
int singleNumber(vector<int>& nums)
{
	return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return singleNumber(nums);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

