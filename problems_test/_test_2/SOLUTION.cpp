
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string SearchAndReplace(string input, string searchFor, string replaceWith) {
        string output;
        int l = searchFor.size();
        vector<pair<int,int>> ri;
        stack<int> s;
        for (int i = 0;i < input.size();++i) {
            if ('[' == input[i]) {
                s.push(i);
            }
            else if (']' == input[i]) {
                int j = s.top();
                s.pop();
                int nl = i - j - 1;
                if (nl != l) continue;
                bool b = true;
                for (int k = j + 1, m = 0; m < l; ++m, ++k) {
                    if (searchFor[m] != input[k]) {
                        b = false;
                        break;
                    }
                }
                if (b) {
                    ri.push_back({ j,i });
                }
            }
        }
        sort(ri.begin(),ri.end(),less<pair<int,int>>());
        for (int i = 0;i < input.size();++i) {
            if (!ri.empty()) {
                auto t = ri.back();
                if (t.first == i) {
                    output += replaceWith;
                    i = t.second;
                    ri.pop_back();
                }
                else {
                    output.push_back(input[i]);
                }
            }
            else {
                output.push_back(input[i]);
            }
        }
        
        return output;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string input, string searchFor, string replaceWith)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.SearchAndReplace(input, searchFor, replaceWith);
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
