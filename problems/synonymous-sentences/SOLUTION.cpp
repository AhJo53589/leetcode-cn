


//////////////////////////////////////////////////////////////////////////
void generateSentences(vector<vector<string>>& synonyms, vector<string> words, size_t id, vector<string> &ans, unordered_set<string> us)
{
	if (id == words.size())
	{
		string temp;
		for (auto w : words)
		{
			temp += w;
			temp += " ";
		}
		temp.pop_back();
		ans.push_back(temp);
		return;
	}

	if (us.count(words[id])) return;
	us.insert(words[id]);

	for (auto vs : synonyms)
	{
		if (words[id] == vs[0])
		{
			words[id] = vs[1];
			generateSentences(synonyms, words, id, ans, us);
			words[id] = vs[0];
		}
		if (words[id] == vs[1])
		{
			words[id] = vs[0];
			generateSentences(synonyms, words, id, ans, us);
			words[id] = vs[1];
		}
	}
	us.clear();
	generateSentences(synonyms, words, id + 1, ans, us);
}

vector<string> generateSentences(vector<vector<string>>& synonyms, string text) 
{
	stringstream ss(text);
	vector<string> words;
	string temp;
	while (ss >> temp)
	{
		words.push_back(temp);
	}
	vector<string> ans;
	unordered_set<string> us;
	generateSentences(synonyms, words, 0, ans, us);
	sort(ans.begin(), ans.end());
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(vector<vector<string>>& synonyms, string text)
{
	return generateSentences(synonyms,text);
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
	return "../../problems/synonymous-sentences/tests.txt";
}

