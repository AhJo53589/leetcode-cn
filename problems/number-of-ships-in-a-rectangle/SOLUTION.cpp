
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */
class Sea
{
public:
	Sea(vector<vector<int>> ships) : m_ships(ships), m_cnt(0) {}

	bool hasShips(vector<int> topRight, vector<int> bottomLeft)
	{
		m_cnt++;

		for (auto s : m_ships)
		{
			if (s[0] >= bottomLeft[0] && s[0] <= topRight[0]
				&& s[1] >= bottomLeft[1] && s[1] <= topRight[1])
			{
				return true;
			}
		}
		return false;
	}

	int getCount() { return m_cnt; }

private:
	vector<vector<int>> m_ships;
	int m_cnt;
};

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
//int _solution_run(Sea sea, vector<int> topRight, vector<int> bottomLeft)
//{
//	return countShips(sea,topRight,bottomLeft);
//}

#define USE_SOLUTION_CUSTOM
int _solution_custom(TestCases &tc)
{
	Sea sea(tc.get<vector<vector<int>>>());
	int ans = countShips(sea, tc.get<vector<int>>(), tc.get<vector<int>>());
	return (sea.getCount() < 400) ? ans : -1;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

