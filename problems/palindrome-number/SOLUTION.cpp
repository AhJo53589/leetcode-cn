
//bool isPalindrome(int x) {
//	if (x < 0 || ((x % 10 == 0) && x != 0)) {
//		return false;
//	}
//	int reverse = 0;
//	while (x > reverse) {
//		reverse = reverse * 10 + x % 10;
//		x /= 10;
//	}
//	return x == reverse || x == reverse / 10;
//}


//////////////////////////////////////////////////////////////////////////
bool isPalindrome(int x)
{
	if (x < 0) return false;
	if (x < 10) return true;

	deque<int> d;
	while (x >= 1)
	{
		d.push_back(x % 10);
		x /= 10;
	}
	while (d.size() > 1)
	{
		int h = d.front();
		d.pop_front();
		int t = d.back();
		d.pop_back();
		if (h != t) return false;
	}
	return true;
}


//////////////////////////////////////////////////////////////////////////
bool _solution_run(int x)
{
	return isPalindrome(x);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

