
//////////////////////////////////////////////////////////////////////////
int minTime(vector<int>& p1, vector<int>& p2)
{
    int x = abs(p2[0] - p1[0]);
    int y = abs(p2[1] - p1[1]);
    //return max(x, y) - min(x, y) + min(x, y);
	return max(x, y);
}

int minTimeToVisitAllPoints(vector<vector<int>>& points) 
{
    int ans = 0;
    for (size_t i = 1; i < points.size(); i++)
    {
        ans += minTime(points[i - 1], points[i]);
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& points)
{
	return minTimeToVisitAllPoints(points);
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
	return "../../problems/minimum-time-visiting-all-points/tests.txt";
}

