
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int lengthLongestPath(string input) {
        int ans = 0;
        vector<string> path;

        replaceAll(input, "\t", "/");
        replaceAll(input, " ", "_");
        stringstream ss(input);
        string temp;
        while (ss >> temp) {
            int depth = temp.find_last_of('/') + 1;
            temp = temp.substr(depth);
            
            while (path.size() > depth) {
                path.pop_back();
            }

            if (temp.find(".") != temp.npos) {
                int sz = 0;
                for (auto &p : path) {
                    sz += p.size() + 1;
                }
                ans = max(ans, sz + (int)temp.size());
            }
            else {
                path.push_back(temp);
            }
        }
        return ans;
    }

    void replaceAll(string& input, string a, string b) {
        while (input.find(a) != input.npos) {
            input = input.replace(input.find(a), 1, b);
        }
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string input)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.lengthLongestPath(input);
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
