


//////////////////////////////////////////////////////////////////////////
vector<string> letterCombinations(string digits)
{
	if (digits.empty()) return {};
	vector<string> data{ "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> res;
	res.push_back("");

	for (int i = 0; i < digits.size(); i++)
	{
		int d = digits[i] - '2';
		int len = res.size();
		for (int j = 0; j < len; j++)
		{
			for (auto m : data[d])
			{
				res.push_back(res[j] + m);
			}
		}
		res.erase(res.begin(), res.begin() + len);
	}
	return res;
}


//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(string digits)
{
	return letterCombinations(digits);
}

//#define USE_SOLUTION_CUSTOM
//vector<string> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/letter-combinations-of-a-phone-number/tests.txt";
}

