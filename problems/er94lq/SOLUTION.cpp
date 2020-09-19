
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isMagic(vector<int>& target) {
        vector<int> cards;
        for (int i = 0; i < target.size(); i++) {
            cards.push_back(i + 1);
        }
        magicSort(cards, 0);

        int maxk = sameCnt(cards, target, 0);
        for (int i = maxk; i > 0; i--) {
            if (check(cards, target, i)) return true;
        }
        return false;
    }

    bool check(vector<int> cards, vector<int>& target, int k) {
        int start = k;
        while (start < (int)cards.size() - 1) {
            magicSort(cards, start);
            if (sameCnt(cards, target, start) < k) break;
            start += k;
        }
        return sameCnt(cards, target, 0) == target.size();
    }

    void magicSort(vector<int>& v, int start) {
        vector<int> temp;
        for (int i = 0; i < start; i++) {
            temp.push_back(v[i]);
        }
        for (int i = start + 1; i < v.size(); i += 2) {
            temp.push_back(v[i]);
        }
        for (int i = start; i < v.size(); i += 2) {
            temp.push_back(v[i]);
        }
        swap(temp, v);
    }

    int sameCnt(vector<int>& v, vector<int>& target, int start) {
        for (int i = start; i < target.size(); i++) {
            if (v[i] != target[i]) return i - start;
        }
        return target.size() - start;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& target)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(target);
    Solution sln;
    return sln.isMagic(target);
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
