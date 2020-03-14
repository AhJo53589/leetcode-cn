//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        if (words.size() == 0) return {};

        int n = words.size();
        int len = words[0].size();

        if (s.size() < n * len) return {};

        unordered_map<string, int> m;
        for (int i = 0; i < n; ++i) ++m[words[i]];

        vector<int> res;
        for (int i = 0; i < len; ++i)
        {
            int start = i;
            int pos = start;
            int cnt = 0;
            unordered_map<string, int> store;
            while (start + n * len <= s.size()) 
            {
                while (cnt < n && m.find(s.substr(pos, len)) != m.end()) 
                {
                    ++cnt;
                    ++store[s.substr(pos, len)];
                    pos += len;
                }

                if (cnt == n) 
                {
                    if (store == m) res.push_back(pos - n * len);
                    --cnt;
                    --store[s.substr(start, len)];
                    start += len;
                }
                else 
                {
                    cnt = 0;
                    store.clear();
                    start = pos + len;
                    pos = start;
                }
            }
        }

        return res;
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        if (words.size() == 0) return {};
        unordered_map<string, int> wordcnt;
        for (auto& w : words)
        {
            wordcnt[w]++;
        }
        int len = words[0].size();

        vector<int> ans;
        for (int i = 0; i < len; i++)
        {
            int left = i;
            int right = left;
            int cnt = 0;

            unordered_map<string, int> window;
            while (left + words.size() * len <= s.size())
            {
                string temp = "";
                while (cnt < words.size())
                {
                    temp = s.substr(right, len);
                    if (wordcnt.find(temp) == wordcnt.end() || window[temp] >= wordcnt[temp]) break;
                    window[temp]++;
                    cnt++;
                    right += len;
                }

                if (window == wordcnt)
                {
                    ans.push_back(left);
                }

                if (wordcnt.find(temp) != wordcnt.end())
                {
                    window[s.substr(left, len)]--;
                    cnt--;
                    left += len;
                }
                else
                {
                    right += len;
                    left = right;
                    cnt = 0;
                    window.clear();
                }
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(string s, vector<string>& words)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    //cout << s << endl;
    //printVectorT(words);
    Solution sln;
    return sln.findSubstring(s, words);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
