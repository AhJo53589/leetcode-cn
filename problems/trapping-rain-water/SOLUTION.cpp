
//////////////////////////////////////////////////////////////////////////
//int trap(vector<int>& height, int &first, int last)
//{
//    int ans = 0;
//    int cut = 0;
//
//    for (int i = 0; i < last; i++)
//    {
//        if (first == -1)
//        {
//            first = (height[i] != 0) ? i : first;
//            continue;
//        }
//
//        if (height[i] < height[first])
//        {
//            cut += height[i];
//        }
//        else
//        {
//            ans += (i - first - 1) * min(height[first], height[i]) - cut;
//            first = i;
//            cut = 0;
//        }
//    }
//
//    return ans;
//}
//
//int trap(vector<int>& height)
//{
//    if (height.empty()) return 0;
//
//    int ans = 0;
//    int first = -1;
//    int last = height.size();
//    ans = trap(height, first, last);
//    if (first == -1) return ans;
//
//    reverse(height.begin(), height.end());
//    last = height.size() - first;
//    first = -1;
//    ans += trap(height, first, last);
//
//    return ans;
//}



//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int trap(vector<int>& height)
    {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++)
        {
            while (!st.empty() && height[st.top()] < height[i])
            {
                int cur = st.top();
                st.pop();
                if (st.empty()) break;
                int l = st.top();
                int r = i;
                int h = min(height[r], height[l]) - height[cur];
                ans += (r - l - 1) * h;
            }
            st.push(i);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& height)
{
    printVectorT(height);
    Solution sln;
    return sln.trap(height);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}

