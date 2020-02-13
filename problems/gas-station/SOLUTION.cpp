
//////////////////////////////////////////////////////////////////////////
//int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//	int total = 0;
//	int sum = 0;
//	int start = 0;
//	for (int i = 0; i < gas.size(); i++)
//	{
//		int sub = gas[i] - cost[i];
//		total += sub;
//		sum += sub;
//		if (sum < 0)
//		{
//			sum = 0;
//			start = i + 1;
//		}
//	}
//
//	return total < 0 ? -1 : start;
//}

//////////////////////////////////////////////////////////////////////////
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	int n = gas.size();
	int f = 0;
	vector<int> fuel(n, 0);
	for (int i = 0; i < n; i++)
	{
		fuel[i] = gas[i] - cost[i];
		f += fuel[i];
	}
	if (f < 0) return -1;

	for (int i = 0; i < n; i++)
	{
		if (fuel[i] < 0) continue;
		f = fuel[i];

		int j = (i + 1) % n;
		while (true)
		{
			f += fuel[j];
			if (f < 0)
			{
				i = j;
				break;
			}

			j = (j + 1) % n;
			if (j == i) return i;
		}
	}
	return -1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& gas, vector<int>& cost)
{
	return canCompleteCircuit(gas,cost);
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

