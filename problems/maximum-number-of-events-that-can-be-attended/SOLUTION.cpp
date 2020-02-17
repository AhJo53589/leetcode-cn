
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) 
	{
		sort(events.rbegin(), events.rend());
		priority_queue<int, vector<int>, greater<int>> pq;

		int ans = 0;
		int day = 0;
		while (!events.empty() || !pq.empty())
		{
			day++;
			while (!pq.empty() && pq.top() < day)
			{
				pq.pop();
			}
			while (!events.empty() && events.back()[0] == day)
			{
				pq.push(events.back()[1]);
				events.pop_back();
			}
			if (pq.empty()) continue;
			pq.pop();
			ans++;
		}
		
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& events)
{
	//int caseNo = 6;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxEvents(events);
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
