
//////////////////////////////////////////////////////////////////////////
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        vector<int> vote(persons.size(), 0);
		int top = 0;
        for (int i = 0; i < times.size(); i++) {
            vote[persons[i]]++;
			top = (vote[persons[i]] >= vote[top]) ? persons[i] : top;
            mp[times[i]] = top;
        }
    }
    
    int q(int t) {
        auto it = mp.upper_bound(t);
		it--;
        return it->second;
    }

private:
    map<int, int> mp;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
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

	TopVotedCandidate *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "TopVotedCandidate")
		{
			TestCases stc(sp[i]);
			vector<int> persons = stc.get<vector<int>>();
			vector<int> times = stc.get<vector<int>>();
			obj = new TopVotedCandidate(persons, times);
			ans.push_back("null");
		}
		else if (sf[i] == "q")
		{
			TestCases stc(sp[i]);
			int t = stc.get<int>();
			int r = obj->q(t);
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
