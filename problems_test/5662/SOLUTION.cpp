
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> ca(26, 0);
        vector<int> cb(26, 0);
        for (auto& c : a) {
            ca[c - 'a']++;
        }
        for (auto& c : b) {
            cb[c - 'a']++;
        }

        vector<int> pa;
        vector<int> pb;
        partial_sum(ca.begin(), ca.end(), back_inserter(pa));
        partial_sum(cb.begin(), cb.end(), back_inserter(pb));

        return min({ change1(pa, pb), change1(pb, pa), change3(ca, cb) });
    }

    int change1(vector<int>& pa, vector<int>& pb) {
        int _min = INT_MAX;
        for (int i = 0; i < 25; i++) {
            int cnt_a = pa.back() - pa[i];
            int cnt_b = pb[i];
            _min = min(cnt_a + cnt_b, _min);
        }
        return _min;
    }

    int change3(vector<int>& ca, vector<int>& cb) {
        int _max = 0;
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (ca[i] == 0 && cb[i] == 0) continue;
            _max = max(ca[i] + cb[i], _max);
            cnt += ca[i] + cb[i];
        }
        return cnt - _max;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string a, string b)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << a << endl << b << endl;
    Solution sln;
    return sln.minCharacters(a, b);
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
