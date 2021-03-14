
//////////////////////////////////////////////////////////////////////////
struct cmp {
    bool operator () (pair<double, double> a, pair<double, double> b) {
        double aa = ((a.first + 1) / (a.second + 1)) - (a.first / a.second);
        double bb = ((b.first + 1) / (b.second + 1)) - (b.first / b.second);
        return aa < bb;
    }
};
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans = 0;
        priority_queue<pair<double, double>, vector<pair<double, double>>, cmp> pq;
        for (auto& c : classes) {
            if (c[0] == c[1]) {
                ans += 1;
            }
            else {
                pq.push({ c[0], c[1] });
            }
        }

        while (extraStudents-- != 0 && !pq.empty()) {
            auto [pass, total] = pq.top();
            pq.pop();

            pq.push({ pass + 1, total + 1 });
        }

        while (!pq.empty()) {
            auto [pass, total] = pq.top();
            pq.pop();

            ans += (pass / total);
        }

        return ans / (double)classes.size();
    }
};

//////////////////////////////////////////////////////////////////////////
double _solution_run(vector<vector<int>>& classes, int extraStudents)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxAverageRatio(classes, extraStudents);
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
