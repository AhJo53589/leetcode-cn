


//////////////////////////////////////////////////////////////////////////
vector<string> fizzBuzz(int n)
{
	vector<string> str;
	for (int i = 1; i <= n; i++)
	{
		if (i % 15 == 0)
		{
			str.push_back("FizzBuzz");
		}
		else if (i % 5 == 0)
		{
			str.push_back("Buzz");
		}
		else if (i % 3 == 0)
		{
			str.push_back("Fizz");
		}
		else
		{
			str.push_back(to_string(i));
		}
	}
	return str;
}

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(int n)
{
	return fizzBuzz(n);
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
	return "../../problems/fizz-buzz/tests.txt";
}

