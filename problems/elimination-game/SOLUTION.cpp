

//////////////////////////////////////////////////////////////////////////
int lastRemaining(int n) 
{
	int time = 0;
	int factor = 1;
	int len = n;
	while (len != 1) 
	{
		time++;
		if (time % 2 == 0 || len % 2 == 1) 
		{
			n -= factor;
		}
		factor <<= 1;
		len >>= 1;
	}
	return n;
}

//////////////////////////////////////////////////////////////////////////
//int lastRemaining(int n)
//{
//	if (n == 0) return 0;
//
//	int first = 1;							//第一个数
//	int factor = 1;							//公差
//	bool isLeft = true;						//方向
//	bool isEven = ((n & 1) == 0);			//长度是否为偶数
//
//	while (n != 1)
//	{
//		if (isLeft || !isEven)				//若从左向右或者从右向左时为奇数，第一个数变为原来的第二个
//		{
//			first += factor;
//		}
//		isLeft = !isLeft;					//改变方向
//		n >>= 1;							//长度减半
//		factor <<= 1;						//公差翻倍
//		isEven = ((n & 1) == 0);			//判断奇偶
//	}
//	return first;
//}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	return lastRemaining(n);
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
	return "../../problems/elimination-game/tests.txt";
}

