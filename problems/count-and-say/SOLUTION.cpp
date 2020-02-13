
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221

// 1 被读作  "one 1"  ("一个一"), 即 11。
// 11 被读作 "two 1s" ("两个一"）, 即 21。
// 21 被读作 "one 2", "one 1" （"一个二", "一个一"), 即 1211。


//////////////////////////////////////////////////////////////////////////
string countAndSay(int n)
{
	if (n <= 0 || n > 30) return "";

	if (n == 1) return "1";

	string str = countAndSay(n - 1);
	string strCount;
	size_t i = 0;
	while (i < str.size())
	{
		size_t j = 1;
		while (str[i] == str[i + j])
		{
			j++;
		}
		strCount += to_string(j);
		strCount += str[i];
		i += j;
	}
	return strCount;
}


//////////////////////////////////////////////////////////////////////////
string _solution_run(int n)
{
	return countAndSay(n);
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

