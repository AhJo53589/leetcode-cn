
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string arrangeWords(string text) {
        vector<string> words;
        stringstream ss(text);
        string temp;
        while (ss >> temp) {
            words.push_back(temp);
        }
        if (!words.empty()) {
            words[0][0] = tolower(words[0][0]);
        }

        stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        string ans = "";
        for (auto& s : words) {
            ans += s;
            ans += " ";
        }
        if (!ans.empty()) {
            ans[0] = toupper(ans[0]);
        }
        ans.pop_back();
        return ans;
    }
};

//class Solution {
//public:
//    string arrangeWords(string text) {
//        text[0] += 'a' - 'A';
//        int start = 0;
//        int end = 0;
//        vector<pair<int, int> > pos_len;
//        int len_now = 0;
//
//        // 提取每个word 的pos 和 len， 放进pos_len中
//        while (end < text.size() && start < text.size()) {
//            if (text[end] == ' ') {
//                len_now = end - start;
//                pos_len.push_back(make_pair(start, len_now));
//                start = end + 1;
//                end = start;
//            }
//            else {
//                end++;
//            }
//        }
//
//        if (start < text.size()) {
//            len_now = text.size() - start;
//            pos_len.push_back(make_pair(start, len_now));
//        }
//
//
//        //依据len排序pos_len， 再把每一个子字符串拼接起来
//        sort(pos_len.begin(), pos_len.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
//            if (a.second == b.second) {
//                return a.first < b.first;
//            }
//            return (a.second < b.second);
//        });
//
//        string result;
//
//        result = text.substr(pos_len[0].first, pos_len[0].second);
//
//
//        for (int i = 1; i < pos_len.size(); i++) {
//            result = result + " " + text.substr(pos_len[i].first, pos_len[i].second);
//        }
//        result[0] -= 'a' - 'A';
//        return result;
//    }
//};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string text)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.arrangeWords(text);
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
