


//////////////////////////////////////////////////////////////////////////
int getNum(string word, unordered_map<char, int>& um)
{
	if (word.size() == 0 || um[word[0]] == 0) return -1;
	int out = 0;
	for (auto c : word)
	{
		out *= 10;
		out += um[c];
	}
	return out;
}

bool calc(vector<string>& words, string result, unordered_map<char, int>& um)
{
	int left = 0;
	for (auto w : words)
	{
		int t = getNum(w, um);
		if (t == -1) return false;
		left += t;
	}
	int right = getNum(result, um);
	return left == right;
}

bool isSolvable(vector<string>& words, string result) 
{
	set<char> chars;
	for (auto s : words)
	{
		for (auto c : s)
		{
			chars.insert(c);
		}
	}
	for (auto c : result)
	{
		chars.insert(c);
	}
	vector<char> ch(chars.begin(), chars.end());

	vector<int> nums;
	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}

	do 
	{
		unordered_map<char, int> um;
		for (size_t i = 0; i < ch.size(); i++)
		{
			um[ch[i]] = nums[i];
		}
		if (calc(words, result, um)) return true;

	} while (next_permutation(nums.begin(), nums.end()));
	return false;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<string>& words, string result)
{
	return isSolvable(words,result);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
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
	return "../../problems/_test_0/tests.txt";
}

