


//////////////////////////////////////////////////////////////////////////
vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
{
	unordered_set<int> fri_set;
	fri_set.insert(id);
	vector<int> fri_vct = { id };
	for (int i = 0; i < level; i++)
	{
		vector<int> temp;
		for (auto n : fri_vct)
		{
			for (auto cur : friends[n])
			{
				if (fri_set.count(cur) != 0) continue;
				fri_set.insert(cur);
				temp.push_back(cur);
			}
		}
		fri_vct = temp;
	}

	map<string, int> videos_time;
	multimap<int, string> videos;
	for (auto n : fri_vct)
	{
		for (auto v : watchedVideos[n])
		{
			videos_time[v]++;
		}
	}
	for (auto n : videos_time)
	{
		videos.insert({ n.second, n.first });
	}

	vector<string> ans;
	for (auto m : videos)
	{
		ans.push_back(m.second);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level)
{
	return watchedVideosByFriends(watchedVideos,friends,id,level);
}

//#define USE_SOLUTION_CUSTOM
//vector<string> _solution_custom(TestCases &tc)
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
	return "../../problems/get-watched-videos-by-your-friends/tests.txt";
}

