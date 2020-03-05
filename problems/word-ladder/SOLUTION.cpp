
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
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
            int k = (que[0].size() <= que[1].size() && que[0].size() != 0) ? 0 : 1;

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
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) return 0;

        unordered_set<string> from({ beginWord });
        unordered_set<string> to({ endWord });
        int ans = 2;

        while (!from.empty())
        {
            unordered_set<string> next;
            for (auto& word : from)
            {
                wordSet.erase(word);
            }
            for (auto& word : from)
            {
                for (int i = 0; i < word.size(); i++)
                {
                    string s = word;
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        s[i] = c;
                        if (wordSet.count(s) == 0) continue;
                        next.insert(s);
                        if (to.count(s) == 0) continue;
                        return ans;
                    }
                }
            }
            from = next;
            if (from.size() > to.size())
            {
                swap(from, to);
            }
            ans++;
        }

	    return 0;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string beginWord, string endWord, vector<string>& wordList)
{
	Solution sln;
	return sln.ladderLength(beginWord,endWord,wordList);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

