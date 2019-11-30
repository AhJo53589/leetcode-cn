


//////////////////////////////////////////////////////////////////////////
int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft)
{
	int x = topRight[0], y = topRight[1], a = bottomLeft[0], b = bottomLeft[1];
	if (a > x || b > y) return 0;
	if (a == x && b == y) return sea.hasShips(topRight, bottomLeft);

	if (sea.hasShips(topRight, bottomLeft))
	{
		int m = (a + x) >> 1, n = (b + y) >> 1;
		return countShips(sea, { m, n }, { a, b }) +
			countShips(sea, { x, y }, { m + 1, n + 1 }) +
			countShips(sea, { m, y }, { a, n + 1 }) +
			countShips(sea, { x, n }, { m + 1, b });
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(Sea sea, vector<int> topRight, vector<int> bottomLeft)
{
	return countShips(sea,topRight,bottomLeft);
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
	return "../../problems/number-of-ships-in-a-rectangle/tests.txt";
}

