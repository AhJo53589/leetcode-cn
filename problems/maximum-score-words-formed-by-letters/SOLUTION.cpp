
//////////////////////////////////////////////////////////////////////////
vector<int> group(vector<string>& words, int bit)
{
    vector<int> g(26, 0);
    for (int i = 0; i < words.size(); i++)
    {
        if (bit & (1 << i))
        {
            for (auto c : words[i])
            {
                g[c - 'a']++;
            }
        }
    }
    return g;
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
{
    vector<int> l(26, 0);
    for (auto c : letters)
    {
        l[c - 'a']++;
    }

    int ans = 0;
    for (int i = 0; i < (1 << words.size()); i++)
    {
        auto g = group(words, i);
        int temp = 0;
        for (int j = 0; j < 26; j++)
        {
            if (l[j] < g[j])
            {
                temp = 0;
                break;
            }
            else
            {
                temp += g[j] * score[j];
            }
        }
        ans = max(ans, temp);
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& words, vector<char>& letters, vector<int>& score)
{
	return maxScoreWords(words,letters,score);
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

