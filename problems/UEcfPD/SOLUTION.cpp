
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
        int ans = -1;

        for (int i = 0; i < (1 << cookbooks.size()); i++) {
            vector<int> temp = materials;
            vector<int> att = { 0, 0 };

            for (int j = 0; j < cookbooks.size(); j++) {
                if ((i & (1 << j)) == 0) continue;
                if (!CheckEnough(temp, cookbooks[j])) continue;
                Cook(temp, cookbooks[j], att, attribute[j]);
            }

            if (att[1] >= limit) {
                ans = max(ans, att[0]);
            }
        }

        return ans;
    }

    bool CheckEnough(vector<int>& materials, vector<int>& book) {
        for (int i = 0; i < book.size(); i++) {
            if (book[i] > materials[i]) return false;
        }
        return true;
    }

    void Cook(vector<int>& materials, vector<int>& book, vector<int>& att, vector<int>& attribute) {
        for (int i = 0; i < book.size(); i++) {
            materials[i] -= book[i];
        }
        att[0] += attribute[0];
        att[1] += attribute[1];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.perfectMenu(materials, cookbooks, attribute, limit);
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
