//#include <ctime>  

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	void inputDate(string date, int& y, int& m, int& d)
	{
		stringstream ss;
		while (date.find("-") != string::npos)
		{
			date = date.replace(date.find("-"), 1, " ");
		}
		ss << date;
		ss >> y >> m >> d;
	}

	void setDay(tm& day, int y, int m, int d)
	{
		day.tm_year = y - 1900;
		day.tm_mon = m - 1;
		day.tm_mday = d;
		day.tm_hour = day.tm_min = day.tm_sec = 0;
	}

    int daysBetweenDates(string date1, string date2)
	{
		tm time1, time2;
		int year, month, day;
		inputDate(date1, year, month, day);
		setDay(time1, year, month, day);
		inputDate(date2, year, month, day);
		setDay(time2, year, month, day);

		time_t tim1 = mktime(&time1);
		time_t tim2 = mktime(&time2);
		return abs(tim2 - tim1) / (24 * 60 * 60);
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
