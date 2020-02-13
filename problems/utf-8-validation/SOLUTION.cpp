
bool validUtf8(vector<int>& data, size_t start)
{
	if (start == data.size()) return true;
	bitset<8> n = data[start];
	if (n[7] == 0) return validUtf8(data, start + 1);

	size_t len = 0;
	int i = 8;
	while (--i >= 0)
	{
		if (n[i] == 0) break;
		if (n[i] == 1)
		{
			len++;
		}
	}
	if (len < 2 || len > 4) return false;

	for (size_t j = 1; j < len; j++)
	{
		if (start + j >= data.size()) return false;
		n = data[start + j];
		if (n[7] != 1 || n[6] != 0) return false;
	}
	return validUtf8(data, start + len);
}

//////////////////////////////////////////////////////////////////////////
bool validUtf8(vector<int>& data)
{
	return validUtf8(data, 0);
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& data)
{
	return validUtf8(data);
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

