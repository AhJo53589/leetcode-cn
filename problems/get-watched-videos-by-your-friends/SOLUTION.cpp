


//////////////////////////////////////////////////////////////////////////
vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
{
	unordered_set<int> friend_set;
	friend_set.insert(id);
	vector<int> friend_vector = { id };

	for (int i = 0; i < level; i++)	// �������������
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

	map<string, int> frequencies;	// ͳ�ƹۿ�Ƶ��
	for (auto n : friend_vector)
	{
		for (auto v : watchedVideos[n])
		{
			frequencies[v]++;
		}
	}

	multimap<int, string> videos;	// ת��Ϊ����Ƶ�������ֵ���
	for (auto n : frequencies)
	{
		videos.insert({ n.second, n.first });
	}

	vector<string> ans;	// ת��Ϊ�����ʽ
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
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

