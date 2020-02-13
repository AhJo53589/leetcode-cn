


//////////////////////////////////////////////////////////////////////////
vector<int> plusOne(vector<int>& digits)
{
	if (digits.size() == 0) return digits;

	int i = digits.size() - 1;
	int bUpFlag = 1;
	while (i >= 0 && bUpFlag > 0)
	{
		digits[i] += bUpFlag;
		bUpFlag--;
		if (digits[i] > 9)
		{
			bUpFlag += digits[i] / 10;
			digits[i] %= 10;
		}
		i--;
	}
	if (bUpFlag > 0)
	{
		digits.insert(digits.begin(), bUpFlag);
	}
	return digits;
}


//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& digits)
{
	return plusOne(digits);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

