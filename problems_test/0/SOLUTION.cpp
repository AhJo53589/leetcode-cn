
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
//int _solution_run(int)
//{
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<string> sp = tc.get<vector<string>>();
	vector<string> ans;

	TweetCounts *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "TweetCounts")
		{
			obj = new TweetCounts();
			ans.push_back("null");
		}
		else if (sf[i] == "recordTweet")
		{
			TestCases stc(sp[i]);
			string tweetName = stc.get<string>();
			int time = stc.get<int>();
			obj->recordTweet(tweetName, time);
			ans.push_back("null");
		}
		else if (sf[i] == "getTweetCountsPerFrequency")
		{
			TestCases stc(sp[i]);
			string freq = stc.get<string>();
			string tweetName = stc.get<string>();
			int startTime = stc.get<int>();
			int endTime = stc.get<int>();
			vector<int> r = obj->getTweetCountsPerFrequency(freq, tweetName, startTime, endTime);
			ans.push_back(convert<string>(r));
		}
	}
	delete obj;

	return convert<string>(ans);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
