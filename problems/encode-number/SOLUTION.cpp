


//////////////////////////////////////////////////////////////////////////
string encode(int num) 
{
	if (num == 0) return "";

	int i = 1;
	while (true)
	{
		int n = 1 << i;
		if (num <= n)
		{
			num--;
			string ans = "";
			while (num != 0)
			{
				ans += to_string(num % 2);
				num /= 2;
			}
			while (ans.size() != i)
			{
				ans += "0";
			}
			reverse(ans.begin(), ans.end());
			return ans;
		}
		num -= n;
		i++;
	}
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(int num)
{
	return encode(num);
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

