
//uint32_t reverseBits(uint32_t n)
//{
//	bitset<32> b = n;
//	for (int i = 0; i < 16; i++)
//	{
//		if (b[i] != b[31 - i])
//		{
//			b[i] = !b[i];
//			b[31 - i] = !b[31 - i];
//		}
//	}
//	return b.to_ulong();//将bitset转换成unsigned long类型 
//}

//////////////////////////////////////////////////////////////////////////
uint32_t reverseBits(uint32_t n)
{
	int i = 32;
	uint32_t res = 0;
	while (i--)
	{
		res <<= 1;//向左移一位 
		res += n & 1;
		n >>= 1;//向右移一位 
	}
	return res;
}

//////////////////////////////////////////////////////////////////////////
uint32_t _solution_run(uint32_t n)
{
	return reverseBits(n);
}

//#define USE_SOLUTION_CUSTOM
//uint32_t _solution_custom(TestCases &tc)
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
	return "../../problems/reverse-bits/tests.txt";
}

