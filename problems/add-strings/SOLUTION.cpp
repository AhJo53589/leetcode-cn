


//////////////////////////////////////////////////////////////////////////
string addStrings(string num1, string num2)
{
	while (num1.size() < num2.size()) num1.insert(num1.begin(), '0');
	while (num2.size() < num1.size()) num2.insert(num2.begin(), '0');

	string sum;
	int iCarry = 0;
	for (int i = num1.size() - 1; i >= 0; i--)
	{
		int val = (int)(num1[i] - '0') + (int)(num2[i] - '0') + iCarry;
		iCarry = val / 10;
		val %= 10;
		char c = (char)(val)+'0';
		sum.push_back(c);
	}
	if (iCarry != 0) sum.push_back((char)(iCarry) + '0');

	reverse(sum.begin(), sum.end());

	return sum;
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(string num1, string num2)
{
	return addStrings(num1,num2);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

