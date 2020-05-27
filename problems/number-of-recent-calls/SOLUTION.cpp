
//////////////////////////////////////////////////////////////////////////
class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        record.push(t);
        while (!record.empty() && record.front() + 3000 < t) {
            record.pop();
        }
        return record.size();
    }

private:
    queue<int> record;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

//////////////////////////////////////////////////////////////////////////
int _solution_run(int t)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	RecentCounter sln;
	return sln.ping(t);
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
