
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        vector<int> a;
        vector<int> b;

        for (auto n : cards) {
            if (n % 2 == 0) {
                a.push_back(n);
            }
            else {
                b.push_back(n);
            }
        }
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());

        int ans = 0;
        int i = 0;
        int j = 0;
        
        if (cnt % 2 == 1) {
            if (a.size() == 0) return 0;
            ans += a[i++];
            cnt--;
        }

        while (cnt > 0) {
            if (i + 1 < a.size() && j + 1 < b.size()) {
                int aa = a[i] + a[i + 1];
                int bb = b[j] + b[j + 1];
                ans += max(aa, bb);
                i += (aa > bb) ? 2 : 0;
                j += (aa > bb) ? 0 : 2;
            }
            else if (i + 1 < a.size()) {
                ans += a[i] + a[i + 1];
                i += 2;
            }
            else if (j + 1 < b.size()) {
                ans += b[j] + b[j + 1];
                j += 2;
            }
            else {
                return 0;
            }
            cnt -= 2;
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& cards, int cnt)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(cards);
    cout << cnt << endl;
    Solution sln;
    return sln.maxmiumScore(cards, cnt);
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
