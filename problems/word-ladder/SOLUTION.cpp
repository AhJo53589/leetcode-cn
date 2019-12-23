
//////////////////////////////////////////////////////////////////////////
//int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
//{
//	unordered_set<string> wordDict(wordList.begin(), wordList.end());
//	if (wordDict.find(endWord) == wordDict.end()) return 0;
//
//	unordered_set<string> beginSet{ beginWord };
//	unordered_set<string> endSet{ endWord };
//	int step = 1;
//	while (!beginSet.empty()) 
//	{
//		unordered_set<string> tempSet;
//		++step;
//
//		for (auto s : beginSet) // ��wordDictȥ��,�����ظ�����
//		{
//			wordDict.erase(s);
//		}
//
//		for (auto s : beginSet) 
//		{
//			for (int i = 0; i < s.size(); ++i) 
//			{
//				string str = s;   // str��beginSet�е�һ���ַ���
//				for (char c = 'a'; c <= 'z'; ++c) 
//				{
//					str[i] = c;   // ��ʱstr��beginSet�е�ĳ���ַ����滻һ���ַ�����ַ���
//
//					if (wordDict.count(str) == 0) continue;	// wordDict��û��beginSet�е�ĳ���ַ����滻һ���ַ�����ַ���
//					if (endSet.count(str) > 0) return step; // endSet����str����endSet����beginSet�е�ĳ���ַ����滻һ���ַ�����ַ�����
//						
//					tempSet.insert(str);  // ��ʱ��str������wordDict�У����ǲ���endSet�С�����û�ҵ���
//				}
//			}
//		}
//
//		if (tempSet.size() < endSet.size()) 
//		{
//			beginSet = tempSet;
//		}
//		else
//		{
//			beginSet = endSet;
//			endSet = tempSet;
//		}
//	}
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////
int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
	if (beginWord == endWord) return 1;
	bool flag = true;

	map<string, vector<string>> comboList;
	for (auto w : wordList)
	{
		if (w == endWord)
		{
			flag = false;
		}
		for (size_t i = 0; i < w.size(); i++)
		{
			auto temp = w;
			temp[i] = '*';
			comboList[temp].push_back(w);
		}
	}
	if (flag) return 0;

	unordered_map<string, int> vi[2];
	queue<string> que[2];
	que[0].push(beginWord);
	vi[0][beginWord] = 1;
	que[1].push(endWord);
	vi[1][endWord] = 1;

	while (!que[0].empty() || !que[1].empty())
	{
		int k = (que[0].size() < que[1].size()) ? 0 : 1;
		k = (que[k].size() == 0) ? (k + 1) % 2 : k;
		auto& qr = (que[0].size() < que[1].size()) ? que[0] : que[1];
		
		for (int i = que[k].size(); i > 0; i--)
		{
			auto q = que[k].front();
			que[k].pop();

			for (size_t i = 0; i < q.size(); i++)
			{
				auto temp = q;
				temp[i] = '*';

				for (auto w : comboList[temp])
				{
					if (vi[k].count(w) != 0) continue;
					int k2 = (k + 1) % 2;
					if (vi[k2].count(w) != 0)
					{
						return vi[k2][w] + vi[k][q];
					}

					que[k].push(w);
					vi[k][w] = vi[k][q] + 1;
				}
			}
		}
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string beginWord, string endWord, vector<string>& wordList)
{
	return ladderLength(beginWord,endWord,wordList);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
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
	return "../../problems/word-ladder/tests.txt";
}

