//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        vector<int> ans(seq.size(), 0);
        int d = 0;
        stack<int> st;
        for (int i = 0; i < seq.size(); i++)
        {
            d = max(d, (int)st.size());
            if (seq[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
            }
        }
        for (int i = 0; i < seq.size(); i++)
        {
            int j = 0;
            if (seq[i] == '(')
            {
                st.push(i);
            }
            else
            {
                j = st.top();
                st.pop();
            }
            if (st.size() < d / 2)
            {
                ans[i] = 1;
                ans[j] = 1;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) 
    {
        vector<int> ans(seq.size(), 0);
        int d = 0;
        for (int i = 0; i < seq.size(); i++)
        {
            if (seq[i] == '(') 
            {
                ans[i] = d % 2;
                d++;
            }
            else
            {
                d--;
                ans[i] = d % 2;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(string seq)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << seq << endl;
    Solution sln;
    return sln.maxDepthAfterSplit(seq);

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
