
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> dic;

        for (auto& name : names) {
            if (dic.count(name) == 0) {
                dic.insert({ name, 0 });
                continue;
            }
           
            int idx = dic[name];
            while (true) {
                idx++;
                string temp = name + "(" + to_string(idx) + ")";
                if (dic.count(temp) != 0) continue;
                dic[name] = idx;
                name = temp;
                dic[name] = 0;
                break;
            }
        }

        return names;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(vector<string>& names)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    //printVectorT(names);
    Solution sln;
    return sln.getFolderNames(names);
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
