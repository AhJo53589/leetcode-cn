//////////////////////////////////////////////////////////////////////////
class Leaderboard
{
public:
	Leaderboard()
	{
		memset(a, 0, sizeof(a));
		s.clear();
	}

	void addScore(int playerId, int score)
	{
		if (a[playerId] != 0)
		{
			s.erase(s.find(-a[playerId]));
		}
		a[playerId] += score;
		s.insert(-a[playerId]);
	}

	int top(int K) 
	{
		int ans = 0;
		for (auto it = s.begin(); K--; it++)
		{
			ans += *it;
		}
		return -ans;
	}

	void reset(int playerId) 
	{
		s.erase(s.find(-a[playerId]));
		a[playerId] = 0;
	}

private:
	multiset<int> s;
	int a[10001];
};


//////////////////////////////////////////////////////////////////////////
//class Leaderboard 
//{
//public:
//	Leaderboard()
//	{
//
//	}
//
//	void addScore(int playerId, int score)
//	{
//		if (lb_id.count(playerId) == 0)
//		{
//			lb_score.push_back({ playerId, score });
//			lb_id[playerId] = lb_score.size() - 1;
//		}
//		else
//		{
//			lb_score[lb_id[playerId]].second += score;
//		}
//
//		while (true)
//		{
//			size_t i = lb_id[playerId];
//			if (i == 0) break;
//
//			if (lb_score[i].second > lb_score[i - 1].second)
//			{
//				swap(lb_id[playerId], lb_id[lb_score[i - 1].first]);
//				swap(lb_score[i], lb_score[i - 1]);
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//
//	int top(int K) 
//	{
//		int sum = 0;
//		for (int i = 0; i < K; i++)
//		{
//			sum += lb_score[i].second;
//		}
//		return sum;
//	}
//
//	void reset(int playerId)
//	{
//		for (size_t i = lb_id[playerId] + 1; i < lb_score.size(); i++)
//		{
//			lb_id[lb_score[i].first]--;
//		}
//		auto del = lb_score.begin() + lb_id[playerId];
//		lb_score.erase(del);
//		lb_id.erase(playerId);
//	}
//
//private:
//	vector<pair<int, int>> lb_score;
//	unordered_map<int, size_t> lb_id;
//};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr)
{
	return 0;
}

#define USE_SOLUTION_CUSTOM
int _solution_custom(TestCases &tc)
{
	vector<vector<int>> _addScore = stringToVectorT<std::vector<int>>("[[1,73],[2,56],[3,39],[4,51],[5,4]]");
	vector<int> _top = { 1 };
	vector<int> _reset = { 1,2 };
	vector<vector<int>> _addScore2 = stringToVectorT<std::vector<int>>("[[2,51]]");
	vector<int> _top2 = { 3 };

	Leaderboard* obj = new Leaderboard();
	for (auto a : _addScore)
	{
		obj->addScore(a[0], a[1]);
	}
	for (auto t : _top)
	{
		cout << obj->top(t) << endl;
	}
	for (auto r : _reset)
	{
		obj->reset(r);
	}
	for (auto a : _addScore2)
	{
		obj->addScore(a[0], a[1]);
	}
	for (auto t : _top2)
	{
		cout << obj->top(t) << endl;
	}


	return tc.get<int>();
}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/design-a-leaderboard/tests.txt";
}

