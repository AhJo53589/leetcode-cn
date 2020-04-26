
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) 
    {
        vector<int> ans(requirements.size(), -1);

        vector<int> att_0(increase.size() + 1, 0);
        vector<int> att_1(increase.size() + 1, 0);
        vector<int> att_2(increase.size() + 1, 0);

        for (int i = 0; i < increase.size(); i++)
        {
            att_0[i + 1] = att_0[i] + increase[i][0];
            att_1[i + 1] = att_1[i] + increase[i][1];
            att_2[i + 1] = att_2[i] + increase[i][2];
        }

        for (int i = 0; i < requirements.size(); i++)
        {
            auto day_0 = lower_bound(att_0.begin(), att_0.end(), requirements[i][0]);
            auto day_1 = lower_bound(att_1.begin(), att_1.end(), requirements[i][1]);
            auto day_2 = lower_bound(att_2.begin(), att_2.end(), requirements[i][2]);
            if (day_0 == att_0.end() || day_1 == att_1.end() || day_2 == att_2.end()) continue;
            
            ans[i] = max(day_0 - att_0.begin(), max(day_1 - att_1.begin(), day_2 - att_2.begin()));
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& increase, vector<vector<int>>& requirements)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getTriggerTime(increase, requirements);
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
