
//////////////////////////////////////////////////////////////////////////
int maximumSwap(int num)
{
	string ss = to_string(num);
	vector<char> vc;
	for (auto c : ss)
	{
		vc.push_back(c);
	}
	sort(vc.rbegin(), vc.rend());

	size_t i = 0;
	while (ss[i] == vc[i])
	{
		if (++i == ss.size())
		{
			return num;
		}
	}

	size_t j = ss.find_last_of(vc[i]);

	swap(ss[i], ss[j]);
	return stoi(ss);
}


//////////////////////////////////////////////////////////////////////////
//int maximumSwap(int num) 
//{
//	string ss = to_string(num);
//	vector<int> cnts(10, 0);
//	for (auto c : ss)
//	{
//		cnts[c - '0']++;
//	}
//
//	size_t i = cnts.size() - 1;
//	size_t j = 0;
//	while (true)
//	{
//		if (cnts[i] == 0)
//		{
//			i--;
//			if (i >= cnts.size())
//			{
//				return num;
//			}
//			continue;
//		}
//		if (j < ss.size() && ss[j] - '0' != i) break;
//		cnts[i]--;
//		j++;
//	}
//
//	size_t k = ss.size() - 1;
//	while (k < ss.size())
//	{
//		if (ss[k] - '0' == i) break;
//		k--;
//	}
//
//	swap(ss[j], ss[k]);
//	return stoi(ss);
//}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int num)
{
	return maximumSwap(num);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
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
	return "../../problems/maximum-swap/tests.txt";
}

