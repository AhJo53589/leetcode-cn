


//////////////////////////////////////////////////////////////////////////
class CombinationIterator 
{
public:
    CombinationIterator(string characters, int combinationLength) 
        : chs(characters), len(combinationLength)
    {
        for (size_t i = 0; i < chs.size(); i++)
        {
            um[chs[i]] = i;
        }

		for (size_t i = 0; i < len; i++)
		{
			strNext.push_back(chs[i]);
		}
    }

    string next()
    {
        string ret = strNext;

        for (size_t i = strNext.size() - 1; i < strNext.size(); i--)
        {
            auto di = um[strNext[i]] + 1;
            if (di + len - i - 1 < chs.size())
            {
                strNext[i] = chs[di];
                while ((++i) < strNext.size())
                {
					strNext[i] = chs[++di];
                }
                return ret;
            }
        }
		strNext = "";

		return ret;
    }

    bool hasNext() 
    {
        return strNext != "";
	}

private:
    string chs;
	string strNext;
    int len;

    unordered_map<char, size_t> um;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

//////////////////////////////////////////////////////////////////////////
//int _solution_run(vector<vector<int>>& intervals)
//{
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases& tc)
{
	vector<string> sf = tc.get<vector<string>>();
	string chs = tc.get<string>();
	int len = tc.get<int>();

	string ans = "[";
	CombinationIterator* obj = nullptr;
	for (size_t i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "CombinationIterator")
		{
			obj = new CombinationIterator(chs, len);
			ans += "null";
		}
		else if (sf[i] == "next")
		{
			string r = obj->next();
			ans += r;
		}
		else if (sf[i] == "hasNext")
		{
			bool r = obj->hasNext();
			ans += r ? "true" : "false";
		}
		ans += ",";
	}
	ans.pop_back();
	ans += "]";
	return ans;
}
//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/iterator-for-combination/tests.txt";
}

