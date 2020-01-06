


//////////////////////////////////////////////////////////////////////////
vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
{
	unordered_set<int> friend_set;
	friend_set.insert(id);
	vector<int> friend_vector = { id };

	for (int i = 0; i < level; i++)	// 仅用来计算次数
	{
		vector<int> temp;
		for (auto n : friend_vector)
		{
			for (auto cur : friends[n])
			{
				if (friend_set.count(cur) != 0) continue;
				friend_set.insert(cur);
				temp.push_back(cur);
			}
		}
		friend_vector = temp;
	}

	map<string, int> frequencies;	// 统计观看频率
	for (auto n : friend_vector)
	{
		for (auto v : watchedVideos[n])
		{
			frequencies[v]++;
		}
	}

	multimap<int, string> videos;	// 转换为按照频率升序及字典序
	for (auto n : frequencies)
	{
		videos.insert({ n.second, n.first });
	}

	vector<string> ans;	// 转换为输出格式
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

