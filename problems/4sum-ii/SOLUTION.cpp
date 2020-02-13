


//////////////////////////////////////////////////////////////////////////
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
{
	unordered_map<int, int> rec;
	int res = 0;
	for (int i = 0; i < C.size(); i++)
		for (int j = 0; j < D.size(); j++)
			rec[C[i] + D[j]]++;

	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++) {
			if (rec.find(-A[i] - B[j]) != rec.end())
				res += rec[-A[i] - B[j]];
		}
	return res;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
{
	return fourSumCount(A,B,C,D);
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

