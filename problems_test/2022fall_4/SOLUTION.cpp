
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int Leetcode(vector<string>& words) {
        vector<int> count = { 1, 4, 3, 2, 1, 1 };
        dfs(words, count, 0);
        return ans;
    }
    
    void dfs(vector<string>& words, vector<int>& count, int cost) {
        if (cost >= ans) return;
        if (all_of(count.begin(), count.end(), [](int n) { return n == 0; })) {
            ans = min(ans, cost);
            return;
        }
        
        for (int i = 0; i < count.size(); i++) {
            if (count[i] == 0) continue;
            
            count[i]--;
            char c = cWord[i];
            for (auto& word : words) {
                int f1 = word.find_first_of(c);
                int f2 = word.find_last_of(c);
                if (f1 == string::npos) continue;
                
                int _cost = getChar(word, f1);
                dfs(words, count, cost + _cost);
                putChar(word, f1);
                
                if (f1 != f2) {
                    int _cost = getChar(word, f2);
                    dfs(words, count, cost + _cost);
                    putChar(word, f2);
                }
            }
            count[i]++;
        }
    }
    
    int calc(vector<string>& words, int idx, char c) {
        int f1 = words[idx].find_first_of(c);
        int f2 = words[idx].find_last_of(c);
        if (f1 != string::npos) {
            int t1 = f1 * (words[idx].size() - f1 - 1);
            int t2 = f2 * (words[idx].size() - f2 - 1);
            if (t1 <= t2) {
            }
        }
        return 0;
    }
    
    int getChar(string& word, int idx) {
        word[idx] = toupper(word[idx]);
        int left = 0;
        int right = 0;
        for (int i = 0; i < word.size(); i++) {
            left += (i < idx);
            right += (i > idx);
        }
        return left * right;
    }
    
    void putChar(string& word, int idx) {
        word[idx] = tolower(word[idx]);
    }
    
private:
    const int len = 6;
    string cWord = { "helocd" }; // helloleetcode
    int ans = INT_MAX;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& words)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.Leetcode(words);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
