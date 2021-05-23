
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        const int maxSpd = 1e7 + 1;
        int lo = 1;
        int hi = maxSpd;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (calc(dist, mid) <= hour) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return (lo == maxSpd) ? -1 : lo;
    }

    double calc(vector<int>& dist, int spd) {
        double h = 0;
        for (int i = 0; i < dist.size(); i++) {
            double d = dist[i];
            double t = d / (double)spd;
            if (i + 1 != dist.size()) {
                int tt = t;
                if ((double)tt != t) {
                    tt++;
                }
                h += tt;
            }
            else {
                h += t;
            }
        }
        return h;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& dist, double hour)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(dist);
    cout << hour << endl;
    Solution sln;
    return sln.minSpeedOnTime(dist, hour);
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
