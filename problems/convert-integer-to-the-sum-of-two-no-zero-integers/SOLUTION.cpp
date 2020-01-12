


//////////////////////////////////////////////////////////////////////////
bool valid(int n)
{
	string str = to_string(n);
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '0') return false;
	}
	return true;
}

int getNext(int n)
{
	n++;
	string str = to_string(n);

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '0')
		{
			for (size_t j = i; j < str.size(); j++)
			{
				str[j] = '1';
			}
		}
	}

	return stoi(str);
}

vector<int> getNoZeroIntegers(int n)
{
	int a = 1;
	int b = n - a;
	while (true)
	{
		if (valid(a) && valid(b)) return { a, b };
		a = getNext(a);
		b = n - a;
		if (a > b) break;
	}
	return {};
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int n)
{
	return getNoZeroIntegers(n);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
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
	return "../../problems/convert-integer-to-the-sum-of-two-no-zero-integers/tests.txt";
}

