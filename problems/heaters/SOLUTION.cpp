class Solution2 {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int Nh = houses.size();
        sort(heaters.begin(), heaters.end());
        int ans = 0;

        for (auto& x : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), x);
            if (it == heaters.begin()) {
                ans = max(ans, abs(*it - x));
            }
            else if (it == heaters.end()) {
                ans = max(ans, abs(*(it - 1) - x));
            }
            else {
                ans = max(ans, min(abs(*(it - 1) - x), abs(*it - x)));
            }

        }

        return ans;
    }
};


//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        int l = 0;
        for (int i = 0; i < houses.size(); i++)
        {
            int radius = INT_MAX;
            for (int j = l; j < heaters.size(); j++)
            {
                l = (houses[i] >= heaters[j]) ? j : l;
                radius = min(radius, abs(houses[i] - heaters[j]));
                if (houses[i] < heaters[j]) break;
            }
            ans = max(ans, radius);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& houses, vector<int>& heaters)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.findRadius(houses, heaters);
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
