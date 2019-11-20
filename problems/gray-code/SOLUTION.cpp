
//////////////////////////////////////////////////////////////////////////
//vector<int> grayCode(int n)
//{
//	if (n == 0) return { 0 };
//	if (n == 1) return { 0, 1 };
//
//	vector<int> prev = grayCode(n - 1);
//	vector<int> res;
//	bool bFlag = true;
//	for (int i = 0; i < prev.size(); i += 2)
//	{
//		int add1 = prev[i] & 1;
//		int add2 = (add1 == 1) ? 0 : 1;
//		if (!bFlag) swap(add1, add2);
//		res.push_back((prev[i] << 1) + add1);
//		res.push_back((prev[i] << 1) + add2);
//
//		add1 = prev[i + 1] & 1;
//		add2 = (add1 == 1) ? 0 : 1;
//		if (!bFlag) swap(add1, add2);
//		res.push_back((prev[i + 1] << 1) + add1);
//		res.push_back((prev[i + 1] << 1) + add2);
//
//		bFlag = !bFlag;
//	}
//	return res;
//}


//////////////////////////////////////////////////////////////////////////
vector<int> grayCode(int n) {
	vector<int> res;
	for (int i = 0; i < (1 << n); ++i)
		res.push_back(i ^ (i >> 1));
	return res;
}


//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int n)
{
	return grayCode(n);
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
	return "../../problems/gray-code/tests.txt";
}

