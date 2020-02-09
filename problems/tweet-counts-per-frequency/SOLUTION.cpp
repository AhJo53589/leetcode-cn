
//////////////////////////////////////////////////////////////////////////
class TweetCounts {
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) 
	{
		record[tweetName][time]++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
	{
		vector<int> ans;

		int f = 1;
		f *= (freq == "minute") ? 60 : 1;
		f *= (freq == "hour") ? 60 * 60 : 1;
		f *= (freq == "day") ? 60 * 60 * 24 : 1;

		int t = startTime;
		while (t <= endTime)
		{
			auto bg = record[tweetName].lower_bound(t);
			auto ed = record[tweetName].upper_bound(min(t + f - 1, endTime));
			int cnt = 0;
			for (auto it = bg; it != ed; it++)
			{
				cnt += it->second;
			}
			ans.push_back(cnt);
			t += f;
		}

		return ans;
    }

private:
	unordered_map<string, map<int, int>> record;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */

//////////////////////////////////////////////////////////////////////////
//vector<int> _solution_run(string freq, string tweetName, int startTime, int endTime)
//{
//	//int caseNo = -1;
//	//static int caseCnt = 0;
//	//if (caseNo != -1 && caseCnt++ != caseNo) return {};
//
//	Solution sln;
//	return sln.getTweetCountsPerFrequency(freq, tweetName, startTime, endTime);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases& tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<vector<string>> param = tc.get<vector<vector<string>>>();

	string ans = "[";
	TweetCounts* obj = nullptr;
	for (size_t i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "TweetCounts")
		{
			obj = new TweetCounts();
			ans += "null";
		}
		else if (sf[i] == "recordTweet")
		{
			obj->recordTweet(param[i][0], stoi(param[i][1]));
			ans += "null";
		}
		else if (sf[i] == "getTweetCountsPerFrequency")
		{
			vector<int> r = obj->getTweetCountsPerFrequency(param[i][0], param[i][1], stoi(param[i][2]), stoi(param[i][3]));
			ans += VectorIntToString(r);
		}
		ans += ",";
	}
	ans.pop_back();
	ans += "]";
	return ans;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
