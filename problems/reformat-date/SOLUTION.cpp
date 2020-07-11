
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string reformatDate(string date) {
        vector<string> vcMonth = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        unordered_map<string, int> umMonth;
        for (int i = 0; i < vcMonth.size(); i++) {
            umMonth[vcMonth[i]] = i + 1;
        }

        string temp;
        stringstream ss(date);
        
        ss >> temp;
        int day = 0;
        for (int i = 0; i < temp.size(); i++) {
            if (isalpha(temp[i])) break;
            day *= 10;
            day += (temp[i] - '0');
        }

        ss >> temp;
        int month = umMonth[temp];
        
        ss >> temp;

        string ans = temp;

        ans += "-";
        ans += (month < 10) ? "0" : "";
        ans += to_string(month);
        ans += "-";
        ans += (day < 10) ? "0" : "";
        ans += to_string(day);

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string date)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.reformatDate(date);
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
