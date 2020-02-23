//#include <ctime>  

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	void parseDate(string &date, int& y, int& m, int& d)
	{
		stringstream ss;
		while (date.find("-") != string::npos)
		{
			date = date.replace(date.find("-"), 1, " ");
		}
		ss << date;
		ss >> y >> m >> d;
	}

	tm setDate(int& y, int& m, int& d)
	{
		tm ret;
		ret.tm_year = y - 1900;
		ret.tm_mon = m - 1;
		ret.tm_mday = d;
		ret.tm_hour = ret.tm_min = ret.tm_sec = 0;
		return ret;
	}

	int daysBetweenDates(string date1, string date2)
	{
		int y, m, d;
		parseDate(date1, y, m, d);
		tm t1 = setDate(y, m, d);
		parseDate(date2, y, m, d);
		tm t2 = setDate(y, m, d);

		time_t tt1 = mktime(&t1);
		time_t tt2 = mktime(&t2);
		return abs(tt2 - tt1) / (24 * 60 * 60);
	}
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string date1, string date2)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.daysBetweenDates(date1, date2);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
