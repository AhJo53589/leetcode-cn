
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
        unordered_map<string, int> cnt;
        unordered_set<string> ban;
        for (auto& w : banned)
        {
            ban.insert(w);
        }

        int maxcnt = 0;
        string ans;

        for (auto& c : paragraph)
        {
            c = isalpha(c) ? c : ' ';
        }
        stringstream ss(paragraph);
        string temp;
        while (ss >> temp)
        {
            for (auto& c : temp)
            {
                c = tolower(c);
            }
            //transform(temp.begin(), temp.end(), temp.begin(), tolower);
            if (ban.count(temp) != 0) continue;
            cnt[temp]++;
            if (cnt[temp] > maxcnt)
            {
                maxcnt = cnt[temp];
                ans = temp;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string paragraph, vector<string>& banned)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << paragraph << endl;
    Solution sln;
    return sln.mostCommonWord(paragraph, banned);
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
