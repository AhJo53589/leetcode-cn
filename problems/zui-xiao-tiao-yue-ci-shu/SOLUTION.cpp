
//////////////////////////////////////////////////////////////////////////
//class Solution2 {
//public:
//    int minJump(vector<int>& jump) 
//    {
//        vector<vector<int>> jumpEnd(jump.size() + 1, vector<int>());
//        for (int i = 0; i < jump.size(); i++)
//        {
//            int t = max((int)jump.size(), i + jump[i]);
//            jumpEnd[t].push_back(i);
//        }
//
//        int ans = 0;
//        vector<int> jumpBackPos;
//        
//        int maxPos = jump.size();
//        int minPos = jump.size() - 1;
//
//        queue<unordered_set<int>> que;
//        que.push(jumpEnd(jump.size()));
//
//        while (true)
//        {
//            auto cur = que.front();
//            que.pop();
//
//            maxPos = minPos;
//            for (auto c : cur)
//            {
//                minPos = min(c, minPos);
//            }
//
//            unordered_set<int> back;
//            for (int i = minPos; i < maxPos; i++)
//            {
//                if (cur.count(i) != 0) continue;
//                back.insert(i);
//            }
//            
//            
//        }
//    }
//};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minJump(vector<int>& jump)
    {
        vector<bool> vi(jump.size(), false);
        vi[0] = true;
        int ans = 0;
        int last = 0;

        queue<int> que;
        que.push(0);
        while (!que.empty())
        {
            ans++;
            int len = que.size();
            for (int idx = 0; idx < len; idx++)
            {
                int pos = que.front();
                que.pop();

                if (pos + jump[pos] >= jump.size()) return ans;
                if (!vi[pos + jump[pos]])
                {
                    vi[pos + jump[pos]] = true;
                    que.push(pos + jump[pos]);
                }
                for (int i = last; i < pos; i++)
                {
                    if (!vi[i])
                    {
                        vi[i] = true;
                        que.push(i);
                    }
                }
                if (last < pos)
                {
                    last = pos;
                }
            }
        }
        return 0;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& jump)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minJump(jump);
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
